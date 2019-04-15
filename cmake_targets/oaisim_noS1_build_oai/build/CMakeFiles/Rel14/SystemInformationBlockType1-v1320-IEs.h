/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_SystemInformationBlockType1_v1320_IEs_H_
#define	_SystemInformationBlockType1_v1320_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__mpdcch_pdsch_HoppingNB_r13 {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__mpdcch_pdsch_HoppingNB_r13_nb2	= 0,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__mpdcch_pdsch_HoppingNB_r13_nb4	= 1
} e_SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__mpdcch_pdsch_HoppingNB_r13;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR_NOTHING,	/* No components present */
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR_interval_FDD_r13,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR_interval_TDD_r13
} SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13 {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int1	= 0,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int2	= 1,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int4	= 2,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int8	= 3
} e_SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13 {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int1	= 0,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int5	= 1,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int10	= 2,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int20	= 3
} e_SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR_NOTHING,	/* No components present */
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR_interval_FDD_r13,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR_interval_TDD_r13
} SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13 {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int2	= 0,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int4	= 1,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int8	= 2,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int16	= 3
} e_SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13;
typedef enum SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13 {
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int5	= 0,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int10	= 1,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int20	= 2,
	SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int40	= 3
} e_SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13;

/* Forward declarations */
struct SystemInformationBlockType1_v1350_IEs;

/* SystemInformationBlockType1-v1320-IEs */
typedef struct SystemInformationBlockType1_v1320_IEs {
	struct SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13 {
		long	*mpdcch_pdsch_HoppingNB_r13	/* OPTIONAL */;
		struct SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13 {
			SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_PR present;
			union SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeA_r13_u {
				long	 interval_FDD_r13;
				long	 interval_TDD_r13;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *interval_DLHoppingConfigCommonModeA_r13;
		struct SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13 {
			SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_PR present;
			union SystemInformationBlockType1_v1320_IEs__freqHoppingParametersDL_r13__interval_DLHoppingConfigCommonModeB_r13_u {
				long	 interval_FDD_r13;
				long	 interval_TDD_r13;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *interval_DLHoppingConfigCommonModeB_r13;
		long	*mpdcch_pdsch_HoppingOffset_r13	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *freqHoppingParametersDL_r13;
	struct SystemInformationBlockType1_v1350_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SystemInformationBlockType1_v1320_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_mpdcch_pdsch_HoppingNB_r13_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_7;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_12;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_18;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_23;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SystemInformationBlockType1_v1320_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SystemInformationBlockType1-v1350-IEs.h"

#endif	/* _SystemInformationBlockType1_v1320_IEs_H_ */
#include <asn_internal.h>
