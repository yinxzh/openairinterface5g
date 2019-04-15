/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_SystemInformationBlockType1_v1360_IEs_H_
#define	_SystemInformationBlockType1_v1360_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CellSelectionInfoCE1_v1360;
struct SystemInformationBlockType1_v1430_IEs;

/* SystemInformationBlockType1-v1360-IEs */
typedef struct SystemInformationBlockType1_v1360_IEs {
	struct CellSelectionInfoCE1_v1360	*cellSelectionInfoCE1_v1360	/* OPTIONAL */;
	struct SystemInformationBlockType1_v1430_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SystemInformationBlockType1_v1360_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SystemInformationBlockType1_v1360_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CellSelectionInfoCE1-v1360.h"
#include "SystemInformationBlockType1-v1430-IEs.h"

#endif	/* _SystemInformationBlockType1_v1360_IEs_H_ */
#include <asn_internal.h>
