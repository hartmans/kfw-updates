krb5_error_code  krb5_encrypt(krb5_context context, const krb5_pointer inptr, krb5_pointer outptr, const size_t size, krb5_encrypt_block * eblock, krb5_pointer ivec);
krb5_error_code krb5_decrypt(krb5_context context, const krb5_pointer inptr, krb5_pointer outptr, const size_t size, krb5_encrypt_block * eblock, krb5_pointer ivec);
krb5_error_code krb5_process_key(krb5_context context, krb5_encrypt_block * eblock, const krb5_keyblock * key);
krb5_error_code krb5_finish_key(krb5_context context, krb5_encrypt_block * eblock);
krb5_error_code krb5_string_to_key(krb5_context context, const krb5_encrypt_block * eblock, krb5_keyblock * keyblock, const krb5_data * data, const krb5_data * salt);
krb5_error_code krb5_init_random_key(krb5_context context, const krb5_encrypt_block * eblock, const krb5_keyblock * keyblock, krb5_pointer * ptr);
krb5_error_code krb5_finish_random_key(krb5_context context, const krb5_encrypt_block * eblock, krb5_pointer * ptr);
krb5_error_code krb5_random_key(krb5_context context, const krb5_encrypt_block * eblock, krb5_pointer ptr, krb5_keyblock ** keyblock);
krb5_enctype krb5_eblock_enctype(krb5_context context, const krb5_encrypt_block * eblock);
krb5_error_code krb5_use_enctype(krb5_context context, krb5_encrypt_block * eblock, const krb5_enctype enctype);
size_t krb5_encrypt_size(const size_t length, const struct _krb5_cryptosystem_entry * crypto);
size_t krb5_checksum_size(krb5_context context, const krb5_cksumtype ctype);
krb5_error_code krb5_calculate_checksum(krb5_context context, const krb5_cksumtype ctype, const krb5_pointer in, const size_t in_length, const krb5_pointer seed, const size_t seed_length, krb5_checksum * outcksum);
krb5_error_code krb5_verify_checksum(krb5_context context, const krb5_cksumtype ctype, const krb5_checksum * cksum, const krb5_pointer in, const size_t in_length, const krb5_pointer seed, const size_t seed_length);
krb5_error_code krb5_random_confounder(size_t, krb5_pointer);
krb5_boolean valid_enctype(const krb5_enctype ktype);
krb5_boolean valid_cksumtype(const krb5_cksumtype ctype);
krb5_boolean is_coll_proof_cksum(const krb5_cksumtype ctype);
krb5_boolean is_keyed_cksum(const krb5_cksumtype ctype);
krb5_error_code krb5_encrypt_data(krb5_context context, krb5_keyblock *key, krb5_pointer ivec, krb5_data *data, krb5_enc_data *enc_data);
krb5_error_code krb5_decrypt_data(krb5_context context, krb5_keyblock *key, krb5_pointer ivec, krb5_enc_data *data, krb5_data *enc_data);
krb5_error_code krb5_rc_default (krb5_context, krb5_rcache *);
krb5_error_code krb5_rc_register_type (krb5_context, krb5_rc_ops *);
krb5_error_code krb5_rc_resolve_type (krb5_context, krb5_rcache *, char *);
krb5_error_code krb5_rc_resolve_full (krb5_context, krb5_rcache *, char *);
char * krb5_rc_get_type (krb5_context, krb5_rcache);
char * krb5_rc_default_type (krb5_context);
char * krb5_rc_default_name (krb5_context);
krb5_error_code krb5_auth_to_rep (krb5_context, krb5_tkt_authent *, krb5_donot_replay *);
krb5_error_code krb5_init_context(krb5_context *);
void krb5_free_context(krb5_context);
krb5_error_code krb5_set_default_in_tkt_ktypes(krb5_context, const krb5_enctype *);
krb5_error_code krb5_get_default_in_tkt_ktypes(krb5_context, krb5_enctype **);
krb5_error_code krb5_set_default_tgs_ktypes(krb5_context, const krb5_enctype *);
krb5_error_code krb5_get_tgs_ktypes(krb5_context, const_principal, krb5_enctype **);
krb5_error_code krb5_kdc_rep_decrypt_proc(krb5_context, const krb5_keyblock *, const_pointer, krb5_kdc_rep * );
krb5_error_code krb5_decrypt_tkt_part(krb5_context, const krb5_keyblock *, krb5_ticket * );
krb5_error_code krb5_get_cred_from_kdc(krb5_context, krb5_ccache, krb5_creds *, krb5_creds **, krb5_creds *** );
krb5_error_code krb5_get_cred_from_kdc_validate(krb5_context, krb5_ccache, krb5_creds *, krb5_creds **, krb5_creds *** );
krb5_error_code krb5_get_cred_from_kdc_renew(krb5_context, krb5_ccache, krb5_creds *, krb5_creds **, krb5_creds *** );
void krb5_free_tgt_creds(krb5_context, krb5_creds ** );
krb5_error_code krb5_get_credentials(krb5_context, const krb5_flags, krb5_ccache, krb5_creds *, krb5_creds **);
krb5_error_code krb5_get_credentials_validate(krb5_context, const krb5_flags, krb5_ccache, krb5_creds *, krb5_creds **);
krb5_error_code krb5_get_credentials_renew(krb5_context, const krb5_flags, krb5_ccache, krb5_creds *, krb5_creds **);
krb5_error_code krb5_get_cred_via_tkt(krb5_context, krb5_creds *, const krb5_flags, krb5_address * const *, krb5_creds *, krb5_creds **);
krb5_error_code krb5_mk_req(krb5_context, krb5_auth_context *, const krb5_flags, char *, char *, krb5_data *, krb5_ccache, krb5_data * );
krb5_error_code krb5_mk_req_extended(krb5_context, krb5_auth_context *, const krb5_flags, krb5_data *, krb5_creds *, krb5_data * );
krb5_error_code krb5_mk_rep(krb5_context, krb5_auth_context, krb5_data *);
krb5_error_code krb5_rd_rep(krb5_context, krb5_auth_context, const krb5_data *, krb5_ap_rep_enc_part **);
krb5_error_code krb5_mk_error(krb5_context, const krb5_error *, krb5_data * );
krb5_error_code krb5_rd_error(krb5_context, const krb5_data *, krb5_error ** );
krb5_error_code krb5_rd_safe(krb5_context, krb5_auth_context, const krb5_data *, krb5_data *, krb5_replay_data *);
krb5_error_code krb5_rd_priv(krb5_context, krb5_auth_context, const krb5_data *, krb5_data *, krb5_replay_data *);
krb5_error_code krb5_parse_name(krb5_context, const char *, krb5_principal * );
krb5_error_code krb5_unparse_name(krb5_context, const_principal, char ** );
krb5_error_code krb5_unparse_name_ext(krb5_context, const_principal, char **, int *);
krb5_error_code krb5_set_principal_realm(krb5_context, krb5_principal, const char *);
krb5_boolean krb5_address_search(krb5_context, const krb5_address *, krb5_address * const *);
krb5_boolean krb5_address_compare(krb5_context, const krb5_address *, const krb5_address *);
int krb5_address_order(krb5_context, const krb5_address *, const krb5_address *);
krb5_boolean krb5_realm_compare(krb5_context, const_principal, const_principal);
krb5_boolean krb5_principal_compare(krb5_context, const_principal, const_principal);
krb5_error_code krb5_copy_keyblock(krb5_context, const krb5_keyblock *, krb5_keyblock **);
krb5_error_code krb5_copy_keyblock_contents(krb5_context, const krb5_keyblock *, krb5_keyblock *);
krb5_error_code krb5_copy_creds(krb5_context, const krb5_creds *, krb5_creds **);
krb5_error_code krb5_copy_data(krb5_context, const krb5_data *, krb5_data **);
krb5_error_code krb5_copy_principal(krb5_context, const_principal, krb5_principal *);
krb5_error_code krb5_copy_addr(krb5_context, const krb5_address *, krb5_address **);
krb5_error_code krb5_copy_addresses(krb5_context, krb5_address * const *, krb5_address ***);
krb5_error_code krb5_copy_ticket(krb5_context, const krb5_ticket *, krb5_ticket **);
krb5_error_code krb5_copy_authdata(krb5_context, krb5_authdata * const *, krb5_authdata ***);
krb5_error_code krb5_copy_authenticator(krb5_context, const krb5_authenticator *, krb5_authenticator **);
krb5_error_code krb5_copy_checksum(krb5_context, const krb5_checksum *, krb5_checksum **);
void krb5_init_ets(krb5_context);
void krb5_free_ets(krb5_context);
krb5_error_code krb5_generate_subkey(krb5_context, const krb5_keyblock *, krb5_keyblock **);
krb5_error_code krb5_generate_seq_number(krb5_context, const krb5_keyblock *, krb5_int32 *);
krb5_error_code krb5_get_server_rcache(krb5_context, const krb5_data *, krb5_rcache *);
krb5_error_code krb5_build_principal_va(krb5_context, krb5_principal, int, const char *, va_list);
krb5_error_code krb5_425_conv_principal(krb5_context, const char *name, const char *instance, const char *realm, krb5_principal *princ);
krb5_error_code krb5_524_conv_principal(krb5_context context, const krb5_principal princ, char *name, char *inst, char *realm);
krb5_error_code krb5_mk_chpw_req(krb5_context context, krb5_auth_context auth_context,  krb5_data *ap_req, char *passwd, krb5_data *packet);
krb5_error_code krb5_rd_chpw_rep(krb5_context context, krb5_auth_context auth_context, krb5_data *packet, int *result_code, krb5_data *result_data);
krb5_error_code krb5_chpw_result_code_string(krb5_context context, int result_code, char **result_codestr);
krb5_error_code krb5_kt_register(krb5_context, krb5_kt_ops * );
krb5_error_code krb5_kt_resolve(krb5_context, const char *, krb5_keytab * );
krb5_error_code krb5_kt_default_name(krb5_context, char *, int );
krb5_error_code krb5_kt_default(krb5_context, krb5_keytab * );
krb5_error_code krb5_kt_free_entry(krb5_context, krb5_keytab_entry * );
krb5_error_code krb5_kt_remove_entry(krb5_context, krb5_keytab, krb5_keytab_entry * );
krb5_error_code krb5_kt_add_entry(krb5_context, krb5_keytab, krb5_keytab_entry * );
krb5_error_code krb5_principal2salt(krb5_context, const_principal, krb5_data *);
krb5_error_code krb5_principal2salt_norealm(krb5_context, const_principal, krb5_data *);
krb5_error_code krb5_cc_resolve(krb5_context, const char *, krb5_ccache * );
const char * krb5_cc_default_name(krb5_context);
krb5_error_code krb5_cc_default(krb5_context, krb5_ccache *);
unsigned int krb5_get_notification_message(void);
krb5_error_code krb5_cc_copy_creds(krb5_context context, krb5_ccache incc, krb5_ccache outcc);
krb5_error_code krb5_check_transited_list(krb5_context, krb5_data *trans, krb5_data *realm1, krb5_data *realm2);
void krb5_free_realm_tree(krb5_context, krb5_principal *);
void krb5_free_principal(krb5_context, krb5_principal );
void krb5_free_authenticator(krb5_context, krb5_authenticator * );
void krb5_free_authenticator_contents(krb5_context, krb5_authenticator * );
void krb5_free_addresses(krb5_context, krb5_address ** );
void krb5_free_address(krb5_context, krb5_address * );
void krb5_free_authdata(krb5_context, krb5_authdata ** );
void krb5_free_enc_tkt_part(krb5_context, krb5_enc_tkt_part * );
void krb5_free_ticket(krb5_context, krb5_ticket * );
void krb5_free_tickets(krb5_context, krb5_ticket ** );
void krb5_free_kdc_req(krb5_context, krb5_kdc_req * );
void krb5_free_kdc_rep(krb5_context, krb5_kdc_rep * );
void krb5_free_last_req(krb5_context, krb5_last_req_entry ** );
void krb5_free_enc_kdc_rep_part(krb5_context, krb5_enc_kdc_rep_part * );
void krb5_free_error(krb5_context, krb5_error * );
void krb5_free_ap_req(krb5_context, krb5_ap_req * );
void krb5_free_ap_rep(krb5_context, krb5_ap_rep * );
void krb5_free_safe(krb5_context, krb5_safe * );
void krb5_free_priv(krb5_context, krb5_priv * );
void krb5_free_priv_enc_part(krb5_context, krb5_priv_enc_part * );
void krb5_free_cred(krb5_context, krb5_cred *);
void krb5_free_creds(krb5_context, krb5_creds *);
void krb5_free_cred_contents(krb5_context, krb5_creds *);
void krb5_free_cred_enc_part(krb5_context, krb5_cred_enc_part *);
void krb5_free_checksum(krb5_context, krb5_checksum *);
void krb5_free_keyblock(krb5_context, krb5_keyblock *);
void krb5_free_keyblock_contents(krb5_context, krb5_keyblock *);
void krb5_free_pa_data(krb5_context, krb5_pa_data **);
void krb5_free_ap_rep_enc_part(krb5_context, krb5_ap_rep_enc_part *);
void krb5_free_tkt_authent(krb5_context, krb5_tkt_authent *);
void krb5_free_pwd_data(krb5_context, krb5_pwd_data *);
void krb5_free_pwd_sequences(krb5_context, passwd_phrase_element **);
void krb5_free_data(krb5_context, krb5_data *);
void krb5_free_data_contents(krb5_context, krb5_data *);
void krb5_free_unparsed_name(krb5_context, char *);
krb5_error_code krb5_us_timeofday(krb5_context, krb5_int32 *, krb5_int32 * );
krb5_error_code krb5_timeofday(krb5_context, krb5_int32 * );
krb5_error_code krb5_os_localaddr(krb5_context, krb5_address ***);
krb5_error_code krb5_get_default_realm(krb5_context, char ** );
krb5_error_code krb5_set_default_realm(krb5_context, const char * );
krb5_error_code krb5_sname_to_principal(krb5_context, const char *, const char *, krb5_int32, krb5_principal *);
krb5_error_code krb5_change_password(krb5_context context, krb5_creds *creds, char *newpw, int *result_code, krb5_data *result_code_string, krb5_data *result_string);
krb5_error_code krb5_set_config_files(krb5_context, const char **);
krb5_error_code krb5_secure_config_files(krb5_context);
krb5_error_code krb5_send_tgs(krb5_context, const krb5_flags, const krb5_ticket_times *, const krb5_enctype *, const_principal, krb5_address * const *, krb5_authdata * const *, krb5_pa_data * const *, const krb5_data *, krb5_creds *, krb5_response * );
krb5_error_code krb5_get_in_tkt_with_password(krb5_context, const krb5_flags, krb5_address * const *, krb5_enctype *, krb5_preauthtype *, const char *, krb5_ccache, krb5_creds *, krb5_kdc_rep ** );
krb5_error_code krb5_get_in_tkt_with_skey(krb5_context, const krb5_flags, krb5_address * const *, krb5_enctype *, krb5_preauthtype *, const krb5_keyblock *, krb5_ccache, krb5_creds *, krb5_kdc_rep ** );
krb5_error_code krb5_get_in_tkt_with_keytab(krb5_context, const krb5_flags, krb5_address * const *, krb5_enctype *, krb5_preauthtype *, const krb5_keytab, krb5_ccache, krb5_creds *, krb5_kdc_rep ** );
krb5_error_code krb5_decode_kdc_rep(krb5_context, krb5_data *, const krb5_keyblock *, krb5_kdc_rep ** );
krb5_error_code krb5_rd_req(krb5_context, krb5_auth_context *, const krb5_data *, const_principal, krb5_keytab, krb5_flags *, krb5_ticket **);
krb5_error_code krb5_rd_req_decoded(krb5_context, krb5_auth_context *, const krb5_ap_req *, const_principal, krb5_keytab, krb5_flags *, krb5_ticket **);
krb5_error_code krb5_rd_req_decoded_anyflag(krb5_context, krb5_auth_context *, const krb5_ap_req *, const_principal, krb5_keytab, krb5_flags *, krb5_ticket **);
krb5_error_code krb5_kt_read_service_key(krb5_context, krb5_pointer, krb5_principal, krb5_kvno, krb5_enctype, krb5_keyblock **);
krb5_error_code krb5_mk_safe(krb5_context, krb5_auth_context, const krb5_data *, krb5_data *, krb5_replay_data *);
krb5_error_code krb5_mk_priv(krb5_context, krb5_auth_context, const krb5_data *, krb5_data *, krb5_replay_data *);
krb5_error_code krb5_cc_register(krb5_context, krb5_cc_ops *, krb5_boolean );
krb5_error_code krb5_sendauth (krb5_context, krb5_auth_context *, krb5_pointer, char *, krb5_principal, krb5_principal, krb5_flags, krb5_data *, krb5_creds *, krb5_ccache, krb5_error **, krb5_ap_rep_enc_part **, krb5_creds **);
krb5_error_code krb5_recvauth(krb5_context, krb5_auth_context *, krb5_pointer, char *, krb5_principal, krb5_int32, krb5_keytab, krb5_ticket **);
krb5_error_code krb5_walk_realm_tree(krb5_context, const krb5_data *, const krb5_data *, krb5_principal **, int);
krb5_error_code krb5_mk_ncred(krb5_context, krb5_auth_context, krb5_creds **, krb5_data **, krb5_replay_data *);
krb5_error_code krb5_mk_1cred(krb5_context, krb5_auth_context, krb5_creds *, krb5_data **, krb5_replay_data *);
krb5_error_code krb5_rd_cred(krb5_context, krb5_auth_context, krb5_data *, krb5_creds ***, krb5_replay_data *);
krb5_error_code krb5_fwd_tgt_creds(krb5_context, krb5_auth_context, char *, krb5_principal, krb5_principal, krb5_ccache, int forwardable, krb5_data *);
krb5_error_code krb5_auth_con_init(krb5_context, krb5_auth_context *);
krb5_error_code krb5_auth_con_free(krb5_context, krb5_auth_context);
krb5_error_code krb5_auth_con_setflags(krb5_context, krb5_auth_context, krb5_int32);
krb5_error_code krb5_auth_con_getflags(krb5_context, krb5_auth_context, krb5_int32 *);
krb5_error_code krb5_auth_con_setaddrs(krb5_context, krb5_auth_context, krb5_address *, krb5_address *);
krb5_error_code krb5_auth_con_getaddrs(krb5_context, krb5_auth_context, krb5_address **, krb5_address **);
krb5_error_code krb5_auth_con_setports(krb5_context, krb5_auth_context, krb5_address *, krb5_address *);
krb5_error_code krb5_auth_con_setuseruserkey(krb5_context, krb5_auth_context, krb5_keyblock *);
krb5_error_code krb5_auth_con_getkey(krb5_context, krb5_auth_context, krb5_keyblock **);
krb5_error_code krb5_auth_con_getlocalsubkey(krb5_context, krb5_auth_context, krb5_keyblock **);
krb5_error_code krb5_auth_con_set_req_cksumtype(krb5_context, krb5_auth_context, krb5_cksumtype);
krb5_error_code krb5_auth_con_set_safe_cksumtype(krb5_context, krb5_auth_context, krb5_cksumtype);
krb5_error_code krb5_auth_con_getcksumtype(krb5_context, krb5_auth_context, krb5_cksumtype *);
krb5_error_code krb5_auth_con_getlocalseqnumber(krb5_context, krb5_auth_context, krb5_int32 *);
krb5_error_code krb5_auth_con_getremoteseqnumber(krb5_context, krb5_auth_context, krb5_int32 *);
krb5_error_code krb5_auth_con_initivector(krb5_context, krb5_auth_context);
krb5_error_code krb5_auth_con_setivector(krb5_context, krb5_auth_context, krb5_pointer);
krb5_error_code krb5_auth_con_getivector(krb5_context, krb5_auth_context, krb5_pointer *);
krb5_error_code krb5_auth_con_setrcache(krb5_context, krb5_auth_context, krb5_rcache);
krb5_error_code krb5_auth_con_getrcache(krb5_context, krb5_auth_context, krb5_rcache *);
krb5_error_code krb5_auth_con_getauthenticator(krb5_context, krb5_auth_context, krb5_authenticator **);
krb5_error_code krb5_auth_con_getremotesubkey(krb5_context, krb5_auth_context, krb5_keyblock **);
krb5_error_code krb5_read_password(krb5_context, const char *, const char *, char *, int * );
krb5_error_code krb5_aname_to_localname(krb5_context, const_principal, const int, char * );
krb5_error_code krb5_get_host_realm(krb5_context, const char *, char *** );
krb5_error_code krb5_free_host_realm(krb5_context, char * const * );
krb5_error_code krb5_get_realm_domain(krb5_context, const char *, char ** );
krb5_boolean krb5_kuserok(krb5_context, krb5_principal, const char *);
krb5_error_code krb5_auth_con_genaddrs(krb5_context, krb5_auth_context, int, int);
krb5_error_code krb5_gen_portaddr(krb5_context, const krb5_address *, const_pointer, krb5_address **);
krb5_error_code krb5_make_fulladdr(krb5_context, krb5_address *, krb5_address *, krb5_address *);
krb5_error_code krb5_os_hostaddr(krb5_context, const char *, krb5_address ***);
krb5_error_code krb5_set_real_time(krb5_context, krb5_int32, krb5_int32);
krb5_error_code krb5_set_debugging_time(krb5_context, krb5_int32, krb5_int32);
krb5_error_code krb5_use_natural_time(krb5_context);
krb5_error_code krb5_get_time_offsets(krb5_context, krb5_int32 *, krb5_int32 *);
krb5_error_code krb5_set_time_offsets(krb5_context, krb5_int32, krb5_int32);
krb5_error_code krb5_string_to_enctype(char *, krb5_enctype *);
krb5_error_code krb5_string_to_salttype(char *, krb5_int32 *);
krb5_error_code krb5_string_to_cksumtype(char *, krb5_cksumtype *);
krb5_error_code krb5_string_to_timestamp(char *, krb5_timestamp *);
krb5_error_code krb5_string_to_deltat(char *, krb5_deltat *);
krb5_error_code krb5_enctype_to_string(krb5_enctype, char *, size_t);
krb5_error_code krb5_salttype_to_string(krb5_int32, char *, size_t);
krb5_error_code krb5_cksumtype_to_string(krb5_cksumtype, char *, size_t);
krb5_error_code krb5_timestamp_to_string(krb5_timestamp, char *, size_t);
krb5_error_code krb5_timestamp_to_sfstring(krb5_timestamp, char *, size_t, char *);
krb5_error_code krb5_deltat_to_string(krb5_deltat, char *, size_t);
krb5_error_code krb5_prompter_posix(krb5_context context, void *data, const char *banner, int num_prompts, krb5_prompt prompts[]);
void krb5_get_init_creds_opt_init(krb5_get_init_creds_opt *opt);
void krb5_get_init_creds_opt_set_tkt_life(krb5_get_init_creds_opt *opt, krb5_deltat tkt_life);
void krb5_get_init_creds_opt_set_renew_life(krb5_get_init_creds_opt *opt, krb5_deltat renew_life);
void krb5_get_init_creds_opt_set_forwardable(krb5_get_init_creds_opt *opt, int forwardable);
void krb5_get_init_creds_opt_set_proxiable(krb5_get_init_creds_opt *opt, int proxiable);
void krb5_get_init_creds_opt_set_etype_list(krb5_get_init_creds_opt *opt, krb5_enctype *etype_list, int etype_list_length);
void krb5_get_init_creds_opt_set_address_list(krb5_get_init_creds_opt *opt, krb5_address **addresses);
void krb5_get_init_creds_opt_set_preauth_list(krb5_get_init_creds_opt *opt, krb5_preauthtype *preauth_list, int preauth_list_length);
void krb5_get_init_creds_opt_set_salt(krb5_get_init_creds_opt *opt, krb5_data *salt);
krb5_error_code krb5_get_init_creds_password(krb5_context context, krb5_creds *creds, krb5_principal client, char *password, krb5_prompter_fct prompter, void *data, krb5_deltat start_time, char *in_tkt_service, krb5_get_init_creds_opt *options);
krb5_error_code krb5_get_init_creds_keytab(krb5_context context, krb5_creds *creds, krb5_principal client, krb5_keytab arg_keytab, krb5_deltat start_time, char *in_tkt_service, krb5_get_init_creds_opt *options);
void krb5_verify_init_creds_opt_init(krb5_verify_init_creds_opt *options);
void krb5_verify_init_creds_opt_set_ap_req_nofail(krb5_verify_init_creds_opt *options, int ap_req_nofail);
krb5_error_code krb5_verify_init_creds(krb5_context context, krb5_creds *creds, krb5_principal ap_req_server, krb5_keytab ap_req_keytab, krb5_ccache *ccache, krb5_verify_init_creds_opt *options);
krb5_error_code krb5_get_validated_creds(krb5_context context, krb5_creds *creds, krb5_principal client, krb5_ccache ccache, char *in_tkt_service);
krb5_error_code krb5_get_renewed_creds(krb5_context context, krb5_creds *creds, krb5_principal client, krb5_ccache ccache, char *in_tkt_service);
int mit_des_ecb_encrypt(const mit_des_cblock  *, mit_des_cblock  *, mit_des_key_schedule , int );
krb5_error_code mit_des_init_random_key( const krb5_encrypt_block  *, const krb5_keyblock  *, krb5_pointer  *);
int mit_des_key_sched(mit_des_cblock , mit_des_key_schedule );
krb5_error_code mit_des_random_key( const krb5_encrypt_block  *, krb5_pointer , krb5_keyblock  *  *);
void KRB5_CALLCONV com_err_va(const char  *whoami, errcode_t code, const char  *fmt, va_list ap));
const char * error_message(errcode_t);
errcode_t add_error_table(const struct error_table  *);
errcode_t remove_error_table(const struct error_table  *);
