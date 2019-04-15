/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "X2AP-PDU"
 * 	found in "/home/momo/openairinterface5g/openair2/X2AP/MESSAGES/ASN1/R11.2/X2AP-PDU.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_X2SetupFailure_H_
#define	_X2SetupFailure_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct X2ap_IE;

/* X2SetupFailure */
typedef struct X2SetupFailure {
	struct X2SetupFailure__x2SetupFailure_ies {
		A_SEQUENCE_OF(struct X2ap_IE) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} x2SetupFailure_ies;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} X2SetupFailure_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_X2SetupFailure;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "X2ap-IE.h"

#endif	/* _X2SetupFailure_H_ */
#include <asn_internal.h>
