/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_RadioResourceConfigCommonSCell_r10_H_
#define	_RadioResourceConfigCommonSCell_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include "AntennaInfoCommon.h"
#include "PHICH-Config.h"
#include "PDSCH-ConfigCommon.h"
#include <constr_SEQUENCE.h>
#include "P-Max.h"
#include "UplinkPowerControlCommonSCell-r10.h"
#include "SoundingRS-UL-ConfigCommon.h"
#include "UL-CyclicPrefixLength.h"
#include "PUSCH-ConfigCommon.h"
#include "ARFCN-ValueEUTRA.h"
#include "AdditionalSpectrumEmission.h"
#include "ARFCN-ValueEUTRA-v9e0.h"
#include "ARFCN-ValueEUTRA-r9.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10 {
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n6	= 0,
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n15	= 1,
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n25	= 2,
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n50	= 3,
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n75	= 4,
	RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10_n100	= 5
} e_RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10__dl_Bandwidth_r10;
typedef enum RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10 {
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n6	= 0,
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n15	= 1,
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n25	= 2,
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n50	= 3,
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n75	= 4,
	RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10_n100	= 5
} e_RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10__ul_Bandwidth_r10;
typedef enum RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14 {
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n6	= 0,
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n15	= 1,
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n25	= 2,
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n50	= 3,
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n75	= 4,
	RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14_n100	= 5
} e_RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14__ul_Bandwidth_r14;
typedef enum RadioResourceConfigCommonSCell_r10__ext5__harq_ReferenceConfig_r14 {
	RadioResourceConfigCommonSCell_r10__ext5__harq_ReferenceConfig_r14_sa2	= 0,
	RadioResourceConfigCommonSCell_r10__ext5__harq_ReferenceConfig_r14_sa4	= 1,
	RadioResourceConfigCommonSCell_r10__ext5__harq_ReferenceConfig_r14_sa5	= 2
} e_RadioResourceConfigCommonSCell_r10__ext5__harq_ReferenceConfig_r14;
typedef enum RadioResourceConfigCommonSCell_r10__ext5__soundingRS_FlexibleTiming_r14 {
	RadioResourceConfigCommonSCell_r10__ext5__soundingRS_FlexibleTiming_r14_true	= 0
} e_RadioResourceConfigCommonSCell_r10__ext5__soundingRS_FlexibleTiming_r14;

/* Forward declarations */
struct MBSFN_SubframeConfigList;
struct TDD_Config;
struct PRACH_ConfigSCell_r10;
struct RACH_ConfigCommonSCell_r11;
struct PRACH_Config;
struct TDD_Config_v1130;
struct UplinkPowerControlCommonSCell_v1130;
struct PUSCH_ConfigCommon_v1270;
struct PUCCH_ConfigCommon;
struct UplinkPowerControlCommonSCell_v1310;
struct HighSpeedConfigSCell_r14;
struct PRACH_Config_v1430;
struct UplinkPowerControlCommonPUSCH_LessCell_v1430;
struct MBSFN_SubframeConfigList_v1430;

/* RadioResourceConfigCommonSCell-r10 */
typedef struct RadioResourceConfigCommonSCell_r10 {
	struct RadioResourceConfigCommonSCell_r10__nonUL_Configuration_r10 {
		long	 dl_Bandwidth_r10;
		AntennaInfoCommon_t	 antennaInfoCommon_r10;
		struct MBSFN_SubframeConfigList	*mbsfn_SubframeConfigList_r10	/* OPTIONAL */;
		PHICH_Config_t	 phich_Config_r10;
		PDSCH_ConfigCommon_t	 pdsch_ConfigCommon_r10;
		struct TDD_Config	*tdd_Config_r10	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} nonUL_Configuration_r10;
	struct RadioResourceConfigCommonSCell_r10__ul_Configuration_r10 {
		struct RadioResourceConfigCommonSCell_r10__ul_Configuration_r10__ul_FreqInfo_r10 {
			ARFCN_ValueEUTRA_t	*ul_CarrierFreq_r10	/* OPTIONAL */;
			long	*ul_Bandwidth_r10	/* OPTIONAL */;
			AdditionalSpectrumEmission_t	 additionalSpectrumEmissionSCell_r10;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} ul_FreqInfo_r10;
		P_Max_t	*p_Max_r10	/* OPTIONAL */;
		UplinkPowerControlCommonSCell_r10_t	 uplinkPowerControlCommonSCell_r10;
		SoundingRS_UL_ConfigCommon_t	 soundingRS_UL_ConfigCommon_r10;
		UL_CyclicPrefixLength_t	 ul_CyclicPrefixLength_r10;
		struct PRACH_ConfigSCell_r10	*prach_ConfigSCell_r10	/* OPTIONAL */;
		PUSCH_ConfigCommon_t	 pusch_ConfigCommon_r10;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ul_Configuration_r10;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct RadioResourceConfigCommonSCell_r10__ext1 {
		ARFCN_ValueEUTRA_v9e0_t	*ul_CarrierFreq_v1090	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext1;
	struct RadioResourceConfigCommonSCell_r10__ext2 {
		struct RACH_ConfigCommonSCell_r11	*rach_ConfigCommonSCell_r11	/* OPTIONAL */;
		struct PRACH_Config	*prach_ConfigSCell_r11	/* OPTIONAL */;
		struct TDD_Config_v1130	*tdd_Config_v1130	/* OPTIONAL */;
		struct UplinkPowerControlCommonSCell_v1130	*uplinkPowerControlCommonSCell_v1130	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext2;
	struct RadioResourceConfigCommonSCell_r10__ext3 {
		struct PUSCH_ConfigCommon_v1270	*pusch_ConfigCommon_v1270	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext3;
	struct RadioResourceConfigCommonSCell_r10__ext4 {
		struct PUCCH_ConfigCommon	*pucch_ConfigCommon_r13	/* OPTIONAL */;
		struct UplinkPowerControlCommonSCell_v1310	*uplinkPowerControlCommonSCell_v1310	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext4;
	struct RadioResourceConfigCommonSCell_r10__ext5 {
		struct HighSpeedConfigSCell_r14	*highSpeedConfigSCell_r14	/* OPTIONAL */;
		struct PRACH_Config_v1430	*prach_Config_v1430	/* OPTIONAL */;
		struct RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14 {
			struct RadioResourceConfigCommonSCell_r10__ext5__ul_Configuration_r14__ul_FreqInfo_r14 {
				ARFCN_ValueEUTRA_r9_t	*ul_CarrierFreq_r14	/* OPTIONAL */;
				long	*ul_Bandwidth_r14	/* OPTIONAL */;
				AdditionalSpectrumEmission_t	 additionalSpectrumEmissionSCell_r14;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} ul_FreqInfo_r14;
			P_Max_t	*p_Max_r14	/* OPTIONAL */;
			SoundingRS_UL_ConfigCommon_t	 soundingRS_UL_ConfigCommon_r14;
			UL_CyclicPrefixLength_t	 ul_CyclicPrefixLength_r14;
			struct PRACH_ConfigSCell_r10	*prach_ConfigSCell_r14	/* OPTIONAL */;
			struct UplinkPowerControlCommonPUSCH_LessCell_v1430	*uplinkPowerControlCommonPUSCH_LessCell_v1430	/* OPTIONAL */;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *ul_Configuration_r14;
		long	*harq_ReferenceConfig_r14	/* OPTIONAL */;
		long	*soundingRS_FlexibleTiming_r14	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext5;
	struct RadioResourceConfigCommonSCell_r10__ext6 {
		struct MBSFN_SubframeConfigList_v1430	*mbsfn_SubframeConfigList_v1430	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext6;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RadioResourceConfigCommonSCell_r10_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_dl_Bandwidth_r10_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ul_Bandwidth_r10_18;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ul_Bandwidth_r14_51;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_harq_ReferenceConfig_r14_64;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_soundingRS_FlexibleTiming_r14_68;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigCommonSCell_r10;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MBSFN-SubframeConfigList.h"
#include "TDD-Config.h"
#include "PRACH-ConfigSCell-r10.h"
#include "RACH-ConfigCommonSCell-r11.h"
#include "PRACH-Config.h"
#include "TDD-Config-v1130.h"
#include "UplinkPowerControlCommonSCell-v1130.h"
#include "PUSCH-ConfigCommon-v1270.h"
#include "PUCCH-ConfigCommon.h"
#include "UplinkPowerControlCommonSCell-v1310.h"
#include "HighSpeedConfigSCell-r14.h"
#include "PRACH-Config-v1430.h"
#include "UplinkPowerControlCommonPUSCH-LessCell-v1430.h"
#include "MBSFN-SubframeConfigList-v1430.h"

#endif	/* _RadioResourceConfigCommonSCell_r10_H_ */
#include <asn_internal.h>
