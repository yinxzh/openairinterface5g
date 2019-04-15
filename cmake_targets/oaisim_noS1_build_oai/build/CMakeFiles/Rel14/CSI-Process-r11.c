/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "CSI-Process-r11.h"

static int
alternativeCodebookEnabledFor4TXProc_r12_11_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	td->aper_decoder   = asn_DEF_NativeEnumerated.aper_decoder;
	td->aper_encoder   = asn_DEF_NativeEnumerated.aper_encoder;
	td->compare        = asn_DEF_NativeEnumerated.compare;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
alternativeCodebookEnabledFor4TXProc_r12_11_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
alternativeCodebookEnabledFor4TXProc_r12_11_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
alternativeCodebookEnabledFor4TXProc_r12_11_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td1);
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
alternativeCodebookEnabledFor4TXProc_r12_11_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	alternativeCodebookEnabledFor4TXProc_r12_11_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
memb_setup_constraint_13(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 2)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_cqi_ReportPeriodicProcId_r11_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 3)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_alternativeCodebookEnabledFor4TXProc_r12_constr_11 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_setup_constr_15 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 1,  1,  1,  2 }	/* (SIZE(1..2)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_setup_constr_15 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 1,  1,  1,  2 }	/* (SIZE(1..2)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_csi_IM_ConfigIdList_r12_constr_13 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_cqi_ReportAperiodicProc2_r12_constr_17 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_cqi_ReportAperiodicProc_v1310_constr_21 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_cqi_ReportAperiodicProc2_v1310_constr_24 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_cqi_ReportPeriodicProcId_r11_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_alternativeCodebookEnabledFor4TXProc_r12_value2enum_11[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_alternativeCodebookEnabledFor4TXProc_r12_enum2value_11[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_alternativeCodebookEnabledFor4TXProc_r12_specs_11 = {
	asn_MAP_alternativeCodebookEnabledFor4TXProc_r12_value2enum_11,	/* "tag" => N; sorted by tag */
	asn_MAP_alternativeCodebookEnabledFor4TXProc_r12_enum2value_11,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_11 = {
	"alternativeCodebookEnabledFor4TXProc-r12",
	"alternativeCodebookEnabledFor4TXProc-r12",
	alternativeCodebookEnabledFor4TXProc_r12_11_free,
	alternativeCodebookEnabledFor4TXProc_r12_11_print,
	alternativeCodebookEnabledFor4TXProc_r12_11_constraint,
	alternativeCodebookEnabledFor4TXProc_r12_11_decode_ber,
	alternativeCodebookEnabledFor4TXProc_r12_11_encode_der,
	alternativeCodebookEnabledFor4TXProc_r12_11_decode_xer,
	alternativeCodebookEnabledFor4TXProc_r12_11_encode_xer,
	alternativeCodebookEnabledFor4TXProc_r12_11_decode_uper,
	alternativeCodebookEnabledFor4TXProc_r12_11_encode_uper,
	alternativeCodebookEnabledFor4TXProc_r12_11_decode_aper,
	alternativeCodebookEnabledFor4TXProc_r12_11_encode_aper,
	alternativeCodebookEnabledFor4TXProc_r12_11_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11,
	sizeof(asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11)
		/sizeof(asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11[0]) - 1, /* 1 */
	asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11,	/* Same as above */
	sizeof(asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11)
		/sizeof(asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_tags_11[0]), /* 2 */
	&asn_PER_type_alternativeCodebookEnabledFor4TXProc_r12_constr_11,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_alternativeCodebookEnabledFor4TXProc_r12_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_15[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_CSI_IM_ConfigId_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_setup_tags_15[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_setup_specs_15 = {
	sizeof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12__setup),
	offsetof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12__setup, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_15 = {
	"setup",
	"setup",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	SEQUENCE_OF_decode_aper,
	SEQUENCE_OF_encode_aper,
	SEQUENCE_OF_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_setup_tags_15,
	sizeof(asn_DEF_setup_tags_15)
		/sizeof(asn_DEF_setup_tags_15[0]) - 1, /* 1 */
	asn_DEF_setup_tags_15,	/* Same as above */
	sizeof(asn_DEF_setup_tags_15)
		/sizeof(asn_DEF_setup_tags_15[0]), /* 2 */
	&asn_PER_type_setup_constr_15,
	asn_MBR_setup_15,
	1,	/* Single element */
	&asn_SPC_setup_specs_15	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_csi_IM_ConfigIdList_r12_13[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_15,
		memb_setup_constraint_13,
		&asn_PER_memb_setup_constr_15,
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_csi_IM_ConfigIdList_r12_tag2el_13[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4031 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4033 */
};
static asn_CHOICE_specifics_t asn_SPC_csi_IM_ConfigIdList_r12_specs_13 = {
	sizeof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12),
	offsetof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12, _asn_ctx),
	offsetof(struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12, present),
	sizeof(((struct CSI_Process_r11__ext1__csi_IM_ConfigIdList_r12 *)0)->present),
	asn_MAP_csi_IM_ConfigIdList_r12_tag2el_13,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_csi_IM_ConfigIdList_r12_13 = {
	"csi-IM-ConfigIdList-r12",
	"csi-IM-ConfigIdList-r12",
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
	&asn_PER_type_csi_IM_ConfigIdList_r12_constr_13,
	asn_MBR_csi_IM_ConfigIdList_r12_13,
	2,	/* Elements count */
	&asn_SPC_csi_IM_ConfigIdList_r12_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_cqi_ReportAperiodicProc2_r12_17[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CQI_ReportAperiodicProc_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_cqi_ReportAperiodicProc2_r12_tag2el_17[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4035 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4037 */
};
static asn_CHOICE_specifics_t asn_SPC_cqi_ReportAperiodicProc2_r12_specs_17 = {
	sizeof(struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12),
	offsetof(struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12, _asn_ctx),
	offsetof(struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12, present),
	sizeof(((struct CSI_Process_r11__ext1__cqi_ReportAperiodicProc2_r12 *)0)->present),
	asn_MAP_cqi_ReportAperiodicProc2_r12_tag2el_17,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cqi_ReportAperiodicProc2_r12_17 = {
	"cqi-ReportAperiodicProc2-r12",
	"cqi-ReportAperiodicProc2-r12",
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
	&asn_PER_type_cqi_ReportAperiodicProc2_r12_constr_17,
	asn_MBR_cqi_ReportAperiodicProc2_r12_17,
	2,	/* Elements count */
	&asn_SPC_cqi_ReportAperiodicProc2_r12_specs_17	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext1_10[] = {
	{ ATF_POINTER, 3, offsetof(struct CSI_Process_r11__ext1, alternativeCodebookEnabledFor4TXProc_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_alternativeCodebookEnabledFor4TXProc_r12_11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"alternativeCodebookEnabledFor4TXProc-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_Process_r11__ext1, csi_IM_ConfigIdList_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_csi_IM_ConfigIdList_r12_13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-IM-ConfigIdList-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_Process_r11__ext1, cqi_ReportAperiodicProc2_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_cqi_ReportAperiodicProc2_r12_17,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cqi-ReportAperiodicProc2-r12"
		},
};
static int asn_MAP_ext1_oms_10[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_ext1_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext1_tag2el_10[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* alternativeCodebookEnabledFor4TXProc-r12 at 4029 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* csi-IM-ConfigIdList-r12 at 4031 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* cqi-ReportAperiodicProc2-r12 at 4035 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext1_specs_10 = {
	sizeof(struct CSI_Process_r11__ext1),
	offsetof(struct CSI_Process_r11__ext1, _asn_ctx),
	asn_MAP_ext1_tag2el_10,
	3,	/* Count of tags in the map */
	asn_MAP_ext1_oms_10,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext1_10 = {
	"ext1",
	"ext1",
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
	asn_DEF_ext1_tags_10,
	sizeof(asn_DEF_ext1_tags_10)
		/sizeof(asn_DEF_ext1_tags_10[0]) - 1, /* 1 */
	asn_DEF_ext1_tags_10,	/* Same as above */
	sizeof(asn_DEF_ext1_tags_10)
		/sizeof(asn_DEF_ext1_tags_10[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext1_10,
	3,	/* Elements count */
	&asn_SPC_ext1_specs_10	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_cqi_ReportAperiodicProc_v1310_21[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CQI_ReportAperiodicProc_v1310,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_cqi_ReportAperiodicProc_v1310_tag2el_21[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4040 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4042 */
};
static asn_CHOICE_specifics_t asn_SPC_cqi_ReportAperiodicProc_v1310_specs_21 = {
	sizeof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310),
	offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310, _asn_ctx),
	offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310, present),
	sizeof(((struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc_v1310 *)0)->present),
	asn_MAP_cqi_ReportAperiodicProc_v1310_tag2el_21,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cqi_ReportAperiodicProc_v1310_21 = {
	"cqi-ReportAperiodicProc-v1310",
	"cqi-ReportAperiodicProc-v1310",
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
	&asn_PER_type_cqi_ReportAperiodicProc_v1310_constr_21,
	asn_MBR_cqi_ReportAperiodicProc_v1310_21,
	2,	/* Elements count */
	&asn_SPC_cqi_ReportAperiodicProc_v1310_specs_21	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_cqi_ReportAperiodicProc2_v1310_24[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CQI_ReportAperiodicProc_v1310,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_cqi_ReportAperiodicProc2_v1310_tag2el_24[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4044 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4046 */
};
static asn_CHOICE_specifics_t asn_SPC_cqi_ReportAperiodicProc2_v1310_specs_24 = {
	sizeof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310),
	offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310, _asn_ctx),
	offsetof(struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310, present),
	sizeof(((struct CSI_Process_r11__ext2__cqi_ReportAperiodicProc2_v1310 *)0)->present),
	asn_MAP_cqi_ReportAperiodicProc2_v1310_tag2el_24,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cqi_ReportAperiodicProc2_v1310_24 = {
	"cqi-ReportAperiodicProc2-v1310",
	"cqi-ReportAperiodicProc2-v1310",
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
	&asn_PER_type_cqi_ReportAperiodicProc2_v1310_constr_24,
	asn_MBR_cqi_ReportAperiodicProc2_v1310_24,
	2,	/* Elements count */
	&asn_SPC_cqi_ReportAperiodicProc2_v1310_specs_24	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext2_20[] = {
	{ ATF_POINTER, 3, offsetof(struct CSI_Process_r11__ext2, cqi_ReportAperiodicProc_v1310),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_cqi_ReportAperiodicProc_v1310_21,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cqi-ReportAperiodicProc-v1310"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_Process_r11__ext2, cqi_ReportAperiodicProc2_v1310),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_cqi_ReportAperiodicProc2_v1310_24,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cqi-ReportAperiodicProc2-v1310"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_Process_r11__ext2, eMIMO_Type_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigEMIMO_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"eMIMO-Type-r13"
		},
};
static int asn_MAP_ext2_oms_20[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_ext2_tags_20[] = {
	(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext2_tag2el_20[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cqi-ReportAperiodicProc-v1310 at 4040 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* cqi-ReportAperiodicProc2-v1310 at 4044 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* eMIMO-Type-r13 at 4047 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext2_specs_20 = {
	sizeof(struct CSI_Process_r11__ext2),
	offsetof(struct CSI_Process_r11__ext2, _asn_ctx),
	asn_MAP_ext2_tag2el_20,
	3,	/* Count of tags in the map */
	asn_MAP_ext2_oms_20,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext2_20 = {
	"ext2",
	"ext2",
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
	asn_DEF_ext2_tags_20,
	sizeof(asn_DEF_ext2_tags_20)
		/sizeof(asn_DEF_ext2_tags_20[0]) - 1, /* 1 */
	asn_DEF_ext2_tags_20,	/* Same as above */
	sizeof(asn_DEF_ext2_tags_20)
		/sizeof(asn_DEF_ext2_tags_20[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext2_20,
	3,	/* Elements count */
	&asn_SPC_ext2_specs_20	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext3_28[] = {
	{ ATF_POINTER, 3, offsetof(struct CSI_Process_r11__ext3, eMIMO_Type_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigEMIMO_v1430,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"eMIMO-Type-v1430"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_Process_r11__ext3, eMIMO_Hybrid_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigEMIMO_Hybrid_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"eMIMO-Hybrid-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_Process_r11__ext3, advancedCodebookEnabled_r14),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"advancedCodebookEnabled-r14"
		},
};
static int asn_MAP_ext3_oms_28[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_ext3_tags_28[] = {
	(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext3_tag2el_28[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* eMIMO-Type-v1430 at 4049 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* eMIMO-Hybrid-r14 at 4050 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* advancedCodebookEnabled-r14 at 4051 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext3_specs_28 = {
	sizeof(struct CSI_Process_r11__ext3),
	offsetof(struct CSI_Process_r11__ext3, _asn_ctx),
	asn_MAP_ext3_tag2el_28,
	3,	/* Count of tags in the map */
	asn_MAP_ext3_oms_28,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext3_28 = {
	"ext3",
	"ext3",
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
	asn_DEF_ext3_tags_28,
	sizeof(asn_DEF_ext3_tags_28)
		/sizeof(asn_DEF_ext3_tags_28[0]) - 1, /* 1 */
	asn_DEF_ext3_tags_28,	/* Same as above */
	sizeof(asn_DEF_ext3_tags_28)
		/sizeof(asn_DEF_ext3_tags_28[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext3_28,
	3,	/* Elements count */
	&asn_SPC_ext3_specs_28	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_CSI_Process_r11_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11, csi_ProcessId_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_ProcessId_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-ProcessId-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11, csi_RS_ConfigNZPId_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigNZPId_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-RS-ConfigNZPId-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11, csi_IM_ConfigId_r11),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_IM_ConfigId_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-IM-ConfigId-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_Process_r11, p_C_AndCBSRList_r11),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_P_C_AndCBSR_Pair_r13a,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"p-C-AndCBSRList-r11"
		},
	{ ATF_POINTER, 6, offsetof(struct CSI_Process_r11, cqi_ReportBothProc_r11),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CQI_ReportBothProc_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cqi-ReportBothProc-r11"
		},
	{ ATF_POINTER, 5, offsetof(struct CSI_Process_r11, cqi_ReportPeriodicProcId_r11),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_cqi_ReportPeriodicProcId_r11_constraint_1,
		&asn_PER_memb_cqi_ReportPeriodicProcId_r11_constr_7,
		0,
		"cqi-ReportPeriodicProcId-r11"
		},
	{ ATF_POINTER, 4, offsetof(struct CSI_Process_r11, cqi_ReportAperiodicProc_r11),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CQI_ReportAperiodicProc_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cqi-ReportAperiodicProc-r11"
		},
	{ ATF_POINTER, 3, offsetof(struct CSI_Process_r11, ext1),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		0,
		&asn_DEF_ext1_10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext1"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_Process_r11, ext2),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		0,
		&asn_DEF_ext2_20,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext2"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_Process_r11, ext3),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		0,
		&asn_DEF_ext3_28,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext3"
		},
};
static int asn_MAP_CSI_Process_r11_oms_1[] = { 4, 5, 6, 7, 8, 9 };
static ber_tlv_tag_t asn_DEF_CSI_Process_r11_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CSI_Process_r11_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* csi-ProcessId-r11 at 4021 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* csi-RS-ConfigNZPId-r11 at 4022 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* csi-IM-ConfigId-r11 at 4023 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* p-C-AndCBSRList-r11 at 4024 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* cqi-ReportBothProc-r11 at 4025 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* cqi-ReportPeriodicProcId-r11 at 4026 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* cqi-ReportAperiodicProc-r11 at 4027 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* ext1 at 4029 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* ext2 at 4042 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* ext3 at 4049 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CSI_Process_r11_specs_1 = {
	sizeof(struct CSI_Process_r11),
	offsetof(struct CSI_Process_r11, _asn_ctx),
	asn_MAP_CSI_Process_r11_tag2el_1,
	10,	/* Count of tags in the map */
	asn_MAP_CSI_Process_r11_oms_1,	/* Optional members */
	3, 3,	/* Root/Additions */
	6,	/* Start extensions */
	11	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CSI_Process_r11 = {
	"CSI-Process-r11",
	"CSI-Process-r11",
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
	asn_DEF_CSI_Process_r11_tags_1,
	sizeof(asn_DEF_CSI_Process_r11_tags_1)
		/sizeof(asn_DEF_CSI_Process_r11_tags_1[0]), /* 1 */
	asn_DEF_CSI_Process_r11_tags_1,	/* Same as above */
	sizeof(asn_DEF_CSI_Process_r11_tags_1)
		/sizeof(asn_DEF_CSI_Process_r11_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CSI_Process_r11_1,
	10,	/* Elements count */
	&asn_SPC_CSI_Process_r11_specs_1	/* Additional specs */
};

