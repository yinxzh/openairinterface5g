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
#include "L1_paramdef.h"
#include "MACRLC_paramdef.h"
#include "common/config/config_userapi.h"




void RCconfig_NbIoTL1() {
  int               i,j;
  paramdef_t NbIoT_L1_Params[] = L1PARAMS_DESC;
  paramlist_def_t NbIoT_L1_ParamList = {NBIOT_L1LIST_CONFIG_STRING,NULL,0};


  config_getlist( &NbIoT_L1_ParamList,NbIoT_L1_Params,sizeof(NbIoT_L1_Params)/sizeof(paramdef_t), NULL);    
  if (NbIoT_L1_ParamList.numelt > 0) {

/*    if (RC.nb_iot_rrc == NULL) {
      RC.L1_NB_IoT                         = (PHY_VARS_eNB_NB_IoT **)malloc(RC.nb_iot_rrc*sizeof(PHY_VARS_eNB_NB_IoT));
      LOG_I(PHY,"RC.nb_iot_rrc = %p\n",RC.nb_iot_rrc);
      memset(RC.nb_iot_rrc,0,RC.nb_iot_rrc*sizeof(PHY_VARS_eNB_NB_IoT));
    }

    for (j = 0; j < RC.nb_nb_iot_L1_inst; j++) {
      RC.nb_L1_CC[j] = *(L1_ParamList.paramarray[j][L1_CC_IDX].uptr);


      if (RC.eNB[j] == NULL) {
	RC.eNB[j]                       = (PHY_VARS_eNB **)malloc((1+MAX_NUM_CCs)*sizeof(PHY_VARS_eNB**));
	LOG_I(PHY,"RC.eNB[%d] = %p\n",j,RC.eNB[j]);
	memset(RC.eNB[j],0,(1+MAX_NUM_CCs)*sizeof(PHY_VARS_eNB***));
      }


      for (i=0;i<RC.nb_L1_CC[j];i++) {
	if (RC.eNB[j][i] == NULL) {
	  RC.eNB[j][i] = (PHY_VARS_eNB *)malloc(sizeof(PHY_VARS_eNB));
	  memset((void*)RC.eNB[j][i],0,sizeof(PHY_VARS_eNB));
	  LOG_I(PHY,"RC.eNB[%d][%d] = %p\n",j,i,RC.eNB[j][i]);
	  RC.eNB[j][i]->Mod_id  = j;
	  RC.eNB[j][i]->CC_id   = i;
	}
      }

      if (strcmp(*(L1_ParamList.paramarray[j][L1_TRANSPORT_N_PREFERENCE_IDX].strptr), "local_mac") == 0) {

      }
      else if (strcmp(*(L1_ParamList.paramarray[j][L1_TRANSPORT_N_PREFERENCE_IDX].strptr), "nfapi") == 0) {
	RC.eNB[j][0]->eth_params_n.local_if_name            = strdup(*(L1_ParamList.paramarray[j][L1_LOCAL_N_IF_NAME_IDX].strptr));
	RC.eNB[j][0]->eth_params_n.my_addr                  = strdup(*(L1_ParamList.paramarray[j][L1_LOCAL_N_ADDRESS_IDX].strptr));
	RC.eNB[j][0]->eth_params_n.remote_addr              = strdup(*(L1_ParamList.paramarray[j][L1_REMOTE_N_ADDRESS_IDX].strptr));
	RC.eNB[j][0]->eth_params_n.my_portc                 = *(L1_ParamList.paramarray[j][L1_LOCAL_N_PORTC_IDX].iptr);
	RC.eNB[j][0]->eth_params_n.remote_portc             = *(L1_ParamList.paramarray[j][L1_REMOTE_N_PORTC_IDX].iptr);
	RC.eNB[j][0]->eth_params_n.my_portd                 = *(L1_ParamList.paramarray[j][L1_LOCAL_N_PORTD_IDX].iptr);
	RC.eNB[j][0]->eth_params_n.remote_portd             = *(L1_ParamList.paramarray[j][L1_REMOTE_N_PORTD_IDX].iptr);
	RC.eNB[j][0]->eth_params_n.transp_preference        = ETH_UDP_MODE;
      }
      
      else { // other midhaul
      }	
    }// j=0..num_inst
    printf("Initializing northbound interface for L1\n");
    l1_north_init_eNB();*/
  } else {
    LOG_I(PHY,"No " NBIOT_L1LIST_CONFIG_STRING " configuration found");    
  }
}

void RCconfig_NbIoTmacrlc() {
  int               j;


  paramdef_t NbIoT_MacRLC_Params[] = MACRLCPARAMS_DESC;
  paramlist_def_t NbIoT_MacRLC_ParamList = {NBIOT_MACRLCLIST_CONFIG_STRING,NULL,0};

  config_getlist( &NbIoT_MacRLC_ParamList,NbIoT_MacRLC_Params,sizeof(NbIoT_MacRLC_Params)/sizeof(paramdef_t), NULL);    
  

  if ( NbIoT_MacRLC_ParamList.numelt > 0) {

    RC.nb_nb_iot_macrlc_inst=NbIoT_MacRLC_ParamList.numelt; 
/*    mac_top_init_eNB();   
    for (j=0;j<RC.nb_macrlc_inst;j++) {

      if (strcmp(*(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_N_PREFERENCE_IDX].strptr), "local_RRC") == 0) {
	// check number of instances is same as RRC/PDCP
	
      } else if (strcmp(*(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_N_PREFERENCE_IDX].strptr), "cudu") == 0) {
	RC.mac[j]->eth_params_n.local_if_name            = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_N_IF_NAME_IDX].strptr));
	RC.mac[j]->eth_params_n.my_addr                  = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_N_ADDRESS_IDX].strptr));
	RC.mac[j]->eth_params_n.remote_addr              = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_N_ADDRESS_IDX].strptr));
	RC.mac[j]->eth_params_n.my_portc                 = *(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_N_PORTC_IDX].iptr);
	RC.mac[j]->eth_params_n.remote_portc             = *(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_N_PORTC_IDX].iptr);
	RC.mac[j]->eth_params_n.my_portd                 = *(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_N_PORTD_IDX].iptr);
	RC.mac[j]->eth_params_n.remote_portd             = *(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_N_PORTD_IDX].iptr);;
	RC.mac[j]->eth_params_n.transp_preference        = ETH_UDP_MODE;
      } else { // other midhaul
	AssertFatal(1==0,"MACRLC %d: %s unknown northbound midhaul\n",j, *(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_N_PREFERENCE_IDX].strptr));
      }	

      if (strcmp(*(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_S_PREFERENCE_IDX].strptr), "local_L1") == 0) {

	
      } else if (strcmp(*(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_S_PREFERENCE_IDX].strptr), "nfapi") == 0) {
	RC.mac[j]->eth_params_s.local_if_name            = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_S_IF_NAME_IDX].strptr));
	RC.mac[j]->eth_params_s.my_addr                  = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_S_ADDRESS_IDX].strptr));
	RC.mac[j]->eth_params_s.remote_addr              = strdup(*(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_S_ADDRESS_IDX].strptr));
	RC.mac[j]->eth_params_s.my_portc                 = *(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_S_PORTC_IDX].iptr);
	RC.mac[j]->eth_params_s.remote_portc             = *(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_S_PORTC_IDX].iptr);
	RC.mac[j]->eth_params_s.my_portd                 = *(MacRLC_ParamList.paramarray[j][MACRLC_LOCAL_S_PORTD_IDX].iptr);
	RC.mac[j]->eth_params_s.remote_portd             = *(MacRLC_ParamList.paramarray[j][MACRLC_REMOTE_S_PORTD_IDX].iptr);
	RC.mac[j]->eth_params_s.transp_preference        = ETH_UDP_MODE;
      } else { // other midhaul
	AssertFatal(1==0,"MACRLC %d: %s unknown southbound midhaul\n",j,*(MacRLC_ParamList.paramarray[j][MACRLC_TRANSPORT_S_PREFERENCE_IDX].strptr));
      }	
    }// j=0..num_inst */
  } else {// MacRLC_ParamList.numelt > 0
	  AssertFatal (0,
		       "No " NBIOT_MACRLCLIST_CONFIG_STRING " configuration found");     
  }
}



	       
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

void RCConfig_NbIoT(RAN_CONTEXT_t *RC) {

  paramlist_def_t NbIoT_MACRLCParamList = {NBIOT_MACRLCLIST_CONFIG_STRING,NULL,0};
  paramlist_def_t NbIoT_L1ParamList = {NBIOT_L1LIST_CONFIG_STRING,NULL,0};
  paramlist_def_t NbIoT_ParamList = {NBIOT_RRCLIST_CONFIG_STRING,NULL,0};
  
  char aprefix[MAX_OPTNAME_SIZE*2 + 8];  
  
  config_getlist( &NbIoT_ParamList,NULL,0,NULL);
  RC->nb_nb_iot_rrc_inst = NbIoT_ParamList.numelt;


    
 
    config_getlist( &NbIoT_MACRLCParamList,NULL,0, NULL);
    RC->nb_nb_iot_macrlc_inst  = NbIoT_MACRLCParamList.numelt;
    // Get num L1 instances
    config_getlist( &NbIoT_L1ParamList,NULL,0, NULL);
    RC->nb_nb_iot_L1_inst = NbIoT_L1ParamList.numelt;

}
