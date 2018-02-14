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

#include "PHY/defs_L1_NB_IoT.h"
#include "PHY/extern_NB_IoT.h"
//#include "PHY/sse_intrin.h"
#include <math.h>

#include "PHY/LTE_ESTIMATION/defs_NB_IoT.h"
#include "PHY/LTE_TRANSPORT/extern_NB_IoT.h"
//#define DEBUG_CH

#include "T.h"




// round(exp(sqrt(-1)*(pi/2)*[0:1:N-1]/N)*pow2(15))

#define SCALE 0x3FFF

int32_t lte_ul_channel_estimation_NB_IoT(PHY_VARS_eNB_NB_IoT      *eNB,
				                                 eNB_rxtx_proc_NB_IoT_t   *proc,
                                         uint8_t                  eNB_id,
                                         uint8_t                  UE_id,
                                         unsigned char            l,
                                         unsigned char            Ns,
                                         uint8_t                  cooperation_flag)
{

 
  return(0);
}


int16_t lte_ul_freq_offset_estimation_NB_IoT(NB_IoT_DL_FRAME_PARMS *frame_parms,
                                             int32_t *ul_ch_estimates,
                                             uint16_t nb_rb)
{


  return(0);

}
