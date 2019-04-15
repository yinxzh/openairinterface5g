/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "AS-Context-v1320.h"

static int
memb_wlanConnectionStatusReport_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

static asn_per_constraints_t asn_PER_memb_wlanConnectionStatusReport_r13_constr_2 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_AS_Context_v1320_1[] = {
	{ ATF_POINTER, 1, offsetof(struct AS_Context_v1320, wlanConnectionStatusReport_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_wlanConnectionStatusReport_r13_constraint_1,
		&asn_PER_memb_wlanConnectionStatusReport_r13_constr_2,
		0,
		"wlanConnectionStatusReport-r13"
		},
};
static int asn_MAP_AS_Context_v1320_oms_1[] = { 0 };
static ber_tlv_tag_t asn_DEF_AS_Context_v1320_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AS_Context_v1320_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* wlanConnectionStatusReport-r13 at 13610 */
};
static asn_SEQUENCE_specifics_t asn_SPC_AS_Context_v1320_specs_1 = {
	sizeof(struct AS_Context_v1320),
	offsetof(struct AS_Context_v1320, _asn_ctx),
	asn_MAP_AS_Context_v1320_tag2el_1,
	1,	/* Count of tags in the map */
	asn_MAP_AS_Context_v1320_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AS_Context_v1320 = {
	"AS-Context-v1320",
	"AS-Context-v1320",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	SEQUENCE_decode_aper,
	SEQUENCE_encode_aper,
	SEQUENCE_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AS_Context_v1320_tags_1,
	sizeof(asn_DEF_AS_Context_v1320_tags_1)
		/sizeof(asn_DEF_AS_Context_v1320_tags_1[0]), /* 1 */
	asn_DEF_AS_Context_v1320_tags_1,	/* Same as above */
	sizeof(asn_DEF_AS_Context_v1320_tags_1)
		/sizeof(asn_DEF_AS_Context_v1320_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_AS_Context_v1320_1,
	1,	/* Elements count */
	&asn_SPC_AS_Context_v1320_specs_1	/* Additional specs */
};

