/*
 * $Source$
 * $Author$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/copyright.h>.
 *
 * Return default keytab file name.
 */

#if !defined(lint) && !defined(SABER)
static char rcsid_ktdefname_c[] =
"$Id$";
#endif	/* !lint & !SABER */

#include <krb5/copyright.h>
#include <krb5/krb5.h>
#include <krb5/osconf.h>

#include <stdio.h>
#include <krb5/ext-proto.h>

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

static char krb5_defkeyname[] = DEFAULT_KEYTAB_NAME;

krb5_error_code
krb5_kt_default_name(name, namesize)
char *name;
int namesize;
{
    strncpy(name, krb5_defkeyname, min(namesize, sizeof(krb5_defkeyname)));
    if (namesize < sizeof(krb5_defkeyname))
	return KRB5_CONFIG_NOTENUFSPACE;
    else
	return 0;
}
    
