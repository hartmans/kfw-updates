/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/* lib/krb5/krb/copy_ctx.c */
/*
 * Copyright 1994,1999,2000, 2002, 2003, 2007, 2008, 2009  by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
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
 * permission.  Furthermore if you modify this software you must label
 * your software as modified software and not distribute it in such a
 * fashion that it might be confused with the original M.I.T. software.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 */
/*
 * Copyright (C) 1998 by the FundsXpress, INC.
 *
 * All rights reserved.
 *
 * Export of this software from the United States of America may require
 * a specific license from the United States Government.  It is the
 * responsibility of any person or organization contemplating export to
 * obtain such a license before exporting.
 *
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of FundsXpress. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  FundsXpress makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "k5-int.h"
#include "int-proto.h"
#include <ctype.h>

krb5_error_code KRB5_CALLCONV
krb5_copy_context(krb5_context ctx, krb5_context *nctx_out)
{
    krb5_error_code ret;
    krb5_context nctx;

    *nctx_out = NULL;
    if (ctx == NULL)
        return EINVAL;          /* XXX */

    nctx = malloc(sizeof(*nctx));
    if (nctx == NULL)
        return ENOMEM;

    *nctx = *ctx;

    nctx->in_tkt_etypes = NULL;
    nctx->tgs_etypes = NULL;
    nctx->default_realm = NULL;
    nctx->profile = NULL;
    nctx->dal_handle = NULL;
    nctx->ser_ctx_count = 0;
    nctx->ser_ctx = NULL;
    nctx->prompt_types = NULL;
    nctx->os_context.default_ccname = NULL;

    memset(&nctx->libkrb5_plugins, 0, sizeof(nctx->libkrb5_plugins));
    nctx->vtbl = NULL;
    nctx->locate_fptrs = NULL;

    memset(&nctx->err, 0, sizeof(nctx->err));

    ret = krb5int_copy_etypes(ctx->in_tkt_etypes, &nctx->in_tkt_etypes);
    if (ret)
        goto errout;
    ret = krb5int_copy_etypes(ctx->tgs_etypes, &nctx->tgs_etypes);
    if (ret)
        goto errout;

    if (ctx->os_context.default_ccname != NULL) {
        nctx->os_context.default_ccname =
            strdup(ctx->os_context.default_ccname);
        if (nctx->os_context.default_ccname == NULL) {
            ret = ENOMEM;
            goto errout;
        }
    }
    ret = krb5_get_profile(ctx, &nctx->profile);
    if (ret)
        goto errout;

errout:
    if (ret) {
        krb5_free_context(nctx);
    } else {
        *nctx_out = nctx;
    }
    return ret;
}
