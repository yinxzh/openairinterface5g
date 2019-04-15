/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "PMCH-Config-r12.h"

static int
memb_normal_r12_constraint_3(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 28)) {
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
memb_higerOrder_r12_constraint_3(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 27)) {
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
mch_SchedulingPeriod_r12_6_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
mch_SchedulingPeriod_r12_6_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
mch_SchedulingPeriod_r12_6_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_r12_6_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
mch_SchedulingPeriod_r12_6_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_r12_6_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
mch_SchedulingPeriod_r12_6_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_r12_6_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
mch_SchedulingPeriod_r12_6_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
mch_SchedulingPeriod_r12_6_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
mch_SchedulingPeriod_r12_6_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td1);
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
mch_SchedulingPeriod_r12_6_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mch_SchedulingPeriod_r12_6_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
mch_SchedulingPeriod_v1430_18_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
mch_SchedulingPeriod_v1430_18_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
mch_SchedulingPeriod_v1430_18_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_v1430_18_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
mch_SchedulingPeriod_v1430_18_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_v1430_18_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
mch_SchedulingPeriod_v1430_18_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
mch_SchedulingPeriod_v1430_18_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
mch_SchedulingPeriod_v1430_18_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
mch_SchedulingPeriod_v1430_18_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
mch_SchedulingPeriod_v1430_18_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td1);
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
mch_SchedulingPeriod_v1430_18_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mch_SchedulingPeriod_v1430_18_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
memb_sf_AllocEnd_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_normal_r12_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  0,  28 }	/* (0..28) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_higerOrder_r12_constr_5 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  0,  27 }	/* (0..27) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_dataMCS_r12_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_mch_SchedulingPeriod_r12_constr_6 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  8 }	/* (0..8) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_mch_SchedulingPeriod_v1430_constr_18 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_sf_AllocEnd_r12_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11,  0,  1535 }	/* (0..1535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_dataMCS_r12_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PMCH_Config_r12__dataMCS_r12, choice.normal_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_normal_r12_constraint_3,
		&asn_PER_memb_normal_r12_constr_4,
		0,
		"normal-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PMCH_Config_r12__dataMCS_r12, choice.higerOrder_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_higerOrder_r12_constraint_3,
		&asn_PER_memb_higerOrder_r12_constr_5,
		0,
		"higerOrder-r12"
		},
};
static asn_TYPE_tag2member_t asn_MAP_dataMCS_r12_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* normal-r12 at 9977 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* higerOrder-r12 at 9978 */
};
static asn_CHOICE_specifics_t asn_SPC_dataMCS_r12_specs_3 = {
	sizeof(struct PMCH_Config_r12__dataMCS_r12),
	offsetof(struct PMCH_Config_r12__dataMCS_r12, _asn_ctx),
	offsetof(struct PMCH_Config_r12__dataMCS_r12, present),
	sizeof(((struct PMCH_Config_r12__dataMCS_r12 *)0)->present),
	asn_MAP_dataMCS_r12_tag2el_3,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_dataMCS_r12_3 = {
	"dataMCS-r12",
	"dataMCS-r12",
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
	&asn_PER_type_dataMCS_r12_constr_3,
	asn_MBR_dataMCS_r12_3,
	2,	/* Elements count */
	&asn_SPC_dataMCS_r12_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_mch_SchedulingPeriod_r12_value2enum_6[] = {
	{ 0,	3,	"rf4" },
	{ 1,	3,	"rf8" },
	{ 2,	4,	"rf16" },
	{ 3,	4,	"rf32" },
	{ 4,	4,	"rf64" },
	{ 5,	5,	"rf128" },
	{ 6,	5,	"rf256" },
	{ 7,	5,	"rf512" },
	{ 8,	6,	"rf1024" }
};
static unsigned int asn_MAP_mch_SchedulingPeriod_r12_enum2value_6[] = {
	8,	/* rf1024(8) */
	5,	/* rf128(5) */
	2,	/* rf16(2) */
	6,	/* rf256(6) */
	3,	/* rf32(3) */
	0,	/* rf4(0) */
	7,	/* rf512(7) */
	4,	/* rf64(4) */
	1	/* rf8(1) */
};
static asn_INTEGER_specifics_t asn_SPC_mch_SchedulingPeriod_r12_specs_6 = {
	asn_MAP_mch_SchedulingPeriod_r12_value2enum_6,	/* "tag" => N; sorted by tag */
	asn_MAP_mch_SchedulingPeriod_r12_enum2value_6,	/* N => "tag"; sorted by N */
	9,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_mch_SchedulingPeriod_r12_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mch_SchedulingPeriod_r12_6 = {
	"mch-SchedulingPeriod-r12",
	"mch-SchedulingPeriod-r12",
	mch_SchedulingPeriod_r12_6_free,
	mch_SchedulingPeriod_r12_6_print,
	mch_SchedulingPeriod_r12_6_constraint,
	mch_SchedulingPeriod_r12_6_decode_ber,
	mch_SchedulingPeriod_r12_6_encode_der,
	mch_SchedulingPeriod_r12_6_decode_xer,
	mch_SchedulingPeriod_r12_6_encode_xer,
	mch_SchedulingPeriod_r12_6_decode_uper,
	mch_SchedulingPeriod_r12_6_encode_uper,
	mch_SchedulingPeriod_r12_6_decode_aper,
	mch_SchedulingPeriod_r12_6_encode_aper,
	mch_SchedulingPeriod_r12_6_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mch_SchedulingPeriod_r12_tags_6,
	sizeof(asn_DEF_mch_SchedulingPeriod_r12_tags_6)
		/sizeof(asn_DEF_mch_SchedulingPeriod_r12_tags_6[0]) - 1, /* 1 */
	asn_DEF_mch_SchedulingPeriod_r12_tags_6,	/* Same as above */
	sizeof(asn_DEF_mch_SchedulingPeriod_r12_tags_6)
		/sizeof(asn_DEF_mch_SchedulingPeriod_r12_tags_6[0]), /* 2 */
	&asn_PER_type_mch_SchedulingPeriod_r12_constr_6,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_mch_SchedulingPeriod_r12_specs_6	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_mch_SchedulingPeriod_v1430_value2enum_18[] = {
	{ 0,	3,	"rf1" },
	{ 1,	3,	"rf2" }
};
static unsigned int asn_MAP_mch_SchedulingPeriod_v1430_enum2value_18[] = {
	0,	/* rf1(0) */
	1	/* rf2(1) */
};
static asn_INTEGER_specifics_t asn_SPC_mch_SchedulingPeriod_v1430_specs_18 = {
	asn_MAP_mch_SchedulingPeriod_v1430_value2enum_18,	/* "tag" => N; sorted by tag */
	asn_MAP_mch_SchedulingPeriod_v1430_enum2value_18,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_mch_SchedulingPeriod_v1430_tags_18[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mch_SchedulingPeriod_v1430_18 = {
	"mch-SchedulingPeriod-v1430",
	"mch-SchedulingPeriod-v1430",
	mch_SchedulingPeriod_v1430_18_free,
	mch_SchedulingPeriod_v1430_18_print,
	mch_SchedulingPeriod_v1430_18_constraint,
	mch_SchedulingPeriod_v1430_18_decode_ber,
	mch_SchedulingPeriod_v1430_18_encode_der,
	mch_SchedulingPeriod_v1430_18_decode_xer,
	mch_SchedulingPeriod_v1430_18_encode_xer,
	mch_SchedulingPeriod_v1430_18_decode_uper,
	mch_SchedulingPeriod_v1430_18_encode_uper,
	mch_SchedulingPeriod_v1430_18_decode_aper,
	mch_SchedulingPeriod_v1430_18_encode_aper,
	mch_SchedulingPeriod_v1430_18_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mch_SchedulingPeriod_v1430_tags_18,
	sizeof(asn_DEF_mch_SchedulingPeriod_v1430_tags_18)
		/sizeof(asn_DEF_mch_SchedulingPeriod_v1430_tags_18[0]) - 1, /* 1 */
	asn_DEF_mch_SchedulingPeriod_v1430_tags_18,	/* Same as above */
	sizeof(asn_DEF_mch_SchedulingPeriod_v1430_tags_18)
		/sizeof(asn_DEF_mch_SchedulingPeriod_v1430_tags_18[0]), /* 2 */
	&asn_PER_type_mch_SchedulingPeriod_v1430_constr_18,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_mch_SchedulingPeriod_v1430_specs_18	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext1_17[] = {
	{ ATF_POINTER, 1, offsetof(struct PMCH_Config_r12__ext1, mch_SchedulingPeriod_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mch_SchedulingPeriod_v1430_18,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mch-SchedulingPeriod-v1430"
		},
};
static int asn_MAP_ext1_oms_17[] = { 0 };
static ber_tlv_tag_t asn_DEF_ext1_tags_17[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ext1_tag2el_17[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* mch-SchedulingPeriod-v1430 at 9983 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext1_specs_17 = {
	sizeof(struct PMCH_Config_r12__ext1),
	offsetof(struct PMCH_Config_r12__ext1, _asn_ctx),
	asn_MAP_ext1_tag2el_17,
	1,	/* Count of tags in the map */
	asn_MAP_ext1_oms_17,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext1_17 = {
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
	asn_DEF_ext1_tags_17,
	sizeof(asn_DEF_ext1_tags_17)
		/sizeof(asn_DEF_ext1_tags_17[0]) - 1, /* 1 */
	asn_DEF_ext1_tags_17,	/* Same as above */
	sizeof(asn_DEF_ext1_tags_17)
		/sizeof(asn_DEF_ext1_tags_17[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ext1_17,
	1,	/* Elements count */
	&asn_SPC_ext1_specs_17	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_PMCH_Config_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PMCH_Config_r12, sf_AllocEnd_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_sf_AllocEnd_r12_constraint_1,
		&asn_PER_memb_sf_AllocEnd_r12_constr_2,
		0,
		"sf-AllocEnd-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PMCH_Config_r12, dataMCS_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_dataMCS_r12_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dataMCS-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PMCH_Config_r12, mch_SchedulingPeriod_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mch_SchedulingPeriod_r12_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mch-SchedulingPeriod-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct PMCH_Config_r12, ext1),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_ext1_17,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ext1"
		},
};
static int asn_MAP_PMCH_Config_r12_oms_1[] = { 3 };
static ber_tlv_tag_t asn_DEF_PMCH_Config_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PMCH_Config_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sf-AllocEnd-r12 at 9975 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* dataMCS-r12 at 9977 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* mch-SchedulingPeriod-r12 at 9981 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* ext1 at 9983 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PMCH_Config_r12_specs_1 = {
	sizeof(struct PMCH_Config_r12),
	offsetof(struct PMCH_Config_r12, _asn_ctx),
	asn_MAP_PMCH_Config_r12_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_PMCH_Config_r12_oms_1,	/* Optional members */
	0, 1,	/* Root/Additions */
	2,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PMCH_Config_r12 = {
	"PMCH-Config-r12",
	"PMCH-Config-r12",
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
	asn_DEF_PMCH_Config_r12_tags_1,
	sizeof(asn_DEF_PMCH_Config_r12_tags_1)
		/sizeof(asn_DEF_PMCH_Config_r12_tags_1[0]), /* 1 */
	asn_DEF_PMCH_Config_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_PMCH_Config_r12_tags_1)
		/sizeof(asn_DEF_PMCH_Config_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PMCH_Config_r12_1,
	4,	/* Elements count */
	&asn_SPC_PMCH_Config_r12_specs_1	/* Additional specs */
};

