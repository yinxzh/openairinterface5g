/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "CSI-RS-ConfigNZP-r11.h"

static int
antennaPortsCount_r11_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
antennaPortsCount_r11_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
antennaPortsCount_r11_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
antennaPortsCount_r11_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
antennaPortsCount_r11_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
antennaPortsCount_r11_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
antennaPortsCount_r11_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
antennaPortsCount_r11_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
antennaPortsCount_r11_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
antennaPortsCount_r11_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
antennaPortsCount_r11_3_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
antennaPortsCount_r11_3_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td1);
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
antennaPortsCount_r11_3_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	antennaPortsCount_r11_3_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
crs_PortsCount_r11_13_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
crs_PortsCount_r11_13_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
crs_PortsCount_r11_13_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
crs_PortsCount_r11_13_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
crs_PortsCount_r11_13_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
crs_PortsCount_r11_13_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
crs_PortsCount_r11_13_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
crs_PortsCount_r11_13_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
crs_PortsCount_r11_13_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
crs_PortsCount_r11_13_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
crs_PortsCount_r11_13_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
crs_PortsCount_r11_13_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td1);
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
crs_PortsCount_r11_13_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	crs_PortsCount_r11_13_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
memb_qcl_ScramblingIdentity_r11_constraint_11(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 503)) {
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
memb_resourceConfig_r11_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 31)) {
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
memb_subframeConfig_r11_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 154)) {
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
memb_scramblingIdentity_r11_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 503)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_antennaPortsCount_r11_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_crs_PortsCount_r11_constr_13 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_mbsfn_SubframeConfigList_r11_constr_18 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_qcl_ScramblingIdentity_r11_constr_12 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  503 }	/* (0..503) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_mbsfn_SubframeConfigList_v1430_constr_29 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_resourceConfig_r11_constr_8 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  0,  31 }	/* (0..31) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_subframeConfig_r11_constr_9 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  154 }	/* (0..154) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_scramblingIdentity_r11_constr_10 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  503 }	/* (0..503) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_antennaPortsCount_r11_value2enum_3[] = {
	{ 0,	3,	"an1" },
	{ 1,	3,	"an2" },
	{ 2,	3,	"an4" },
	{ 3,	3,	"an8" }
};
static unsigned int asn_MAP_antennaPortsCount_r11_enum2value_3[] = {
	0,	/* an1(0) */
	1,	/* an2(1) */
	2,	/* an4(2) */
	3	/* an8(3) */
};
static asn_INTEGER_specifics_t asn_SPC_antennaPortsCount_r11_specs_3 = {
	asn_MAP_antennaPortsCount_r11_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_antennaPortsCount_r11_enum2value_3,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_antennaPortsCount_r11_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_antennaPortsCount_r11_3 = {
	"antennaPortsCount-r11",
	"antennaPortsCount-r11",
	antennaPortsCount_r11_3_free,
	antennaPortsCount_r11_3_print,
	antennaPortsCount_r11_3_constraint,
	antennaPortsCount_r11_3_decode_ber,
	antennaPortsCount_r11_3_encode_der,
	antennaPortsCount_r11_3_decode_xer,
	antennaPortsCount_r11_3_encode_xer,
	antennaPortsCount_r11_3_decode_uper,
	antennaPortsCount_r11_3_encode_uper,
	antennaPortsCount_r11_3_decode_aper,
	antennaPortsCount_r11_3_encode_aper,
	antennaPortsCount_r11_3_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_antennaPortsCount_r11_tags_3,
	sizeof(asn_DEF_antennaPortsCount_r11_tags_3)
		/sizeof(asn_DEF_antennaPortsCount_r11_tags_3[0]) - 1, /* 1 */
	asn_DEF_antennaPortsCount_r11_tags_3,	/* Same as above */
	sizeof(asn_DEF_antennaPortsCount_r11_tags_3)
		/sizeof(asn_DEF_antennaPortsCount_r11_tags_3[0]), /* 2 */
	&asn_PER_type_antennaPortsCount_r11_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_antennaPortsCount_r11_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_crs_PortsCount_r11_value2enum_13[] = {
	{ 0,	2,	"n1" },
	{ 1,	2,	"n2" },
	{ 2,	2,	"n4" },
	{ 3,	6,	"spare1" }
};
static unsigned int asn_MAP_crs_PortsCount_r11_enum2value_13[] = {
	0,	/* n1(0) */
	1,	/* n2(1) */
	2,	/* n4(2) */
	3	/* spare1(3) */
};
static asn_INTEGER_specifics_t asn_SPC_crs_PortsCount_r11_specs_13 = {
	asn_MAP_crs_PortsCount_r11_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_crs_PortsCount_r11_enum2value_13,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_crs_PortsCount_r11_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_crs_PortsCount_r11_13 = {
	"crs-PortsCount-r11",
	"crs-PortsCount-r11",
	crs_PortsCount_r11_13_free,
	crs_PortsCount_r11_13_print,
	crs_PortsCount_r11_13_constraint,
	crs_PortsCount_r11_13_decode_ber,
	crs_PortsCount_r11_13_encode_der,
	crs_PortsCount_r11_13_decode_xer,
	crs_PortsCount_r11_13_encode_xer,
	crs_PortsCount_r11_13_decode_uper,
	crs_PortsCount_r11_13_encode_uper,
	crs_PortsCount_r11_13_decode_aper,
	crs_PortsCount_r11_13_encode_aper,
	crs_PortsCount_r11_13_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_crs_PortsCount_r11_tags_13,
	sizeof(asn_DEF_crs_PortsCount_r11_tags_13)
		/sizeof(asn_DEF_crs_PortsCount_r11_tags_13[0]) - 1, /* 1 */
	asn_DEF_crs_PortsCount_r11_tags_13,	/* Same as above */
	sizeof(asn_DEF_crs_PortsCount_r11_tags_13)
		/sizeof(asn_DEF_crs_PortsCount_r11_tags_13[0]), /* 2 */
	&asn_PER_type_crs_PortsCount_r11_constr_13,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_crs_PortsCount_r11_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_20[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup, subframeConfigList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBSFN_SubframeConfigList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"subframeConfigList"
		},
};
static ber_tlv_tag_t asn_DEF_setup_tags_20[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_setup_tag2el_20[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* subframeConfigList at 4203 */
};
static asn_SEQUENCE_specifics_t asn_SPC_setup_specs_20 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup, _asn_ctx),
	asn_MAP_setup_tag2el_20,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_20 = {
	"setup",
	"setup",
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
	asn_DEF_setup_tags_20,
	sizeof(asn_DEF_setup_tags_20)
		/sizeof(asn_DEF_setup_tags_20[0]) - 1, /* 1 */
	asn_DEF_setup_tags_20,	/* Same as above */
	sizeof(asn_DEF_setup_tags_20)
		/sizeof(asn_DEF_setup_tags_20[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_setup_20,
	1,	/* Elements count */
	&asn_SPC_setup_specs_20	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_mbsfn_SubframeConfigList_r11_18[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_20,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_mbsfn_SubframeConfigList_r11_tag2el_18[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4200 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4203 */
};
static asn_CHOICE_specifics_t asn_SPC_mbsfn_SubframeConfigList_r11_specs_18 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, _asn_ctx),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, present),
	sizeof(((struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11 *)0)->present),
	asn_MAP_mbsfn_SubframeConfigList_r11_tag2el_18,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mbsfn_SubframeConfigList_r11_18 = {
	"mbsfn-SubframeConfigList-r11",
	"mbsfn-SubframeConfigList-r11",
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
	&asn_PER_type_mbsfn_SubframeConfigList_r11_constr_18,
	asn_MBR_mbsfn_SubframeConfigList_r11_18,
	2,	/* Elements count */
	&asn_SPC_mbsfn_SubframeConfigList_r11_specs_18	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_qcl_CRS_Info_r11_11[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, qcl_ScramblingIdentity_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_qcl_ScramblingIdentity_r11_constraint_11,
		&asn_PER_memb_qcl_ScramblingIdentity_r11_constr_12,
		0,
		"qcl-ScramblingIdentity-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, crs_PortsCount_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_crs_PortsCount_r11_13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"crs-PortsCount-r11"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, mbsfn_SubframeConfigList_r11),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_mbsfn_SubframeConfigList_r11_18,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mbsfn-SubframeConfigList-r11"
		},
};
static int asn_MAP_qcl_CRS_Info_r11_oms_11[] = { 2 };
static ber_tlv_tag_t asn_DEF_qcl_CRS_Info_r11_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_qcl_CRS_Info_r11_tag2el_11[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* qcl-ScramblingIdentity-r11 at 4197 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* crs-PortsCount-r11 at 4198 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* mbsfn-SubframeConfigList-r11 at 4200 */
};
static asn_SEQUENCE_specifics_t asn_SPC_qcl_CRS_Info_r11_specs_11 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, _asn_ctx),
	asn_MAP_qcl_CRS_Info_r11_tag2el_11,
	3,	/* Count of tags in the map */
	asn_MAP_qcl_CRS_Info_r11_oms_11,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_qcl_CRS_Info_r11_11 = {
	"qcl-CRS-Info-r11",
	"qcl-CRS-Info-r11",
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
	asn_DEF_qcl_CRS_Info_r11_tags_11,
	sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11)
		/sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11[0]) - 1, /* 1 */
	asn_DEF_qcl_CRS_Info_r11_tags_11,	/* Same as above */
	sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11)
		/sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_qcl_CRS_Info_r11_11,
	3,	/* Elements count */
	&asn_SPC_qcl_CRS_Info_r11_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext1_23[] = {
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11__ext1, csi_RS_ConfigNZPId_v1310),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigNZPId_v1310,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-RS-ConfigNZPId-v1310"
		},
};
static int asn_MAP_ext1_oms_23[] = { 0 };
static ber_tlv_tag_t asn_DEF_ext1_tags_23[] = {
	(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext1_tag2el_23[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* csi-RS-ConfigNZPId-v1310 at 4207 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext1_specs_23 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__ext1),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext1, _asn_ctx),
	asn_MAP_ext1_tag2el_23,
	1,	/* Count of tags in the map */
	asn_MAP_ext1_oms_23,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext1_23 = {
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
	asn_DEF_ext1_tags_23,
	sizeof(asn_DEF_ext1_tags_23)
		/sizeof(asn_DEF_ext1_tags_23[0]) - 1, /* 1 */
	asn_DEF_ext1_tags_23,	/* Same as above */
	sizeof(asn_DEF_ext1_tags_23)
		/sizeof(asn_DEF_ext1_tags_23[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext1_23,
	1,	/* Elements count */
	&asn_SPC_ext1_specs_23	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext2_25[] = {
	{ ATF_POINTER, 2, offsetof(struct CSI_RS_ConfigNZP_r11__ext2, transmissionComb_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NZP_TransmissionComb_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"transmissionComb-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11__ext2, frequencyDensity_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NZP_FrequencyDensity_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"frequencyDensity-r14"
		},
};
static int asn_MAP_ext2_oms_25[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_ext2_tags_25[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext2_tag2el_25[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* transmissionComb-r14 at 4209 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* frequencyDensity-r14 at 4210 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext2_specs_25 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__ext2),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext2, _asn_ctx),
	asn_MAP_ext2_tag2el_25,
	2,	/* Count of tags in the map */
	asn_MAP_ext2_oms_25,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext2_25 = {
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
	asn_DEF_ext2_tags_25,
	sizeof(asn_DEF_ext2_tags_25)
		/sizeof(asn_DEF_ext2_tags_25[0]) - 1, /* 1 */
	asn_DEF_ext2_tags_25,	/* Same as above */
	sizeof(asn_DEF_ext2_tags_25)
		/sizeof(asn_DEF_ext2_tags_25[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext2_25,
	2,	/* Elements count */
	&asn_SPC_ext2_specs_25	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_31[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430__setup, subframeConfigList_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBSFN_SubframeConfigList_v1430,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"subframeConfigList-v1430"
		},
};
static ber_tlv_tag_t asn_DEF_setup_tags_31[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_setup_tag2el_31[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* subframeConfigList-v1430 at 4216 */
};
static asn_SEQUENCE_specifics_t asn_SPC_setup_specs_31 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430__setup),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430__setup, _asn_ctx),
	asn_MAP_setup_tag2el_31,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_31 = {
	"setup",
	"setup",
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
	asn_DEF_setup_tags_31,
	sizeof(asn_DEF_setup_tags_31)
		/sizeof(asn_DEF_setup_tags_31[0]) - 1, /* 1 */
	asn_DEF_setup_tags_31,	/* Same as above */
	sizeof(asn_DEF_setup_tags_31)
		/sizeof(asn_DEF_setup_tags_31[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_setup_31,
	1,	/* Elements count */
	&asn_SPC_setup_specs_31	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_mbsfn_SubframeConfigList_v1430_29[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_31,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_mbsfn_SubframeConfigList_v1430_tag2el_29[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release at 4213 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup at 4216 */
};
static asn_CHOICE_specifics_t asn_SPC_mbsfn_SubframeConfigList_v1430_specs_29 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430, _asn_ctx),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430, present),
	sizeof(((struct CSI_RS_ConfigNZP_r11__ext3__mbsfn_SubframeConfigList_v1430 *)0)->present),
	asn_MAP_mbsfn_SubframeConfigList_v1430_tag2el_29,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mbsfn_SubframeConfigList_v1430_29 = {
	"mbsfn-SubframeConfigList-v1430",
	"mbsfn-SubframeConfigList-v1430",
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
	&asn_PER_type_mbsfn_SubframeConfigList_v1430_constr_29,
	asn_MBR_mbsfn_SubframeConfigList_v1430_29,
	2,	/* Elements count */
	&asn_SPC_mbsfn_SubframeConfigList_v1430_specs_29	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext3_28[] = {
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11__ext3, mbsfn_SubframeConfigList_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_mbsfn_SubframeConfigList_v1430_29,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mbsfn-SubframeConfigList-v1430"
		},
};
static int asn_MAP_ext3_oms_28[] = { 0 };
static ber_tlv_tag_t asn_DEF_ext3_tags_28[] = {
	(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext3_tag2el_28[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* mbsfn-SubframeConfigList-v1430 at 4213 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext3_specs_28 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__ext3),
	offsetof(struct CSI_RS_ConfigNZP_r11__ext3, _asn_ctx),
	asn_MAP_ext3_tag2el_28,
	1,	/* Count of tags in the map */
	asn_MAP_ext3_oms_28,	/* Optional members */
	1, 0,	/* Root/Additions */
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
	1,	/* Elements count */
	&asn_SPC_ext3_specs_28	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_CSI_RS_ConfigNZP_r11_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, csi_RS_ConfigNZPId_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigNZPId_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"csi-RS-ConfigNZPId-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, antennaPortsCount_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_antennaPortsCount_r11_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"antennaPortsCount-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, resourceConfig_r11),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_resourceConfig_r11_constraint_1,
		&asn_PER_memb_resourceConfig_r11_constr_8,
		0,
		"resourceConfig-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, subframeConfig_r11),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_subframeConfig_r11_constraint_1,
		&asn_PER_memb_subframeConfig_r11_constr_9,
		0,
		"subframeConfig-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, scramblingIdentity_r11),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_scramblingIdentity_r11_constraint_1,
		&asn_PER_memb_scramblingIdentity_r11_constr_10,
		0,
		"scramblingIdentity-r11"
		},
	{ ATF_POINTER, 4, offsetof(struct CSI_RS_ConfigNZP_r11, qcl_CRS_Info_r11),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		0,
		&asn_DEF_qcl_CRS_Info_r11_11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"qcl-CRS-Info-r11"
		},
	{ ATF_POINTER, 3, offsetof(struct CSI_RS_ConfigNZP_r11, ext1),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		0,
		&asn_DEF_ext1_23,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext1"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_RS_ConfigNZP_r11, ext2),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		0,
		&asn_DEF_ext2_25,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext2"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11, ext3),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		0,
		&asn_DEF_ext3_28,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext3"
		},
};
static int asn_MAP_CSI_RS_ConfigNZP_r11_oms_1[] = { 5, 6, 7, 8 };
static ber_tlv_tag_t asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CSI_RS_ConfigNZP_r11_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* csi-RS-ConfigNZPId-r11 at 4191 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* antennaPortsCount-r11 at 4192 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* resourceConfig-r11 at 4193 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* subframeConfig-r11 at 4194 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* scramblingIdentity-r11 at 4195 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* qcl-CRS-Info-r11 at 4197 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* ext1 at 4207 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* ext2 at 4209 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* ext3 at 4217 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CSI_RS_ConfigNZP_r11_specs_1 = {
	sizeof(struct CSI_RS_ConfigNZP_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11, _asn_ctx),
	asn_MAP_CSI_RS_ConfigNZP_r11_tag2el_1,
	9,	/* Count of tags in the map */
	asn_MAP_CSI_RS_ConfigNZP_r11_oms_1,	/* Optional members */
	1, 3,	/* Root/Additions */
	5,	/* Start extensions */
	10	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CSI_RS_ConfigNZP_r11 = {
	"CSI-RS-ConfigNZP-r11",
	"CSI-RS-ConfigNZP-r11",
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
	asn_DEF_CSI_RS_ConfigNZP_r11_tags_1,
	sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1)
		/sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[0]), /* 1 */
	asn_DEF_CSI_RS_ConfigNZP_r11_tags_1,	/* Same as above */
	sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1)
		/sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CSI_RS_ConfigNZP_r11_1,
	9,	/* Elements count */
	&asn_SPC_CSI_RS_ConfigNZP_r11_specs_1	/* Additional specs */
};
