# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# compile C with /usr/bin/cc
C_FLAGS =    -mavx2 -msse4.1 -mssse3  -std=gnu99 -Wall -Wstrict-prototypes -fno-strict-aliasing -rdynamic -funroll-loops -Wno-packed-bitfield-compat -fPIC  -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_FCNTL_H=1 -DHAVE_ARPA_INET_H=1 -DHAVE_SYS_TIME_H=1 -DHAVE_SYS_SOCKET_H=1 -DHAVE_STRERROR=1 -DHAVE_SOCKET=1 -DHAVE_MEMSET=1 -DHAVE_GETTIMEOFDAY=1 -DHAVE_STDLIB_H=1 -DHAVE_MALLOC=1 -DHAVE_LIBSCTP    -mavx2 -msse4.1 -mssse3  -std=gnu99 -Wall -Wstrict-prototypes -fno-strict-aliasing -rdynamic -funroll-loops -Wno-packed-bitfield-compat -fPIC  -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_FCNTL_H=1 -DHAVE_ARPA_INET_H=1 -DHAVE_SYS_TIME_H=1 -DHAVE_SYS_SOCKET_H=1 -DHAVE_STRERROR=1 -DHAVE_SOCKET=1 -DHAVE_MEMSET=1 -DHAVE_GETTIMEOFDAY=1 -DHAVE_STDLIB_H=1 -DHAVE_MALLOC=1 -DHAVE_LIBSCTP -g -DMALLOC_CHECK_=3 -fPIC -I/home/momo/openairinterface5g/cmake_targets/oaisim_noS1_build_oai/build/CMakeFiles/Rel14 -I/home/momo/openairinterface5g/cmake_targets/oaisim_noS1_build_oai/build/CMakeFiles/R10.5 -I/home/momo/openairinterface5g/openair3/S1AP -I/home/momo/openairinterface5g/cmake_targets/oaisim_noS1_build_oai/build/CMakeFiles/R11.2 -I/home/momo/openairinterface5g/openair2/X2AP -I/home/momo/openairinterface5g/targets/ARCH/EXMIMO/USERSPACE/LIB -I/home/momo/openairinterface5g/targets/ARCH/EXMIMO/DEFS -I/home/momo/openairinterface5g/targets/ARCH/USRP/USERSPACE/LIB -I/home/momo/openairinterface5g/targets/ARCH/BLADERF/USERSPACE/LIB -I/home/momo/openairinterface5g/targets/ARCH/LMSSDR/USERSPACE/LIB -I/home/momo/openairinterface5g/targets/ARCH/ETHERNET/USERSPACE/LIB -I/home/momo/openairinterface5g/targets/ARCH/COMMON -I/home/momo/openairinterface5g/cmake_targets/oaisim_noS1_build_oai/build/CMakeFiles -I/home/momo/openairinterface5g/openair2/COMMON -I/home/momo/openairinterface5g/openair2/UTIL -I/home/momo/openairinterface5g/openair2/UTIL/LOG -I/home/momo/openairinterface5g/openair3/COMMON -I/home/momo/openairinterface5g/openair3/UTILS -I/home/momo/openairinterface5g/openair1 -I/home/momo/openairinterface5g/openair2/NAS -I/home/momo/openairinterface5g/openair2 -I/home/momo/openairinterface5g/openair2/LAYER2/RLC -I/home/momo/openairinterface5g/openair2/LAYER2/RLC/AM_v9.3.0 -I/home/momo/openairinterface5g/openair2/LAYER2/RLC/UM_v9.3.0 -I/home/momo/openairinterface5g/openair2/LAYER2/RLC/TM_v9.3.0 -I/home/momo/openairinterface5g/openair2/LAYER2/PDCP_v10.1.0 -I/home/momo/openairinterface5g/openair2/RRC/LITE/MESSAGES -I/home/momo/openairinterface5g/openair2/RRC/LITE -I/home/momo/openairinterface5g/openair3/RAL-LTE/INTERFACE-802.21/INCLUDE -I/home/momo/openairinterface5g/openair3/RAL-LTE/LTE_RAL_ENB/INCLUDE -I/home/momo/openairinterface5g/openair3/RAL-LTE/LTE_RAL_UE/INCLUDE -I/home/momo/openairinterface5g/common/utils -I/home/momo/openairinterface5g/common/utils/itti -I/home/momo/openairinterface5g/openair3/NAS/COMMON -I/home/momo/openairinterface5g/openair3/NAS/COMMON/API/NETWORK -I/home/momo/openairinterface5g/openair3/NAS/COMMON/EMM/MSG -I/home/momo/openairinterface5g/openair3/NAS/COMMON/ESM/MSG -I/home/momo/openairinterface5g/openair3/NAS/COMMON/IES -I/home/momo/openairinterface5g/openair3/NAS/COMMON/UTIL -I/home/momo/openairinterface5g/openair3/SECU -I/home/momo/openairinterface5g/openair3/SCTP -I/home/momo/openairinterface5g/openair3/UDP -I/home/momo/openairinterface5g/openair3/GTPV1-U -I/home/momo/openairinterface5g/targets/COMMON -I/home/momo/openairinterface5g/openair2/ENB_APP -I/home/momo/openairinterface5g/openair2/ENB_APP/CONTROL_MODULES/MAC -I/home/momo/openairinterface5g/openair2/UTIL/OSA -I/home/momo/openairinterface5g/openair2/UTIL/LFDS/liblfds6.1.1/liblfds611/inc -I/home/momo/openairinterface5g/openair2/UTIL/LFDS/liblfds7.0.0/liblfds700/inc -I/home/momo/openairinterface5g/openair2/UTIL/MEM -I/home/momo/openairinterface5g/openair2/UTIL/LISTS -I/home/momo/openairinterface5g/openair2/UTIL/FIFO -I/home/momo/openairinterface5g/openair2/UTIL/OCG -I/home/momo/openairinterface5g/openair2/UTIL/MATH -I/home/momo/openairinterface5g/openair2/UTIL/TIMER -I/home/momo/openairinterface5g/openair2/UTIL/OMG -I/home/momo/openairinterface5g/openair2/UTIL/OTG -I/home/momo/openairinterface5g/openair2/UTIL/CLI -I/home/momo/openairinterface5g/openair2/UTIL/OPT -I/home/momo/openairinterface5g/openair2/UTIL/OMV -I/home/momo/openairinterface5g/openair3/GTPV1-U/nw-gtpv1u/shared -I/home/momo/openairinterface5g/openair3/GTPV1-U/nw-gtpv1u/include -I/home/momo/openairinterface5g -I/home/momo/openairinterface5g/common/utils/hashtable -I/home/momo/openairinterface5g/common/utils/msc -I/home/momo/openairinterface5g/openair2/UTIL/LFDS/liblfds6.1.1/liblfds611/src -I/home/momo/openairinterface5g/openair2/UTIL/LFDS/liblfds7.0.0/liblfds700/src -I/usr/include/libxml2 -I/usr/include/pgm-5.1 -I/usr/lib/x86_64-linux-gnu/pgm-5.1/include -I/usr/include/atlas -I/usr/include/X11 -I/home/momo/openairinterface5g/common/utils/T    -DUPDATE_RELEASE_9 -DUPDATE_RELEASE_10

C_DEFINES = -DASN1_MINIMUM_VERSION=924 -DCMAKER -DCMAKE_BUILD_TYPE=\"Debug\" -DDRIVER2013 -DENABLE_FXP -DENABLE_ITTI -DENABLE_NEW_MULTICAST -DENABLE_PGM_TRANSPORT -DENABLE_USE_CPU_EXECUTION_TIME -DENABLE_VCD -DENB_MODE -DEXMIMO_IOT -DFIRMWARE_VERSION="\"No svn information\"" -DJUMBO_FRAME -DLINUX -DLOG_NO_THREAD -DMAC_CONTEXT -DMAX_NUM_CCs=1 -DNAS_ADDRESS_FIX -DNB_ANTENNAS_RX=2 -DNB_ANTENNAS_TX=2 -DNB_ANTENNAS_TXRX=2 -DNB_IOT -DNETTLE_VERSION_MAJOR=2 -DNETTLE_VERSION_MINOR=7 -DNEW_FFT -DNO_RRM -DNone=1 -DOAISIM -DOAI_EMU -DOAI_NW_DRIVER_USE_NETLINK -DOPENAIR1 -DOPENAIR2 -DOPENAIR_LTE -DPACKAGE_BUGREPORT=\"openair4g-devel@lists.eurecom.fr\" -DPACKAGE_NAME=\"oaisim\" -DPACKAGE_VERSION="\"Branch: develop-nb-iot Abrev. Hash: d38f75b Date: Fri May 4 15:14:47 2018 +0200\"" -DPC_DSP -DPC_TARGET -DPDCP_USE_NETLINK -DPHYSIM -DPHY_ABSTRACTION -DPRINT_STATS -DPUCCH -DRel14=1 -DS1AP_VERSION=R10 -DTRACE_RLC_MUTEX -DUSER_MODE -DX2AP_VERSION=R11 -DXFORMS -Doai_exmimodevif_EXPORTS

