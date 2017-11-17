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

/*
  enb_config.c
  -------------------
  AUTHOR  : Lionel GAUTHIER, navid nikaein, Laurent Winckel
  COMPANY : EURECOM
  EMAIL   : Lionel.Gauthier@eurecom.fr, navid.nikaein@eurecom.fr
*/

#include <string.h>
#include <inttypes.h>

#include "log.h"
#include "log_extern.h"
#include "assertions.h"
#include "enb_config.h"
#include "UTIL/OTG/otg.h"
#include "UTIL/OTG/otg_externs.h"
#if defined(OAI_EMU)
# include "OCG.h"
# include "OCG_extern.h"
#endif
#if defined(ENABLE_ITTI)
# include "intertask_interface.h"
# if defined(ENABLE_USE_MME)
#   include "s1ap_eNB.h"
#   include "sctp_eNB_task.h"
# endif
#endif
#include "sctp_default_values.h"
#include "SystemInformationBlockType2.h"
#include "LAYER2/MAC/extern.h"
#include "PHY/extern.h"
#include "targets/ARCH/ETHERNET/USERSPACE/LIB/ethernet_lib.h"
#include "nbiot_paramdef.h"
#include "common/config/config_userapi.h"


	       
int RCconfig_NbIoTRRC(MessageDef *msg_p) {


  char nbiotlist_path[MAX_OPTNAME_SIZE + 8];
  paramdef_t NBIoTParams[] = NBIOTRRCPARAMS_DESC;
  paramlist_def_t NBIoTRRCParamList = {NBIOT_RRCLIST_CONFIG_STRING,NULL,0};  

 
  config_getlist( &NBIoTRRCParamList,NBIoTParams,sizeof(NBIoTParams)/sizeof(paramdef_t),NULL); 
	  
  LOG_I(RRC,"num NbIoT RRCs %d \n",NBIoTRRCParamList.numelt);  


	    for (int j = 0; j < NBIoTRRCParamList.numelt ;j++) { 


	      NBIOTRRC_CONFIGURATION_REQ (msg_p).rach_raResponseWindowSize_NB[j] = *(NBIoTRRCParamList.paramarray[j][NBIOT_RACH_RARESPONSEWINDOWSIZE_NB_IDX].uptr);
	      

      
    }
return 0;
}

