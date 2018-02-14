/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.0  (the "License"); you may not use this file
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

/*! \file PHY/LTE_TRANSPORT/ulsch_decoding.c
* \brief Top-level routines for decoding  the ULSCH transport channel from 36.212 V8.6 2009-03
* \author R. Knopp
* \date 2011
* \version 0.1
* \company Eurecom
* \email: knopp@eurecom.fr
* \note
* \warning
*/

//#include "defs.h"

//#include "PHY/defs.h"
#include "PHY/defs_L1_NB_IoT.h"
#include "PHY/extern_NB_IoT.h"
#include "PHY/LTE_TRANSPORT/vars_NB_IoT.h"
#include "PHY/CODING/defs_NB_IoT.h"
//#include "PHY/CODING/extern.h"
//#include "extern_NB_IoT.h"
//#include "SCHED/extern.h"
/*
#ifdef OPENAIR2
#include "LAYER2/MAC/defs.h"
#include "LAYER2/MAC/extern_NB_IoT.h"
#include "RRC/LITE/extern.h"
#include "PHY_INTERFACE/extern.h"
#endif

#ifdef PHY_ABSTRACTION
#include "UTIL/OCG/OCG.h"
#include "UTIL/OCG/OCG_extern.h"
#endif
*/
#include "UTIL/LOG/vcd_signal_dumper.h"
//#define DEBUG_ULSCH_DECODING
/*
void free_eNB_ulsch(LTE_eNB_ULSCH_t *ulsch)
{

  int i,r;

  if (ulsch) {
    for (i=0; i<8; i++) {
      if (ulsch->harq_processes[i]) {
        if (ulsch->harq_processes[i]->b) {
          free16(ulsch->harq_processes[i]->b,MAX_ULSCH_PAYLOAD_BYTES);
          ulsch->harq_processes[i]->b = NULL;
        }

        for (r=0; r<MAX_NUM_ULSCH_SEGMENTS; r++) {
          free16(ulsch->harq_processes[i]->c[r],((r==0)?8:0) + 768);
          ulsch->harq_processes[i]->c[r] = NULL;
        }

        for (r=0; r<MAX_NUM_ULSCH_SEGMENTS; r++)
          if (ulsch->harq_processes[i]->d[r]) {
            free16(ulsch->harq_processes[i]->d[r],((3*8*6144)+12+96)*sizeof(short));
            ulsch->harq_processes[i]->d[r] = NULL;
          }

        free16(ulsch->harq_processes[i],sizeof(LTE_UL_eNB_HARQ_t));
        ulsch->harq_processes[i] = NULL;
      }
    }

    free16(ulsch,sizeof(LTE_eNB_ULSCH_t));
    ulsch = NULL;
  }
}
*/


NB_IoT_eNB_NULSCH_t *new_nulsch(uint8_t max_turboiter)
{

  NB_IoT_eNB_NULSCH_t *nulsch;


  nulsch = (NB_IoT_eNB_NULSCH_t *)malloc16(sizeof(NB_IoT_eNB_NULSCH_t));

  if (nulsch) {
    memset(nulsch,0,sizeof(NB_IoT_eNB_NULSCH_t));
    //MP: add some parameters in npusch structure for convolutional coding to be set
    return(nulsch);
  }

  return(NULL);
}


/*
void clean_eNb_ulsch(LTE_eNB_ULSCH_t *ulsch)
{

  unsigned char i;

  //ulsch = (LTE_eNB_ULSCH_t *)malloc16(sizeof(LTE_eNB_ULSCH_t));
  if (ulsch) {
    ulsch->rnti = 0;

    for (i=0; i<8; i++) {
      if (ulsch->harq_processes[i]) {
        //    ulsch->harq_processes[i]->Ndi = 0;
        ulsch->harq_processes[i]->status = 0;
        ulsch->harq_processes[i]->subframe_scheduling_flag = 0;
        //ulsch->harq_processes[i]->phich_active = 0; //this will be done later after transmission of PHICH
        ulsch->harq_processes[i]->phich_ACK = 0;
        ulsch->harq_processes[i]->round = 0;
      }
    }

  }
}
*/

uint8_t extract_cqi_crc_NB_IoT(uint8_t *cqi,uint8_t CQI_LENGTH)
{

  uint8_t crc;

  crc = cqi[CQI_LENGTH>>3];
  //  printf("crc1: %x, shift %d\n",crc,CQI_LENGTH&0x7);
  crc = (crc<<(CQI_LENGTH&0x7));
  // clear crc bits
  //  ((char *)cqi)[CQI_LENGTH>>3] &= 0xff>>(8-(CQI_LENGTH&0x7));
  //  printf("crc2: %x, cqi0 %x\n",crc,cqi[1+(CQI_LENGTH>>3)]);
  crc |= (cqi[1+(CQI_LENGTH>>3)])>>(8-(CQI_LENGTH&0x7));
  // clear crc bits
  //(((char *)cqi)[1+(CQI_LENGTH>>3)]) = 0;

  //  printf("crc : %x\n",crc);
  return(crc);

}

/*




int ulsch_decoding_data_2thread0(td_params* tdp) {

  PHY_VARS_eNB *eNB = tdp->eNB;
  int UE_id         = tdp->UE_id;
  int harq_pid      = tdp->harq_pid;
  int llr8_flag     = tdp->llr8_flag;

  unsigned int r,r_offset=0,Kr,Kr_bytes,iind;
  uint8_t crc_type;
  int offset = 0;
  int ret = 1;
  int16_t dummy_w[MAX_NUM_ULSCH_SEGMENTS][3*(6144+64)];
  LTE_eNB_ULSCH_t *ulsch = eNB->ulsch[UE_id];
  LTE_UL_eNB_HARQ_t *ulsch_harq = ulsch->harq_processes[harq_pid];
  int Q_m = get_Qm_ul(ulsch_harq->mcs);
  int G = ulsch_harq->G;
  uint32_t E;
  uint32_t Gp,GpmodC,Nl=1;
  uint32_t C = ulsch_harq->C;

  uint8_t (*tc)(int16_t *y,
                uint8_t *,
                uint16_t,
                uint16_t,
                uint16_t,
                uint8_t,
                uint8_t,
                uint8_t,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *);

  if (llr8_flag == 0)
    tc = phy_threegpplte_turbo_decoder16;
  else
    tc = phy_threegpplte_turbo_decoder8;



  // go through first half of segments to get r_offset
  for (r=0; r<(ulsch_harq->C/2); r++) {

    // Get Turbo interleaver parameters
    if (r<ulsch_harq->Cminus)
      Kr = ulsch_harq->Kminus;
    else
      Kr = ulsch_harq->Kplus;

    Kr_bytes = Kr>>3;

    if (Kr_bytes<=64)
      iind = (Kr_bytes-5);
    else if (Kr_bytes <=128)
      iind = 59 + ((Kr_bytes-64)>>1);
    else if (Kr_bytes <= 256)
      iind = 91 + ((Kr_bytes-128)>>2);
    else if (Kr_bytes <= 768)
      iind = 123 + ((Kr_bytes-256)>>3);
    else {
      LOG_E(PHY,"ulsch_decoding: Illegal codeword size %d!!!\n",Kr_bytes);
      return(-1);
    }

    // This is stolen from rate-matching algorithm to get the value of E
    
    Gp = G/Nl/Q_m;
    GpmodC = Gp%C;
    
    if (r < (C-(GpmodC)))
      E = Nl*Q_m * (Gp/C);
    else
      E = Nl*Q_m * ((GpmodC==0?0:1) + (Gp/C));
    
    r_offset += E;

    if (r==0) {
      offset = Kr_bytes - (ulsch_harq->F>>3) - ((ulsch_harq->C>1)?3:0);
    } else {
      offset += (Kr_bytes- ((ulsch_harq->C>1)?3:0));
    }
  }

  // go through second half of segments
  for (; r<(ulsch_harq->C); r++) {


    //    printf("before subblock deinterleaving c[%d] = %p\n",r,ulsch_harq->c[r]);
    // Get Turbo interleaver parameters
    if (r<ulsch_harq->Cminus)
      Kr = ulsch_harq->Kminus;
    else
      Kr = ulsch_harq->Kplus;

    Kr_bytes = Kr>>3;

    if (Kr_bytes<=64)
      iind = (Kr_bytes-5);
    else if (Kr_bytes <=128)
      iind = 59 + ((Kr_bytes-64)>>1);
    else if (Kr_bytes <= 256)
      iind = 91 + ((Kr_bytes-128)>>2);
    else if (Kr_bytes <= 768)
      iind = 123 + ((Kr_bytes-256)>>3);
    else {
      LOG_E(PHY,"ulsch_decoding: Illegal codeword size %d!!!\n",Kr_bytes);
      return(-1);
    }

#ifdef DEBUG_ULSCH_DECODING
    printf("f1 %d, f2 %d, F %d\n",f1f2mat_old[2*iind],f1f2mat_old[1+(2*iind)],(r==0) ? ulsch_harq->F : 0);
#endif

    memset(&dummy_w[r][0],0,3*(6144+64)*sizeof(short));
    ulsch_harq->RTC[r] = generate_dummy_w(4+(Kr_bytes*8),
                                          (uint8_t*)&dummy_w[r][0],
                                          (r==0) ? ulsch_harq->F : 0);

#ifdef DEBUG_ULSCH_DECODING
    printf("Rate Matching Segment %d (coded bits (G) %d,unpunctured/repeated bits %d, Q_m %d, nb_rb %d, Nl %d)...\n",
        r, G,
        Kr*3,
        Q_m,
        nb_rb,
        ulsch_harq->Nl);
#endif


    if (lte_rate_matching_turbo_rx(ulsch_harq->RTC[r],
                                   G,
                                   ulsch_harq->w[r],
                                   (uint8_t*) &dummy_w[r][0],
                                   ulsch_harq->e+r_offset,
                                   ulsch_harq->C,
                                   NSOFT,
                                   0,   //Uplink
                                   1,
                                   ulsch_harq->rvidx,
                                   (ulsch_harq->round==0)?1:0,  // clear
                                   get_Qm_ul(ulsch_harq->mcs),
                                   1,
                                   r,
                                   &E)==-1) {
      LOG_E(PHY,"ulsch_decoding.c: Problem in rate matching\n");
      return(-1);
    }

    r_offset += E;

    sub_block_deinterleaving_turbo(4+Kr,
                                   &ulsch_harq->d[r][96],
                                   ulsch_harq->w[r]);

    if (ulsch_harq->C == 1)
      crc_type = CRC24_A;
    else
      crc_type = CRC24_B;
    
    
    ret = tc(&ulsch_harq->d[r][96],
	     ulsch_harq->c[r],
	     Kr,
	     f1f2mat_old[iind*2],
	     f1f2mat_old[(iind*2)+1],
	     ulsch->max_turbo_iterations,//MAX_TURBO_ITERATIONS,
	     crc_type,
	     (r==0) ? ulsch_harq->F : 0,
	     &eNB->ulsch_tc_init_stats,
	     &eNB->ulsch_tc_alpha_stats,
	     &eNB->ulsch_tc_beta_stats,
	     &eNB->ulsch_tc_gamma_stats,
	     &eNB->ulsch_tc_ext_stats,
	     &eNB->ulsch_tc_intl1_stats,
	     &eNB->ulsch_tc_intl2_stats);
    
    // Reassembly of Transport block here

    if (ret != (1+ulsch->max_turbo_iterations)) {
      if (r<ulsch_harq->Cminus)
	Kr = ulsch_harq->Kminus;
      else
	Kr = ulsch_harq->Kplus;
      
      Kr_bytes = Kr>>3;
      
      memcpy(ulsch_harq->b+offset,
	     ulsch_harq->c[r],
	     Kr_bytes - ((ulsch_harq->C>1)?3:0));
      offset += (Kr_bytes- ((ulsch_harq->C>1)?3:0));
      
      
    } else {
      break;
    }
    
  }

  return(ret);
}

extern int oai_exit;
void *td_thread(void *param) {
  pthread_setname_np( pthread_self(), "td processing");
  PHY_VARS_eNB *eNB = ((td_params*)param)->eNB;
  eNB_proc_t *proc  = &eNB->proc;

  while (!oai_exit) {

    if (wait_on_condition(&proc->mutex_td,&proc->cond_td,&proc->instance_cnt_td,"td thread")<0) break;  

    ((td_params*)param)->ret = ulsch_decoding_data_2thread0((td_params*)param);

    if (release_thread(&proc->mutex_td,&proc->instance_cnt_td,"td thread")<0) break;

    if (pthread_cond_signal(&proc->cond_td) != 0) {
      printf("[eNB] ERROR pthread_cond_signal for td thread exit\n");
      exit_fun( "ERROR pthread_cond_signal" );
      return(NULL);
    }
  }

  return(NULL);
}

int ulsch_decoding_data_2thread(PHY_VARS_eNB *eNB,int UE_id,int harq_pid,int llr8_flag) {

  eNB_proc_t *proc = &eNB->proc;
  unsigned int r,r_offset=0,Kr,Kr_bytes,iind;
  uint8_t crc_type;
  int offset = 0;
  int ret = 1;
  int16_t dummy_w[MAX_NUM_ULSCH_SEGMENTS][3*(6144+64)];
  LTE_eNB_ULSCH_t *ulsch = eNB->ulsch[UE_id];
  LTE_UL_eNB_HARQ_t *ulsch_harq = ulsch->harq_processes[harq_pid];
  //int Q_m = get_Qm_ul(ulsch_harq->mcs);
  int G = ulsch_harq->G;
  unsigned int E;
  int Cby2;

  uint8_t (*tc)(int16_t *y,
                uint8_t *,
                uint16_t,
                uint16_t,
                uint16_t,
                uint8_t,
                uint8_t,
                uint8_t,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *,
                time_stats_t *);

  struct timespec wait;

  wait.tv_sec=0;
  wait.tv_nsec=5000000L;


  if (llr8_flag == 0)
    tc = phy_threegpplte_turbo_decoder16;
  else
    tc = phy_threegpplte_turbo_decoder8;

  if (ulsch_harq->C>1) { // wakeup worker if more than 1 segment
    if (pthread_mutex_timedlock(&proc->mutex_td,&wait) != 0) {
      printf("[eNB] ERROR pthread_mutex_lock for TD thread (IC %d)\n", proc->instance_cnt_td);
      exit_fun( "error locking mutex_fep" );
      return -1;
    }
    
    if (proc->instance_cnt_td==0) {
      printf("[eNB] TD thread busy\n");
      exit_fun("TD thread busy");
      pthread_mutex_unlock( &proc->mutex_td );
      return -1;
    }
    
    ++proc->instance_cnt_td;
    
    proc->tdp.eNB       = eNB;
    proc->tdp.UE_id     = UE_id;
    proc->tdp.harq_pid  = harq_pid;
    proc->tdp.llr8_flag = llr8_flag;
    
    
    // wakeup worker to do second half segments 
    if (pthread_cond_signal(&proc->cond_td) != 0) {
      printf("[eNB] ERROR pthread_cond_signal for td thread exit\n");
      exit_fun( "ERROR pthread_cond_signal" );
      return (1+ulsch->max_turbo_iterations);
    }

    pthread_mutex_unlock( &proc->mutex_td );
    Cby2 = ulsch_harq->C/2;
  }
  else {
    Cby2 = 1;
  }

  // go through first half of segments in main thread
  for (r=0; r<Cby2; r++) {

    //    printf("before subblock deinterleaving c[%d] = %p\n",r,ulsch_harq->c[r]);
    // Get Turbo interleaver parameters
    if (r<ulsch_harq->Cminus)
      Kr = ulsch_harq->Kminus;
    else
      Kr = ulsch_harq->Kplus;

    Kr_bytes = Kr>>3;

    if (Kr_bytes<=64)
      iind = (Kr_bytes-5);
    else if (Kr_bytes <=128)
      iind = 59 + ((Kr_bytes-64)>>1);
    else if (Kr_bytes <= 256)
      iind = 91 + ((Kr_bytes-128)>>2);
    else if (Kr_bytes <= 768)
      iind = 123 + ((Kr_bytes-256)>>3);
    else {
      LOG_E(PHY,"ulsch_decoding: Illegal codeword size %d!!!\n",Kr_bytes);
      return(-1);
    }

#ifdef DEBUG_ULSCH_DECODING
    printf("f1 %d, f2 %d, F %d\n",f1f2mat_old[2*iind],f1f2mat_old[1+(2*iind)],(r==0) ? ulsch_harq->F : 0);
#endif

    memset(&dummy_w[r][0],0,3*(6144+64)*sizeof(short));
    ulsch_harq->RTC[r] = generate_dummy_w(4+(Kr_bytes*8),
                                          (uint8_t*)&dummy_w[r][0],
                                          (r==0) ? ulsch_harq->F : 0);

#ifdef DEBUG_ULSCH_DECODING
    printf("Rate Matching Segment %d (coded bits (G) %d,unpunctured/repeated bits %d, Q_m %d, nb_rb %d, Nl %d)...\n",
        r, G,
        Kr*3,
        Q_m,
        nb_rb,
        ulsch_harq->Nl);
#endif

    start_meas(&eNB->ulsch_rate_unmatching_stats);

    if (lte_rate_matching_turbo_rx(ulsch_harq->RTC[r],
                                   G,
                                   ulsch_harq->w[r],
                                   (uint8_t*) &dummy_w[r][0],
                                   ulsch_harq->e+r_offset,
                                   ulsch_harq->C,
                                   NSOFT,
                                   0,   //Uplink
                                   1,
                                   ulsch_harq->rvidx,
                                   (ulsch_harq->round==0)?1:0,  // clear
                                   get_Qm_ul(ulsch_harq->mcs),
                                   1,
                                   r,
                                   &E)==-1) {
      LOG_E(PHY,"ulsch_decoding.c: Problem in rate matching\n");
      return(-1);
    }

    stop_meas(&eNB->ulsch_rate_unmatching_stats);
    r_offset += E;

    start_meas(&eNB->ulsch_deinterleaving_stats);
    sub_block_deinterleaving_turbo(4+Kr,
                                   &ulsch_harq->d[r][96],
                                   ulsch_harq->w[r]);
    stop_meas(&eNB->ulsch_deinterleaving_stats);

    if (ulsch_harq->C == 1)
      crc_type = CRC24_A;
    else
      crc_type = CRC24_B;

    start_meas(&eNB->ulsch_turbo_decoding_stats);
    
    ret = tc(&ulsch_harq->d[r][96],
	     ulsch_harq->c[r],
	     Kr,
	     f1f2mat_old[iind*2],
	     f1f2mat_old[(iind*2)+1],
	     ulsch->max_turbo_iterations,//MAX_TURBO_ITERATIONS,
	     crc_type,
	     (r==0) ? ulsch_harq->F : 0,
	     &eNB->ulsch_tc_init_stats,
	     &eNB->ulsch_tc_alpha_stats,
	     &eNB->ulsch_tc_beta_stats,
	     &eNB->ulsch_tc_gamma_stats,
	     &eNB->ulsch_tc_ext_stats,
	     &eNB->ulsch_tc_intl1_stats,
	     &eNB->ulsch_tc_intl2_stats);

  // Reassembly of Transport block here

    if (ret != (1+ulsch->max_turbo_iterations)) {
      if (r<ulsch_harq->Cminus)
	Kr = ulsch_harq->Kminus;
      else
	Kr = ulsch_harq->Kplus;
      
      Kr_bytes = Kr>>3;
      
      if (r==0) {
	memcpy(ulsch_harq->b,
	       &ulsch_harq->c[0][(ulsch_harq->F>>3)],
	       Kr_bytes - (ulsch_harq->F>>3) - ((ulsch_harq->C>1)?3:0));
	offset = Kr_bytes - (ulsch_harq->F>>3) - ((ulsch_harq->C>1)?3:0);
      } else {
	memcpy(ulsch_harq->b+offset,
	       ulsch_harq->c[r],
	       Kr_bytes - ((ulsch_harq->C>1)?3:0));
	offset += (Kr_bytes- ((ulsch_harq->C>1)?3:0));
      }
      
    } else {
      break;
    }
    stop_meas(&eNB->ulsch_turbo_decoding_stats);    
  }

   // wait for worker to finish

  wait_on_busy_condition(&proc->mutex_td,&proc->cond_td,&proc->instance_cnt_td,"td thread");  

  return( (ret>proc->tdp.ret) ? ret : proc->tdp.ret );
}
*/

// NB_IoT: functions in ulsch_decoding_data_NB_IoT must be defined

int ulsch_decoding_data_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,int UE_id,int harq_pid,int llr8_flag) {
int ret=0;


  return ret;
}



// NB_IoT: functions in ulsch_decoding_data_NB_IoT must be defined :ulsch_decoding_data_NB_IoT (defined in this file)

static inline unsigned int lte_gold_unscram_NB_IoT(unsigned int *x1, unsigned int *x2, unsigned char reset) __attribute__((always_inline));
static inline unsigned int lte_gold_unscram_NB_IoT(unsigned int *x1, unsigned int *x2, unsigned char reset)
{
  int n;

  if (reset) {
    *x1 = 1+ (1<<31);
    *x2=*x2 ^ ((*x2 ^ (*x2>>1) ^ (*x2>>2) ^ (*x2>>3))<<31);

    // skip first 50 double words (1600 bits)
    //      printf("n=0 : x1 %x, x2 %x\n",x1,x2);
    for (n=1; n<50; n++) {
      *x1 = (*x1>>1) ^ (*x1>>4);
      *x1 = *x1 ^ (*x1<<31) ^ (*x1<<28);
      *x2 = (*x2>>1) ^ (*x2>>2) ^ (*x2>>3) ^ (*x2>>4);
      *x2 = *x2 ^ (*x2<<31) ^ (*x2<<30) ^ (*x2<<29) ^ (*x2<<28);
    }
  }

  *x1 = (*x1>>1) ^ (*x1>>4);
  *x1 = *x1 ^ (*x1<<31) ^ (*x1<<28);
  *x2 = (*x2>>1) ^ (*x2>>2) ^ (*x2>>3) ^ (*x2>>4);
  *x2 = *x2 ^ (*x2<<31) ^ (*x2<<30) ^ (*x2<<29) ^ (*x2<<28);
  return(*x1^*x2);
  //  printf("n=%d : c %x\n",n,x1^x2);

}


unsigned int  ulsch_decoding_NB_IoT(PHY_VARS_eNB_NB_IoT     *eNB,
                                    eNB_rxtx_proc_NB_IoT_t  *proc,
                                    uint8_t                 UE_id,
                                    uint8_t                 control_only_flag,
                                    uint8_t                 Nbundled,
                                    uint8_t                 llr8_flag)
{
  int ret=0;
  return ret;
}


/*
#ifdef PHY_ABSTRACTION

#ifdef PHY_ABSTRACTION_UL
int ulsch_abstraction(double* sinr_dB, uint8_t TM, uint8_t mcs,uint16_t nrb, uint16_t frb)
{

  int index,ii;
  double sinr_eff = 0;
  int rb_count = 0;
  int offset;
  double bler = 0;
  TM = TM-1;
  sinr_eff = sinr_dB[frb]; //the single sinr_eff value we calculated with MMSE FDE formula in init_snr_up function


  sinr_eff *= 10;
  sinr_eff = floor(sinr_eff);
  sinr_eff /= 10;

  LOG_D(PHY,"[ABSTRACTION] sinr_eff after rounding = %f\n",sinr_eff);

  for (index = 0; index < 16; index++) {
    if(index == 0) {
      if (sinr_eff < sinr_bler_map_up[mcs][0][index]) {
        bler = 1;
        break;
      }
    }

    if (sinr_eff == sinr_bler_map_up[mcs][0][index]) {
      bler = sinr_bler_map_up[mcs][1][index];
    }
  }

#ifdef USER_MODE // need to be adapted for the emulation in the kernel space 

  if (uniformrandom() < bler) {
    LOG_I(OCM,"abstraction_decoding failed (mcs=%d, sinr_eff=%f, bler=%f)\n",mcs,sinr_eff,bler);
    return(0);
  } else {
    LOG_I(OCM,"abstraction_decoding successful (mcs=%d, sinr_eff=%f, bler=%f)\n",mcs,sinr_eff,bler);
    return(1);
  }

#endif
}







int ulsch_abstraction_MIESM(double* sinr_dB,uint8_t TM, uint8_t mcs,uint16_t nrb, uint16_t frb)
{
  int index;
  double sinr_eff = 0;
  double sinr_db1 = 0;
  double sinr_db2 = 0;
  double SI=0;
  double RBIR=0;
  int rb_count = 0;
  int offset, M=0;
  double bler = 0;
  int start,middle,end;
  TM = TM-1;

  for (offset = frb; offset <= (frb + nrb -1); offset++) {

    rb_count++;

    //we need to do the table lookups here for the mutual information corresponding to the certain sinr_dB.

    sinr_db1 = sinr_dB[offset*2];
    sinr_db2 = sinr_dB[offset*2+1];

    printf("sinr_db1=%f\n,sinr_db2=%f\n",sinr_db1,sinr_db2);

    //rounding up for the table lookup
    sinr_db1 *= 10;
    sinr_db2 *= 10;

    sinr_db1 = floor(sinr_db1);
    sinr_db2 = floor(sinr_db2);

    if ((int)sinr_db1%2) {
      sinr_db1 += 1;
    }

    if ((int)sinr_db2%2) {
      sinr_db2 += 1;
    }

    sinr_db1 /= 10;
    sinr_db2 /= 10;

    if(mcs<10) {
      //for sinr_db1
      for (index = 0; index < 162; index++) {
        if (sinr_db1 < MI_map_4qam[0][0]) {
          SI += (MI_map_4qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }

        if (sinr_db1 > MI_map_4qam[0][161]) {
          SI += (MI_map_4qam[1][161]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }

        if (sinr_db1 == MI_map_4qam[0][index]) {
          SI += (MI_map_4qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }
      }

      //for sinr_db2
      for (index = 0; index < 162; index++) {
        if (sinr_db2 < MI_map_4qam[0][0]) {
          SI += (MI_map_4qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }

        if (sinr_db2 > MI_map_4qam[0][161]) {
          SI += (MI_map_4qam[1][161]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }

        if (sinr_db2 == MI_map_4qam[0][index]) {
          SI += (MI_map_4qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=2;
          break;
        }
      }

    } else if(mcs>9 && mcs<17) {
      //for sinr_db1
      for (index = 0; index < 197; index++) {
        if (sinr_db1 < MI_map_16qam[0][0]) {
          SI += (MI_map_16qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }

        if (sinr_db1 > MI_map_16qam[0][196]) {
          SI += (MI_map_16qam[1][196]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }

        if (sinr_db1 == MI_map_16qam[0][index]) {
          SI += (MI_map_16qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }
      }

      //for sinr_db2
      for (index = 0; index < 197; index++) {
        if (sinr_db2 < MI_map_16qam[0][0]) {
          SI += (MI_map_16qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }

        if (sinr_db2 > MI_map_16qam[0][196]) {
          SI += (MI_map_16qam[1][196]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }

        if (sinr_db2 == MI_map_16qam[0][index]) {
          SI += (MI_map_16qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=4;
          break;
        }
      }

    } else if(mcs>16 && mcs<22) {
      //for sinr_db1
      for (index = 0; index < 227; index++) {
        if (sinr_db1 < MI_map_64qam[0][0]) {
          SI += (MI_map_64qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }

        if (sinr_db1 > MI_map_64qam[0][226]) {
          SI += (MI_map_64qam[1][226]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }

        if (sinr_db1 == MI_map_64qam[0][index]) {
          SI += (MI_map_64qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }
      }

      //for sinr_db2
      for (index = 0; index < 227; index++) {
        if (sinr_db2 < MI_map_64qam[0][0]) {
          SI += (MI_map_64qam[1][0]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }

        if (sinr_db2 > MI_map_64qam[0][226]) {
          SI += (MI_map_64qam[1][226]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }

        if (sinr_db2 == MI_map_64qam[0][index]) {
          SI += (MI_map_64qam[1][index]/beta1_dlsch_MI[TM][mcs]);
          M +=6;
          break;
        }
      }
    }
  }

  // }

  RBIR = SI/M;

  //Now RBIR->SINR_effective Mapping
  //binary search method is performed here
  if(mcs<10) {
    start = 0;
    end = 161;
    middle = end/2;

    if (RBIR <= MI_map_4qam[2][start]) {
      sinr_eff =  MI_map_4qam[0][start];
    } else {
      if (RBIR >= MI_map_4qam[2][end])
        sinr_eff =  MI_map_4qam[0][end];
      else {
        //while((end-start > 1) && (RBIR >= MI_map_4qam[2]))
        if (RBIR < MI_map_4qam[2][middle]) {
          end = middle;
          middle = end/2;
        } else {
          start = middle;
          middle = (end-middle)/2;
        }
      }

      for (; end>start; end--) {
        if ((RBIR < MI_map_4qam[2][end]) && (RBIR >  MI_map_4qam[2][end-2])) {
          sinr_eff = MI_map_4qam[0][end-1];
          break;
        }
      }
    }

    sinr_eff = sinr_eff * beta2_dlsch_MI[TM][mcs];
  }



  else if (mcs>9 && mcs<17) {

    start = 0;
    end = 196;
    middle = end/2;

    if (RBIR <= MI_map_16qam[2][start]) {
      sinr_eff =  MI_map_16qam[0][start];
    } else {
      if (RBIR >= MI_map_16qam[2][end])
        sinr_eff =  MI_map_16qam[0][end];
      else {
        //while((end-start > 1) && (RBIR >= MI_map_4qam[2]))
        if (RBIR < MI_map_16qam[2][middle]) {
          end = middle;
          middle = end/2;
        } else {
          start = middle;
          middle = (end-middle)/2;
        }
      }

      for (; end>start; end--) {
        if ((RBIR < MI_map_16qam[2][end]) && (RBIR >  MI_map_16qam[2][end-2])) {
          sinr_eff = MI_map_16qam[0][end-1];
          break;
        }
      }
    }

    sinr_eff = sinr_eff * beta2_dlsch_MI[TM][mcs];
  } else if (mcs>16) {
    start = 0;
    end = 226;
    middle = end/2;

    if (RBIR <= MI_map_64qam[2][start]) {
      sinr_eff =  MI_map_64qam[0][start];
    } else {
      if (RBIR >= MI_map_64qam[2][end])
        sinr_eff =  MI_map_64qam[0][end];
      else {
        //while((end-start > 1) && (RBIR >= MI_map_4qam[2]))
        if (RBIR < MI_map_64qam[2][middle]) {
          end = middle;
          middle = end/2;
        } else {
          start = middle;
          middle = (end-middle)/2;
        }
      }

      for (; end>start; end--) {
        if ((RBIR < MI_map_64qam[2][end]) && (RBIR >  MI_map_64qam[2][end-2])) {
          sinr_eff = MI_map_64qam[0][end-1];
          break;
        }
      }
    }

    sinr_eff = sinr_eff * beta2_dlsch_MI[TM][mcs];
  }

  printf("SINR_Eff = %e\n",sinr_eff);

  sinr_eff *= 10;
  sinr_eff = floor(sinr_eff);
  // if ((int)sinr_eff%2) {
  //   sinr_eff += 1;
  // }
  sinr_eff /= 10;
  printf("sinr_eff after rounding = %f\n",sinr_eff);

  for (index = 0; index < 16; index++) {
    if(index == 0) {
      if (sinr_eff < sinr_bler_map_up[mcs][0][index]) {
        bler = 1;
        break;
      }
    }

    if (sinr_eff == sinr_bler_map_up[mcs][0][index]) {
      bler = sinr_bler_map_up[mcs][1][index];
    }
  }

#ifdef USER_MODE // need to be adapted for the emulation in the kernel space 

  if (uniformrandom() < bler) {
    printf("abstraction_decoding failed (mcs=%d, sinr_eff=%f, bler=%f)\n",mcs,sinr_eff,bler);
    return(0);
  } else {
    printf("abstraction_decoding successful (mcs=%d, sinr_eff=%f, bler=%f)\n",mcs,sinr_eff,bler);
    return(1);
  }

#endif

}

#endif

uint32_t ulsch_decoding_emul(PHY_VARS_eNB *eNB, eNB_rxtx_proc_t *proc,
                             uint8_t UE_index,
                             uint16_t *crnti)
{

  uint8_t UE_id;
  uint16_t rnti;
  int subframe = proc->subframe_rx;
  uint8_t harq_pid;
  uint8_t CC_id = eNB->CC_id;

  harq_pid = subframe2harq_pid(&eNB->frame_parms,proc->frame_rx,subframe);

  rnti = eNB->ulsch[UE_index]->rnti;
#ifdef DEBUG_PHY
  LOG_D(PHY,"[eNB %d] ulsch_decoding_emul : subframe %d UE_index %d harq_pid %d rnti %x\n",eNB->Mod_id,subframe,UE_index,harq_pid,rnti);
#endif

  for (UE_id=0; UE_id<NB_UE_INST; UE_id++) {
    if (rnti == PHY_vars_UE_g[UE_id][CC_id]->pdcch_vars[subframe & 0x1][0]->crnti)
      break;

  }

  if (UE_id==NB_UE_INST) {
    LOG_W(PHY,"[eNB %d] ulsch_decoding_emul: FATAL, didn't find UE with rnti %x (UE index %d)\n",
          eNB->Mod_id, rnti, UE_index);
    return(1+eNB->ulsch[UE_id]->max_turbo_iterations);
  } else {
    LOG_D(PHY,"[eNB %d] Found UE with rnti %x => UE_id %d\n",eNB->Mod_id, rnti, UE_id);
  }

  if (PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->harq_processes[harq_pid]->status == CBA_ACTIVE) {
    *crnti = rnti;
    PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->harq_processes[harq_pid]->status=IDLE;
  } else
    *crnti = 0x0;

  // Do abstraction here to determine if packet it in error
  /// if (ulsch_abstraction_MIESM(eNB->sinr_dB_eNB,1, eNB->ulsch[UE_id]->harq_processes[harq_pid]->mcs,eNB->ulsch[UE_id]->harq_processes[harq_pid]->nb_rb, eNB->ulsch[UE_id]->harq_processes[harq_pid]->first_rb) == 1)
   flag = 1;
   else flag = 0;///


  
  //SINRdbPost = eNB->sinr_dB_eNB;
  mcsPost = eNB->ulsch[UE_id]->harq_processes[harq_pid]->mcs,
  nrbPost = eNB->ulsch[UE_id]->harq_processes[harq_pid]->nb_rb;
  frbPost = eNB->ulsch[UE_id]->harq_processes[harq_pid]->first_rb;


  if(nrbPost > 0)
  {
  SINRdbPost = eNB->sinr_dB_eNB;
  ULflag1 = 1;
  }
  else
  {
   SINRdbPost = NULL  ;
   ULflag1 = 0 ;
  }//

  //
  // write_output("postprocSINR.m","SINReNB",eNB->sinr_dB,301,1,7);


  //Yazdir buraya her frame icin 300 eNb
  // fprintf(SINRrx,"%e,%e,%e,%e;\n",SINRdbPost);
  //fprintf(SINRrx,"%e\n",SINRdbPost);

  // fprintf(csv_fd,"%e+i*(%e),",channelx,channely);

  // if (ulsch_abstraction(eNB->sinr_dB,1, eNB->ulsch[UE_id]->harq_processes[harq_pid]->mcs,eNB->ulsch[UE_id]->harq_processes[harq_pid]->nb_rb, eNB->ulsch[UE_id]->harq_processes[harq_pid]->first_rb) == 1) {
  if (1) {
    LOG_D(PHY,"ulsch_decoding_emul abstraction successful\n");

    memcpy(eNB->ulsch[UE_index]->harq_processes[harq_pid]->b,
           PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->harq_processes[harq_pid]->b,
           eNB->ulsch[UE_index]->harq_processes[harq_pid]->TBS>>3);

    // get local ue's ack
    if ((UE_index >= oai_emulation.info.first_ue_local) ||(UE_index <(oai_emulation.info.first_ue_local+oai_emulation.info.nb_ue_local))) {
      get_ack(&eNB->frame_parms,
              PHY_vars_UE_g[UE_id][CC_id]->dlsch[0][0][0]->harq_ack,
              proc->subframe_tx,
              proc->subframe_rx,
              eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_ACK,0);
    } else { // get remote UEs' ack
      eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_ACK[0] = PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->o_ACK[0];
      eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_ACK[1] = PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->o_ACK[1];
    }

    // Do abstraction of PUSCH feedback
#ifdef DEBUG_PHY
    LOG_D(PHY,"[eNB %d][EMUL] ue index %d UE_id %d: subframe %d : o_ACK (%d %d), cqi (val %d, len %d)\n",
          eNB->Mod_id,UE_index, UE_id, subframe,eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_ACK[0],
          eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_ACK[1],
          ((HLC_subband_cqi_rank1_2A_5MHz *)PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->o)->cqi1,
          PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->O);
#endif

    eNB->ulsch[UE_index]->harq_processes[harq_pid]->Or1 = PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->O;
    eNB->ulsch[UE_index]->harq_processes[harq_pid]->Or2 = PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->O;

    eNB->ulsch[UE_index]->harq_processes[harq_pid]->uci_format = PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->uci_format;
    memcpy(eNB->ulsch[UE_index]->harq_processes[harq_pid]->o,PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->o,MAX_CQI_BYTES);
    memcpy(eNB->ulsch[UE_index]->harq_processes[harq_pid]->o_RI,PHY_vars_UE_g[UE_id][CC_id]->ulsch[0]->o_RI,2);

    eNB->ulsch[UE_index]->harq_processes[harq_pid]->cqi_crc_status = 1;

    return(1);
  } else {
    LOG_W(PHY,"[eNB %d] ulsch_decoding_emul abstraction failed for UE %d\n",eNB->Mod_id,UE_index);

    eNB->ulsch[UE_index]->harq_processes[harq_pid]->cqi_crc_status = 0;

    // retransmission
    return(1+eNB->ulsch[UE_index]->max_turbo_iterations);
  }

}


#endif
*/
