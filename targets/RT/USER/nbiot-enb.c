/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file nbiot-enb.c
 * \brief Top-level threads for eNodeB
 * \author R. Knopp, F. Kaltenberger, Navid Nikaein
 * \date 2012
 * \version 0.1
 * \company Eurecom
 * \email: knopp@eurecom.fr,florian.kaltenberger@eurecom.fr, navid.nikaein@eurecom.fr
 * \note
 * \warning
 */

#define _GNU_SOURCE
#include <pthread.h>

#include "time_utils.h"

#undef MALLOC //there are two conflicting definitions, so we better make sure we don't use it at all

#include "rt_wrapper.h"

#include "assertions.h"


#include "PHY/types.h"

#include "PHY/defs.h"
#undef MALLOC //there are two conflicting definitions, so we better make sure we don't use it at all
//#undef FRAME_LENGTH_COMPLEX_SAMPLES //there are two conflicting definitions, so we better make sure we don't use it at all

#include "../../ARCH/COMMON/common_lib.h"

//#undef FRAME_LENGTH_COMPLEX_SAMPLES //there are two conflicting definitions, so we better make sure we don't use it at all

#include "PHY/LTE_TRANSPORT/if4_tools.h"
#include "PHY/LTE_TRANSPORT/if5_tools.h"

#include "PHY/extern.h"
#include "SCHED/extern.h"
#include "LAYER2/MAC/extern.h"

#include "../../SIMU/USER/init_lte.h"

//NB-IoT 
#include "PHY/defs_NB_IoT.h"
#include "SCHED/defs_NB_IoT.h"
#include "PHY_INTERFACE/IF_Module_NB_IoT.h"
#include "LAYER2/MAC/extern_NB_IoT.h"
#include "PHY/extern_NB_IoT.h"
#include "LAYER2/MAC/defs.h"
#include "LAYER2/MAC/extern.h"
#include "LAYER2/MAC/proto.h"
#include "RRC/LITE/extern.h"
#include "PHY_INTERFACE/extern.h"
#include "PHY_INTERFACE/defs.h"
#ifdef SMBV
#include "PHY/TOOLS/smbv.h"
unsigned short config_frames[4] = {2,9,11,13};
#endif
#include "UTIL/LOG/log_extern.h"
#include "UTIL/OTG/otg_tx.h"
#include "UTIL/OTG/otg_externs.h"
#include "UTIL/MATH/oml.h"
#include "UTIL/LOG/vcd_signal_dumper.h"
#include "UTIL/OPT/opt.h"
#include "enb_config.h"
//#include "PHY/TOOLS/time_meas.h"

#ifndef OPENAIR2
#include "UTIL/OTG/otg_extern.h"
#endif

#if defined(ENABLE_ITTI)
# if defined(ENABLE_USE_MME)
#   include "s1ap_eNB.h"
#ifdef PDCP_USE_NETLINK
#   include "SIMULATION/ETH_TRANSPORT/proto.h"
#endif
# endif
#endif

#include "T.h"

//#define DEBUG_THREADS 1

//#define USRP_DEBUG 1
struct timing_info_t {
  //unsigned int frame, hw_slot, last_slot, next_slot;
  RTIME time_min, time_max, time_avg, time_last, time_now;
  //unsigned int mbox0, mbox1, mbox2, mbox_target;
  unsigned int n_samples;
} timing_info;

// Fix per CC openair rf/if device update
// extern openair0_device openair0;


#if defined(ENABLE_ITTI)
extern volatile int             start_eNB;
extern volatile int             start_UE;
#endif
extern volatile int                    oai_exit;

extern openair0_config_t openair0_cfg[MAX_CARDS];

extern int transmission_mode;

extern int oaisim_flag;

//pthread_t                       main_eNB_thread;

time_stats_t softmodem_stats_mt; // main thread
time_stats_t softmodem_stats_hw; //  hw acquisition
time_stats_t softmodem_stats_rxtx_sf; // total tx time
time_stats_t softmodem_stats_rx_sf; // total rx time

/* mutex, cond and variable to serialize phy proc TX calls
 * (this mechanism may be relaxed in the future for better
 * performances)
 */
static struct {
  pthread_mutex_t  mutex_phy_proc_tx;
  pthread_cond_t   cond_phy_proc_tx;
  volatile uint8_t phy_proc_CC_id;
} sync_phy_proc;

extern double cpuf;

void exit_fun(const char* s);

void init_eNB_NB_IoT(int,int);
void stop_eNB_NB_IoT(int nb_inst);


void wakeup_prach_eNB_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,RU_t *ru,int frame,int subframe);


/*NB-IoT rxtx
 *
 * IMPORTANT When we run the rxtx thread for NB-IoT we should not run at the same time otherwise we fill the same buffers in PHY_Vars_eNB
 *
 * For the moment the NB-IoT implementation foresees a single thread implementation
 * */
static inline int rxtx_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,eNB_rxtx_proc_t *proc, char *thread_name) {

  //Allocate memory for the structures used by PHY and MAC
  UL_IND_NB_IoT_t *UL_INFO;
  Sched_Rsp_NB_IoT_t *Sched_Rsp; 

  UL_INFO = (UL_IND_NB_IoT_t*) malloc(sizeof(UL_IND_NB_IoT_t));
  Sched_Rsp = (Sched_Rsp_NB_IoT_t*) malloc(sizeof(Sched_Rsp_NB_IoT_t)); 

  // ****************************************
  // Common RX procedures subframe n

  if ((eNB->do_prach)&&((eNB->node_function != NGFI_RCC_IF4p5_NB_IoT)))
    eNB->do_prach(eNB,proc->frame_rx,proc->subframe_rx);
  
  /*UE-specific RX processing for subframe n*/


  /*
   * stored the Upink information in UL_info struct, process it and made it into FAPI style,
   */

  phy_procedures_eNB_uespec_RX_NB_IoT(eNB,proc,UL_INFO);

  /*
   * send the UL_Indication to higher layer that also provide a tick to the scheduler_dlsch_ulsch
   * (on its turn the scheduler will trigger the phy_procedure_eNB_TX through schedule_responce function
   */

  pthread_mutex_lock(&eNB->UL_INFO_mutex);
  eNB->UL_INFO.frame     = proc->frame_rx;
  eNB->UL_INFO.subframe  = proc->subframe_rx;
  eNB->UL_INFO.module_id = eNB->Mod_id;
  eNB->UL_INFO.CC_id     = eNB->CC_id;
  eNB->if_inst->UL_indication(&eNB->UL_INFO);
  pthread_mutex_unlock(&eNB->UL_INFO_mutex);

  

  if (oai_exit) return(-1);
  
  
  if (release_thread(&proc->mutex_rxtx,&proc->instance_cnt_rxtx,thread_name)<0) return(-1);

  stop_meas( &softmodem_stats_rxtx_sf );
  
  return(0);
}


#if 0 //defined(ENABLE_ITTI) && defined(ENABLE_USE_MME)
// Wait for eNB application initialization to be complete (eNB registration to MME)
static void wait_system_ready (char *message, volatile int *start_flag) {
  
  static char *indicator[] = {".    ", "..   ", "...  ", ".... ", ".....",
			      " ....", "  ...", "   ..", "    .", "     "};
  int i = 0;
  
  while ((!oai_exit) && (*start_flag == 0)) {
    LOG_N(EMU, message, indicator[i]);
    fflush(stdout);
    i = (i + 1) % (sizeof(indicator) / sizeof(indicator[0]));
    usleep(200000);
  }
  
  LOG_D(EMU,"\n");
}
#endif





void nb_iot_eNB_top(PHY_VARS_eNB_NB_IoT *eNB, int frame_rx, int subframe_rx, char *string)
{
  eNB_proc_t *proc           = &eNB->proc;
  eNB_rxtx_proc_t *proc_rxtx = &proc->proc_rxtx[0];

  proc->frame_rx    = frame_rx;
  proc->subframe_rx = subframe_rx;

  if (!oai_exit) {
    LOG_D(PHY,"eNB_top in %p (proc %p, CC_id %d), frame %d, subframe %d, instance_cnt_prach %d\n",
	  (void*)pthread_self(), proc, eNB->CC_id, proc->frame_rx,proc->subframe_rx,proc->instance_cnt_prach);

    T(T_ENB_MASTER_TICK, T_INT(0), T_INT(proc->frame_rx), T_INT(proc->subframe_rx));

    proc_rxtx->subframe_rx = proc->subframe_rx;
    proc_rxtx->frame_rx    = proc->frame_rx;
    proc_rxtx->subframe_tx = (proc->subframe_rx+4)%10;
    proc_rxtx->frame_tx    = (proc->subframe_rx>5) ? (1+proc->frame_rx)&1023 : proc->frame_rx;
    proc->frame_tx         = proc_rxtx->frame_tx;
    proc_rxtx->timestamp_tx = proc->timestamp_tx;

    if (rxtx(eNB,proc_rxtx,string) < 0) LOG_E(PHY,"eNB %d CC_id %d failed during execution\n",eNB->Mod_id,eNB->CC_id);
    LOG_D(PHY,"eNB_top out %p (proc %p, CC_id %d), frame %d, subframe %d, instance_cnt_prach %d\n",
	  (void*)pthread_self(), proc, eNB->CC_id, proc->frame_rx,proc->subframe_rx,proc->instance_cnt_prach);
  }
}


int wakeup_nb_iot_rxtx(PHY_VARS_eNB_NB_IoT *eNB,RU_t *ru) {

  eNB_proc_t *proc=&eNB->proc;

  eNB_rxtx_proc_t *proc_rxtx=&proc->proc_rxtx[proc->frame_rx&1];

  LTE_DL_FRAME_PARMS *fp = &eNB->frame_parms;

  int i;
  struct timespec wait;
  
  pthread_mutex_lock(&proc->mutex_RU);
  for (i=0;i<eNB->num_RU;i++) {
    if (ru == eNB->RU_list[i]) {
      if ((proc->RU_mask&(1<<i)) > 0)
	LOG_E(PHY,"eNB %d frame %d, subframe %d : previous information from RU %d (num_RU %d,mask %x) has not been served yet!\n",
	      eNB->Mod_id,proc->frame_rx,proc->subframe_rx,ru->idx,eNB->num_RU,proc->RU_mask);
      proc->RU_mask |= (1<<i);
    }
  }
  if (proc->RU_mask != (1<<eNB->num_RU)-1) {  // not all RUs have provided their information so return
    pthread_mutex_unlock(&proc->mutex_RU);
    return(0);
  }
  else { // all RUs have provided their information so continue on and wakeup eNB processing
    proc->RU_mask = 0;
    pthread_mutex_unlock(&proc->mutex_RU);
  }




  wait.tv_sec=0;
  wait.tv_nsec=5000000L;

  /* accept some delay in processing - up to 5ms */
  for (i = 0; i < 10 && proc_rxtx->instance_cnt_rxtx == 0; i++) {
    LOG_W( PHY,"[eNB] Frame %d, eNB RXn-TXnp4 thread busy!! (cnt_rxtx %i)\n", proc_rxtx->frame_tx, proc_rxtx->instance_cnt_rxtx);
    usleep(500);
  }
  if (proc_rxtx->instance_cnt_rxtx == 0) {
    exit_fun( "TX thread busy" );
    return(-1);
  }

  // wake up TX for subframe n+4
  // lock the TX mutex and make sure the thread is ready
  if (pthread_mutex_timedlock(&proc_rxtx->mutex_rxtx,&wait) != 0) {
    LOG_E( PHY, "[eNB] ERROR pthread_mutex_lock for eNB RXTX thread %d (IC %d)\n", proc_rxtx->subframe_rx&1,proc_rxtx->instance_cnt_rxtx );
    exit_fun( "error locking mutex_rxtx" );
    return(-1);
  }
  
  ++proc_rxtx->instance_cnt_rxtx;
  
  // We have just received and processed the common part of a subframe, say n. 
  // TS_rx is the last received timestamp (start of 1st slot), TS_tx is the desired 
  // transmitted timestamp of the next TX slot (first).
  // The last (TS_rx mod samples_per_frame) was n*samples_per_tti, 
  // we want to generate subframe (n+4), so TS_tx = TX_rx+4*samples_per_tti,
  // and proc->subframe_tx = proc->subframe_rx+4
  proc_rxtx->timestamp_tx = proc->timestamp_rx + (4*fp->samples_per_tti);
  proc_rxtx->frame_rx     = proc->frame_rx;
  proc_rxtx->subframe_rx  = proc->subframe_rx;
  proc_rxtx->frame_tx     = (proc_rxtx->subframe_rx > 5) ? (proc_rxtx->frame_rx+1)&1023 : proc_rxtx->frame_rx;
  proc_rxtx->subframe_tx  = (proc_rxtx->subframe_rx + 4)%10;
  
  // the thread can now be woken up
  if (pthread_cond_signal(&proc_rxtx->cond_rxtx) != 0) {
    LOG_E( PHY, "[eNB] ERROR pthread_cond_signal for eNB RXn-TXnp4 thread\n");
    exit_fun( "ERROR pthread_cond_signal" );
    return(-1);
  }
  
  pthread_mutex_unlock( &proc_rxtx->mutex_rxtx );

  return(0);
}

void wakeup_prach_nb_iot_eNB(PHY_VARS_eNB_NB_IoT *eNB,RU_t *ru,int frame,int subframe) {

  eNB_proc_t *proc = &eNB->proc;
  LTE_DL_FRAME_PARMS *fp=&eNB->frame_parms;
  int i;

  if (ru!=NULL) {
    pthread_mutex_lock(&proc->mutex_RU_PRACH);
    for (i=0;i<eNB->num_RU;i++) {
      if (ru == eNB->RU_list[i]) {
	LOG_D(PHY,"frame %d, subframe %d: RU %d for eNB %d signals PRACH (mask %x, num_RU %d)\n",frame,subframe,i,eNB->Mod_id,proc->RU_mask_prach,eNB->num_RU);
	if ((proc->RU_mask_prach&(1<<i)) > 0)
	  LOG_E(PHY,"eNB %d frame %d, subframe %d : previous information (PRACH) from RU %d (num_RU %d, mask %x) has not been served yet!\n",
		eNB->Mod_id,frame,subframe,ru->idx,eNB->num_RU,proc->RU_mask_prach);
	proc->RU_mask_prach |= (1<<i);
      }
    }
    if (proc->RU_mask_prach != (1<<eNB->num_RU)-1) {  // not all RUs have provided their information so return
      pthread_mutex_unlock(&proc->mutex_RU_PRACH);
      return;
    }
    else { // all RUs have provided their information so continue on and wakeup eNB processing
      proc->RU_mask_prach = 0;
      pthread_mutex_unlock(&proc->mutex_RU_PRACH);
    }
  }
    
  // check if we have to detect PRACH first
  if (is_prach_subframe(fp,frame,subframe)>0) { 
    LOG_D(PHY,"Triggering prach processing, frame %d, subframe %d\n",frame,subframe);
    if (proc->instance_cnt_prach == 0) {
      LOG_W(PHY,"[eNB] Frame %d Subframe %d, dropping PRACH\n", frame,subframe);
      return;
    }
    
    // wake up thread for PRACH RX
    if (pthread_mutex_lock(&proc->mutex_prach) != 0) {
      LOG_E( PHY, "[eNB] ERROR pthread_mutex_lock for eNB PRACH thread %d (IC %d)\n", proc->thread_index, proc->instance_cnt_prach);
      exit_fun( "error locking mutex_prach" );
      return;
    }
    
    ++proc->instance_cnt_prach;
    // set timing for prach thread
    proc->frame_prach = frame;
    proc->subframe_prach = subframe;
    
    // the thread can now be woken up
    if (pthread_cond_signal(&proc->cond_prach) != 0) {
      LOG_E( PHY, "[eNB] ERROR pthread_cond_signal for eNB PRACH thread %d\n", proc->thread_index);
      exit_fun( "ERROR pthread_cond_signal" );
      return;
    }
    
    pthread_mutex_unlock( &proc->mutex_prach );
  }

}



/*!
 * \brief The prach receive thread of eNB.
 * \param param is a \ref eNB_proc_t structure which contains the info what to process.
 * \returns a pointer to an int. The storage is not on the heap and must not be freed.
 */
static void* nb_iot_eNB_thread_prach( void* param ) {
  static int eNB_thread_prach_status;


  PHY_VARS_eNB_NB_IoT *eNB= (PHY_VARS_eNB_NB_IoT *)param;
  eNB_proc_t *proc = &eNB->proc;

  // set default return value
  eNB_thread_prach_status = 0;

  thread_top_init("eNB_thread_prach",1,500000L,1000000L,20000000L);


  while (!oai_exit) {
    
    if (oai_exit) break;

    
    if (wait_on_condition(&proc->mutex_prach,&proc->cond_prach,&proc->instance_cnt_prach,"eNB_prach_thread") < 0) break;

    LOG_D(PHY,"Running eNB prach procedures\n");
    prach_procedures(eNB
#ifdef Rel14
		     ,0
#endif
		     );
    
    if (release_thread(&proc->mutex_prach,&proc->instance_cnt_prach,"eNB_prach_thread") < 0) break;
  }

  LOG_I(PHY, "Exiting eNB thread PRACH\n");


  eNB_thread_prach_status = 0;
  return &eNB_thread_prach_status;
}

void init_eNB_proc_NB_IoT(int inst) {
  
  int i=0;
  int CC_id;
  PHY_VARS_eNB_NB_IoT *eNB;
  eNB_proc_t *proc;
  eNB_rxtx_proc_t *proc_rxtx;
  pthread_attr_t *attr0=NULL,*attr1=NULL,*attr_prach=NULL;
    //*attr_td=NULL,*attr_te=NULL;
#ifdef Rel14
  pthread_attr_t *attr_prach_br=NULL;
#endif

  for (CC_id=0; CC_id<RC.nb_CC[inst]; CC_id++) {
    eNB = RC.L1_NB_IoT[inst][CC_id];
#ifndef OCP_FRAMEWORK
    LOG_I(PHY,"Initializing eNB processes %d CC_id %d \n",inst,CC_id);
#endif
    proc = &eNB->proc;

    proc_rxtx                      = proc->proc_rxtx;
    proc_rxtx[0].instance_cnt_rxtx = -1;
    proc_rxtx[1].instance_cnt_rxtx = -1;
    proc->instance_cnt_prach       = -1;
    proc->instance_cnt_asynch_rxtx = -1;
    proc->CC_id                    = CC_id;    

    proc->first_rx=1;
    proc->first_tx=1;
    proc->RU_mask=0;
    proc->RU_mask_prach=0;

    pthread_mutex_init( &eNB->UL_INFO_mutex, NULL);
    pthread_mutex_init( &proc_rxtx[0].mutex_rxtx, NULL);
    pthread_mutex_init( &proc_rxtx[1].mutex_rxtx, NULL);
    pthread_cond_init( &proc_rxtx[0].cond_rxtx, NULL);
    pthread_cond_init( &proc_rxtx[1].cond_rxtx, NULL);

    pthread_mutex_init( &proc->mutex_prach, NULL);
    pthread_mutex_init( &proc->mutex_asynch_rxtx, NULL);
    pthread_mutex_init( &proc->mutex_RU,NULL);
    pthread_mutex_init( &proc->mutex_RU_PRACH,NULL);

    pthread_cond_init( &proc->cond_prach, NULL);
    pthread_cond_init( &proc->cond_asynch_rxtx, NULL);

    pthread_attr_init( &proc->attr_prach);
    pthread_attr_init( &proc->attr_asynch_rxtx);
    //    pthread_attr_init( &proc->attr_td);
    //    pthread_attr_init( &proc->attr_te);
    pthread_attr_init( &proc_rxtx[0].attr_rxtx);
    pthread_attr_init( &proc_rxtx[1].attr_rxtx);
#ifdef Rel14
    proc->instance_cnt_prach_br    = -1;
    proc->RU_mask_prach_br=0;
    pthread_mutex_init( &proc->mutex_prach_br, NULL);
    pthread_mutex_init( &proc->mutex_RU_PRACH_br,NULL);
    pthread_cond_init( &proc->cond_prach_br, NULL);
    pthread_attr_init( &proc->attr_prach_br);
#endif
#ifndef DEADLINE_SCHEDULER
    attr0       = &proc_rxtx[0].attr_rxtx;
    attr1       = &proc_rxtx[1].attr_rxtx;
    attr_prach  = &proc->attr_prach;
#ifdef Rel14
    attr_prach_br  = &proc->attr_prach_br;
#endif

    //    attr_td     = &proc->attr_td;
    //    attr_te     = &proc->attr_te; 
#endif

    if (eNB->single_thread_flag==0) {
      //the two threads that manage tw consecutive subframes
      pthread_create( &proc_rxtx[0].pthread_rxtx, attr0, eNB_thread_rxtx, &proc_rxtx[0] );
      pthread_create( &proc_rxtx[1].pthread_rxtx, attr1, eNB_thread_rxtx, &proc_rxtx[1] );
    }
    pthread_create( &proc->pthread_prach, attr_prach, eNB_thread_prach, eNB );
#ifdef Rel14
    pthread_create( &proc->pthread_prach_br, attr_prach_br, eNB_thread_prach_br, eNB );
#endif
    char name[16];
    if (eNB->single_thread_flag==0) {
      snprintf( name, sizeof(name), "RXTX0 %d", i );
      pthread_setname_np( proc_rxtx[0].pthread_rxtx, name );
      snprintf( name, sizeof(name), "RXTX1 %d", i );
      pthread_setname_np( proc_rxtx[1].pthread_rxtx, name );
    }

    AssertFatal(proc->instance_cnt_prach == -1,"instance_cnt_prach = %d\n",proc->instance_cnt_prach);

    
  }

  //for multiple CCs: setup master and slaves
  /* 
     for (CC_id=0; CC_id<MAX_NUM_CCs; CC_id++) {
     eNB = PHY_vars_eNB_g[inst][CC_id];

     if (eNB->node_timing == synch_to_ext_device) { //master
     eNB->proc.num_slaves = MAX_NUM_CCs-1;
     eNB->proc.slave_proc = (eNB_proc_t**)malloc(eNB->proc.num_slaves*sizeof(eNB_proc_t*));

     for (i=0; i< eNB->proc.num_slaves; i++) {
     if (i < CC_id)  eNB->proc.slave_proc[i] = &(PHY_vars_eNB_g[inst][i]->proc);
     if (i >= CC_id)  eNB->proc.slave_proc[i] = &(PHY_vars_eNB_g[inst][i+1]->proc);
     }
     }
     }
  */

  /* setup PHY proc TX sync mechanism */
  pthread_mutex_init(&sync_phy_proc.mutex_phy_proc_tx, NULL);
  pthread_cond_init(&sync_phy_proc.cond_phy_proc_tx, NULL);
  sync_phy_proc.phy_proc_CC_id = 0;
}



/*!
 * \brief Terminate eNB TX and RX threads.
 */
void kill_eNB_proc_NB_IoT(int inst) {

  int *status;
  PHY_VARS_eNB_NB_IoT *eNB;
  eNB_proc_t *proc;
  eNB_rxtx_proc_t *proc_rxtx;
  for (int CC_id=0; CC_id<MAX_NUM_CCs; CC_id++) {
    eNB=RC.L1_NB_IoT[inst][CC_id];
    
    proc = &eNB->proc;
    proc_rxtx = &proc->proc_rxtx[0];
    

    LOG_I(PHY, "Killing TX CC_id %d inst %d\n", CC_id, inst );

    if (eNB->single_thread_flag==0) {
      proc_rxtx[0].instance_cnt_rxtx = 0; // FIXME data race!
      proc_rxtx[1].instance_cnt_rxtx = 0; // FIXME data race!
      pthread_cond_signal( &proc_rxtx[0].cond_rxtx );    
      pthread_cond_signal( &proc_rxtx[1].cond_rxtx );
    }
    proc->instance_cnt_prach = 0;
    pthread_cond_signal( &proc->cond_prach );

    pthread_cond_broadcast(&sync_phy_proc.cond_phy_proc_tx);
    pthread_join( proc->pthread_prach, (void**)&status );    

    LOG_I(PHY, "Destroying prach mutex/cond\n");
    pthread_mutex_destroy( &proc->mutex_prach );
    pthread_cond_destroy( &proc->cond_prach );
#ifdef Rel14
    proc->instance_cnt_prach_br = 0;
    pthread_cond_signal( &proc->cond_prach_br );
    pthread_join( proc->pthread_prach_br, (void**)&status );    
    pthread_mutex_destroy( &proc->mutex_prach_br );
    pthread_cond_destroy( &proc->cond_prach_br );
#endif         
    LOG_I(PHY, "Destroying UL_INFO mutex\n");
    pthread_mutex_destroy(&eNB->UL_INFO_mutex);
    int i;
    if (eNB->single_thread_flag==0) {
      for (i=0;i<2;i++) {
	LOG_I(PHY, "Joining rxtx[%d] mutex/cond\n",i);
	pthread_join( proc_rxtx[i].pthread_rxtx, (void**)&status );
	LOG_I(PHY, "Destroying rxtx[%d] mutex/cond\n",i);
	pthread_mutex_destroy( &proc_rxtx[i].mutex_rxtx );
	pthread_cond_destroy( &proc_rxtx[i].cond_rxtx );
      }
    }
  }
}




void init_eNB_afterRU_NB_IoT(void) {

  int inst,CC_id,ru_id,i,aa;
  PHY_VARS_eNB_NB_IoT *eNB;


  for (inst=0;inst<RC.nb_inst;inst++) {
    for (CC_id=0;CC_id<RC.nb_CC[inst];CC_id++) {
      eNB                                  =  RC.L1_NB_IoT_NB_IoT[inst][CC_id];
      phy_init_lte_eNB_NB_IoT(eNB,0,0);
      // map antennas and PRACH signals to eNB RX
      AssertFatal(eNB->num_RU>0,"Number of RU attached to eNB %d is zero\n",eNB->Mod_id);
      LOG_I(PHY,"Mapping RX ports from %d RUs to eNB %d\n",eNB->num_RU,eNB->Mod_id);
      eNB->frame_parms.nb_antennas_rx       = 0;
      eNB->prach_vars.rxsigF[0] = (int16_t**)malloc16(64*sizeof(int16_t*));
      for (ru_id=0,aa=0;ru_id<eNB->num_RU;ru_id++) {
	eNB->frame_parms.nb_antennas_rx    += eNB->RU_list[ru_id]->nb_rx;

	AssertFatal(eNB->RU_list[ru_id]->common.rxdataF!=NULL,
		    "RU %d : common.rxdataF is NULL\n",
		    eNB->RU_list[ru_id]->idx);

	AssertFatal(eNB->RU_list[ru_id]->prach_rxsigF!=NULL,
		    "RU %d : prach_rxsigF is NULL\n",
		    eNB->RU_list[ru_id]->idx);

	for (i=0;i<eNB->RU_list[ru_id]->nb_rx;aa++,i++) { 
	  LOG_I(PHY,"Attaching RU %d antenna %d to eNB antenna %d\n",eNB->RU_list[ru_id]->idx,i,aa);
	  eNB->prach_vars.rxsigF[0][aa]    =  eNB->RU_list[ru_id]->prach_rxsigF[i];
	  eNB->common_vars.rxdataF[aa]     =  eNB->RU_list[ru_id]->common.rxdataF[i];
	}
      }
      AssertFatal(eNB->frame_parms.nb_antennas_rx >0,
		  "inst %d, CC_id %d : nb_antennas_rx %d\n",inst,CC_id,eNB->frame_parms.nb_antennas_rx);
      LOG_I(PHY,"inst %d, CC_id %d : nb_antennas_rx %d\n",inst,CC_id,eNB->frame_parms.nb_antennas_rx);

    }
    init_eNB_proc_NB_IoT(inst);
  }

  for (ru_id=0;ru_id<RC.nb_RU;ru_id++) {

    AssertFatal(RC.ru[ru_id]!=NULL,"ru_id %d is null\n",ru_id);
    
    RC.ru[ru_id]->wakeup_rxtx_NB_IoT         = wakeup_rxtx_NB_IoT;
    RC.ru[ru_id]->wakeup_prach_eNB_NB_IoT    = wakeup_prach_eNB_NB_IoT;
    RC.ru[ru_id]->eNB_top_NB_IoT             = eNB_top_NB_IoT;
  }
}

void init_eNB_NB_IoT(int single_thread_flag,int wait_for_sync) {
  
  int CC_id;
  int inst;
  PHY_VARS_eNB_NB_IoT *eNB;

  if (RC.L1_NB_IoT == NULL) RC.L1_NB_IoT = (PHY_VARS_eNB_NB_IoT***) malloc(RC.nb_L1_inst*sizeof(PHY_VARS_eNB_NB_IoT **));
  for (inst=0;inst<RC.nb_L1_inst;inst++) {
    if (RC.L1_NB_IoT[inst] == NULL) RC.L1_NB_IoT[inst] = (PHY_VARS_eNB_NB_IoT**) malloc(RC.nb_CC[inst]*sizeof(PHY_VARS_eNB_NB_IoT *));
    for (CC_id=0;CC_id<RC.nb_L1_CC[inst];CC_id++) {
      if (RC.L1_NB_IoT[inst][CC_id] == NULL) RC.L1_NB_IoT[inst][CC_id] = (PHY_VARS_eNB_NB_IoT*) malloc(sizeof(PHY_VARS_eNB_NB_IoT));
      eNB                     = RC.L1_NB_IoT[inst][CC_id]; 
      eNB->abstraction_flag   = 0;
      eNB->single_thread_flag = single_thread_flag;


#ifndef OCP_FRAMEWORK
      LOG_I(PHY,"Initializing eNB %d CC_id %d\n",inst,CC_id);
#endif


      eNB->td                   = ulsch_decoding_data;//(single_thread_flag==1) ? ulsch_decoding_data_2thread : ulsch_decoding_data;
      eNB->te                   = dlsch_encoding;//(single_thread_flag==1) ? dlsch_encoding_2threads : dlsch_encoding;

      
      LOG_I(PHY,"Registering with MAC interface module\n");
      AssertFatal((eNB->if_inst         = IF_Module_init(inst))!=NULL,"Cannot register interface");
      eNB->if_inst->schedule_response   = schedule_response;
      eNB->if_inst->PHY_config_req      = phy_config_request;
      memset((void*)&eNB->UL_INFO,0,sizeof(eNB->UL_INFO));
      memset((void*)&eNB->Sched_INFO,0,sizeof(eNB->Sched_INFO));
      LOG_I(PHY,"Setting indication lists\n");
      eNB->UL_INFO.rx_ind.rx_pdu_list   = eNB->rx_pdu_list;
      eNB->UL_INFO.crc_ind.crc_pdu_list = eNB->crc_pdu_list;
      eNB->UL_INFO.sr_ind.sr_pdu_list = eNB->sr_pdu_list;
      eNB->UL_INFO.harq_ind.harq_pdu_list = eNB->harq_pdu_list;
      eNB->UL_INFO.cqi_ind.cqi_pdu_list = eNB->cqi_pdu_list;
      eNB->UL_INFO.cqi_ind.cqi_raw_pdu_list = eNB->cqi_raw_pdu_list;
      eNB->prach_energy_counter = 0;
    }

  }


  LOG_I(PHY,"[lte-softmodem.c] eNB structure allocated\n");
  


}


void stop_eNB(int nb_inst) {

  for (int inst=0;inst<nb_inst;inst++) {
    LOG_I(PHY,"Killing eNB %d processing threads\n",inst);
    kill_eNB_proc(inst);
  }
}
