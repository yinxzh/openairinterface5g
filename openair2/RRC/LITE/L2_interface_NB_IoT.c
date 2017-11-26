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
