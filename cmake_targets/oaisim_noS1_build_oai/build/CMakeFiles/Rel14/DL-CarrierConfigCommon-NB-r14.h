/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_DL_CarrierConfigCommon_NB_r14_H_
#define	_DL_CarrierConfigCommon_NB_r14_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CarrierFreq-NB-r13.h"
#include <NativeEnumerated.h>
#include <NULL.h>
#include "DL-Bitmap-NB-r13.h"
#include <constr_CHOICE.h>
#include "DL-GapConfig-NB-r13.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR {
	DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR_NOTHING,	/* No components present */
	DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR_useNoBitmap_r14,
	DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR_useAnchorBitmap_r14,
	DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR_explicitBitmapConfiguration_r14
} DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR;
typedef enum DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR {
	DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR_NOTHING,	/* No components present */
	DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR_useNoGap_r14,
	DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR_useAnchorGapConfig_r14,
	DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR_explicitGapConfiguration_r14
} DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR;
typedef enum DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR {
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR_NOTHING,	/* No components present */
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR_samePCI_r14,
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR_differentPCI_r14
} DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR;
typedef enum DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__differentPCI_r14__eutra_NumCRS_Ports_r14 {
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__differentPCI_r14__eutra_NumCRS_Ports_r14_same	= 0,
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__differentPCI_r14__eutra_NumCRS_Ports_r14_four	= 1
} e_DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__differentPCI_r14__eutra_NumCRS_Ports_r14;
typedef enum DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__eutraControlRegionSize_r14 {
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__eutraControlRegionSize_r14_n1	= 0,
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__eutraControlRegionSize_r14_n2	= 1,
	DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__eutraControlRegionSize_r14_n3	= 2
} e_DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__eutraControlRegionSize_r14;
typedef enum DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14 {
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_12	= 0,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_10	= 1,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_8	= 2,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_6	= 3,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_4	= 4,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB_2	= 5,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB0	= 6,
	DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14_dB3	= 7
} e_DL_CarrierConfigCommon_NB_r14__nrs_PowerOffsetNonAnchor_r14;

/* DL-CarrierConfigCommon-NB-r14 */
typedef struct DL_CarrierConfigCommon_NB_r14 {
	CarrierFreq_NB_r13_t	 dl_CarrierFreq_r14;
	struct DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14 {
		DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_PR present;
		union DL_CarrierConfigCommon_NB_r14__downlinkBitmapNonAnchor_r14_u {
			NULL_t	 useNoBitmap_r14;
			NULL_t	 useAnchorBitmap_r14;
			DL_Bitmap_NB_r13_t	 explicitBitmapConfiguration_r14;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} downlinkBitmapNonAnchor_r14;
	struct DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14 {
		DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_PR present;
		union DL_CarrierConfigCommon_NB_r14__dl_GapNonAnchor_r14_u {
			NULL_t	 useNoGap_r14;
			NULL_t	 useAnchorGapConfig_r14;
			DL_GapConfig_NB_r13_t	 explicitGapConfiguration_r14;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} dl_GapNonAnchor_r14;
	struct DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14 {
		struct DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14 {
			DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_PR present;
			union DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14_u {
				struct DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__samePCI_r14 {
					long	 indexToMidPRB_r14;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} samePCI_r14;
				struct DL_CarrierConfigCommon_NB_r14__inbandCarrierInfo_r14__samePCI_Indicator_r14__differentPCI_r14 {
					long	 eutra_NumCRS_Ports_r14;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} differentPCI_r14;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *samePCI_Indicator_r14;
		long	 eutraControlRegionSize_r14;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *inbandCarrierInfo_r14;
	long	*nrs_PowerOffsetNonAnchor_r14	/* DEFAULT 6 */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DL_CarrierConfigCommon_NB_r14_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_eutra_NumCRS_Ports_r14_16;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_eutraControlRegionSize_r14_19;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_nrs_PowerOffsetNonAnchor_r14_23;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_DL_CarrierConfigCommon_NB_r14;

#ifdef __cplusplus
}
#endif

#endif	/* _DL_CarrierConfigCommon_NB_r14_H_ */
#include <asn_internal.h>
