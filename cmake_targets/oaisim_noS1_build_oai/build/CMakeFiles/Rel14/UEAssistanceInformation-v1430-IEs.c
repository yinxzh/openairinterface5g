/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "UEAssistanceInformation-v1430-IEs.h"

static int
rlm_Event_r14_7_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
rlm_Event_r14_7_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
rlm_Event_r14_7_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
rlm_Event_r14_7_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
rlm_Event_r14_7_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
rlm_Event_r14_7_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
rlm_Event_r14_7_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
rlm_Event_r14_7_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
rlm_Event_r14_7_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
rlm_Event_r14_7_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
rlm_Event_r14_7_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
rlm_Event_r14_7_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	rlm_Event_r14_7_inherit_TYPE_descriptor(td1);
	rlm_Event_r14_7_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
rlm_Event_r14_7_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	rlm_Event_r14_7_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static int
excessRep_MPDCCH_r14_10_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
excessRep_MPDCCH_r14_10_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
excessRep_MPDCCH_r14_10_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
excessRep_MPDCCH_r14_10_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
excessRep_MPDCCH_r14_10_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
excessRep_MPDCCH_r14_10_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
excessRep_MPDCCH_r14_10_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
excessRep_MPDCCH_r14_10_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
excessRep_MPDCCH_r14_10_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_enc_rval_t
excessRep_MPDCCH_r14_10_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

static asn_comp_rval_t * 
excessRep_MPDCCH_r14_10_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td1);
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

static asn_dec_rval_t
excessRep_MPDCCH_r14_10_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	excessRep_MPDCCH_r14_10_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_per_constraints_t asn_PER_type_rlm_Event_r14_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_excessRep_MPDCCH_r14_constr_10 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_sps_AssistanceInformation_r14_3[] = {
	{ ATF_POINTER, 2, offsetof(struct UEAssistanceInformation_v1430_IEs__sps_AssistanceInformation_r14, trafficPatternInfoListSL_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TrafficPatternInfoList_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"trafficPatternInfoListSL-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct UEAssistanceInformation_v1430_IEs__sps_AssistanceInformation_r14, trafficPatternInfoListUL_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TrafficPatternInfoList_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"trafficPatternInfoListUL-r14"
		},
};
static int asn_MAP_sps_AssistanceInformation_r14_oms_3[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_sps_AssistanceInformation_r14_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_sps_AssistanceInformation_r14_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* trafficPatternInfoListSL-r14 at 2135 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* trafficPatternInfoListUL-r14 at 2136 */
};
static asn_SEQUENCE_specifics_t asn_SPC_sps_AssistanceInformation_r14_specs_3 = {
	sizeof(struct UEAssistanceInformation_v1430_IEs__sps_AssistanceInformation_r14),
	offsetof(struct UEAssistanceInformation_v1430_IEs__sps_AssistanceInformation_r14, _asn_ctx),
	asn_MAP_sps_AssistanceInformation_r14_tag2el_3,
	2,	/* Count of tags in the map */
	asn_MAP_sps_AssistanceInformation_r14_oms_3,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_sps_AssistanceInformation_r14_3 = {
	"sps-AssistanceInformation-r14",
	"sps-AssistanceInformation-r14",
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
	asn_DEF_sps_AssistanceInformation_r14_tags_3,
	sizeof(asn_DEF_sps_AssistanceInformation_r14_tags_3)
		/sizeof(asn_DEF_sps_AssistanceInformation_r14_tags_3[0]) - 1, /* 1 */
	asn_DEF_sps_AssistanceInformation_r14_tags_3,	/* Same as above */
	sizeof(asn_DEF_sps_AssistanceInformation_r14_tags_3)
		/sizeof(asn_DEF_sps_AssistanceInformation_r14_tags_3[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_sps_AssistanceInformation_r14_3,
	2,	/* Elements count */
	&asn_SPC_sps_AssistanceInformation_r14_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_rlm_Event_r14_value2enum_7[] = {
	{ 0,	14,	"earlyOutOfSync" },
	{ 1,	11,	"earlyInSync" }
};
static unsigned int asn_MAP_rlm_Event_r14_enum2value_7[] = {
	1,	/* earlyInSync(1) */
	0	/* earlyOutOfSync(0) */
};
static asn_INTEGER_specifics_t asn_SPC_rlm_Event_r14_specs_7 = {
	asn_MAP_rlm_Event_r14_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_rlm_Event_r14_enum2value_7,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_rlm_Event_r14_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_rlm_Event_r14_7 = {
	"rlm-Event-r14",
	"rlm-Event-r14",
	rlm_Event_r14_7_free,
	rlm_Event_r14_7_print,
	rlm_Event_r14_7_constraint,
	rlm_Event_r14_7_decode_ber,
	rlm_Event_r14_7_encode_der,
	rlm_Event_r14_7_decode_xer,
	rlm_Event_r14_7_encode_xer,
	rlm_Event_r14_7_decode_uper,
	rlm_Event_r14_7_encode_uper,
	rlm_Event_r14_7_decode_aper,
	rlm_Event_r14_7_encode_aper,
	rlm_Event_r14_7_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_rlm_Event_r14_tags_7,
	sizeof(asn_DEF_rlm_Event_r14_tags_7)
		/sizeof(asn_DEF_rlm_Event_r14_tags_7[0]) - 1, /* 1 */
	asn_DEF_rlm_Event_r14_tags_7,	/* Same as above */
	sizeof(asn_DEF_rlm_Event_r14_tags_7)
		/sizeof(asn_DEF_rlm_Event_r14_tags_7[0]), /* 2 */
	&asn_PER_type_rlm_Event_r14_constr_7,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_rlm_Event_r14_specs_7	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_excessRep_MPDCCH_r14_value2enum_10[] = {
	{ 0,	10,	"excessRep1" },
	{ 1,	10,	"excessRep2" }
};
static unsigned int asn_MAP_excessRep_MPDCCH_r14_enum2value_10[] = {
	0,	/* excessRep1(0) */
	1	/* excessRep2(1) */
};
static asn_INTEGER_specifics_t asn_SPC_excessRep_MPDCCH_r14_specs_10 = {
	asn_MAP_excessRep_MPDCCH_r14_value2enum_10,	/* "tag" => N; sorted by tag */
	asn_MAP_excessRep_MPDCCH_r14_enum2value_10,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_excessRep_MPDCCH_r14_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_excessRep_MPDCCH_r14_10 = {
	"excessRep-MPDCCH-r14",
	"excessRep-MPDCCH-r14",
	excessRep_MPDCCH_r14_10_free,
	excessRep_MPDCCH_r14_10_print,
	excessRep_MPDCCH_r14_10_constraint,
	excessRep_MPDCCH_r14_10_decode_ber,
	excessRep_MPDCCH_r14_10_encode_der,
	excessRep_MPDCCH_r14_10_decode_xer,
	excessRep_MPDCCH_r14_10_encode_xer,
	excessRep_MPDCCH_r14_10_decode_uper,
	excessRep_MPDCCH_r14_10_encode_uper,
	excessRep_MPDCCH_r14_10_decode_aper,
	excessRep_MPDCCH_r14_10_encode_aper,
	excessRep_MPDCCH_r14_10_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_excessRep_MPDCCH_r14_tags_10,
	sizeof(asn_DEF_excessRep_MPDCCH_r14_tags_10)
		/sizeof(asn_DEF_excessRep_MPDCCH_r14_tags_10[0]) - 1, /* 1 */
	asn_DEF_excessRep_MPDCCH_r14_tags_10,	/* Same as above */
	sizeof(asn_DEF_excessRep_MPDCCH_r14_tags_10)
		/sizeof(asn_DEF_excessRep_MPDCCH_r14_tags_10[0]), /* 2 */
	&asn_PER_type_excessRep_MPDCCH_r14_constr_10,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_excessRep_MPDCCH_r14_specs_10	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_rlm_Report_r14_6[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UEAssistanceInformation_v1430_IEs__rlm_Report_r14, rlm_Event_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_rlm_Event_r14_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rlm-Event-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct UEAssistanceInformation_v1430_IEs__rlm_Report_r14, excessRep_MPDCCH_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_excessRep_MPDCCH_r14_10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"excessRep-MPDCCH-r14"
		},
};
static int asn_MAP_rlm_Report_r14_oms_6[] = { 1 };
static ber_tlv_tag_t asn_DEF_rlm_Report_r14_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_rlm_Report_r14_tag2el_6[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rlm-Event-r14 at 2139 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* excessRep-MPDCCH-r14 at 2140 */
};
static asn_SEQUENCE_specifics_t asn_SPC_rlm_Report_r14_specs_6 = {
	sizeof(struct UEAssistanceInformation_v1430_IEs__rlm_Report_r14),
	offsetof(struct UEAssistanceInformation_v1430_IEs__rlm_Report_r14, _asn_ctx),
	asn_MAP_rlm_Report_r14_tag2el_6,
	2,	/* Count of tags in the map */
	asn_MAP_rlm_Report_r14_oms_6,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_rlm_Report_r14_6 = {
	"rlm-Report-r14",
	"rlm-Report-r14",
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
	asn_DEF_rlm_Report_r14_tags_6,
	sizeof(asn_DEF_rlm_Report_r14_tags_6)
		/sizeof(asn_DEF_rlm_Report_r14_tags_6[0]) - 1, /* 1 */
	asn_DEF_rlm_Report_r14_tags_6,	/* Same as above */
	sizeof(asn_DEF_rlm_Report_r14_tags_6)
		/sizeof(asn_DEF_rlm_Report_r14_tags_6[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_rlm_Report_r14_6,
	2,	/* Elements count */
	&asn_SPC_rlm_Report_r14_specs_6	/* Additional specs */
};

static ber_tlv_tag_t asn_DEF_nonCriticalExtension_tags_14[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SEQUENCE_specifics_t asn_SPC_nonCriticalExtension_specs_14 = {
	sizeof(struct UEAssistanceInformation_v1430_IEs__nonCriticalExtension),
	offsetof(struct UEAssistanceInformation_v1430_IEs__nonCriticalExtension, _asn_ctx),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nonCriticalExtension_14 = {
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
	asn_DEF_nonCriticalExtension_tags_14,
	sizeof(asn_DEF_nonCriticalExtension_tags_14)
		/sizeof(asn_DEF_nonCriticalExtension_tags_14[0]) - 1, /* 1 */
	asn_DEF_nonCriticalExtension_tags_14,	/* Same as above */
	sizeof(asn_DEF_nonCriticalExtension_tags_14)
		/sizeof(asn_DEF_nonCriticalExtension_tags_14[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	&asn_SPC_nonCriticalExtension_specs_14	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_UEAssistanceInformation_v1430_IEs_1[] = {
	{ ATF_POINTER, 5, offsetof(struct UEAssistanceInformation_v1430_IEs, bw_Preference_r14),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BW_Preference_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"bw-Preference-r14"
		},
	{ ATF_POINTER, 4, offsetof(struct UEAssistanceInformation_v1430_IEs, sps_AssistanceInformation_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_sps_AssistanceInformation_r14_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"sps-AssistanceInformation-r14"
		},
	{ ATF_POINTER, 3, offsetof(struct UEAssistanceInformation_v1430_IEs, rlm_Report_r14),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_rlm_Report_r14_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rlm-Report-r14"
		},
	{ ATF_POINTER, 2, offsetof(struct UEAssistanceInformation_v1430_IEs, delayBudgetReport_r14),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_DelayBudgetReport_r14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"delayBudgetReport-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct UEAssistanceInformation_v1430_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		0,
		&asn_DEF_nonCriticalExtension_14,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_UEAssistanceInformation_v1430_IEs_oms_1[] = { 0, 1, 2, 3, 4 };
static ber_tlv_tag_t asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_UEAssistanceInformation_v1430_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* bw-Preference-r14 at 2133 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sps-AssistanceInformation-r14 at 2135 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rlm-Report-r14 at 2139 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* delayBudgetReport-r14 at 2141 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* nonCriticalExtension at 2142 */
};
static asn_SEQUENCE_specifics_t asn_SPC_UEAssistanceInformation_v1430_IEs_specs_1 = {
	sizeof(struct UEAssistanceInformation_v1430_IEs),
	offsetof(struct UEAssistanceInformation_v1430_IEs, _asn_ctx),
	asn_MAP_UEAssistanceInformation_v1430_IEs_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_UEAssistanceInformation_v1430_IEs_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_UEAssistanceInformation_v1430_IEs = {
	"UEAssistanceInformation-v1430-IEs",
	"UEAssistanceInformation-v1430-IEs",
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
	asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1,
	sizeof(asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1)
		/sizeof(asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1[0]), /* 1 */
	asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1)
		/sizeof(asn_DEF_UEAssistanceInformation_v1430_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_UEAssistanceInformation_v1430_IEs_1,
	5,	/* Elements count */
	&asn_SPC_UEAssistanceInformation_v1430_IEs_specs_1	/* Additional specs */
};

