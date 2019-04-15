/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "ZeroTxPowerCSI-RS-Conf-r12.h"

static asn_per_constraints_t asn_PER_type_ZeroTxPowerCSI_RS_Conf_r12_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ZeroTxPowerCSI_RS_Conf_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ZeroTxPowerCSI_RS_Conf_r12, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ZeroTxPowerCSI_RS_Conf_r12, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ZeroTxPowerCSI_RS_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_ZeroTxPowerCSI_RS_Conf_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4093 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4095 */
};
static asn_CHOICE_specifics_t asn_SPC_ZeroTxPowerCSI_RS_Conf_r12_specs_1 = {
	sizeof(struct ZeroTxPowerCSI_RS_Conf_r12),
	offsetof(struct ZeroTxPowerCSI_RS_Conf_r12, _asn_ctx),
	offsetof(struct ZeroTxPowerCSI_RS_Conf_r12, present),
	sizeof(((struct ZeroTxPowerCSI_RS_Conf_r12 *)0)->present),
	asn_MAP_ZeroTxPowerCSI_RS_Conf_r12_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ZeroTxPowerCSI_RS_Conf_r12 = {
	"ZeroTxPowerCSI-RS-Conf-r12",
	"ZeroTxPowerCSI-RS-Conf-r12",
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
	&asn_PER_type_ZeroTxPowerCSI_RS_Conf_r12_constr_1,
	asn_MBR_ZeroTxPowerCSI_RS_Conf_r12_1,
	2,	/* Elements count */
	&asn_SPC_ZeroTxPowerCSI_RS_Conf_r12_specs_1	/* Additional specs */
};

