/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * For copying and distribution information, please see the file
 * <krb5/copyright.h>.
 *
 * Definition of default configuration parameters.
 */

#if !defined(lint) && !defined(SABER)
static char rcsid_config_fn_c [] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/osconf.h>
#include <krb5/config.h>


char *krb5_config_file = DEFAULT_CONFIG_FILENAME;
char *krb5_trans_file = DEFAULT_TRANS_FILENAME;
char *krb5_defkeyname  = DEFAULT_KEYTAB_NAME;
#ifdef USE_DBM_LNAME
char *krb5_lname_file = DEFAULT_LNAME_FILENAME;
#endif

int krb5_max_dgram_size = MAX_DGRAM_SIZE;
int krb5_max_skdc_timeout = MAX_SKDC_TIMEOUT;
int krb5_skdc_timeout_shift = SKDC_TIMEOUT_SHIFT;
int krb5_skdc_timeout_1 = SKDC_TIMEOUT_1;

#ifdef KRB5_USE_INET
char *krb5_kdc_udp_portname = KDC_PORTNAME;
#endif

char *krb5_default_pwd_prompt1 = DEFAULT_PWD_STRING1;
char *krb5_default_pwd_prompt2 = DEFAULT_PWD_STRING2;
