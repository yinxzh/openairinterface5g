/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_AS_Config_v1430_H_
#define	_AS_Config_v1430_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SL_V2X_ConfigDedicated_r14;
struct LWA_Config_r13;
struct MeasResultListWLAN_r13;

/* AS-Config-v1430 */
typedef struct AS_Config_v1430 {
	struct SL_V2X_ConfigDedicated_r14	*sourceSL_V2X_CommConfig_r14	/* OPTIONAL */;
	struct LWA_Config_r13	*sourceLWA_Config_r14	/* OPTIONAL */;
	struct MeasResultListWLAN_r13	*sourceWLAN_MeasResult_r14	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AS_Config_v1430_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AS_Config_v1430;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SL-V2X-ConfigDedicated-r14.h"
#include "LWA-Config-r13.h"
#include "MeasResultListWLAN-r13.h"

#endif	/* _AS_Config_v1430_H_ */
#include <asn_internal.h>
