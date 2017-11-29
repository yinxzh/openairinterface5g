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
		  

/* NB-Iot RRC list section name */		
#define NBIOT_RRCLIST_CONFIG_STRING          "NB-IoT_RRCs"		 


#define RACH_RARESPONSEWINDOWSIZE_NB_OKVALUES                   {20,50,80,120,180,240,320,400}
#define RACH_MACCONTENTIONRESOLUTIONTIMER_NB_OKVALUES           {80,100,120,160,200,240,480,960}  
#define RACH_POWERRAMPINGSTEP_NB_OKVALUES                       {0,2,4,6}
#define RACH_PREAMBLEINITIALRECEIVEDTARGETPOWER_NB_OKRANGE      {-120, -90}
#define RACH_PREAMBLETRANSMAX_CE_NB_OKVALUES                    {3,4,5,6,7,8,10,20,50,100,200}
#define BCCH_MODIFICATIONPERIODCOEFF_NB_OKVALUES
#define PCCH_DEFAULTPAGINGCYCLE_NB_OKVALUES
#define NPRACH_CP_LENGTH_OKVALUES                               {0,1}
#define NPRACH_RSRP_RANGE_OKVALUES
#define NPRACH_SUBCARRIERMSG3_RANGESTART_OKVALUES               {"zero","oneThird","twoThird","one"}
#define MAXNUMPREAMBLEATTEMPTCE_NB_OKVALUES                     {3,4,5,6,7,8,10}
#define NPDCCH_NUMREPETITIONS_RA_OKVALUES                       {1,2,4,8,16,32,64,128}
#define NPDCCH_STARTSF_CSS_RA_OKVALUES                          {1.5,2,4,8,16,32,48,64}
#define NPDCCH_OFFSET_RA_OKVALUES                               {"zero","oneEighth","oneFourth","threeEighth"}
#define NPDSCH_NRS_POWER_OKRANGE                                {-60,50}
#define NPUSCH_ACK_NACK_NUMREPETITIONS_NB_OKVALUES
#define NPUSCH_SRS_SUBFRAMECONFIG_NB_OKRANGE                    {0,15}
#define NPUSCH_THREETONE_CYCLICSHIFT_R13_OKRANGE                {0,2}
#define NPUSCH_SIXTONE_CYCLICSHIFT_R13_OKRANGE                  {0,3}
#define NPUSCH_GROUPHOPPINGENABLED_OKVALUES
#define NPUSCH_GROUPASSIGNMENTNPUSCH_R13_OKRANGE                {0,29}
#define DL_GAPTHRESHOLD_NB_OKVALUES                             {32,64,128,256}
#define DL_GAPPERIODICITY_NB_OKVALUES                           {64,128,256,512}
#define DL_GAPDURATIONCOEFF_NB_OKVALUES                         {"oneEighth","oneFourth","threeEighth","oneHalf"}
#define NPUSCH_P0_NOMINALNPUSCH_OKRANGE                         {-128,24}
#define NPUSCH_ALPHA_OKVALUES                                   {0,4,5,10} //?? to be checked
#define DELTAPREAMBLEMSG3_OKRANGE                               {-1,6}	

#define NBIOT_RRCPARAMS_CHECK_DESC { \
             {f1:config_check_intval,{RACH_RARESPONSEWINDOWSIZE_NB_OKVALUES,8}} ,             \
             {f1:config_check_intval,{RACH_MACCONTENTIONRESOLUTIONTIMER_NB_OKVALUES,8}} ,     \
}
	
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/*                                                           component carriers configuration parameters                                   */
/*   optname                                       helpstr   paramflags    XXXptr	 defXXXval		      type	   numelt  */
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
#define NBIOTRRCPARAMS_DESC { \
{"rach_raResponseWindowSize_NB",                   NULL,   0,		   uptr:NULL,	 defintval:20,  	TYPE_UINT,	 0},  \
{"rach_macContentionResolutionTimer_NB",           NULL,   0,		   uptr:NULL,	 defintval:80,  	TYPE_UINT,	 0},  \
{"rach_powerRampingStep_NB",                       NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"rach_preambleInitialReceivedTargetPower_NB",     NULL,   0,		   iptr:NULL,	 defintval:-112,	TYPE_UINT,	 0},  \
{"rach_preambleTransMax_CE_NB",                    NULL,   0,		   uptr:NULL,	 defintval:3,		TYPE_UINT,	 0},  \
{"bcch_modificationPeriodCoeff_NB",                NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"pcch_defaultPagingCycle_NB",                     NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"nprach_CP_Length",                               NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"nprach_rsrp_range",                              NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"nprach_SubcarrierMSG3_RangeStart",               NULL,   0,		   strptr:NULL,  defstrval:"one",	TYPE_STRING,	 0},  \
{"maxNumPreambleAttemptCE_NB",                     NULL,   0,		   uptr:NULL,	 defintval:10,  	TYPE_UINT,	 0},  \
{"npdcch_NumRepetitions_RA",                       NULL,   0,		   uptr:NULL,	 defintval:4,		TYPE_UINT,	 0},  \
{"npdcch_StartSF_CSS_RA",                          NULL,   0,		   uptr:NULL,	 defintval:2,		TYPE_UINT,	 0},  \
{"npdcch_Offset_RA",                               NULL,   0,		   strptr:NULL,  defstrval:"zero",	TYPE_STRING,	 0},  \
{"npdsch_nrs_Power",                               NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"npusch_ack_nack_numRepetitions_NB",              NULL,   0,		   uptr:NULL,	 defintval:1,		TYPE_UINT,	 0},  \
{"npusch_srs_SubframeConfig_NB",                   NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"npusch_threeTone_CyclicShift_r13",               NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"npusch_sixTone_CyclicShift_r13",                 NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"npusch_groupHoppingEnabled",                     NULL,   PARAMFLAG_BOOL, uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"npusch_groupAssignmentNPUSCH_r13",               NULL,   0,		   uptr:NULL,	 defintval:0,		TYPE_UINT,	 0},  \
{"dl_GapThreshold_NB",                             NULL,   0,		   uptr:NULL,	 defintval:32,  	TYPE_UINT,	 0},  \
{"dl_GapPeriodicity_NB",                           NULL,   0,		   uptr:NULL,	 defintval:64,  	TYPE_UINT,	 0},  \
{"dl_GapDurationCoeff_NB",                         NULL,   0,		   strptr:NULL,  defstrval:"oneEighth", TYPE_STRING,	 0},  \
{"npusch_p0_NominalNPUSCH",                        NULL,   0,		   iptr:NULL,	 defintval:0,		TYPE_INT32,	 0},  \
{"npusch_alpha",                                   NULL,   0,		   uptr:NULL,	 defintval:10,  	TYPE_UINT,	 0},  \
{"deltaPreambleMsg3",                              NULL,   0,		   iptr:NULL,	 defintval:0,		TYPE_INT32,	 0},  \
{"ue_TimersAndConstants_t300_NB",                  NULL,   0,		   uptr:NULL,	 defintval:1000,	TYPE_UINT,	 0},  \
{"ue_TimersAndConstants_t301_NB",                  NULL,   0,		   uptr:NULL,	 defintval:1000,	TYPE_UINT,	 0},  \
{"ue_TimersAndConstants_t310_NB",                  NULL,   0,		   uptr:NULL,	 defintval:1000,	TYPE_UINT,	 0},  \
{"ue_TimersAndConstants_t311_NB",                  NULL,   0,		   uptr:NULL,	 defintval:10000,	TYPE_UINT,	 0},  \
{"ue_TimersAndConstants_n310_NB",                  NULL,   0,		   uptr:NULL,	 defintval:20,  	TYPE_UINT,	 0},  \
{"ue_TimersAndConstants_n311_NB",                  NULL,   0,		   uptr:NULL,	 defintval:1,		TYPE_UINT,	 0},  \
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
#define NBIOT_NPRACH_SUBCARRIERMSG3_RANGESTART_IDX                     9
#define NBIOT_MAXNUMPREAMBLEATTEMPTCE_NB_IDX                           10
#define NBIOT_NPDCCH_NUMREPETITIONS_RA_IDX                             11
#define NBIOT_NPDCCH_STARTSF_CSS_RA_IDX                                12
#define NBIOT_NPDCCH_OFFSET_RA_IDX                                     13
#define NBIOT_NPDSCH_NRS_POWER_IDX                                     14
#define NBIOT_NPUSCH_ACK_NACK_NUMREPETITIONS_NB_IDX                    15
#define NBIOT_NPUSCH_SRS_SUBFRAMECONFIG_NB_IDX                         16
#define NBIOT_NPUSCH_THREETONE_CYCLICSHIFT_R13_IDX                     17
#define NBIOT_NPUSCH_SIXTONE_CYCLICSHIFT_R13_IDX                       18
#define NBIOT_NPUSCH_GROUPHOPPINGENABLED_IDX                           19
#define NBIOT_NPUSCH_GROUPASSIGNMENTNPUSCH_R13_IDX                     20
#define NBIOT_DL_GAPTHRESHOLD_NB_IDX                                   21
#define NBIOT_DL_GAPPERIODICITY_NB_IDX                                 22
#define NBIOT_DL_GAPDURATIONCOEFF_NB_IDX                               23
#define NBIOT_NPUSCH_P0_NOMINALNPUSCH_IDX                              24
#define NBIOT_NPUSCH_ALPHA_IDX                                         25
#define NBIOT_DELTAPREAMBLEMSG3_IDX                                    26
#define NBIOT_UE_TIMERSANDCONSTANTS_T300_NB_IDX                        27
#define NBIOT_UE_TIMERSANDCONSTANTS_T301_NB_IDX                        28
#define NBIOT_UE_TIMERSANDCONSTANTS_T310_NB_IDX                        29
#define NBIOT_UE_TIMERSANDCONSTANTS_T311_NB_IDX                        30
#define NBIOT_UE_TIMERSANDCONSTANTS_N310_NB_IDX                        31
#define NBIOT_UE_TIMERSANDCONSTANTS_N311_NB_IDX                        32




#define NBIOT_RRCLIST_NPRACHPARAMS_CONFIG_STRING        "NPRACH-NB-r13"
/*------------------------------------------------------------------------------------------------------------------------------*/
/* NB-IoT NPrach parameters, there will be three ocuurences of these parameters in each RRC instance                            */
 /*   optname                                helpstr   paramflags    XXXptr	 defXXXval		  type	        numelt  */
/*------------------------------------------------------------------------------------------------------------------------------*/
#define NBIOTRRC_NPRACH_PARAMS_DESC { \
{"nprach_Periodicity",                        NULL,   0,            uptr:NULL,     defintval:320,	  TYPE_UINT,	   0},  \
{"nprach_StartTime",                          NULL,   0,            uptr:NULL,     defintval:8, 	  TYPE_UINT,	   0},  \
{"nprach_SubcarrierOffset",                   NULL,   0,            uptr:NULL,     defintval:0, 	  TYPE_UINT,	   0},  \
{"nprach_NumSubcarriers",                     NULL,   0,            uptr:NULL,     defintval:12,	  TYPE_UINT,	   0},  \
{"numRepetitionsPerPreambleAttempt_NB",       NULL,   0,            uptr:NULL,     defintval:2, 	  TYPE_UINT,	   0},  \
}
#define NPRACH_PERIODICITY_OKVALUES                             {40,80,160,240,320,640,1280,2560}
#define NPRACH_STARTTIME_OKVALUES                               {8,16,32,64,128,256,512,1024}
#define NPRACH_SUBCARRIEROFFSET_OKVALUES                        {0,12,24,36,2,18,34}
#define NPRACH_NUMSUBCARRIERS_OKVALUES                          {12,24,36,48}
#define NUMREPETITIONSPERPREAMBLEATTEMPT_NB_OKVALUES            {1,2,4,8,16,32,64,128}

#define NBIOT_NPRACH_PERIODICITY_IDX                                   0
#define NBIOT_NPRACH_STARTTIME_IDX                                     1
#define NBIOT_NPRACH_SUBCARRIEROFFSET_IDX                              2
#define NBIOT_NPRACH_NUMSUBCARRIERS_IDX                                3
#define NBIOT_NUMREPETITIONSPERPREAMBLEATTEMPT_NB_IDX                  4

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* NB IoT MACRLC configuration list section name   */
#define NBIOT_MACRLCLIST_CONFIG_STRING                          "NB-IoT_MACRLCs"


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* NB IoT L1 configuration list section name   */
#define NBIOT_L1LIST_CONFIG_STRING                          "NB-IoT_L1s"