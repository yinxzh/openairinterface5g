/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "RRCConnectionReconfigurationComplete-v1430-IEs.h"

static int
memb_numFreqEffective_r14_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 12)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_numFreqEffectiveReduced_r14_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 12)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_numFreqEffective_r14_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  1,  12 }	/* (1..12) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_numFreqEffectiveReduced_r14_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  1,  12 }	/* (1..12) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static ber_tlv_tag_t asn_DEF_nonCriticalExtension_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SEQUENCE_specifics_t asn_SPC_nonCriticalExtension_specs_5 = {
	sizeof(struct RRCConnectionReconfigurationComplete_v1430_IEs__nonCriticalExtension),
	offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs__nonCriticalExtension, _asn_ctx),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nonCriticalExtension_5 = {
	"nonCriticalExtension",
	"nonCriticalExtension",
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
	asn_DEF_nonCriticalExtension_tags_5,
	sizeof(asn_DEF_nonCriticalExtension_tags_5)
		/sizeof(asn_DEF_nonCriticalExtension_tags_5[0]) - 1, /* 1 */
	asn_DEF_nonCriticalExtension_tags_5,	/* Same as above */
	sizeof(asn_DEF_nonCriticalExtension_tags_5)
		/sizeof(asn_DEF_nonCriticalExtension_tags_5[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	&asn_SPC_nonCriticalExtension_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RRCConnectionReconfigurationComplete_v1430_IEs_1[] = {
	{ ATF_POINTER, 4, offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs, perCC_GapIndicationList_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PerCC_GapIndicationList_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"perCC-GapIndicationList-r14"
		},
	{ ATF_POINTER, 3, offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs, numFreqEffective_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_numFreqEffective_r14_constraint_1,
		&asn_PER_memb_numFreqEffective_r14_constr_3,
		0,
		"numFreqEffective-r14"
		},
	{ ATF_POINTER, 2, offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs, numFreqEffectiveReduced_r14),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_numFreqEffectiveReduced_r14_constraint_1,
		&asn_PER_memb_numFreqEffectiveReduced_r14_constr_4,
		0,
		"numFreqEffectiveReduced-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_nonCriticalExtension_5,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_RRCConnectionReconfigurationComplete_v1430_IEs_oms_1[] = { 0, 1, 2, 3 };
static ber_tlv_tag_t asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_RRCConnectionReconfigurationComplete_v1430_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* perCC-GapIndicationList-r14 at 1110 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* numFreqEffective-r14 at 1111 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* numFreqEffectiveReduced-r14 at 1112 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* nonCriticalExtension at 1113 */
};
static asn_SEQUENCE_specifics_t asn_SPC_RRCConnectionReconfigurationComplete_v1430_IEs_specs_1 = {
	sizeof(struct RRCConnectionReconfigurationComplete_v1430_IEs),
	offsetof(struct RRCConnectionReconfigurationComplete_v1430_IEs, _asn_ctx),
	asn_MAP_RRCConnectionReconfigurationComplete_v1430_IEs_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_RRCConnectionReconfigurationComplete_v1430_IEs_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs = {
	"RRCConnectionReconfigurationComplete-v1430-IEs",
	"RRCConnectionReconfigurationComplete-v1430-IEs",
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
	asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1,
	sizeof(asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1)
		/sizeof(asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1[0]), /* 1 */
	asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1)
		/sizeof(asn_DEF_RRCConnectionReconfigurationComplete_v1430_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RRCConnectionReconfigurationComplete_v1430_IEs_1,
	4,	/* Elements count */
	&asn_SPC_RRCConnectionReconfigurationComplete_v1430_IEs_specs_1	/* Additional specs */
};

