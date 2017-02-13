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

/*! \file lte-ue.c
 * \brief threads and support functions for real-time LTE UE target
 * \author R. Knopp, F. Kaltenberger, Navid Nikaein
 * \date 2015
 * \version 0.1
 * \company Eurecom
 * \email: knopp@eurecom.fr,florian.kaltenberger@eurecom.fr, navid.nikaein@eurecom.fr
 * \note
 * \warning
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sched.h>
#include <linux/sched.h>
#include <signal.h>
#include <execinfo.h>
#include <getopt.h>
#include <syscall.h>
#include <sys/sysinfo.h>

#include "rt_wrapper.h"
#include "assertions.h"
#include "PHY/types.h"

#include "PHY/defs.h"
#ifdef OPENAIR2
#include "LAYER2/MAC/defs.h"
#include "RRC/LITE/extern.h"
#endif
#include "PHY_INTERFACE/extern.h"

#undef MALLOC //there are two conflicting definitions, so we better make sure we don't use it at all
//#undef FRAME_LENGTH_COMPLEX_SAMPLES //there are two conflicting definitions, so we better make sure we don't use it at all

#include "../../ARCH/COMMON/common_lib.h"

#include "PHY/extern.h"
#include "SCHED/extern.h"
#include "LAYER2/MAC/extern.h"
#include "LAYER2/MAC/proto.h"

#include "UTIL/LOG/log_extern.h"
#include "UTIL/OTG/otg_tx.h"
#include "UTIL/OTG/otg_externs.h"
#include "UTIL/MATH/oml.h"
#include "UTIL/LOG/vcd_signal_dumper.h"
#include "UTIL/OPT/opt.h"

#include "T.h"

#define FRAME_PERIOD    100000000ULL
#define DAQ_PERIOD      66667ULL
#define FIFO_PRIORITY   40

typedef enum {
    pss=0,
    pbch=1,
    si=2
} sync_mode_t;

void init_UE_threads(PHY_VARS_UE *UE);
void *UE_thread(void *arg);
void init_UE(int nb_inst);

extern pthread_cond_t sync_cond;
extern pthread_mutex_t sync_mutex;
extern int sync_var;


extern openair0_config_t openair0_cfg[MAX_CARDS];
extern uint32_t          downlink_frequency[MAX_NUM_CCs][4];
extern int32_t           uplink_frequency_offset[MAX_NUM_CCs][4];
extern int oai_exit;

int32_t **rxdata;
int32_t **txdata;

//extern unsigned int tx_forward_nsamps;
//extern int tx_delay;

extern int rx_input_level_dBm;
extern uint8_t exit_missed_slots;
extern uint64_t num_missed_slots; // counter for the number of missed slots

extern void exit_fun(const char* s);

#define KHz (1000UL)
#define MHz (1000 * KHz)

typedef struct eutra_band_s {
    int16_t band;
    uint32_t ul_min;
    uint32_t ul_max;
    uint32_t dl_min;
    uint32_t dl_max;
    lte_frame_type_t frame_type;
} eutra_band_t;

typedef struct band_info_s {
    int nbands;
    eutra_band_t band_info[100];
} band_info_t;

band_info_t bands_to_scan;

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
    {22, 3510    * MHz, 3590    * MHz, 3410    * MHz, 3490    * MHz, FDD},
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

pthread_t                       main_ue_thread;
pthread_attr_t                  attr_UE_thread;
struct sched_param              sched_param_UE_thread;

void init_thread(int sched_runtime, int sched_deadline, int sched_fifo, cpu_set_t *cpuset, char * name) {

#ifdef DEADLINE_SCHEDULER
    if (sched_runtime!=0) {
        struct sched_attr attr= {0};
        attr.size = sizeof(attr);
        // This creates a .5 ms  reservation
        attr.sched_policy = SCHED_DEADLINE;
        attr.sched_runtime  = sched_runtime;
        attr.sched_deadline = sched_deadline;
        attr.sched_period   = 0;
        AssertFatal(sched_setattr(0, &attr, 0) == 0,
                    "[SCHED] main eNB thread: sched_setattr failed %s \n",perror(errno));
        LOG_I(HW,"[SCHED][eNB] eNB main deadline thread %lu started on CPU %d\n",
              (unsigned long)gettid(), sched_getcpu());
    }

#else
    if (cpuset!=NULL)
        AssertFatal( 0 == pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), cpuset), "");
    struct sched_param sp;
    sp.sched_priority = sched_fifo;
    AssertFatal(pthread_setschedparam(pthread_self(),SCHED_FIFO,&sp)==0,
                "Can't set thread priority, Are you root?\n");
#endif

    // Lock memory from swapping. This is a process wide call (not constraint to this thread).
    mlockall(MCL_CURRENT | MCL_FUTURE);
    pthread_setname_np( pthread_self(), name );

    // LTS: this sync stuff should be wrong
    printf("waiting for sync (%s)\n",name);
    pthread_mutex_lock(&sync_mutex);
    printf("Locked sync_mutex, waiting (%s)\n",name);
    while (sync_var<0)
        pthread_cond_wait(&sync_cond, &sync_mutex);
    pthread_mutex_unlock(&sync_mutex);
    printf("started %s as PID: %ld\n",name, gettid());
}

void init_UE(int nb_inst) {

    for (long long inst=0; inst<nb_inst; inst++) {
        //    UE->rfdevice.type      = NONE_DEV;
        PHY_VARS_UE *UE = PHY_vars_UE_g[inst][0];
        AssertFatal(0 == pthread_create(&UE->proc.pthread_ue,
                                        &UE->proc.attr_ue,
                                        UE_thread,
                                        (void*)UE), "");
    }

    printf("UE threads created by %ld\n", gettid());
#ifdef USE_MME
    while (start_UE == 0) {
        sleep(1);
    }
#endif

}

/*!
 * \brief This is the UE synchronize thread.
 * It performs band scanning and synchonization.
 * \param arg is a pointer to a \ref PHY_VARS_UE structure.
 * \returns a pointer to an int. The storage is not on the heap and must not be freed.
 */
static void *UE_thread_synch(void *arg) {
    static int __thread UE_thread_synch_retval;
    int i, hw_slot_offset;
    PHY_VARS_UE *UE = (PHY_VARS_UE*) arg;
    int current_band = 0;
    int current_offset = 0;
    sync_mode_t sync_mode = pbch;
    int CC_id = UE->CC_id;
    int freq_offset=0;

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(3, &cpuset);
    // this thread priority must be lower that the main acquisition thread
    init_thread(100000, 500000, FIFO_PRIORITY-1, &cpuset,
                "sync UE");

    UE->is_synchronized = 0;

    if (UE->UE_scan == 0) {
        int ind;
        for ( ind=0;
                ind < sizeof(eutra_bands) / sizeof(eutra_bands[0]);
                ind++) {
            current_band = eutra_bands[ind].band;
            LOG_D(PHY, "Scanning band %d, dl_min %"PRIu32", ul_min %"PRIu32"\n", current_band, eutra_bands[ind].dl_min,eutra_bands[ind].ul_min);
            if ( eutra_bands[ind].dl_min <= downlink_frequency[0][0] && eutra_bands[ind].dl_max >= downlink_frequency[0][0] ) {
                for (i=0; i<4; i++)
                    uplink_frequency_offset[CC_id][i] = eutra_bands[ind].ul_min - eutra_bands[ind].dl_min;
                break;
            }
        }
        AssertFatal( ind < sizeof(eutra_bands) / sizeof(eutra_bands[0]), "Can't find EUTRA band for frequency");

        LOG_I( PHY, "[SCHED][UE] Check absolute frequency DL %"PRIu32", UL %"PRIu32" (oai_exit %d, rx_num_channels %d)\n",
               downlink_frequency[0][0], downlink_frequency[0][0]+uplink_frequency_offset[0][0],
               oai_exit, openair0_cfg[0].rx_num_channels);

        for (i=0; i<openair0_cfg[UE->rf_map.card].rx_num_channels; i++) {
            openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i];
            openair0_cfg[UE->rf_map.card].tx_freq[UE->rf_map.chain+i] =
                downlink_frequency[CC_id][i]+uplink_frequency_offset[CC_id][i];
            openair0_cfg[UE->rf_map.card].autocal[UE->rf_map.chain+i] = 1;
            if (uplink_frequency_offset[CC_id][i] != 0) //
                openair0_cfg[UE->rf_map.card].duplex_mode = duplex_mode_FDD;
            else //FDD
                openair0_cfg[UE->rf_map.card].duplex_mode = duplex_mode_TDD;
        }
        sync_mode = pbch;

    } else {
        current_band=0;
        for (i=0; i<openair0_cfg[UE->rf_map.card].rx_num_channels; i++) {
            downlink_frequency[UE->rf_map.card][UE->rf_map.chain+i] = bands_to_scan.band_info[CC_id].dl_min;
            uplink_frequency_offset[UE->rf_map.card][UE->rf_map.chain+i] =
                bands_to_scan.band_info[CC_id].ul_min-bands_to_scan.band_info[CC_id].dl_min;
            openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i];
            openair0_cfg[UE->rf_map.card].tx_freq[UE->rf_map.chain+i] =
                downlink_frequency[CC_id][i]+uplink_frequency_offset[CC_id][i];
            openair0_cfg[UE->rf_map.card].rx_gain[UE->rf_map.chain+i] = UE->rx_total_gain_dB;
        }
    }

    AssertFatal(UE->rfdevice.trx_start_func(&UE->rfdevice) == 0, "Could not start the device\n");

    while (oai_exit==0) {
        AssertFatal ( 0== pthread_mutex_lock(&UE->proc.mutex_synch), "");
        while (UE->proc.instance_cnt_synch < 0)
            // the thread waits here most of the time
            pthread_cond_wait( &UE->proc.cond_synch, &UE->proc.mutex_synch );
        AssertFatal ( 0== pthread_mutex_unlock(&UE->proc.mutex_synch), "");

        switch (sync_mode) {
        case pss:
            LOG_I(PHY,"[SCHED][UE] Scanning band %d (%d), freq %u\n",bands_to_scan.band_info[current_band].band, current_band,bands_to_scan.band_info[current_band].dl_min+current_offset);
            lte_sync_timefreq(UE,current_band,bands_to_scan.band_info[current_band].dl_min+current_offset);
            current_offset += 20000000; // increase by 20 MHz

            if (current_offset > bands_to_scan.band_info[current_band].dl_max-bands_to_scan.band_info[current_band].dl_min) {
                current_band++;
                current_offset=0;
            }

            if (current_band==bands_to_scan.nbands) {
                current_band=0;
                oai_exit=1;
            }

            for (i=0; i<openair0_cfg[UE->rf_map.card].rx_num_channels; i++) {
                downlink_frequency[UE->rf_map.card][UE->rf_map.chain+i] = bands_to_scan.band_info[current_band].dl_min+current_offset;
                uplink_frequency_offset[UE->rf_map.card][UE->rf_map.chain+i] = bands_to_scan.band_info[current_band].ul_min-bands_to_scan.band_info[0].dl_min + current_offset;

                openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i];
                openair0_cfg[UE->rf_map.card].tx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i]+uplink_frequency_offset[CC_id][i];
                openair0_cfg[UE->rf_map.card].rx_gain[UE->rf_map.chain+i] = UE->rx_total_gain_dB;
                if (UE->UE_scan_carrier) {
                    openair0_cfg[UE->rf_map.card].autocal[UE->rf_map.chain+i] = 1;
                }

            }

            break;

        case pbch:

            LOG_I(PHY,"[UE thread Synch] Running Initial Synch (mode %d)\n",UE->mode);
            if (initial_sync( UE, UE->mode ) == 0) {

                hw_slot_offset = (UE->rx_offset<<1) / UE->frame_parms.samples_per_tti;
                LOG_I( HW, "Got synch: hw_slot_offset %d, carrier off %d Hz, rxgain %d (DL %u, UL %u), UE_scan_carrier %d\n",
                       hw_slot_offset,
                       freq_offset,
                       UE->rx_total_gain_dB,
                       downlink_frequency[0][0]+freq_offset,
                       downlink_frequency[0][0]+uplink_frequency_offset[0][0]+freq_offset,
                       UE->UE_scan_carrier );

                if (UE->UE_scan_carrier == 1) {
                    UE->UE_scan_carrier = 0;
                    // rerun with new cell parameters and frequency-offset
                    for (i=0; i<openair0_cfg[UE->rf_map.card].rx_num_channels; i++) {
                        openair0_cfg[UE->rf_map.card].rx_gain[UE->rf_map.chain+i] = UE->rx_total_gain_dB;//-USRP_GAIN_OFFSET;
                        if (freq_offset >= 0)
                            openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] += UE->common_vars.freq_offset;
                        else
                            openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] -= UE->common_vars.freq_offset;
                        openair0_cfg[UE->rf_map.card].tx_freq[UE->rf_map.chain+i] =
                            openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i]+uplink_frequency_offset[CC_id][i];
                        downlink_frequency[CC_id][i] = openair0_cfg[CC_id].rx_freq[i];
                        freq_offset=0;
                    }

                    // reconfigure for potentially different bandwidth
                    switch(UE->frame_parms.N_RB_DL) {
                    case 6:
                        openair0_cfg[UE->rf_map.card].sample_rate =1.92e6;
                        openair0_cfg[UE->rf_map.card].rx_bw          =.96e6;
                        openair0_cfg[UE->rf_map.card].tx_bw          =.96e6;
                        //            openair0_cfg[0].rx_gain[0] -= 12;
                        break;
                    case 25:
                        openair0_cfg[UE->rf_map.card].sample_rate =7.68e6;
                        openair0_cfg[UE->rf_map.card].rx_bw          =2.5e6;
                        openair0_cfg[UE->rf_map.card].tx_bw          =2.5e6;
                        //            openair0_cfg[0].rx_gain[0] -= 6;
                        break;
                    case 50:
                        openair0_cfg[UE->rf_map.card].sample_rate =15.36e6;
                        openair0_cfg[UE->rf_map.card].rx_bw          =5.0e6;
                        openair0_cfg[UE->rf_map.card].tx_bw          =5.0e6;
                        //            openair0_cfg[0].rx_gain[0] -= 3;
                        break;
                    case 100:
                        openair0_cfg[UE->rf_map.card].sample_rate=30.72e6;
                        openair0_cfg[UE->rf_map.card].rx_bw=10.0e6;
                        openair0_cfg[UE->rf_map.card].tx_bw=10.0e6;
                        //            openair0_cfg[0].rx_gain[0] -= 0;
                        break;
                    }

                    UE->rfdevice.trx_set_freq_func(&UE->rfdevice,&openair0_cfg[0],0);
                    //UE->rfdevice.trx_set_gains_func(&openair0,&openair0_cfg[0]);
                    UE->rfdevice.trx_stop_func(&UE->rfdevice);
                    sleep(1);
                    init_frame_parms(&UE->frame_parms,1);
                    if (UE->rfdevice.trx_start_func(&UE->rfdevice) != 0 ) {
                        LOG_E(HW,"Could not start the device\n");
                        oai_exit=1;
                    }
                } else {
                    AssertFatal ( 0== pthread_mutex_lock(&UE->proc.mutex_synch), "");
                    UE->is_synchronized = 1;
                    AssertFatal ( 0== pthread_mutex_unlock(&UE->proc.mutex_synch), "");

                    if( UE->mode == rx_dump_frame ) {
                        FILE *fd;
                        if ((UE->proc.proc_rxtx[0].frame_rx&1) == 0) {  // this guarantees SIB1 is present
                            if ((fd = fopen("rxsig_frame0.dat","w")) != NULL) {
                                fwrite((void*)&UE->common_vars.rxdata[0][0],
                                       sizeof(int32_t),
                                       10*UE->frame_parms.samples_per_tti,
                                       fd);
                                LOG_I(PHY,"Dummping Frame ... bye bye \n");
                                fclose(fd);
                                exit(0);
                            } else {
                                LOG_E(PHY,"Cannot open file for writing\n");
                                exit(0);
                            }
                        } else {
                            AssertFatal ( 0== pthread_mutex_lock(&UE->proc.mutex_synch), "");
                            UE->is_synchronized = 0;
                            AssertFatal ( 0== pthread_mutex_unlock(&UE->proc.mutex_synch), "");

                        }
                    }
                }
            } else {
                // initial sync failed
                // calculate new offset and try again
                if (UE->UE_scan_carrier == 1) {
                    if (freq_offset >= 0)
                        freq_offset += 100;
                    freq_offset *= -1;

                    if (abs(freq_offset) > 7500) {
                        LOG_I( PHY, "[initial_sync] No cell synchronization found, abandoning\n" );
                        FILE *fd;
                        if ((fd = fopen("rxsig_frame0.dat","w"))!=NULL) {
                            fwrite((void*)&UE->common_vars.rxdata[0][0],
                                   sizeof(int32_t),
                                   10*UE->frame_parms.samples_per_tti,
                                   fd);
                            LOG_I(PHY,"Dummping Frame ... bye bye \n");
                            fclose(fd);
                            exit(0);
                        }
                        mac_xface->macphy_exit("No cell synchronization found, abandoning");
                        return &UE_thread_synch_retval; // not reached
                    }
                }
                LOG_I( PHY, "[initial_sync] trying carrier off %d Hz, rxgain %d (DL %u, UL %u)\n",
                       freq_offset,
                       UE->rx_total_gain_dB,
                       downlink_frequency[0][0]+freq_offset,
                       downlink_frequency[0][0]+uplink_frequency_offset[0][0]+freq_offset );

                for (i=0; i<openair0_cfg[UE->rf_map.card].rx_num_channels; i++) {
                    openair0_cfg[UE->rf_map.card].rx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i]+freq_offset;
                    openair0_cfg[UE->rf_map.card].tx_freq[UE->rf_map.chain+i] = downlink_frequency[CC_id][i]+uplink_frequency_offset[CC_id][i]+freq_offset;
                    openair0_cfg[UE->rf_map.card].rx_gain[UE->rf_map.chain+i] = UE->rx_total_gain_dB;//-USRP_GAIN_OFFSET;
                    if (UE->UE_scan_carrier==1)
                        openair0_cfg[UE->rf_map.card].autocal[UE->rf_map.chain+i] = 1;
                }
                UE->rfdevice.trx_set_freq_func(&UE->rfdevice,&openair0_cfg[0],0);
            }// initial_sync=0
            break;
        case si:
        default:
            break;
        }

        AssertFatal ( 0== pthread_mutex_lock(&UE->proc.mutex_synch), "");
        // indicate readiness
        UE->proc.instance_cnt_synch--;
        AssertFatal ( 0== pthread_mutex_unlock(&UE->proc.mutex_synch), "");

        VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME( VCD_SIGNAL_DUMPER_FUNCTIONS_UE_THREAD_SYNCH, 0 );
    }  // while !oai_exit

    return &UE_thread_synch_retval;
}



/*!
 * \brief This is the UE thread for RX subframe n and TX subframe n+4.
 * This thread performs the phy_procedures_UE_RX() on every received slot.
 * then, if TX is enabled it performs TX for n+4.
 * \param arg is a pointer to a \ref PHY_VARS_UE structure.
 * \returns a pointer to an int. The storage is not on the heap and must not be freed.
 */

static void *UE_thread_rxn_txnp4(void *arg) {
    static __thread int UE_thread_rxtx_retval;
    UE_rxtx_proc_t *proc = (UE_rxtx_proc_t *)arg;
    int ret;
    PHY_VARS_UE *UE=PHY_vars_UE_g[0][proc->CC_id];

    static long long __thread instance_cnt_rxtx=-1;
    proc->subframe_rx=proc->sub_frame_start;

    char threadname[256]= {0};
    sprintf(threadname,"UE_proc_%d",proc->sub_frame_start);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(proc->sub_frame_start+1, &cpuset);
    init_thread(900000,1000000 , FIFO_PRIORITY-1, &cpuset,
                threadname);

    while (!oai_exit) {
        // Wait Rx data to process are available
        AssertFatal(pthread_mutex_lock(&proc->mutex_rxtx) ==0,"");
        pthread_cond_wait( &proc->cond_rxtx, &proc->mutex_rxtx );
        if ( (instance_cnt_rxtx+proc->sub_frame_step)%10 != proc->subframe_rx &&  instance_cnt_rxtx!=-1 )
            LOG_W(PHY,"REAL TIME NOT MATCHED: missed a sub-frame: expecting %lld, got %d\n",
                  (instance_cnt_rxtx+proc->sub_frame_step)%10, proc->subframe_rx);
        instance_cnt_rxtx=proc->subframe_rx;
        AssertFatal(pthread_mutex_unlock(&proc->mutex_rxtx) ==0,"");

        initRefTimes(t2);
        initRefTimes(t3);
        pickTime(current);
        updateTimes(proc->gotIQs, &t2, 10000, "Delay to wake up UE_Thread_Rx (case 2)");
      check(2200);

        // Process Rx data for one sub-frame
        lte_subframe_t sf_type = subframe_select( &UE->frame_parms, proc->subframe_rx);
      check(100);
        if ((sf_type == SF_DL) ||
                (UE->frame_parms.frame_type == FDD) ||
                (sf_type == SF_S)) {

            if (UE->frame_parms.frame_type == TDD) {
                LOG_D(PHY, "%s,TDD%d,%s: calling UE_RX\n",
                      threadname,
                      UE->frame_parms.tdd_config,
                      (sf_type==SF_DL? "SF_DL" :
                       (sf_type==SF_UL? "SF_UL" :
                        (sf_type==SF_S ? "SF_S"  : "UNKNOWN_SF_TYPE"))));
            } else {
                LOG_D(PHY, "%s,%s,%s: calling UE_RX\n",
                      threadname,
                      (UE->frame_parms.frame_type==FDD? "FDD":
                       (UE->frame_parms.frame_type==TDD? "TDD":"UNKNOWN_DUPLEX_MODE")),
                      (sf_type==SF_DL? "SF_DL" :
                       (sf_type==SF_UL? "SF_UL" :
                        (sf_type==SF_S ? "SF_S"  : "UNKNOWN_SF_TYPE"))));
            }
            phy_procedures_UE_RX( UE, proc, 0, 0, UE->mode, no_relay, NULL );
        }
        check(900);
        if (UE->mac_enabled==1) {

            ret = mac_xface->ue_scheduler(UE->Mod_id,
                                          proc->frame_rx,
                                          proc->subframe_rx,
                                          proc->frame_tx,
                                          proc->subframe_tx,
                                          subframe_select(&UE->frame_parms,proc->subframe_tx),
                                          0,
                                          0/*FIXME CC_id*/);
            if ( ret != CONNECTION_OK) {
                char *txt;
                switch (ret) {
                case CONNECTION_LOST:
                    txt="RRC Connection lost, returning to PRACH";
                    break;
                case PHY_RESYNCH:
                    txt="RRC Connection lost, trying to resynch";
                    break;
                case RESYNCH:
                    txt="return to PRACH and perform a contention-free access";
                    break;
                default:
                    txt="UNKNOWN RETURN CODE";
                };
                LOG_E( PHY, "[UE %"PRIu8"] Frame %"PRIu32", subframe %u %s\n",
                       UE->Mod_id, proc->frame_rx, proc->subframe_tx,txt );
            }
        }
	check(350);
        // Prepare the future Tx data

        if ((subframe_select( &UE->frame_parms, proc->subframe_tx) == SF_UL) ||
                (UE->frame_parms.frame_type == FDD) )
            if (UE->mode != loop_through_memory)
                phy_procedures_UE_TX(UE,proc,0,0,UE->mode,no_relay);


        if ((subframe_select( &UE->frame_parms, proc->subframe_tx) == SF_S) &&
                (UE->frame_parms.frame_type == TDD))
            if (UE->mode != loop_through_memory)
                phy_procedures_UE_S_TX(UE,0,0,no_relay);
        updateTimes(current, &t3, 10000, "Delay to process sub-frame (case 3)");
       check(300);

    }

// thread finished
    return &UE_thread_rxtx_retval;
}

/*!
 * \brief This is the main UE thread.
 * This thread controls the other three UE threads:
 * - UE_thread_rxn_txnp4 (even subframes)
 * - UE_thread_rxn_txnp4 (odd subframes)
 * - UE_thread_synch
 * \param arg unused
 * \returns a pointer to an int. The storage is not on the heap and must not be freed.
 */

void *UE_thread(void *arg) {

    PHY_VARS_UE *UE = (PHY_VARS_UE *) arg;
    //  int tx_enabled = 0;
    int dummy_rx[UE->frame_parms.nb_antennas_rx][UE->frame_parms.samples_per_tti] __attribute__((aligned(32)));
    openair0_timestamp timestamp,timestamp1;
    void* rxp[NB_ANTENNAS_RX], *txp[NB_ANTENNAS_TX];
    int start_rx_stream = 0;
    int i;

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(3, &cpuset);
    init_thread(100000, 500000, FIFO_PRIORITY, &cpuset,
                "main UE");

    AssertFatal(0== openair0_device_load(&(UE->rfdevice), &openair0_cfg[0]), "");
    UE->rfdevice.host_type = BBU_HOST;
    init_UE_threads(UE);

#ifdef NAS_UE
    MessageDef *message_p;
    message_p = itti_alloc_new_message(TASK_NAS_UE, INITIALIZE_MESSAGE);
    itti_send_msg_to_task (TASK_NAS_UE, INSTANCE_DEFAULT, message_p);
#endif

    int sub_frame=-1;
    //int cumulated_shift=0;
    while (!oai_exit) {
        AssertFatal ( 0== pthread_mutex_lock(&UE->proc.mutex_synch), "");
        int instance_cnt_synch = UE->proc.instance_cnt_synch;
        int is_synchronized    = UE->is_synchronized;
        AssertFatal ( 0== pthread_mutex_unlock(&UE->proc.mutex_synch), "");

        if (is_synchronized == 0) {
            if (instance_cnt_synch < 0) {  // we can invoke the synch
                // grab 10 ms of signal and wakeup synch thread
                for (int i=0; i<UE->frame_parms.nb_antennas_rx; i++)
                    rxp[i] = (void*)&UE->common_vars.rxdata[i][0];

                if (UE->mode != loop_through_memory)
                    AssertFatal( UE->frame_parms.samples_per_tti*10 ==
                                 UE->rfdevice.trx_read_func(&UE->rfdevice,
                                                            &timestamp,
                                                            rxp,
                                                            UE->frame_parms.samples_per_tti*10,
                                                            UE->frame_parms.nb_antennas_rx), "");
                instance_cnt_synch = ++UE->proc.instance_cnt_synch;
                if (instance_cnt_synch == 0) {
                    AssertFatal( 0 == pthread_cond_signal(&UE->proc.cond_synch), "");
                } else {
                    LOG_E( PHY, "[SCHED][UE] UE sync thread busy!!\n" );
                    exit_fun("nothing to add");
                }
            } else {
                // grab 10 ms of signal into dummy buffer
                if (UE->mode != loop_through_memory) {
                    for (int i=0; i<UE->frame_parms.nb_antennas_rx; i++)
                        rxp[i] = (void*)&dummy_rx[i][0];
                    for (int sf=0; sf<10; sf++)
                        //	    printf("Reading dummy sf %d\n",sf);
                        AssertFatal ( UE->frame_parms.samples_per_tti ==
                                      UE->rfdevice.trx_read_func(&UE->rfdevice,
                                              &timestamp,
                                              rxp,
                                              UE->frame_parms.samples_per_tti,
                                              UE->frame_parms.nb_antennas_rx), "");
                }
            }

        } // UE->is_synchronized==0
        else {
            if (start_rx_stream==0) {
                start_rx_stream=1;
                if (UE->mode != loop_through_memory) {
                    if (UE->no_timing_correction==0) {
                        LOG_I(PHY,"Resynchronizing RX by %d samples (mode = %d)\n",UE->rx_offset,UE->mode);
                        AssertFatal(UE->rx_offset ==
                                    UE->rfdevice.trx_read_func(&UE->rfdevice,
                                                               &timestamp,
                                                               (void**)UE->common_vars.rxdata,
                                                               UE->rx_offset,
                                                               UE->frame_parms.nb_antennas_rx),"");
                    }
                    UE->rx_offset=0;
                    UE->proc.proc_rxtx[0].frame_rx++;
                    UE->proc.proc_rxtx[1].frame_rx++;

                    // read in first symbol
                    AssertFatal (UE->frame_parms.ofdm_symbol_size+UE->frame_parms.nb_prefix_samples0 ==
                                 UE->rfdevice.trx_read_func(&UE->rfdevice,
                                                            &timestamp,
                                                            (void**)UE->common_vars.rxdata,
                                                            UE->frame_parms.ofdm_symbol_size+UE->frame_parms.nb_prefix_samples0,
                                                            UE->frame_parms.nb_antennas_rx),"");
                    slot_fep(UE,0, 0, 0, 0, 0);
                } //UE->mode != loop_through_memory
                else
                    rt_sleep_ns(1000*1000);

            } else {
                sub_frame++;
                sub_frame%=10;
                UE_rxtx_proc_t *proc = &UE->proc.proc_rxtx[sub_frame&1];

                if (UE->mode != loop_through_memory) {
                    for (i=0; i<UE->frame_parms.nb_antennas_rx; i++)
                        rxp[i] = (void*)&UE->common_vars.rxdata[i][UE->frame_parms.ofdm_symbol_size+
                                 UE->frame_parms.nb_prefix_samples0+
                                 sub_frame*UE->frame_parms.samples_per_tti];
                    for (i=0; i<UE->frame_parms.nb_antennas_tx; i++)
                        txp[i] = (void*)&UE->common_vars.txdata[i][((sub_frame+2)%10)*UE->frame_parms.samples_per_tti];

                    int readBlockSize, writeBlockSize;
                    if (sub_frame<9) {
                        readBlockSize=UE->frame_parms.samples_per_tti;
                        writeBlockSize=UE->frame_parms.samples_per_tti;
                    } else {
                        if ( UE->rx_offset < 5*UE->frame_parms.samples_per_tti  &&
                                UE->rx_offset > 0 )
                            UE->rx_offset_diff = -1 ;
                        if ( UE->rx_offset > 5*UE->frame_parms.samples_per_tti &&
                                UE->rx_offset < 10*UE->frame_parms.samples_per_tti )
                            UE->rx_offset_diff = 1;

                        LOG_D(PHY,"SET rx_off_diff to %d\n",UE->rx_offset_diff);
                        readBlockSize=UE->frame_parms.samples_per_tti -
                                      UE->frame_parms.ofdm_symbol_size -
                                      UE->frame_parms.nb_prefix_samples0 -
                                      UE->rx_offset_diff;
                        writeBlockSize=UE->frame_parms.samples_per_tti -
                                       UE->rx_offset_diff;
                    }

                    AssertFatal(readBlockSize ==
                                UE->rfdevice.trx_read_func(&UE->rfdevice,
                                                           &timestamp,
                                                           rxp,
                                                           readBlockSize,
                                                           UE->frame_parms.nb_antennas_rx),"");
                    AssertFatal( writeBlockSize ==
                                 UE->rfdevice.trx_write_func(&UE->rfdevice,
                                         timestamp+
                                         (2*UE->frame_parms.samples_per_tti) -
                                         UE->frame_parms.ofdm_symbol_size-UE->frame_parms.nb_prefix_samples0 -
                                         openair0_cfg[0].tx_sample_advance,
                                         txp,
                                         writeBlockSize,
                                         UE->frame_parms.nb_antennas_tx,
                                         1),"");
                    if( sub_frame==9) {
                        // read in first symbol of next frame and adjust for timing drift
                        int first_symbols=writeBlockSize-readBlockSize;
                        if ( first_symbols > 0 )
                            AssertFatal(first_symbols ==
                                        UE->rfdevice.trx_read_func(&UE->rfdevice,
                                                                   &timestamp1,
                                                                   (void**)UE->common_vars.rxdata,
                                                                   first_symbols,
                                                                   UE->frame_parms.nb_antennas_rx),"");
                        if ( first_symbols <0 )
                            LOG_E(PHY,"can't compensate: diff =%d\n", first_symbols);
                    }
                    pickTime(gotIQs);
                    // operate on thread sf mod 2
                    AssertFatal(pthread_mutex_lock(&proc->mutex_rxtx) ==0,"");
                    if(sub_frame == 0) {
                        UE->proc.proc_rxtx[0].frame_rx++;
                        UE->proc.proc_rxtx[1].frame_rx++;
                    }
                    UE->proc.proc_rxtx[0].gotIQs=readTime(gotIQs);
                    UE->proc.proc_rxtx[1].gotIQs=readTime(gotIQs);
                    proc->subframe_rx=sub_frame;
                    proc->subframe_tx=(sub_frame+4)%10;
                    proc->frame_tx = proc->frame_rx + (proc->subframe_rx>5?1:0);
                    proc->timestamp_tx = timestamp+
                                         (4*UE->frame_parms.samples_per_tti)-
                                         UE->frame_parms.ofdm_symbol_size-UE->frame_parms.nb_prefix_samples0;

                    AssertFatal (pthread_cond_signal(&proc->cond_rxtx) ==0 ,"");
                    AssertFatal(pthread_mutex_unlock(&proc->mutex_rxtx) ==0,"");
                    initRefTimes(t1);
                    initStaticTime(lastTime);
                    updateTimes(lastTime, &t1, 20000, "Delay between two IQ acquisitions (case 1)");
                    pickStaticTime(lastTime);

                } else {
                    printf("Processing subframe %d",proc->subframe_rx);
                    getchar();
                }
            } // start_rx_stream==1
        } // UE->is_synchronized==1

    } // while !oai_exit
    return NULL;
}

/*!
 * \brief Initialize the UE theads.
 * Creates the UE threads:
 * - UE_thread_rxtx0
 * - UE_thread_rxtx1
 * - UE_thread_synch
 * and the locking between them.
 */
void init_UE_threads(PHY_VARS_UE *UE) {

    pthread_attr_init (&UE->proc.attr_ue);
    pthread_attr_setstacksize(&UE->proc.attr_ue,8192);//5*PTHREAD_STACK_MIN);

    pthread_mutex_init(&UE->proc.mutex_synch,NULL);
    pthread_cond_init(&UE->proc.cond_synch,NULL);

    // the threads are not yet active, therefore access is allowed without locking
    int nb_threads=2;
    for (int i=0; i<nb_threads; i++) {
        pthread_mutex_init(&UE->proc.proc_rxtx[i].mutex_rxtx,NULL);
        pthread_cond_init(&UE->proc.proc_rxtx[i].cond_rxtx,NULL);
        UE->proc.proc_rxtx[i].sub_frame_start=i;
        UE->proc.proc_rxtx[i].sub_frame_step=nb_threads;
        pthread_create(&UE->proc.proc_rxtx[i].pthread_rxtx,NULL,UE_thread_rxn_txnp4,(void*)&UE->proc.proc_rxtx[i]);
    }
    pthread_create(&UE->proc.pthread_synch,NULL,UE_thread_synch,(void*)UE);

}


#ifdef OPENAIR2
void fill_ue_band_info(void) {

    UE_EUTRA_Capability_t *UE_EUTRA_Capability = UE_rrc_inst[0].UECap->UE_EUTRA_Capability;
    int i,j;

    bands_to_scan.nbands = UE_EUTRA_Capability->rf_Parameters.supportedBandListEUTRA.list.count;

    for (i=0; i<bands_to_scan.nbands; i++) {

        for (j=0; j<sizeof (eutra_bands) / sizeof (eutra_bands[0]); j++)
            if (eutra_bands[j].band == UE_EUTRA_Capability->rf_Parameters.supportedBandListEUTRA.list.array[i]->bandEUTRA) {
                memcpy(&bands_to_scan.band_info[i],
                       &eutra_bands[j],
                       sizeof(eutra_band_t));

                printf("Band %d (%lu) : DL %u..%u Hz, UL %u..%u Hz, Duplex %s \n",
                       bands_to_scan.band_info[i].band,
                       UE_EUTRA_Capability->rf_Parameters.supportedBandListEUTRA.list.array[i]->bandEUTRA,
                       bands_to_scan.band_info[i].dl_min,
                       bands_to_scan.band_info[i].dl_max,
                       bands_to_scan.band_info[i].ul_min,
                       bands_to_scan.band_info[i].ul_max,
                       (bands_to_scan.band_info[i].frame_type==FDD) ? "FDD" : "TDD");
                break;
            }
    }
}
#endif

int setup_ue_buffers(PHY_VARS_UE **phy_vars_ue, openair0_config_t *openair0_cfg) {

    int i, CC_id;
    LTE_DL_FRAME_PARMS *frame_parms;
    openair0_rf_map *rf_map;

    for (CC_id=0; CC_id<MAX_NUM_CCs; CC_id++) {
        rf_map = &phy_vars_ue[CC_id]->rf_map;

        AssertFatal( phy_vars_ue[CC_id] !=0, "");
        frame_parms = &(phy_vars_ue[CC_id]->frame_parms);

        // replace RX signal buffers with mmaped HW versions
        rxdata = (int32_t**)malloc16( frame_parms->nb_antennas_rx*sizeof(int32_t*) );
        txdata = (int32_t**)malloc16( frame_parms->nb_antennas_tx*sizeof(int32_t*) );

        for (i=0; i<frame_parms->nb_antennas_rx; i++) {
            LOG_I(PHY, "Mapping UE CC_id %d, rx_ant %d, freq %u on card %d, chain %d\n",
                  CC_id, i, downlink_frequency[CC_id][i], rf_map->card, rf_map->chain+i );
            free( phy_vars_ue[CC_id]->common_vars.rxdata[i] );
            rxdata[i] = (int32_t*)malloc16_clear( 307200*sizeof(int32_t) );
            phy_vars_ue[CC_id]->common_vars.rxdata[i] = rxdata[i]; // what about the "-N_TA_offset" ? // N_TA offset for TDD
        }

        for (i=0; i<frame_parms->nb_antennas_tx; i++) {
            LOG_I(PHY, "Mapping UE CC_id %d, tx_ant %d, freq %u on card %d, chain %d\n",
                  CC_id, i, downlink_frequency[CC_id][i], rf_map->card, rf_map->chain+i );
            free( phy_vars_ue[CC_id]->common_vars.txdata[i] );
            txdata[i] = (int32_t*)malloc16_clear( 307200*sizeof(int32_t) );
            phy_vars_ue[CC_id]->common_vars.txdata[i] = txdata[i];
        }

        // rxdata[x] points now to the same memory region as phy_vars_ue[CC_id]->common_vars.rxdata[x]
        // txdata[x] points now to the same memory region as phy_vars_ue[CC_id]->common_vars.txdata[x]
        // be careful when releasing memory!
        // because no "release_ue_buffers"-function is available, at least rxdata and txdata memory will leak (only some bytes)
    }
    return 0;
}
