/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "UL-CCCH-MessageType-NB.h"

static asn_per_constraints_t asn_PER_type_c1_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_UL_CCCH_MessageType_NB_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_c1_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB__c1, choice.rrcConnectionReestablishmentRequest_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RRCConnectionReestablishmentRequest_NB,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rrcConnectionReestablishmentRequest-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB__c1, choice.rrcConnectionRequest_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RRCConnectionRequest_NB,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rrcConnectionRequest-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB__c1, choice.rrcConnectionResumeRequest_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RRCConnectionResumeRequest_NB,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rrcConnectionResumeRequest-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB__c1, choice.spare1),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"spare1"
		},
};
static asn_TYPE_tag2member_t asn_MAP_c1_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rrcConnectionReestablishmentRequest-r13 at 11224 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rrcConnectionRequest-r13 at 11225 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rrcConnectionResumeRequest-r13 at 11226 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* spare1 at 11227 */
};
static asn_CHOICE_specifics_t asn_SPC_c1_specs_2 = {
	sizeof(struct UL_CCCH_MessageType_NB__c1),
	offsetof(struct UL_CCCH_MessageType_NB__c1, _asn_ctx),
	offsetof(struct UL_CCCH_MessageType_NB__c1, present),
	sizeof(((struct UL_CCCH_MessageType_NB__c1 *)0)->present),
	asn_MAP_c1_tag2el_2,
	4,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_c1_2 = {
	"c1",
	"c1",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_decode_aper,
	CHOICE_encode_aper,
	CHOICE_compare,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_c1_constr_2,
	asn_MBR_c1_2,
	4,	/* Elements count */
	&asn_SPC_c1_specs_2	/* Additional specs */
};

static ber_tlv_tag_t asn_DEF_messageClassExtension_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SEQUENCE_specifics_t asn_SPC_messageClassExtension_specs_7 = {
	sizeof(struct UL_CCCH_MessageType_NB__messageClassExtension),
	offsetof(struct UL_CCCH_MessageType_NB__messageClassExtension, _asn_ctx),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_messageClassExtension_7 = {
	"messageClassExtension",
	"messageClassExtension",
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
	asn_DEF_messageClassExtension_tags_7,
	sizeof(asn_DEF_messageClassExtension_tags_7)
		/sizeof(asn_DEF_messageClassExtension_tags_7[0]) - 1, /* 1 */
	asn_DEF_messageClassExtension_tags_7,	/* Same as above */
	sizeof(asn_DEF_messageClassExtension_tags_7)
		/sizeof(asn_DEF_messageClassExtension_tags_7[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	&asn_SPC_messageClassExtension_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_UL_CCCH_MessageType_NB_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB, choice.c1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_c1_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"c1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UL_CCCH_MessageType_NB, choice.messageClassExtension),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_messageClassExtension_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"messageClassExtension"
		},
};
static asn_TYPE_tag2member_t asn_MAP_UL_CCCH_MessageType_NB_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* c1 at 11224 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* messageClassExtension at 11229 */
};
static asn_CHOICE_specifics_t asn_SPC_UL_CCCH_MessageType_NB_specs_1 = {
	sizeof(struct UL_CCCH_MessageType_NB),
	offsetof(struct UL_CCCH_MessageType_NB, _asn_ctx),
	offsetof(struct UL_CCCH_MessageType_NB, present),
	sizeof(((struct UL_CCCH_MessageType_NB *)0)->present),
	asn_MAP_UL_CCCH_MessageType_NB_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_UL_CCCH_MessageType_NB = {
	"UL-CCCH-MessageType-NB",
	"UL-CCCH-MessageType-NB",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_decode_aper,
	CHOICE_encode_aper,
	CHOICE_compare,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_UL_CCCH_MessageType_NB_constr_1,
	asn_MBR_UL_CCCH_MessageType_NB_1,
	2,	/* Elements count */
	&asn_SPC_UL_CCCH_MessageType_NB_specs_1	/* Additional specs */
};

