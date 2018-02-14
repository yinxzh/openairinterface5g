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

/*!\brief SCHED external variables */

#ifndef __SCHED_EXTERN_NB_IOT_H__
#define __SCHED_EXTERN_NB_IOT_H__

#ifndef USER_MODE
#define __NO_VERSION__


#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>

#include <asm/io.h>
#include <asm/bitops.h>

#include <asm/uaccess.h>
#include <asm/segment.h>
#include <asm/page.h>


#ifdef RTAI_ENABLED
#include <rtai.h>
//#include <rtai_posix.h>
#include <rtai_fifos.h>
#include <rtai_sched.h>
#include <rtai_sem.h>
//#include "rt_compat.h"

#else
#include <unistd.h>
#endif

#endif  /* USER_MODE */




#include "defs_NB_IoT.h"



#include "openair2/PHY_INTERFACE/IF_Module_NB_IoT.h"


extern uint16_t hundred_times_log10_NPRB_NB_IoT[100];

extern Sched_Rsp_NB_IoT_t* Sched_Rsp;

/*Generate the ulsch params and do the mapping for the FAPI style parameters to OAI, and then do the packing*/
extern void generate_eNB_ulsch_params_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,eNB_rxtx_proc_NB_IoT_t *proc,nfapi_hi_dci0_request_pdu_t *hi_dci0_pdu);

/*Generate the dlsch params and do the mapping for the FAPI style parameters to OAI, and then do the packing*/

extern void generate_eNB_dlsch_params_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,eNB_rxtx_proc_NB_IoT_t * proc,nfapi_dl_config_request_pdu_t *dl_config_pdu); 
/*Process all the scheduling result from MAC and also common signals.*/
extern void phy_procedures_eNB_TX_NB_IoT(PHY_VARS_eNB_NB_IoT *eNB,eNB_rxtx_proc_NB_IoT_t *proc,int do_meas);

#endif /*__SCHED_EXTERN_H__ */
