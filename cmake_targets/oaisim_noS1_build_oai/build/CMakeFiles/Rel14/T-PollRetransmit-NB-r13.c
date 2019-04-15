/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "T-PollRetransmit-NB-r13.h"

int
T_PollRetransmit_NB_r13_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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

void
T_PollRetransmit_NB_r13_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
T_PollRetransmit_NB_r13_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
T_PollRetransmit_NB_r13_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
T_PollRetransmit_NB_r13_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
T_PollRetransmit_NB_r13_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
T_PollRetransmit_NB_r13_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

asn_dec_rval_t
T_PollRetransmit_NB_r13_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

asn_enc_rval_t
T_PollRetransmit_NB_r13_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

asn_enc_rval_t
T_PollRetransmit_NB_r13_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

asn_comp_rval_t * 
T_PollRetransmit_NB_r13_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td1);
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

asn_dec_rval_t
T_PollRetransmit_NB_r13_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	T_PollRetransmit_NB_r13_1_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_per_constraints_t asn_PER_type_T_PollRetransmit_NB_r13_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_T_PollRetransmit_NB_r13_value2enum_1[] = {
	{ 0,	5,	"ms250" },
	{ 1,	5,	"ms500" },
	{ 2,	6,	"ms1000" },
	{ 3,	6,	"ms2000" },
	{ 4,	6,	"ms3000" },
	{ 5,	6,	"ms4000" },
	{ 6,	6,	"ms6000" },
	{ 7,	7,	"ms10000" },
	{ 8,	7,	"ms15000" },
	{ 9,	7,	"ms25000" },
	{ 10,	7,	"ms40000" },
	{ 11,	7,	"ms60000" },
	{ 12,	7,	"ms90000" },
	{ 13,	8,	"ms120000" },
	{ 14,	8,	"ms180000" },
	{ 15,	6,	"spare1" }
};
static unsigned int asn_MAP_T_PollRetransmit_NB_r13_enum2value_1[] = {
	2,	/* ms1000(2) */
	7,	/* ms10000(7) */
	13,	/* ms120000(13) */
	8,	/* ms15000(8) */
	14,	/* ms180000(14) */
	3,	/* ms2000(3) */
	0,	/* ms250(0) */
	9,	/* ms25000(9) */
	4,	/* ms3000(4) */
	5,	/* ms4000(5) */
	10,	/* ms40000(10) */
	1,	/* ms500(1) */
	6,	/* ms6000(6) */
	11,	/* ms60000(11) */
	12,	/* ms90000(12) */
	15	/* spare1(15) */
};
static asn_INTEGER_specifics_t asn_SPC_T_PollRetransmit_NB_r13_specs_1 = {
	asn_MAP_T_PollRetransmit_NB_r13_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_T_PollRetransmit_NB_r13_enum2value_1,	/* N => "tag"; sorted by N */
	16,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_T_PollRetransmit_NB_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_T_PollRetransmit_NB_r13 = {
	"T-PollRetransmit-NB-r13",
	"T-PollRetransmit-NB-r13",
	T_PollRetransmit_NB_r13_free,
	T_PollRetransmit_NB_r13_print,
	T_PollRetransmit_NB_r13_constraint,
	T_PollRetransmit_NB_r13_decode_ber,
	T_PollRetransmit_NB_r13_encode_der,
	T_PollRetransmit_NB_r13_decode_xer,
	T_PollRetransmit_NB_r13_encode_xer,
	T_PollRetransmit_NB_r13_decode_uper,
	T_PollRetransmit_NB_r13_encode_uper,
	T_PollRetransmit_NB_r13_decode_aper,
	T_PollRetransmit_NB_r13_encode_aper,
	T_PollRetransmit_NB_r13_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_T_PollRetransmit_NB_r13_tags_1,
	sizeof(asn_DEF_T_PollRetransmit_NB_r13_tags_1)
		/sizeof(asn_DEF_T_PollRetransmit_NB_r13_tags_1[0]), /* 1 */
	asn_DEF_T_PollRetransmit_NB_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_T_PollRetransmit_NB_r13_tags_1)
		/sizeof(asn_DEF_T_PollRetransmit_NB_r13_tags_1[0]), /* 1 */
	&asn_PER_type_T_PollRetransmit_NB_r13_constr_1,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_T_PollRetransmit_NB_r13_specs_1	/* Additional specs */
};

