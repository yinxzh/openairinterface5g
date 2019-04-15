/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "MBMS-SAI-InterFreq-NB-r14.h"

static asn_TYPE_member_t asn_MBR_MBMS_SAI_InterFreq_NB_r14_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MBMS_SAI_InterFreq_NB_r14, dl_CarrierFreq_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CarrierFreq_NB_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dl-CarrierFreq-r14"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MBMS_SAI_InterFreq_NB_r14, mbms_SAI_List_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBMS_SAI_List_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mbms-SAI-List-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct MBMS_SAI_InterFreq_NB_r14, multiBandInfoList_r14),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AdditionalBandInfoList_NB_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"multiBandInfoList-r14"
		},
};
static int asn_MAP_MBMS_SAI_InterFreq_NB_r14_oms_1[] = { 2 };
static ber_tlv_tag_t asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MBMS_SAI_InterFreq_NB_r14_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* dl-CarrierFreq-r14 at 11916 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mbms-SAI-List-r14 at 11917 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* multiBandInfoList-r14 at 11918 */
};
static asn_SEQUENCE_specifics_t asn_SPC_MBMS_SAI_InterFreq_NB_r14_specs_1 = {
	sizeof(struct MBMS_SAI_InterFreq_NB_r14),
	offsetof(struct MBMS_SAI_InterFreq_NB_r14, _asn_ctx),
	asn_MAP_MBMS_SAI_InterFreq_NB_r14_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_MBMS_SAI_InterFreq_NB_r14_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MBMS_SAI_InterFreq_NB_r14 = {
	"MBMS-SAI-InterFreq-NB-r14",
	"MBMS-SAI-InterFreq-NB-r14",
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
	asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1,
	sizeof(asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1)
		/sizeof(asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1[0]), /* 1 */
	asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1,	/* Same as above */
	sizeof(asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1)
		/sizeof(asn_DEF_MBMS_SAI_InterFreq_NB_r14_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_MBMS_SAI_InterFreq_NB_r14_1,
	3,	/* Elements count */
	&asn_SPC_MBMS_SAI_InterFreq_NB_r14_specs_1	/* Additional specs */
};
