/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_UL_CarrierConfigDedicated_NB_r13_H_
#define	_UL_CarrierConfigDedicated_NB_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CarrierFreq_NB_r13;

/* UL-CarrierConfigDedicated-NB-r13 */
typedef struct UL_CarrierConfigDedicated_NB_r13 {
	struct CarrierFreq_NB_r13	*ul_CarrierFreq_r13	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UL_CarrierConfigDedicated_NB_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UL_CarrierConfigDedicated_NB_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CarrierFreq-NB-r13.h"

#endif	/* _UL_CarrierConfigDedicated_NB_r13_H_ */
#include <asn_internal.h>
