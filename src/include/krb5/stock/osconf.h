#ifdef UnifdefRan
/* WARNING: this file is automatically generated; do not edit! */
#endif
/*
 * $Source$
 * $Author$
 * $Id$
 *
 * Copyright 1990,1991 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America is assumed
 *   to require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 * Site- and OS- dependant configuration.
 */


#ifndef KRB5_OSCONF__
#define KRB5_OSCONF__

#ifndef HasNdbmTrue
#define ODBM
#endif

#ifdef UseSysTimeH
#define	USE_SYS_TIME_H	/* Needs <sys/time.h> for time includes. */		
#endif
#ifdef UseTimeH
#define	USE_TIME_H	/* Needs <time.h> for time includes. */
#endif

#ifdef HasInetTrue
#define KRB5_USE_INET		/* Support IP address family */
#endif
#define	USE_DBM_LNAME		/* Use a DBM database for the aname/lname
				   conversion */

#define	DEFAULT_CONFIG_FILENAME	"/krb5/krb.conf"
#define	DEFAULT_TRANS_FILENAME	"/krb5/krb.realms"
#define	DEFAULT_LNAME_FILENAME	"/krb5/aname"
#define	DEFAULT_KEYTAB_NAME	"FILE:/krb5/v5srvtab"

#define	DEFAULT_KDC_ETYPE	ETYPE_DES_CBC_CRC
#define	DEFAULT_KDC_KEYTYPE	KEYTYPE_DES
#define KDCRCACHE		"dfl:krb5kdc_rcache"

#define KDC_PORTNAME	"kerberos"	/* for /etc/services or equiv. */

#define MAX_DGRAM_SIZE	4096
#define MAX_SKDC_TIMEOUT 30
#define SKDC_TIMEOUT_SHIFT 2		/* left shift of timeout for backoff */
#define SKDC_TIMEOUT_1 1		/* seconds for first timeout */

#define RCTMPDIR	"/usr/tmp"	/* directory to store replay caches */

#endif /* KRB5_OSCONF__ */
