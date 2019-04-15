/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "PUSCH-ConfigDedicatedSCell-v1430.h"

static asn_TYPE_member_t asn_MBR_PUSCH_ConfigDedicatedSCell_v1430_1[] = {
	{ ATF_POINTER, 1, offsetof(struct PUSCH_ConfigDedicatedSCell_v1430, enable256QAM_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_Enable256QAM_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"enable256QAM-r14"
		},
};
static int asn_MAP_PUSCH_ConfigDedicatedSCell_v1430_oms_1[] = { 0 };
static ber_tlv_tag_t asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PUSCH_ConfigDedicatedSCell_v1430_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* enable256QAM-r14 at 5542 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PUSCH_ConfigDedicatedSCell_v1430_specs_1 = {
	sizeof(struct PUSCH_ConfigDedicatedSCell_v1430),
	offsetof(struct PUSCH_ConfigDedicatedSCell_v1430, _asn_ctx),
	asn_MAP_PUSCH_ConfigDedicatedSCell_v1430_tag2el_1,
	1,	/* Count of tags in the map */
	asn_MAP_PUSCH_ConfigDedicatedSCell_v1430_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PUSCH_ConfigDedicatedSCell_v1430 = {
	"PUSCH-ConfigDedicatedSCell-v1430",
	"PUSCH-ConfigDedicatedSCell-v1430",
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
	asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1,
	sizeof(asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1)
		/sizeof(asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1[0]), /* 1 */
	asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1,	/* Same as above */
	sizeof(asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1)
		/sizeof(asn_DEF_PUSCH_ConfigDedicatedSCell_v1430_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PUSCH_ConfigDedicatedSCell_v1430_1,
	1,	/* Elements count */
	&asn_SPC_PUSCH_ConfigDedicatedSCell_v1430_specs_1	/* Additional specs */
};

