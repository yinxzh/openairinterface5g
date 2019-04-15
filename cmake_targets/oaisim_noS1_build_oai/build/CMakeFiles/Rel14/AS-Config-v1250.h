/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_AS_Config_v1250_H_
#define	_AS_Config_v1250_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WLAN_OffloadConfig_r12;
struct SL_CommConfig_r12;
struct SL_DiscConfig_r12;

/* AS-Config-v1250 */
typedef struct AS_Config_v1250 {
	struct WLAN_OffloadConfig_r12	*sourceWlan_OffloadConfig_r12	/* OPTIONAL */;
	struct SL_CommConfig_r12	*sourceSL_CommConfig_r12	/* OPTIONAL */;
	struct SL_DiscConfig_r12	*sourceSL_DiscConfig_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AS_Config_v1250_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AS_Config_v1250;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WLAN-OffloadConfig-r12.h"
#include "SL-CommConfig-r12.h"
#include "SL-DiscConfig-r12.h"

#endif	/* _AS_Config_v1250_H_ */
#include <asn_internal.h>
