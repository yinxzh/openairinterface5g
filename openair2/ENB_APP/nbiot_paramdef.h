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

/*! \file openair2/ENB_APP/enb_paramdef.f
 * \brief definition of configuration parameters for all eNodeB modules 
 * \author Francois TABURET
 * \date 2017
 * \version 0.1
 * \company NOKIA BellLabs France
 * \email: francois.taburet@nokia-bell-labs.com
 * \note
 * \warning
 */

#include "common/config/config_paramdesc.h"









		  

/* NB-Iot section name */		
#define NBIOT_RRCLIST_CONFIG_STRING                                         "NB-IoT_RRCs"		 


		
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*                                     component carriers configuration parameters                                                                                                     */
/*   optname                                                   helpstr   paramflags    XXXptr                                        defXXXval                    type         numelt  */
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define NBIOTRRCPARAMS_DESC { \
{"rach_raResponseWindowSize_NB",                               NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"rach_macContentionResolutionTimer_NB",                       NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"rach_powerRampingStep_NB",                                   NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"rach_preambleInitialReceivedTargetPower_NB",                 NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"rach_preambleTransMax_CE_NB",                                NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"bcch_modificationPeriodCoeff_NB",                            NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"pcch_defaultPagingCycle_NB",                                 NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_CP_Length",                                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_rsrp_range",                                          NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_Periodicity",                                         NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_StartTime",                                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_SubcarrierOffset",                                    NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_NumSubcarriers",                                      NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"nprach_SubcarrierMSG3_RangeStart",                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"maxNumPreambleAttemptCE_NB",                                 NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"numRepetitionsPerPreambleAttempt_NB",                        NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npdcch_NumRepetitions_RA",                                   NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npdcch_StartSF_CSS_RA",                                      NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npdcch_Offset_RA",                                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npdsch_nrs_Power",                                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_ack_nack_numRepetitions_NB",                          NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_srs_SubframeConfig_NB",                               NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_threeTone_CyclicShift_r13",                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_sixTone_CyclicShift_r13",                             NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_groupHoppingEnabled",                                 NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_groupAssignmentNPUSCH_r13",                           NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"dl_GapThreshold_NB",                                         NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"dl_GapPeriodicity_NB",                                       NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"dl_GapDurationCoeff_NB",                                     NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_p0_NominalNPUSCH",                                    NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"npusch_alpha",                                               NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"deltaPreambleMsg3",                                          NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_t300_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_t301_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_t310_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_t311_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_n310_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
{"ue_TimersAndConstants_n311_NB",                              NULL,   0,              uptr:NULL,                                    defintval:0,	    TYPE_UINT,       0},  \
}								    

#define NBIOT_RACH_RARESPONSEWINDOWSIZE_NB_IDX                         0	   
#define NBIOT_RACH_MACCONTENTIONRESOLUTIONTIMER_NB_IDX                 1
#define NBIOT_RACH_POWERRAMPINGSTEP_NB_IDX                             2
#define NBIOT_RACH_PREAMBLEINITIALRECEIVEDTARGETPOWER_NB_IDX           3
#define NBIOT_RACH_PREAMBLETRANSMAX_CE_NB_IDX                          4		   
#define NBIOT_BCCH_MODIFICATIONPERIODCOEFF_NB_IDX                      5
#define NBIOT_PCCH_DEFAULTPAGINGCYCLE_NB_IDX                           6
#define NBIOT_NPRACH_CP_LENGTH_IDX                                     7
#define NBIOT_NPRACH_RSRP_RANGE_IDX                                    8
#define NBIOT_NPRACH_PERIODICITY_IDX                                   9
#define NBIOT_NPRACH_STARTTIME_IDX                                     10
#define NBIOT_NPRACH_SUBCARRIEROFFSET_IDX                              11
#define NBIOT_NPRACH_NUMSUBCARRIERS_IDX                                12
#define NBIOT_NPRACH_SUBCARRIERMSG3_RANGESTART_IDX                     13
#define NBIOT_MAXNUMPREAMBLEATTEMPTCE_NB_IDX                           14
#define NBIOT_NUMREPETITIONSPERPREAMBLEATTEMPT_NB_IDX                  15
#define NBIOT_NPDCCH_NUMREPETITIONS_RA_IDX                             16
#define NBIOT_NPDCCH_STARTSF_CSS_RA_IDX                                17
#define NBIOT_NPDCCH_OFFSET_RA_IDX                                     18
#define NBIOT_NPDSCH_NRS_POWER_IDX                                     19
#define NBIOT_NPUSCH_ACK_NACK_NUMREPETITIONS_NB_IDX                    20
#define NBIOT_NPUSCH_SRS_SUBFRAMECONFIG_NB_IDX                         21
#define NBIOT_NPUSCH_THREETONE_CYCLICSHIFT_R13_IDX                     22
#define NBIOT_NPUSCH_SIXTONE_CYCLICSHIFT_R13_IDX                       23
#define NBIOT_NPUSCH_GROUPHOPPINGENABLED_IDX                           24
#define NBIOT_NPUSCH_GROUPASSIGNMENTNPUSCH_R13_IDX                     25
#define NBIOT_DL_GAPTHRESHOLD_NB_IDX                                   26
#define NBIOT_DL_GAPPERIODICITY_NB_IDX                                 27
#define NBIOT_DL_GAPDURATIONCOEFF_NB_IDX                               28
#define NBIOT_NPUSCH_P0_NOMINALNPUSCH_IDX                              29
#define NBIOT_NPUSCH_ALPHA_IDX                                         30
#define NBIOT_DELTAPREAMBLEMSG3_IDX                                    31
#define NBIOT_UE_TIMERSANDCONSTANTS_T300_NB_IDX                        32
#define NBIOT_UE_TIMERSANDCONSTANTS_T301_NB_IDX                        33
#define NBIOT_UE_TIMERSANDCONSTANTS_T310_NB_IDX                        34
#define NBIOT_UE_TIMERSANDCONSTANTS_T311_NB_IDX                        35
#define NBIOT_UE_TIMERSANDCONSTANTS_N310_NB_IDX                        36
#define NBIOT_UE_TIMERSANDCONSTANTS_N311_NB_IDX                        37



/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
