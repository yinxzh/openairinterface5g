/* Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
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

/*! \file l2_interface_nb_iot.c
 * \brief layer 2 interface, used to support different RRC sublayer
 * \author Raymond Knopp and Navid Nikaein
 * \date 2010-2014
 * \version 1.0
 * \company Eurecom
 * \email: raymond.knopp@eurecom.fr
 */
//#include "PHY/defs.h"
#include "PHY/defs_L1_NB_IoT.h"
#include "openair2/LAYER2/MAC/proto_NB_IoT.h"
#include "openair2/LAYER2/MAC/extern_NB_IoT.h"
//#include "PHY/INIT/defs_NB_IoT.h"
//#include "SCHED/defs.h"
//#include "platform_types.h"
//#include "defs_NB_IoT.h" //RRC
//#include "LAYER2/MAC/defs_NB_IoT.h" //MAC
//#include "LAYER2/MAC/defs.h" // MAC because see the PHY functions
//#include "extern.h"
//#include "LAYER2/MAC/extern.h"
#include "UTIL/LOG/log.h"
#include "UTIL/OCG/OCG_vars.h"
#include "RRC/LITE/rrc_eNB_UE_context_NB_IoT.h"
#include "pdcp_primitives.h"
#include "pdcp.h"
#include "pdcp_util.h"
#include "rlc.h"
#include "msc.h"
#include "UTIL/LOG/vcd_signal_dumper.h"
//#include "gtpv1u.h"
#include "osa_defs.h"
#include "pdcp_sequence_manager.h"
#include "UTIL/OTG/otg_rx.h"
#include "openair2/PHY_INTERFACE/IF_Module_NB_IoT.h"
#include "openair1/SCHED/IF_Module_L1_primitives_NB_IoT.h"
#include "openair3/GTPV1-U/gtpv1u.h"
#include "extern.h"
#if defined(ENABLE_ITTI)
# include "intertask_interface.h"
#endif

//#define RRC_DATA_REQ_DEBUG
#define DEBUG_RRC 1

//to add into platform types
typedef boolean_t srb1bis_flag_t;
#define SRB1BIS_FLAG_NO		FALSE
#define SRB1BIS_FLAG_YES	TRUE //defined in interTask-interface = 1

typedef boolean_t mib_flag_t;
#define MIB_FLAG_YES	TRUE
#define MIB_FLAG_NO		FALSE

//mui_t mui_NB=0;

//XXX MP: just temporary usage since i put in one single file all the primitives modified (but they should be relocated in the
//proper file where they are defined as indicated in the comments

//XXX access of protected variables in pdcp.h
extern unsigned int           pdcp_eNB_UE_instance_to_rnti_index;
extern rnti_t                 pdcp_eNB_UE_instance_to_rnti[NUMBER_OF_UE_MAX_NB_IoT];
extern list_t                 pdcp_sdu_list;
//extern struct mac_data_req rlc_am_mac_data_request (const protocol_ctxt_t* const ctxtP,void * const rlc_pP);

extern void rlc_tm_init ( const protocol_ctxt_t* const  ctxt_pP, rlc_tm_entity_t * const rlcP);
extern void rlc_tm_set_debug_infos(
        const protocol_ctxt_t* const  ctxt_pP,
        rlc_tm_entity_t * const       rlcP,
        const srb_flag_t              srb_flagP,
        const rb_id_t                 rb_idP,
        const logical_chan_id_t chan_idP);
extern void rlc_tm_configure(
        const protocol_ctxt_t* const  ctxt_pP,
        rlc_tm_entity_t * const rlcP,
        const boolean_t is_uplink_downlinkP);
extern void     rlc_am_rx (const protocol_ctxt_t* const ctxtP,void * const rlc_pP, struct mac_data_ind);
extern tbs_size_t            mac_rlc_serialize_tb   (char*, list_t);
extern struct mac_data_ind mac_rlc_deserialize_tb (
		  char     *buffer_pP,
		  const tb_size_t tb_sizeP,
		  num_tb_t  num_tbP,
		  crc_t    *crcs_pP);
extern void rlc_am_init_timer_poll_retransmit(
	    const protocol_ctxt_t* const ctxt_pP,
	    rlc_am_entity_t* const       rlc_pP,
	    const uint32_t               time_outP);

//pointer function in rlc.h file
extern void (*rlc_rrc_data_ind_NB_IoT)(
                const protocol_ctxt_t* const ctxtP,
                const rb_id_t     rb_idP,
                const sdu_size_t  sdu_sizeP,
                const uint8_t   * const sduP,
				const srb1bis_flag_t srb1bis_flag);
extern void (*rlc_rrc_data_conf)(
        const protocol_ctxt_t* const ctxtP,
        const rb_id_t         rb_idP,
        const mui_t           muiP,
        const rlc_tx_status_t statusP);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Most of the Functions re-defined for NB-IoT should be re-located in their proper position over the code as already indicated the comments//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*---------------------------------RRC-MAC-----------------------------------*/

int8_t mac_rrc_data_req_eNB_NB_IoT(
  const module_id_t Mod_idP,
  const int         CC_id,
  const frame_t     frameP,
  const frame_t		h_frameP,
  const sub_frame_t   subframeP, //need for the case in which both SIB1-NB_IoT and SIB23-NB_IoT will be scheduled in the same frame
  const rb_id_t     Srb_id,
  uint8_t*    const buffer_pP,
  uint8_t		flag
)
{
    SRB_INFO_NB_IoT *Srb_info;
    uint8_t Sdu_size=0;

    ///MIB
    if( flag == 1 )
    {
        if (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MIB_NB_IoT == 255)
        {
            printf("[eNB %d] MAC Request for MIB-NB and MIB-NB not initialized\n",Mod_idP);
            // exit here
        }

        memcpy(&buffer_pP[0],RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].MIB_NB_IoT,RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MIB_NB_IoT);

        return (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MIB_NB_IoT);
    }
    ///SIB1
    else if( flag == 2 )
    {
        if (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT == 255)
        {
            printf("[eNB %d] MAC Request for SIB1-NB and SIB1-NB_IoT not initialized\n",Mod_idP);
            // exit here
        }

        memcpy(&buffer_pP[0],RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB1_NB_IoT,RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT);

        return (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT);
    }
    ///SIB23
    else if( flag == 3 )
    {
        if (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT == 255)
        {
            printf("[eNB %d] MAC Request for SIB23-NB and SIB23-NB_IoT not initialized\n",Mod_idP);
            // exit here
        }

        memcpy(&buffer_pP[0],RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB23_NB_IoT,RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT);
        return(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT);
    }
    ///Msg4 transmission (RRCConnectionSetup)
    else
    {
        printf("[eNB %d] Frame %d CCCH request (Srb_id %d)\n",Mod_idP,frameP, Srb_id);

        if(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].Srb0.Active==0)
        {
            printf("[eNB %d] CCCH Not active\n",Mod_idP);
            return -1;
        }

        Srb_info = &RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].Srb0;

        // check if data is there for MAC
        if(Srb_info->Tx_buffer.payload_size>0) //Fill buffer
        {
            printf("[eNB %d] CCCH (%p) has %d bytes (dest: %p, src %p)\n",Mod_idP,Srb_info,Srb_info->Tx_buffer.payload_size,buffer_pP,Srb_info->Tx_buffer.Payload);

            //RRC_MAC_CCCH_DATA_REQ not implemented in MAC/eNB_scheduler.c

            memcpy(buffer_pP, //CCCH_pdu.payload[0]
                    Srb_info->Tx_buffer.Payload,Srb_info->Tx_buffer.payload_size);

            Sdu_size = Srb_info->Tx_buffer.payload_size;
            Srb_info->Tx_buffer.payload_size=0;
        }

        return (Sdu_size);
    }

}

//defined in L2_interface
//called by rx_sdu only in case of CCCH message (e.g RRCConnectionRequest-NB - SRB0) --> is used for a direct communication between MAC and RRC
int8_t mac_rrc_data_ind_eNB_NB_IoT(
  const module_id_t     module_idP,
  const int             CC_id,
  const frame_t         frameP,
  const sub_frame_t     sub_frameP,
  const rnti_t          rntiP,
  const rb_id_t         srb_idP,//could be skipped since always go through the CCCH channel
  const uint8_t*        sduP,
  const sdu_size_t      sdu_lenP
)
{
  SRB_INFO_NB_IoT *Srb_info;
  protocol_ctxt_t ctxt;
  sdu_size_t      sdu_size = 0;

  /* for no gcc warnings */
  (void)sdu_size;

  PROTOCOL_CTXT_SET_BY_MODULE_ID(&ctxt, module_idP, ENB_FLAG_YES, rntiP, frameP, sub_frameP,module_idP);

    Srb_info = &eNB_rrc_inst_NB_IoT[module_idP].carrier[CC_id].Srb0;
    LOG_T(RRC,"[eNB %d] Received SDU for CCCH on SRB %d\n",module_idP,Srb_info->Srb_id);


    //this messages are used by the RRC if ITTI enabled
#if defined(ENABLE_ITTI)
    {
      MessageDef *message_p;
      int msg_sdu_size = sizeof(RRC_MAC_CCCH_DATA_IND (message_p).sdu);

      if (sdu_lenP > msg_sdu_size) {
        LOG_E(RRC, "SDU larger than CCCH SDU buffer size (%d, %d)", sdu_lenP, msg_sdu_size);
        sdu_size = msg_sdu_size;
      } else {
        sdu_size = sdu_lenP;
      }

      message_p = itti_alloc_new_message (TASK_MAC_ENB, RRC_MAC_CCCH_DATA_IND);
      RRC_MAC_CCCH_DATA_IND (message_p).frame     = frameP;
      RRC_MAC_CCCH_DATA_IND (message_p).sub_frame = sub_frameP;
      RRC_MAC_CCCH_DATA_IND (message_p).rnti      = rntiP;
      RRC_MAC_CCCH_DATA_IND (message_p).sdu_size  = sdu_size;
      RRC_MAC_CCCH_DATA_IND (message_p).CC_id = CC_id;
      memset (RRC_MAC_CCCH_DATA_IND (message_p).sdu, 0, CCCH_SDU_SIZE);
      memcpy (RRC_MAC_CCCH_DATA_IND (message_p).sdu, sduP, sdu_size);
      itti_send_msg_to_task (TASK_RRC_ENB, ctxt.instance, message_p);
    }
#else

    if (sdu_lenP > 0) {
      memcpy(Srb_info->Rx_buffer.Payload,sduP,sdu_lenP);
      Srb_info->Rx_buffer.payload_size = sdu_lenP;
      rrc_eNB_decode_ccch_NB_IoT(&ctxt, Srb_info, CC_id);
    }

#endif
  return(0);

}


//defined in L2_interface
void mac_eNB_rrc_ul_failure_NB_IoT(
		const module_id_t mod_idP,
	    const int CC_idP,
	    const frame_t frameP,
	    const sub_frame_t subframeP,
	    const rnti_t rntiP)
{
  struct rrc_eNB_ue_context_NB_IoT_s* ue_context_p = NULL;
  ue_context_p = rrc_eNB_get_ue_context_NB_IoT(
                   &eNB_rrc_inst_NB_IoT[mod_idP],
                   rntiP);

  if (ue_context_p != NULL) {
    LOG_I(RRC,"Frame %d, Subframe %d: UE %x UL failure, activating timer\n",frameP,subframeP,rntiP);
    ue_context_p->ue_context.ul_failure_timer=1;
  }
  else {
    LOG_W(RRC,"Frame %d, Subframe %d: UL failure: UE %x unknown \n",frameP,subframeP,rntiP);
  }
  //rrc_mac_remove_ue_NB_IoT(mod_idP,rntiP);
}


//------------------------------------------------------------------------------
int8_t mac_rrc_data_req_NB_IoT(
  const module_id_t Mod_idP,
  const int         CC_id,
  const frame_t     frameP,
  const rb_id_t     Srb_id,
  const uint8_t     Nb_tb,
  uint8_t*    const buffer_pP,
  const eNB_flag_t  enb_flagP,
  const uint8_t     eNB_index,
  const uint8_t     mbsfn_sync_area
)
//--------------------------------------------------------------------------
{
  //MAC_xface_NB_IoT *mac_xface_NB_IoT; //test_xface
  
  SRB_INFO_NB_IoT *Srb_info;
  uint8_t Sdu_size=0;

#ifdef DEBUG_RRC
  int i;
  LOG_T(RRC,"[eNB %d] mac_rrc_data_req to SRB ID=%d\n",Mod_idP,Srb_id);
#endif

  if( enb_flagP == ENB_FLAG_YES) {

    if((Srb_id & RAB_OFFSET) == BCCH0_NB_IoT) {
      if(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SI.Active==0) {
        return 0;
      }

      // All even frames transmit SIB in SF 5
      if (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT == 255) {
        LOG_E(RRC,"[eNB %d] MAC Request for SIB1 and SIB1 not initialized\n",Mod_idP);
        //exit here
      }

      if ((frameP%2) == 0) {
        memcpy(&buffer_pP[0],
               RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB1_NB_IoT,
               RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT);

#if defined(ENABLE_ITTI)
        {
          MessageDef *message_p;
          int sib1_size = RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT;
          int sdu_size = sizeof(RRC_MAC_BCCH_DATA_REQ (message_p).sdu);

          if (sib1_size > sdu_size) {
            LOG_E(RRC, "SIB1 SDU larger than BCCH SDU buffer size (%d, %d)", sib1_size, sdu_size);
            sib1_size = sdu_size;
          }

          message_p = itti_alloc_new_message (TASK_RRC_ENB, RRC_MAC_BCCH_DATA_REQ);
          RRC_MAC_BCCH_DATA_REQ (message_p).frame    = frameP;
          RRC_MAC_BCCH_DATA_REQ (message_p).sdu_size = sib1_size;
          memset (RRC_MAC_BCCH_DATA_REQ (message_p).sdu, 0, BCCH_SDU_SIZE);
          memcpy (RRC_MAC_BCCH_DATA_REQ (message_p).sdu,
                  RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB1_NB_IoT,
                  sib1_size);
          RRC_MAC_BCCH_DATA_REQ (message_p).enb_index = eNB_index;

          itti_send_msg_to_task (TASK_MAC_ENB, ENB_MODULE_ID_TO_INSTANCE(Mod_idP), message_p);
        }
#endif

#ifdef DEBUG_RRC
        LOG_T(RRC,"[eNB %d] Frame %d : BCCH request => SIB 1\n",Mod_idP,frameP);

        for (i=0; i<RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT; i++) {
          LOG_T(RRC,"%x.",buffer_pP[i]);
        }

        LOG_T(RRC,"\n");
#endif

        return (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB1_NB_IoT);
      } // All RFN mod 8 transmit SIB2-3 in SF 5
      else if ((frameP%8) == 1) {
        memcpy(&buffer_pP[0],
               RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB23_NB_IoT,
               RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT);

#if defined(ENABLE_ITTI)
        {
          MessageDef *message_p;
          int sib23_size = RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT;
          int sdu_size = sizeof(RRC_MAC_BCCH_DATA_REQ (message_p).sdu);

          if (sib23_size > sdu_size) {
            LOG_E(RRC, "SIB23 SDU larger than BCCH SDU buffer size (%d, %d)", sib23_size, sdu_size);
            sib23_size = sdu_size;
          }

          message_p = itti_alloc_new_message (TASK_RRC_ENB, RRC_MAC_BCCH_DATA_REQ);
          RRC_MAC_BCCH_DATA_REQ (message_p).frame = frameP;
          RRC_MAC_BCCH_DATA_REQ (message_p).sdu_size = sib23_size;
          memset (RRC_MAC_BCCH_DATA_REQ (message_p).sdu, 0, BCCH_SDU_SIZE);
          memcpy (RRC_MAC_BCCH_DATA_REQ (message_p).sdu,
                  RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].SIB23_NB_IoT,
                  sib23_size);
          RRC_MAC_BCCH_DATA_REQ (message_p).enb_index = eNB_index;

          itti_send_msg_to_task (TASK_MAC_ENB, ENB_MODULE_ID_TO_INSTANCE(Mod_idP), message_p);
        }
#endif

#ifdef DEBUG_RRC
        LOG_T(RRC,"[eNB %d] Frame %d BCCH request => SIB 2-3\n",Mod_idP,frameP);

        for (i=0; i<RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT; i++) {
          LOG_T(RRC,"%x.",buffer_pP[i]);
        }

        LOG_T(RRC,"\n");
#endif
        return(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_SIB23_NB_IoT);
      } else {
        return(0);
      }
    }

    if( (Srb_id & RAB_OFFSET ) == CCCH_NB_IoT) {
      LOG_T(RRC,"[eNB %d] Frame %d CCCH request (Srb_id %d)\n",Mod_idP,frameP, Srb_id);

      if(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].Srb0.Active==0) {
        LOG_E(RRC,"[eNB %d] CCCH Not active\n",Mod_idP);
        return -1;
      }

      Srb_info=&RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].Srb0;

      // check if data is there for MAC
      if(Srb_info->Tx_buffer.payload_size>0) { //Fill buffer
        LOG_D(RRC,"[eNB %d] CCCH (%p) has %d bytes (dest: %p, src %p)\n",Mod_idP,Srb_info,Srb_info->Tx_buffer.payload_size,buffer_pP,Srb_info->Tx_buffer.Payload);

#if defined(ENABLE_ITTI)
        {
          MessageDef *message_p;
          int ccch_size = Srb_info->Tx_buffer.payload_size;
          int sdu_size = sizeof(RRC_MAC_CCCH_DATA_REQ (message_p).sdu);

          if (ccch_size > sdu_size) {
            LOG_E(RRC, "SDU larger than CCCH SDU buffer size (%d, %d)", ccch_size, sdu_size);
            ccch_size = sdu_size;
          }

          message_p = itti_alloc_new_message (TASK_RRC_ENB, RRC_MAC_CCCH_DATA_REQ);
          RRC_MAC_CCCH_DATA_REQ (message_p).frame = frameP;
          RRC_MAC_CCCH_DATA_REQ (message_p).sdu_size = ccch_size;
          memset (RRC_MAC_CCCH_DATA_REQ (message_p).sdu, 0, CCCH_SDU_SIZE);
          memcpy (RRC_MAC_CCCH_DATA_REQ (message_p).sdu, Srb_info->Tx_buffer.Payload, ccch_size);
          RRC_MAC_CCCH_DATA_REQ (message_p).enb_index = eNB_index;

          itti_send_msg_to_task (TASK_MAC_ENB, ENB_MODULE_ID_TO_INSTANCE(Mod_idP), message_p);
        }
#endif

        memcpy(buffer_pP,Srb_info->Tx_buffer.Payload,Srb_info->Tx_buffer.payload_size);
        Sdu_size = Srb_info->Tx_buffer.payload_size;
        Srb_info->Tx_buffer.payload_size=0;
      }

      return (Sdu_size);
    }

#if defined(Rel10) || defined(Rel14)

    if((Srb_id & RAB_OFFSET) == MCCH_NB_IoT) {
      if(RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].MCCH_MESS[mbsfn_sync_area].Active==0) {
        return 0;  // this parameter is set in function init_mcch in rrc_eNB.c
      }



#if defined(ENABLE_ITTI)
      {
        MessageDef *message_p;
        int mcch_size = RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MCCH_MESSAGE[mbsfn_sync_area];
        int sdu_size = sizeof(RRC_MAC_MCCH_DATA_REQ (message_p).sdu);

        if (mcch_size > sdu_size) {
          LOG_E(RRC, "SDU larger than MCCH SDU buffer size (%d, %d)", mcch_size, sdu_size);
          mcch_size = sdu_size;
        }

        message_p = itti_alloc_new_message (TASK_RRC_ENB, RRC_MAC_MCCH_DATA_REQ);
        RRC_MAC_MCCH_DATA_REQ (message_p).frame = frameP;
        RRC_MAC_MCCH_DATA_REQ (message_p).sdu_size = mcch_size;
        memset (RRC_MAC_MCCH_DATA_REQ (message_p).sdu, 0, MCCH_SDU_SIZE);
        memcpy (RRC_MAC_MCCH_DATA_REQ (message_p).sdu,
                RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].MCCH_MESSAGE[mbsfn_sync_area],
                mcch_size);
        RRC_MAC_MCCH_DATA_REQ (message_p).enb_index = eNB_index;
        RRC_MAC_MCCH_DATA_REQ (message_p).mbsfn_sync_area = mbsfn_sync_area;

        itti_send_msg_to_task (TASK_MAC_ENB, ENB_MODULE_ID_TO_INSTANCE(Mod_idP), message_p);
      }
#endif

      memcpy(&buffer_pP[0],
             RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].MCCH_MESSAGE[mbsfn_sync_area],
             RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MCCH_MESSAGE[mbsfn_sync_area]);

#ifdef DEBUG_RRC
      LOG_D(RRC,"[eNB %d] Frame %d : MCCH request => MCCH_MESSAGE \n",Mod_idP,frameP);

      for (i=0; i<RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MCCH_MESSAGE[mbsfn_sync_area]; i++) {
        LOG_T(RRC,"%x.",buffer_pP[i]);
      }

      LOG_T(RRC,"\n");
#endif

      return (RC.nb_iot_rrc[Mod_idP]->carrier[CC_id].sizeof_MCCH_MESSAGE[mbsfn_sync_area]);
    }
  
#endif //Rel10 || Rel14
  } else {  //This is an UE
    AssertFatal(1==0,"No NB-IoT UE\n");
  }

  return(0);
}



//defined in L2_interface
void mac_eNB_rrc_ul_in_sync_NB_IoT(
				const module_id_t mod_idP,
			    const int CC_idP,
			    const frame_t frameP,
			    const sub_frame_t subframeP,
			    const rnti_t rntiP)
{
  struct rrc_eNB_ue_context_NB_IoT_s* ue_context_p = NULL;
  ue_context_p = rrc_eNB_get_ue_context_NB_IoT(
                   &eNB_rrc_inst_NB_IoT[mod_idP],
                   rntiP);

  if (ue_context_p != NULL) {
    LOG_I(RRC,"Frame %d, Subframe %d: UE %x to UL in synch\n",
          frameP, subframeP, rntiP);
    ue_context_p->ue_context.ul_failure_timer = 0;
  } else {
    LOG_E(RRC,"Frame %d, Subframe %d: UE %x unknown \n",
          frameP, subframeP, rntiP);
  }
}

//defined in L2_interface
int mac_eNB_get_rrc_status_NB_IoT(
  const module_id_t Mod_idP,
  const rnti_t      rntiP
)
{
  struct rrc_eNB_ue_context_NB_IoT_s* ue_context_p = NULL;
  ue_context_p = rrc_eNB_get_ue_context_NB_IoT(
                   &eNB_rrc_inst_NB_IoT[Mod_idP],
                   rntiP);

  if (ue_context_p != NULL) {
    return(ue_context_p->ue_context.Status);
  } else {
    return RRC_INACTIVE_NB_IoT;
  }
}


/*-----------------------------------MAC-RLC------------------------------------------*/

//-----------------------------------------------------------------------------
//defined in rlc_mac.c
void mac_rlc_data_ind_NB_IoT  (
  const module_id_t         module_idP,
  const rnti_t              rntiP,
  const module_id_t         eNB_index,
  const frame_t             frameP,
  const eNB_flag_t          enb_flagP,
//const MBMS_flag_t         MBMS_flagP,
  const logical_chan_id_t   channel_idP,
  char                     *buffer_pP,
  const tb_size_t           tb_sizeP,
  num_tb_t                  num_tbP, //number of transport block
  crc_t                    *crcs_pP)
{
  //-----------------------------------------------------------------------------
  rlc_mode_t             rlc_mode   = RLC_MODE_NONE;
  rlc_union_t           *rlc_union_p     = NULL;
  hash_key_t             key             = HASHTABLE_NOT_A_KEY_VALUE;
  hashtable_rc_t         h_rc;
  srb_flag_t             srb_flag        = (channel_idP <= 3) ? SRB_FLAG_YES : SRB_FLAG_NO;
  //srb1bis_flag_t         srb1bis_flag    = (channel_idP == 3) ? SRB1BIS_FLAG_YES : SRB1BIS_FLAG_NO; //may not needed?
  protocol_ctxt_t     ctxt;

  PROTOCOL_CTXT_SET_BY_MODULE_ID(&ctxt, module_idP, enb_flagP, rntiP, frameP, 0, eNB_index);

  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_MAC_RLC_DATA_IND,VCD_FUNCTION_IN);

  if(channel_idP == 2)
	  LOG_E(RLC, "mac_rlc_data_ind_NB_IoT over srb_id invalid (%d)\n", channel_idP);


#ifdef DEBUG_MAC_INTERFACE

  if (num_tbP) {
    LOG_D(RLC, PROTOCOL_CTXT_FMT" MAC_RLC_DATA_IND on channel %d (%d), rb max %d, Num_tb %d\n",
          PROTOCOL_CTXT_ARGS(&ctxt),
          channel_idP,
          RLC_MAX_LC,
		  NB_RB_MAX_NB_IOT,
          num_tbP);
  }

#endif // DEBUG_MAC_INTERFACE
#ifdef OAI_EMU


    AssertFatal (channel_idP < NB_RB_MAX_NB_IOT,        "channel id is too high (%u/%d)!\n",
                 channel_idP, NB_RB_MAX_NB_IOT);

  CHECK_CTXT_ARGS(&ctxt);

#endif

#if T_TRACER
  if (enb_flagP)
    T(T_ENB_RLC_MAC_UL, T_INT(module_idP), T_INT(rntiP), T_INT(channel_idP), T_INT(tb_sizeP));
#endif

  //no MBMS flag

  {
    key = RLC_COLL_KEY_LCID_VALUE(module_idP, rntiP, enb_flagP, channel_idP, srb_flag);
  }

  h_rc = hashtable_get(rlc_coll_p, key, (void**)&rlc_union_p);

  //MP: also for SRB1bis an RLC-AM mode should be configured
  if (h_rc == HASH_TABLE_OK) {
    rlc_mode = rlc_union_p->mode;
  } else {
    rlc_mode = RLC_MODE_NONE;
    //AssertFatal (0 , "%s RLC not configured rb id %u lcid %u module %u!\n", __FUNCTION__, rb_id, channel_idP, ue_module_idP);
  }

  struct mac_data_ind data_ind = mac_rlc_deserialize_tb(buffer_pP, tb_sizeP, num_tbP, crcs_pP);

  switch (rlc_mode) {
  case RLC_MODE_NONE:
    //handle_event(WARNING,"FILE %s FONCTION mac_rlc_data_ind() LINE %s : no radio bearer configured :%d\n", __FILE__, __LINE__, channel_idP);
    break;

  case RLC_MODE_AM:
    rlc_am_mac_data_indication_NB_IoT(&ctxt, &rlc_union_p->rlc.am, data_ind);
    break;

   //MP: no UM mode for NB_IoT

  case RLC_MODE_TM:
    rlc_tm_mac_data_indication(&ctxt, &rlc_union_p->rlc.tm, data_ind);
    break;

  default:
	  LOG_E(RLC,"mac_rlc_data_ind -> RLC mode unknown");
	break;
  }

  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_MAC_RLC_DATA_IND,VCD_FUNCTION_OUT);

}

//-----------------------------------------------------------------------------
//defined in rlc_am.c
void rlc_am_mac_data_indication_NB_IoT (
  const protocol_ctxt_t* const ctxt_pP,
  void * const                 rlc_pP,
  struct mac_data_ind          data_indP
)
{
  rlc_am_entity_t*           l_rlc_p = (rlc_am_entity_t*) rlc_pP;

#if TRACE_RLC_AM_PDU || MESSAGE_CHART_GENERATOR
  rlc_am_pdu_info_t   pdu_info;
  rlc_am_pdu_sn_10_t *rlc_am_pdu_sn_10_p;
  mem_block_t        *tb_p;
  sdu_size_t          tb_size_in_bytes;
  int                 num_nack;
  char                message_string[7000];
  size_t              message_string_size = 0;
#   if ENABLE_ITTI
  MessageDef         *msg_p;
#   endif
  int                 octet_index, index;
  /* for no gcc warnings */
  (void)num_nack;
  (void)message_string;
  (void)message_string_size;
  (void)octet_index;
  (void)index;
#endif

  (void)l_rlc_p; /* avoid gcc warning "unused variable" */

#if TRACE_RLC_AM_PDU || MESSAGE_CHART_GENERATOR

  if (data_indP.data.nb_elements > 0) {

    tb_p = data_indP.data.head;

    while (tb_p != NULL) {

      rlc_am_pdu_sn_10_p = (rlc_am_pdu_sn_10_t*)((struct mac_tb_ind *) (tb_p->data))->data_ptr;
      tb_size_in_bytes   = ((struct mac_tb_ind *) (tb_p->data))->size;

      if ((((struct mac_tb_ind *) (tb_p->data))->data_ptr[0] & RLC_DC_MASK) == RLC_DC_DATA_PDU ) {
        if (rlc_am_get_data_pdu_infos(ctxt_pP,l_rlc_p,rlc_am_pdu_sn_10_p, tb_size_in_bytes, &pdu_info) >= 0) {
#if MESSAGE_CHART_GENERATOR
          message_string_size = 0;
          message_string_size += sprintf(&message_string[message_string_size],
                                         MSC_AS_TIME_FMT" "PROTOCOL_RLC_AM_MSC_FMT" DATA SN %u size %u RF %u P %u FI %u",
                                         MSC_AS_TIME_ARGS(ctxt_pP),
                                         PROTOCOL_RLC_AM_MSC_ARGS(ctxt_pP, l_rlc_p),
                                         pdu_info.sn,
                                         tb_size_in_bytes,
                                         pdu_info.rf,
                                         pdu_info.p,
                                         pdu_info.fi);

          if (pdu_info.rf) {
            message_string_size += sprintf(&message_string[message_string_size], " LSF %u\n", pdu_info.lsf);
            message_string_size += sprintf(&message_string[message_string_size], " SO %u\n", pdu_info.so);
          }

          if (pdu_info.e) {
            message_string_size += sprintf(&message_string[message_string_size], "| HE:");

            for (index=0; index < pdu_info.num_li; index++) {
              message_string_size += sprintf(&message_string[message_string_size], " LI %u", pdu_info.li_list[index]);
            }
          }

          MSC_LOG_RX_MESSAGE(
            (ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
            (ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_UE:MSC_RLC_ENB,
            (char*)rlc_am_pdu_sn_10_p,
            tb_size_in_bytes,
            message_string);

#endif

#   if ENABLE_ITTI && TRACE_RLC_AM_PDU
          message_string_size += sprintf(&message_string[message_string_size], "Bearer      : %u\n", l_rlc_p->rb_id);
          message_string_size += sprintf(&message_string[message_string_size], "PDU size    : %u\n", tb_size_in_bytes);
          message_string_size += sprintf(&message_string[message_string_size], "Header size : %u\n", pdu_info.header_size);
          message_string_size += sprintf(&message_string[message_string_size], "Payload size: %u\n", pdu_info.payload_size);

          if (pdu_info.rf) {
            message_string_size += sprintf(&message_string[message_string_size], "PDU type    : RLC AM DATA IND: AMD PDU segment\n\n");
          } else {
            message_string_size += sprintf(&message_string[message_string_size], "PDU type    : RLC AM DATA IND: AMD PDU\n\n");
          }

          message_string_size += sprintf(&message_string[message_string_size], "Header      :\n");
          message_string_size += sprintf(&message_string[message_string_size], "  D/C       : %u\n", pdu_info.d_c);
          message_string_size += sprintf(&message_string[message_string_size], "  RF        : %u\n", pdu_info.rf);
          message_string_size += sprintf(&message_string[message_string_size], "  P         : %u\n", pdu_info.p);
          message_string_size += sprintf(&message_string[message_string_size], "  FI        : %u\n", pdu_info.fi);
          message_string_size += sprintf(&message_string[message_string_size], "  E         : %u\n", pdu_info.e);
          message_string_size += sprintf(&message_string[message_string_size], "  SN        : %u\n", pdu_info.sn);

          if (pdu_info.rf) {
            message_string_size += sprintf(&message_string[message_string_size], "  LSF       : %u\n", pdu_info.lsf);
            message_string_size += sprintf(&message_string[message_string_size], "  SO        : %u\n", pdu_info.so);
          }

          if (pdu_info.e) {
            message_string_size += sprintf(&message_string[message_string_size], "\nHeader extension  : \n");

            for (index=0; index < pdu_info.num_li; index++) {
              message_string_size += sprintf(&message_string[message_string_size], "  LI        : %u\n", pdu_info.li_list[index]);
            }
          }

          message_string_size += sprintf(&message_string[message_string_size], "\nPayload  : \n");
          message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");
          message_string_size += sprintf(&message_string[message_string_size], "      |  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f |\n");
          message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");

          for (octet_index = 0; octet_index < pdu_info.payload_size; octet_index++) {
            if ((octet_index % 16) == 0) {
              if (octet_index != 0) {
                message_string_size += sprintf(&message_string[message_string_size], " |\n");
              }

              message_string_size += sprintf(&message_string[message_string_size], " %04d |", octet_index);
            }

            /*
             * Print every single octet in hexadecimal form
             */
            message_string_size += sprintf(&message_string[message_string_size], " %02x", pdu_info.payload[octet_index]);
            /*
             * Align newline and pipes according to the octets in groups of 2
             */
          }

          /*
           * Append enough spaces and put final pipe
           */
          for (index = octet_index; index < 16; ++index) {
            message_string_size += sprintf(&message_string[message_string_size], "   ");
          }

          message_string_size += sprintf(&message_string[message_string_size], " |\n");

          msg_p = itti_alloc_new_message_sized (ctxt_pP->enb_flag > 0 ? TASK_RLC_ENB:TASK_RLC_UE , RLC_AM_DATA_PDU_IND, message_string_size + sizeof (IttiMsgText));
          msg_p->ittiMsg.rlc_am_data_pdu_ind.size = message_string_size;
          memcpy(&msg_p->ittiMsg.rlc_am_data_pdu_ind.text, message_string, message_string_size);

          itti_send_msg_to_task(TASK_UNKNOWN, ctxt_pP->instance, msg_p);

# else
          rlc_am_display_data_pdu_infos(ctxt_pP, l_rlc_p, &pdu_info);
# endif
        }
      } else {
        if (rlc_am_get_control_pdu_infos(rlc_am_pdu_sn_10_p, &tb_size_in_bytes, &l_rlc_p->control_pdu_info) >= 0) {
#if MESSAGE_CHART_GENERATOR
          message_string_size = 0;
          message_string_size += sprintf(&message_string[message_string_size],
                                         MSC_AS_TIME_FMT" "PROTOCOL_RLC_AM_MSC_FMT" STATUS size ACK_SN %u",
                                         MSC_AS_TIME_ARGS(ctxt_pP),
                                         PROTOCOL_RLC_AM_MSC_ARGS(ctxt_pP, l_rlc_p),
                                         l_rlc_p->control_pdu_info.ack_sn);

          for (num_nack = 0; num_nack < l_rlc_p->control_pdu_info.num_nack; num_nack++) {
            if (l_rlc_p->control_pdu_info.nack_list[num_nack].e2) {
              message_string_size += sprintf(&message_string[message_string_size], "  NACK SN %u SO START %u SO END %u",
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].nack_sn,
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].so_start,
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].so_end);

            } else {
              message_string_size += sprintf(&message_string[message_string_size], "  NACK SN %u",
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].nack_sn);
            }
          }

          MSC_LOG_RX_MESSAGE(
            (ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
            (ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_UE:MSC_RLC_ENB,
            (char*)rlc_am_pdu_sn_10_p,
            tb_size_in_bytes,
            message_string);

#endif

#   if ENABLE_ITTI && TRACE_RLC_AM_PDU
          message_string_size = 0;
          message_string_size += sprintf(&message_string[message_string_size], "Bearer      : %u\n", l_rlc_p->rb_id);
          message_string_size += sprintf(&message_string[message_string_size], "PDU size    : %u\n", ((struct mac_tb_ind *) (tb_p->data))->size);
          message_string_size += sprintf(&message_string[message_string_size], "PDU type    : RLC AM DATA IND: STATUS PDU\n\n");
          message_string_size += sprintf(&message_string[message_string_size], "Header      :\n");
          message_string_size += sprintf(&message_string[message_string_size], "  D/C       : %u\n", l_rlc_p->control_pdu_info.d_c);
          message_string_size += sprintf(&message_string[message_string_size], "  CPT       : %u\n", l_rlc_p->control_pdu_info.cpt);
          message_string_size += sprintf(&message_string[message_string_size], "  ACK_SN    : %u\n", l_rlc_p->control_pdu_info.ack_sn);
          message_string_size += sprintf(&message_string[message_string_size], "  E1        : %u\n", l_rlc_p->control_pdu_info.e1);

          for (num_nack = 0; num_nack < l_rlc_p->control_pdu_info.num_nack; num_nack++) {
            if (l_rlc_p->control_pdu_info.nack_list[num_nack].e2) {
              message_string_size += sprintf(&message_string[message_string_size], "  NACK SN %04d SO START %05d SO END %05d",
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].nack_sn,
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].so_start,
                                             l_rlc_p->control_pdu_info.nack_list[num_nack].so_end);
            } else {
              message_string_size += sprintf(&message_string[message_string_size], "  NACK SN %04d",  l_rlc_p->control_pdu_info.nack_list[num_nack].nack_sn);
            }
          }

          msg_p = itti_alloc_new_message_sized (ctxt_pP->enb_flag > 0 ? TASK_RLC_ENB:TASK_RLC_UE , RLC_AM_STATUS_PDU_IND, message_string_size + sizeof (IttiMsgText));
          msg_p->ittiMsg.rlc_am_status_pdu_ind.size = message_string_size;
          memcpy(&msg_p->ittiMsg.rlc_am_status_pdu_ind.text, message_string, message_string_size);

          itti_send_msg_to_task(TASK_UNKNOWN, ctxt_pP->instance, msg_p);

#   endif
        }
      }

      tb_p = tb_p->next;
    }
  }

#endif
  rlc_am_rx (ctxt_pP, rlc_pP, data_indP);
}

//-----------------------------------------------------------------------------
//defined in rlc_mac.c
//called by the schedule_ue_spec for getting SDU to be transmitted from SRB1/SRB1bis and DRBs
tbs_size_t mac_rlc_data_req_eNB_NB_IoT(
  const module_id_t       module_idP,
  const rnti_t            rntiP,
  const eNB_index_t       eNB_index,
  const frame_t           frameP,
  const MBMS_flag_t       MBMS_flagP,
  const logical_chan_id_t channel_idP,
  char             *buffer_pP)
{
  //-----------------------------------------------------------------------------
  struct mac_data_req    data_request;
  rlc_mode_t             rlc_mode        = RLC_MODE_NONE;
  rlc_union_t           *rlc_union_p     = NULL;
  hash_key_t             key             = HASHTABLE_NOT_A_KEY_VALUE;
  hashtable_rc_t         h_rc;
  srb_flag_t             srb_flag        = (channel_idP <= 3) ? SRB_FLAG_YES : SRB_FLAG_NO;
  //srb1bis_flag_t			srb1bis_flag = (channel_idP == 3) ? SRB1BIS_FLAG_YES : SRB1BIS_FLAG_NO;
  tbs_size_t             ret_tb_size         = 0;
  protocol_ctxt_t     ctxt;

  PROTOCOL_CTXT_SET_BY_MODULE_ID(&ctxt, module_idP, ENB_FLAG_YES, rntiP, frameP, 0,eNB_index);

  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_MAC_RLC_DATA_REQ,VCD_FUNCTION_IN);

  if(channel_idP == 2)
  	  LOG_E(RLC, "mac_rlc_data_req_eNB_NB_IoT over srb_id invalid (%d)\n", channel_idP);


#ifdef DEBUG_MAC_INTERFACE
  LOG_D(RLC, PROTOCOL_CTXT_FMT" MAC_RLC_DATA_REQ channel %d (%d) MAX RB %d, Num_tb %d\n",
        PROTOCOL_CTXT_ARGS((&ctxt)),
        channel_idP,
        RLC_MAX_LC,
        NB_RB_MAX);

#endif // DEBUG_MAC_INTERFACE

  { //SRB1 or DRBs
    AssertFatal (channel_idP < NB_RB_MAX_NB_IOT,        "channel id is too high (%u/%d)!\n",     channel_idP, NB_RB_MAX);
  }

#ifdef OAI_EMU
  CHECK_CTXT_ARGS(&ctxt);
  //printf("MBMS_flagP %d, MBMS_FLAG_NO %d \n",MBMS_flagP, MBMS_FLAG_NO);
  //  AssertFatal (MBMS_flagP == MBMS_FLAG_NO ," MBMS FLAG SHOULD NOT BE SET IN mac_rlc_data_req in UE\n");

#endif

  //no MBMS in NB-IoT

  {
    key = RLC_COLL_KEY_LCID_VALUE(module_idP, rntiP, ENB_FLAG_YES, channel_idP, srb_flag);
  }

  h_rc = hashtable_get(rlc_coll_p, key, (void**)&rlc_union_p);

  if (h_rc == HASH_TABLE_OK) {
    rlc_mode = rlc_union_p->mode;
  } else {
    rlc_mode = RLC_MODE_NONE;
    AssertFatal (0 , "mac_rlc_data req --> RLC not configured lcid %u RNTI %x!\n", channel_idP, rntiP);
  }

  switch (rlc_mode) {
  case RLC_MODE_NONE:
    ret_tb_size =0;
    break;

  case RLC_MODE_AM:
    data_request = rlc_am_mac_data_request(&ctxt, &rlc_union_p->rlc.am, ENB_FLAG_YES);
    ret_tb_size =mac_rlc_serialize_tb(buffer_pP, data_request.data);
    break;

    //UM mode not for NB-IoT

  case RLC_MODE_TM:
    data_request = rlc_tm_mac_data_request(&ctxt, &rlc_union_p->rlc.tm);
    ret_tb_size = mac_rlc_serialize_tb(buffer_pP, data_request.data);
    break;

  default:
    ;
  }

#if T_TRACER
  if (enb_flagP)
    T(T_ENB_RLC_MAC_DL, T_INT(module_idP), T_INT(rntiP), T_INT(channel_idP), T_INT(ret_tb_size));
#endif

  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_MAC_RLC_DATA_REQ,VCD_FUNCTION_OUT);
  return ret_tb_size;
}

