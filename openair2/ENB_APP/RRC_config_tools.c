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
  RRC_config_tools.c
  -------------------
  AUTHOR  : Francois TABURET
  COMPANY : NOKIA BellLabs France
  EMAIL   : francois.taburet@nokia-bell-labs.com 

*/

#include <string.h>
#include <inttypes.h>

#include "log.h"
#include "log_extern.h"
#include "assertions.h"
#if defined(ENABLE_ITTI)
# include "intertask_interface.h"
# if defined(ENABLE_USE_MME)
#   include "s1ap_eNB.h"
#   include "sctp_eNB_task.h"
# endif
#endif
#include "SystemInformationBlockType2.h"
#include "common/config/config_userapi.h"
#include "RRC_config_tools.h"
#include "DL-GapConfig-NB-r13.h"
#include "NPRACH-Parameters-NB-r13.h"
static const eutra_band_t eutra_bands[] = {
  { 1, 1920    * MHz, 1980    * MHz, 2110    * MHz, 2170    * MHz, FDD},
  { 2, 1850    * MHz, 1910    * MHz, 1930    * MHz, 1990    * MHz, FDD},
  { 3, 1710    * MHz, 1785    * MHz, 1805    * MHz, 1880    * MHz, FDD},
  { 4, 1710    * MHz, 1755    * MHz, 2110    * MHz, 2155    * MHz, FDD},
  { 5,  824    * MHz,  849    * MHz,  869    * MHz,  894    * MHz, FDD},
  { 6,  830    * MHz,  840    * MHz,  875    * MHz,  885    * MHz, FDD},
  { 7, 2500    * MHz, 2570    * MHz, 2620    * MHz, 2690    * MHz, FDD},
  { 8,  880    * MHz,  915    * MHz,  925    * MHz,  960    * MHz, FDD},
  { 9, 1749900 * KHz, 1784900 * KHz, 1844900 * KHz, 1879900 * KHz, FDD},
  {10, 1710    * MHz, 1770    * MHz, 2110    * MHz, 2170    * MHz, FDD},
  {11, 1427900 * KHz, 1452900 * KHz, 1475900 * KHz, 1500900 * KHz, FDD},
  {12,  698    * MHz,  716    * MHz,  728    * MHz,  746    * MHz, FDD},
  {13,  777    * MHz,  787    * MHz,  746    * MHz,  756    * MHz, FDD},
  {14,  788    * MHz,  798    * MHz,  758    * MHz,  768    * MHz, FDD},

  {17,  704    * MHz,  716    * MHz,  734    * MHz,  746    * MHz, FDD},
  {20,  832    * MHz,  862    * MHz,  791    * MHz,  821    * MHz, FDD},
  {33, 1900    * MHz, 1920    * MHz, 1900    * MHz, 1920    * MHz, TDD},
  {33, 1900    * MHz, 1920    * MHz, 1900    * MHz, 1920    * MHz, TDD},
  {34, 2010    * MHz, 2025    * MHz, 2010    * MHz, 2025    * MHz, TDD},
  {35, 1850    * MHz, 1910    * MHz, 1850    * MHz, 1910    * MHz, TDD},
  {36, 1930    * MHz, 1990    * MHz, 1930    * MHz, 1990    * MHz, TDD},
  {37, 1910    * MHz, 1930    * MHz, 1910    * MHz, 1930    * MHz, TDD},
  {38, 2570    * MHz, 2620    * MHz, 2570    * MHz, 2630    * MHz, TDD},
  {39, 1880    * MHz, 1920    * MHz, 1880    * MHz, 1920    * MHz, TDD},
  {40, 2300    * MHz, 2400    * MHz, 2300    * MHz, 2400    * MHz, TDD},
  {41, 2496    * MHz, 2690    * MHz, 2496    * MHz, 2690    * MHz, TDD},
  {42, 3400    * MHz, 3600    * MHz, 3400    * MHz, 3600    * MHz, TDD},
  {43, 3600    * MHz, 3800    * MHz, 3600    * MHz, 3800    * MHz, TDD},
  {44, 703    * MHz, 803    * MHz, 703    * MHz, 803    * MHz, TDD},
};


int config_check_band_frequencies(    int ind,
                                      int16_t band,
                                      uint32_t downlink_frequency,
                                      int32_t uplink_frequency_offset,
                                      uint32_t  frame_type)
{
  int errors = 0;

  if (band > 0) {
    int band_index;

    for (band_index = 0; band_index < sizeof (eutra_bands) / sizeof (eutra_bands[0]); band_index++) {
      if (band == eutra_bands[band_index].band) {
        uint32_t uplink_frequency = downlink_frequency + uplink_frequency_offset;

        AssertError (eutra_bands[band_index].dl_min < downlink_frequency, errors ++,
                     "enb %d downlink frequency %u too low (%u) for band %d!",
                     ind, downlink_frequency, eutra_bands[band_index].dl_min, band);
        AssertError (downlink_frequency < eutra_bands[band_index].dl_max, errors ++,
                     "enb %d downlink frequency %u too high (%u) for band %d!",
                     ind, downlink_frequency, eutra_bands[band_index].dl_max, band);

        AssertError (eutra_bands[band_index].ul_min < uplink_frequency, errors ++,
                     "enb %d uplink frequency %u too low (%u) for band %d!",
                     ind, uplink_frequency, eutra_bands[band_index].ul_min, band);
        AssertError (uplink_frequency < eutra_bands[band_index].ul_max, errors ++,
                     "enb %d uplink frequency %u too high (%u) for band %d!",
                     ind, uplink_frequency, eutra_bands[band_index].ul_max, band);

        AssertError (eutra_bands[band_index].frame_type == frame_type, errors ++,
                     "enb %d invalid frame type (%d/%d) for band %d!",
                     ind, eutra_bands[band_index].frame_type, frame_type, band);
      }
    }
  }


  return errors;
}






int config_check_assign_integer(paramdef_t *param, int *cfgokvalues, int *assignedvalues, int numokval)
{
int cfgvalue ;
char okvalstr[255];
char *astrptr=okvalstr;

    cfgvalue =*(param->uptr);
    okvalstr[0]=0;
    for (int i=0; i < numokval ; i++) {
    	astrptr += sprintf(astrptr,"%i ",cfgokvalues[i]);
    	if (cfgvalue == cfgokvalues [i] ) {
    	    *(param->uptr) = assignedvalues[i];
            printf_params("[RRCCONFIG] %s:  set to %i\n",param->optname,*(param->uptr));
    	    return 0; 
    	}
   }
   LOG_E(RRC," %s, unknown value \"%d\" authorised values %s  ",
     	 param->optname, cfgvalue,okvalstr);
    return -1;
}

int config_checkstr_assign_integer(paramdef_t *param, char **cfgokvalues, int *assignedvalues, int numokval)
{
char *cfgvalue ;
char okvalstr[512];
char *astrptr=okvalstr;

    cfgvalue =*(param->strptr);
    okvalstr[0]=0;
    for (int i=0; i < numokval ; i++) {
    	astrptr += sprintf(astrptr,"%s ",cfgokvalues[i]);
    	if (strcasecmp(cfgvalue, cfgokvalues[i] ) == 0) {
            config_assign_processedint(param, assignedvalues[i]);
    	    return 0; 
    	}
   }
   LOG_E(RRC," %s, unknown value \"%s\" authorised values %s  ",
     	 param->optname, cfgvalue,okvalstr);
    return -1;
}

int config_check_assign_UEtc(paramdef_t *param)
{
int st = -1;



    if ( param == NULL ){
      fprintf(stderr,"[RRCCONFIG] config_check_assign_UEtc: NULL param argument\n");
      return -1;
    }

    if ( strstr(param->optname,"t300") != NULL) {
          int cfgokvalues[] = {100,200,300,400,600,1000,1500,2000};
          int assignedvalues[] = {UE_TimersAndConstants__t300_ms100, UE_TimersAndConstants__t300_ms200,UE_TimersAndConstants__t300_ms300,
                                UE_TimersAndConstants__t300_ms400, UE_TimersAndConstants__t300_ms600,UE_TimersAndConstants__t300_ms1000,
                                UE_TimersAndConstants__t300_ms1500,UE_TimersAndConstants__t300_ms2000};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* t300 */
     else if ( strstr(param->optname,"t301") != NULL) {
          int cfgokvalues[] = {100,200,300,400,600,1000,1500,2000};
          int assignedvalues[] = {UE_TimersAndConstants__t301_ms100, UE_TimersAndConstants__t301_ms200,UE_TimersAndConstants__t301_ms300,
                                UE_TimersAndConstants__t301_ms400, UE_TimersAndConstants__t301_ms600,UE_TimersAndConstants__t301_ms1000,
                                UE_TimersAndConstants__t301_ms1500,UE_TimersAndConstants__t301_ms2000};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* t301 */
     else if ( strstr(param->optname,"t310") != NULL) {
          int cfgokvalues[] = {0,50,100,200,500,1000,2000};
          int assignedvalues[] = {UE_TimersAndConstants__t310_ms0, UE_TimersAndConstants__t310_ms50,UE_TimersAndConstants__t310_ms100,
                                UE_TimersAndConstants__t310_ms200, UE_TimersAndConstants__t310_ms500,UE_TimersAndConstants__t310_ms1000,
                                UE_TimersAndConstants__t310_ms2000};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* t310 */
     else if ( strstr(param->optname,"t311") != NULL) {
          int cfgokvalues[] = {1000,3110,5000,10000,15000,20000,31100};
          int assignedvalues[] = {UE_TimersAndConstants__t311_ms1000, UE_TimersAndConstants__t311_ms3000,UE_TimersAndConstants__t311_ms5000,
                                  UE_TimersAndConstants__t311_ms10000, UE_TimersAndConstants__t311_ms15000,UE_TimersAndConstants__t311_ms20000,
                                  UE_TimersAndConstants__t311_ms30000};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* t311 */
     else if ( strstr(param->optname,"n310") != NULL) {
          int cfgokvalues[] = {1,2,3,4,6,8,10,20};
          int assignedvalues[] = {UE_TimersAndConstants__n310_n1,  UE_TimersAndConstants__n310_n2, UE_TimersAndConstants__n310_n3,
                                  UE_TimersAndConstants__n310_n4,  UE_TimersAndConstants__n310_n6, UE_TimersAndConstants__n310_n8,
                                  UE_TimersAndConstants__n310_n10, UE_TimersAndConstants__n310_n20};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* n310 */
     else if ( strstr(param->optname,"n311") != NULL) {
          int cfgokvalues[] = {1,2,3,4,5,6,8,10};
          int assignedvalues[] = {UE_TimersAndConstants__n311_n1,  UE_TimersAndConstants__n311_n2, UE_TimersAndConstants__n311_n3,
                                  UE_TimersAndConstants__n311_n4,  UE_TimersAndConstants__n311_n5, UE_TimersAndConstants__n311_n6,
                                  UE_TimersAndConstants__n311_n8, UE_TimersAndConstants__n311_n10};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* n311 */

     return st;
}



int config_check_assign_DLGap_NB(paramdef_t *param)
{
int st = -1;



    if ( param == NULL ){
      fprintf(stderr,"[RRCCONFIG] config_check_assign_UEtc: NULL param argument\n");
      return -1;
    }

    if ( strstr(param->optname,"Threshold") != NULL) {
          int cfgokvalues[] = {32,64,128,256};
          int assignedvalues[] = { DL_GapConfig_NB_r13__dl_GapThreshold_r13_n32,  DL_GapConfig_NB_r13__dl_GapThreshold_r13_n64,
                                   DL_GapConfig_NB_r13__dl_GapThreshold_r13_n128, DL_GapConfig_NB_r13__dl_GapThreshold_r13_n256};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* Threshold */
     else if ( strstr(param->optname,"Periodicity") != NULL) {
          int cfgokvalues[] = {64,128,256,512};
          int assignedvalues[] = { DL_GapConfig_NB_r13__dl_GapPeriodicity_r13_sf64, DL_GapConfig_NB_r13__dl_GapPeriodicity_r13_sf128,
                                   DL_GapConfig_NB_r13__dl_GapPeriodicity_r13_sf256,DL_GapConfig_NB_r13__dl_GapPeriodicity_r13_sf512};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* Periodicityt */
     else if ( strstr(param->optname,"DurationCoeff") != NULL) {
          char * cfgokvalues[] = {"oneEighth","oneFourth","threeEighth","oneHalf"};
          int assignedvalues[] = {DL_GapConfig_NB_r13__dl_GapDurationCoeff_r13_oneEighth,   DL_GapConfig_NB_r13__dl_GapDurationCoeff_r13_oneFourth,
                                  DL_GapConfig_NB_r13__dl_GapDurationCoeff_r13_threeEighth, DL_GapConfig_NB_r13__dl_GapDurationCoeff_r13_oneHalf};
          st = config_checkstr_assign_integer(param, cfgokvalues, assignedvalues, sizeof(assignedvalues)/sizeof(int) );

     } /* DurationCoeff */

     return st;
}

int config_check_assign_rach_NB(paramdef_t *param)
{
int st = -1;

    if ( param == NULL ){
      fprintf(stderr,"[RRCCONFIG] config_check_assign_UEtc: NULL param argument\n");
      return -1;
    }


     if ( strstr(param->optname,"Periodicity") != NULL) {
          int cfgokvalues[] = {40,80,160,240,320,640,1280,2560};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms40,   NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms80,
                                    NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms160,  NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms240,
                                    NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms320,  NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms640,
                                    NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms1280, NPRACH_Parameters_NB_r13__nprach_Periodicity_r13_ms2560 };
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* Periodicityt */
     else if ( strstr(param->optname,"StartTime") != NULL) {
          int cfgokvalues[] = {8,16,32,64,128,256,512,1024};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms8,   NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms16,
                                    NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms32,  NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms64,
                                    NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms128, NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms256,
                                    NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms512, NPRACH_Parameters_NB_r13__nprach_StartTime_r13_ms1024 };
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* StartTime */
     else if ( strstr(param->optname,"SubcarrierOffset") != NULL) {
          int cfgokvalues[] = {0,12,24,36,2,18,34,1};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n0,  NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n12,
                                    NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n24, NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n36,
                                    NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n2,  NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n18,
                                    NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_n34, NPRACH_Parameters_NB_r13__nprach_SubcarrierOffset_r13_spare1 };
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* SubcarrierOffset */
     else if ( strstr(param->optname,"NumSubcarriers") != NULL) {
          int cfgokvalues[] = {12,24,36,48};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__nprach_NumSubcarriers_r13_n12, NPRACH_Parameters_NB_r13__nprach_NumSubcarriers_r13_n24,
                                    NPRACH_Parameters_NB_r13__nprach_NumSubcarriers_r13_n36, NPRACH_Parameters_NB_r13__nprach_NumSubcarriers_r13_n48 };
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* NumSubcarriers */
     else if ( strstr(param->optname,"SubcarrierMSG3_RangeStart") != NULL) {
          char * cfgokvalues[] = {"zero","oneThird","twoThird","one"};
          int assignedvalues[] = {NPRACH_Parameters_NB_r13__nprach_SubcarrierMSG3_RangeStart_r13_zero,     NPRACH_Parameters_NB_r13__nprach_SubcarrierMSG3_RangeStart_r13_oneThird,
                                  NPRACH_Parameters_NB_r13__nprach_SubcarrierMSG3_RangeStart_r13_twoThird, NPRACH_Parameters_NB_r13__nprach_SubcarrierMSG3_RangeStart_r13_one};
          st = config_checkstr_assign_integer(param, cfgokvalues, assignedvalues, sizeof(assignedvalues)/sizeof(int) );

     } /* SubcarrierMSG3_RangeStart */
     else if ( strstr(param->optname,"maxNumPreambleAttemptCE") != NULL) {
          int cfgokvalues[] = {3,4,5,6,7,8,10,1};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n3, NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n4,
                                    NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n5, NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n6,
                                    NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n7, NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n8,
                                    NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_n10,NPRACH_Parameters_NB_r13__maxNumPreambleAttemptCE_r13_spare1 };
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* maxNumPreambleAttemptCE */
     else if ( strstr(param->optname,"RepetitionsPerPreambleAttempt") != NULL) {
          int cfgokvalues[] = {1,2,4,8,16,32,64,128};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n1,  NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n2,
                                    NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n4,  NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n8,
                                    NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n16, NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n32,
                                    NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n64, NPRACH_Parameters_NB_r13__numRepetitionsPerPreambleAttempt_r13_n128};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* RepetitionsPerPreambleAttempt */
     else if ( strstr(param->optname,"NumRepetitions_RA") != NULL) {
          int cfgokvalues[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r1,   NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r2,
                                    NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r4,   NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r8,
                                    NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r16,  NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r32,
                                    NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r64,  NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r128,
                                    NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r256, NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r512,
                                    NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r1024,NPRACH_Parameters_NB_r13__npdcch_NumRepetitions_RA_r13_r2048};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* NumRepetitions_RA */
     else if ( strstr(param->optname,"StartSF_CSS_RA") != NULL) {
          int cfgokvalues[] = {1,2,4,8,16,32,48,64};
          int assignedvalues[] = {  NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v1dot5,  NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v2,
                                    NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v4,      NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v8,
                                    NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v16,     NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v32,
                                    NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v48,     NPRACH_Parameters_NB_r13__npdcch_StartSF_CSS_RA_r13_v64};
          st = config_check_assign_integer(param, cfgokvalues, assignedvalues, sizeof(cfgokvalues)/sizeof(int) );

     } /* StartSF_CSS_RA */
     else if ( strstr(param->optname,"Offset_RA") != NULL) {
          char * cfgokvalues[] = {"zero","oneEighth","oneFourth","threeEighth"};
          int assignedvalues[] = { NPRACH_Parameters_NB_r13__npdcch_Offset_RA_r13_zero,      NPRACH_Parameters_NB_r13__npdcch_Offset_RA_r13_oneEighth,
                                   NPRACH_Parameters_NB_r13__npdcch_Offset_RA_r13_oneFourth, NPRACH_Parameters_NB_r13__npdcch_Offset_RA_r13_threeEighth};
          st = config_checkstr_assign_integer(param, cfgokvalues, assignedvalues, sizeof(assignedvalues)/sizeof(int) );

     } /* Offset_RA */

 
     return st;
}
