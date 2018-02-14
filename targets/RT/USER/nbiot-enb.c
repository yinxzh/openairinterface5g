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

#include "PHY/defs_L1.h"
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
#include "PHY/defs_L1_NB_IoT.h"
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

#include "UTIL/LOG/log_extern.h"
#include "UTIL/OTG/otg_tx.h"
#include "UTIL/OTG/otg_externs.h"
#include "UTIL/MATH/oml.h"
#include "UTIL/LOG/vcd_signal_dumper.h"
#include "UTIL/OPT/opt.h"
#include "enb_config.h"

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

extern int oai_exit;


static inline int nb_iot_rxtx(PHY_VARS_eNB_NB_IoT *eNB, eNB_rxtx_proc_NB_IoT_t *proc, char *thread_name) {



  // ****************************************
  // Common RX procedures subframe n

  T(T_ENB_PHY_DL_TICK, T_INT(eNB->Mod_id), T_INT(proc->frame_tx), T_INT(proc->subframe_tx));

  // if this is IF5 or 3GPP_eNB
//  if (eNB->RU_list[0]->function < NGFI_RAU_IF4p5) {
//    wakeup_prach_eNB(eNB,NULL,proc->frame_rx,proc->subframe_rx);
#ifdef Rel14
//    wakeup_prach_eNB_br(eNB,NULL,proc->frame_rx,proc->subframe_rx);
#endif
//  }
  // UE-specific RX processing for subframe n
//  phy_procedures_eNB_uespec_RX(eNB, proc, no_relay );

//  pthread_mutex_lock(&eNB->UL_INFO_mutex);
//  eNB->UL_INFO.frame     = proc->frame_rx;
//  eNB->UL_INFO.subframe  = proc->subframe_rx;
//  eNB->UL_INFO.module_id = eNB->Mod_id;
//  eNB->if_inst->UL_indication(&eNB->UL_INFO);
//  pthread_mutex_unlock(&eNB->UL_INFO_mutex);

  

  
  if (oai_exit) return(-1);
  
 // phy_procedures_eNB_TX(eNB, proc, no_relay, NULL, 1);
  
  if (release_thread(&proc->mutex_rxtx,&proc->instance_cnt_rxtx,thread_name)<0) return(-1);

  
  return(0);
}


void nb_iot_eNB_top(PHY_VARS_eNB_NB_IoT *eNB, int frame_rx, int subframe_rx, char *string)
{
  eNB_proc_NB_IoT_t *proc           = &eNB->proc;
  eNB_rxtx_proc_NB_IoT_t *proc_rxtx = &proc->proc_rxtx[0];

  proc->frame_rx    = frame_rx;
  proc->subframe_rx = subframe_rx;

  if (!oai_exit) {
    LOG_D(PHY,"eNB_top in %p (proc %p, ), frame %d, subframe %d, instance_cnt_prach %d\n",
	  (void*)pthread_self(), proc,  proc->frame_rx,proc->subframe_rx,proc->instance_cnt_prach);

    T(T_ENB_MASTER_TICK, T_INT(0), T_INT(proc->frame_rx), T_INT(proc->subframe_rx));

    proc_rxtx->subframe_rx = proc->subframe_rx;
    proc_rxtx->frame_rx    = proc->frame_rx;
    proc_rxtx->subframe_tx = (proc->subframe_rx+4)%10;
    proc_rxtx->frame_tx    = (proc->subframe_rx>5) ? (1+proc->frame_rx)&1023 : proc->frame_rx;
    proc->frame_tx         = proc_rxtx->frame_tx;
    proc_rxtx->timestamp_tx = proc->timestamp_tx;

    if (nb_iot_rxtx(eNB,proc_rxtx,string) < 0) LOG_E(PHY,"eNB %d failed during execution\n",eNB->Mod_id);
    LOG_D(PHY,"eNB_top out %p (proc %p), frame %d, subframe %d, instance_cnt_prach %d\n",
	  (void*)pthread_self(), proc, proc->frame_rx,proc->subframe_rx,proc->instance_cnt_prach);
  }
}


int wakeup_nb_iot_rxtx(PHY_VARS_eNB_NB_IoT *eNB,RU_t *ru) {

  eNB_proc_NB_IoT_t *proc=&eNB->proc;

  eNB_rxtx_proc_NB_IoT_t *proc_rxtx=&proc->proc_rxtx[proc->frame_rx&1];

  NB_IoT_DL_FRAME_PARMS *fp = &eNB->frame_parms;

  int i;
  struct timespec wait;
  
//  pthread_mutex_lock(&proc->mutex_RU);
  for (i=0;i<eNB->num_RU;i++) {
    if (ru == eNB->RU_list[i]) {
      if ((proc->RU_mask&(1<<i)) > 0)
	LOG_E(PHY,"eNB %d frame %d, subframe %d : previous information from RU %d (num_RU %d,mask %x) has not been served yet!\n",
	      eNB->Mod_id,proc->frame_rx,proc->subframe_rx,ru->idx,eNB->num_RU,proc->RU_mask);
      proc->RU_mask |= (1<<i);
    }
  }
  if (proc->RU_mask != (1<<eNB->num_RU)-1) {  // not all RUs have provided their information so return
//    pthread_mutex_unlock(&proc->mutex_RU);
    return(0);
  }
  else { // all RUs have provided their information so continue on and wakeup eNB processing
    proc->RU_mask = 0;
//    pthread_mutex_unlock(&proc->mutex_RU);
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


int is_nbiot_prach_subframe(NB_IoT_DL_FRAME_PARMS *fp,int frame,int subframe) {
   return 0;
}

void wakeup_prach_nb_iot_eNB(PHY_VARS_eNB_NB_IoT *eNB,RU_t *ru,int frame,int subframe) {

  eNB_proc_NB_IoT_t *proc = &eNB->proc;
  NB_IoT_DL_FRAME_PARMS *fp=&eNB->frame_parms;
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
  if (is_nbiot_prach_subframe(fp,frame,subframe)>0) { 
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

void init_NbIoT_transport( PHY_VARS_eNB_NB_IoT *phyvar) {

  int i;
  int j;
  NB_IoT_DL_FRAME_PARMS *fp = &phyvar->frame_parms;

  for (i=0; i<NUMBER_OF_UE_MAX; i++) {
    LOG_I(PHY,"Allocating Transport Channel Buffers for DLSCH, NbIoT UE %d\n",i);
    for (j=0; j<2; j++) {
      phyvar->ndlsch[i][j] = new_ndlsch(1,8,NSOFT,0,fp);
      if (!phyvar->ndlsch[i][j]) {
	LOG_E(PHY,"Can't get NbIoT dlsch structures for UE %d \n", i);
	exit(-1);
      } else {
	LOG_D(PHY,"dlsch[%d][%d] => %p\n",i,j,(void *)phyvar->ndlsch[i][j]);
	phyvar->ndlsch[i][j]->rnti=0;
      }
    }
    
    LOG_I(PHY,"Allocating Transport Channel Buffer for ULSCH, UE %d\n",i);
    phyvar->nulsch[1+i] = new_nulsch(MAX_TURBO_ITERATIONS);
    
    if (!phyvar->nulsch[1+i]) {
      LOG_E(PHY,"Can't get NbIoT ulsch structures\n");
      exit(-1);
    }
    
    // this is the transmission mode for the signalling channels
    // this will be overwritten with the real transmission mode by the RRC once the UE is connected
    phyvar->transmission_mode[i] = fp->nb_antenna_ports_eNB==1 ? 1 : 2;
  }
  // ULSCH for RA
  phyvar->nulsch[0] = new_nulsch(MAX_TURBO_ITERATIONS);
  
  if (!phyvar->nulsch[0]) {
    LOG_E(PHY,"Can't get eNB ulsch structures\n");
    exit(-1);
  }
  phyvar->ndlsch_SI  = new_ndlsch(1,8,NSOFT,0, fp);
  LOG_D(PHY,"NB-IoT %d : SI %p\n",phyvar->Mod_id,phyvar->ndlsch_SI);
  phyvar->ndlsch_ra  = new_ndlsch(1,8,NSOFT,0, fp);
  LOG_D(PHY,"NB-IoT %d : RA %p\n",phyvar->Mod_id,phyvar->ndlsch_ra);

  
  
  phyvar->rx_total_gain_dB=130;
  
  for(i=0; i<NUMBER_OF_UE_MAX; i++)
    phyvar->mu_mimo_mode[i].dl_pow_off = 2;
  
  phyvar->check_for_total_transmissions = 0;
  
  phyvar->check_for_MUMIMO_transmissions = 0;
  
  phyvar->FULL_MUMIMO_transmissions = 0;
  
  phyvar->check_for_SUMIMO_transmissions = 0;
  
  
    
} 

void init_NbIoT_afterRU(void) {

  int inst,ru_id,i,aa;
  PHY_VARS_eNB_NB_IoT *phyvar;


  for (inst=0;inst<RC.nb_nb_iot_rrc_inst;inst++) {
      phyvar =  RC.L1_NB_IoT[inst];
      phy_init_nb_iot_eNB(phyvar);
      // map antennas and PRACH signals to eNB RX
      AssertFatal(phyvar->num_RU>0,"Number of RU attached to nb-iot %d is zero\n",phyvar->Mod_id);
      LOG_I(PHY,"Mapping RX ports from %d RUs to eNB %d\n",phyvar->num_RU,phyvar->Mod_id);
      phyvar->frame_parms.nb_antennas_rx       = 0;
      phyvar->prach_vars.rxsigF[0] = malloc(sizeof(int16_t*) * 64);
//#ifdef Rel14
//      for (int ce_level=0;ce_level<4;ce_level++)
//	phyvar->prach_vars_br.rxsigF[ce_level] = (int16_t**)malloc16(64*sizeof(int16_t*));
//#endif
      for (ru_id=0,aa=0;ru_id<phyvar->num_RU;ru_id++) {
	phyvar->frame_parms.nb_antennas_rx    += phyvar->RU_list[ru_id]->nb_rx;

	AssertFatal(phyvar->RU_list[ru_id]->common.rxdataF!=NULL,
		    "RU %d : common.rxdataF is NULL\n",
		    phyvar->RU_list[ru_id]->idx);

	AssertFatal(phyvar->RU_list[ru_id]->prach_rxsigF!=NULL,
		    "RU %d : prach_rxsigF is NULL\n",
		    phyvar->RU_list[ru_id]->idx);

	for (i=0;i<phyvar->RU_list[ru_id]->nb_rx;aa++,i++) { 
	  LOG_I(PHY,"Attaching RU %d antenna %d to eNB antenna %d\n",phyvar->RU_list[ru_id]->idx,i,aa);
	  phyvar->prach_vars.rxsigF[aa]    =  phyvar->RU_list[ru_id]->prach_rxsigF[i];
//#ifdef Rel14
//	  for (int ce_level=0;ce_level<4;ce_level++)
//	    phyvar->prach_vars_br.rxsigF[ce_level][aa] = phyvar->RU_list[ru_id]->prach_rxsigF_br[ce_level][i];
//#endif
	  phyvar->common_vars.rxdataF[aa]     =  phyvar->RU_list[ru_id]->common.rxdataF[i];
	}
      }
      AssertFatal(phyvar->frame_parms.nb_antennas_rx >0,
		  "inst %d, : nb_antennas_rx %d\n",inst,phyvar->frame_parms.nb_antennas_rx);
      LOG_I(PHY,"inst %d: nb_antennas_rx %d\n",inst,phyvar->frame_parms.nb_antennas_rx);

      init_NbIoT_transport(phyvar);
//    init_eNB_proc(inst);
  }

  for (ru_id=0;ru_id<RC.nb_RU && RC.ru[ru_id]->NbIoT;ru_id++) {

    AssertFatal(RC.ru[ru_id]!=NULL,"ru_id %d is null\n",ru_id);
    
//    RC.ru[ru_id]->NbIoT->wakeup_rxtx         = wakeup_rxtx;
    RC.ru[ru_id]->NbIoT->wakeup_prach_NbIoT    = wakeup_prach_nb_iot_eNB;
//    RC.ru[ru_id]->NbIoT->wakeup_prach_eNB_br = wakeup_prach_eNB_br;
    RC.ru[ru_id]->NbIoT->NbIoT_top           = nb_iot_eNB_top;
  }
}

