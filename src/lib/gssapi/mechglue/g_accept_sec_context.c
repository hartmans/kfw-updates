#ident  "@(#)gss_accept_sec_context.c 1.19     95/08/07 SMI"

/*
 * Copyright 1996 by Sun Microsystems, Inc.
 * 
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appears in all copies and
 * that both that copyright notice and this permission notice appear in
 * supporting documentation, and that the name of Sun Microsystems not be used
 * in advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission. Sun Microsystems makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 * 
 * SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
 * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 *  glue routine for gss_accept_sec_context
 */

#include "mglueP.h"
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <string.h>

OM_uint32
gss_accept_sec_context (minor_status,
                        context_handle,
                        verifier_cred_handle,
                        input_token_buffer,
                        input_chan_bindings,
                        src_name,
                        mech_type,
                        output_token,
                        ret_flags,
                        time_rec,
                        delegated_cred_handle)

OM_uint32 *		minor_status;
gss_ctx_id_t *		context_handle;
gss_cred_id_t		verifier_cred_handle;
gss_buffer_t		input_token_buffer;
gss_channel_bindings_t	input_chan_bindings;
gss_name_t *		src_name;
gss_OID *		mech_type;
gss_buffer_t		output_token;
OM_uint32 *		ret_flags;
OM_uint32 *		time_rec;
gss_cred_id_t *		delegated_cred_handle;

{
    OM_uint32		status, temp_status, temp_minor_status;
    gss_union_ctx_id_t	union_ctx_id;
    gss_union_cred_t	union_cred;
    gss_cred_id_t	input_cred_handle = GSS_C_NO_CREDENTIAL;
    gss_name_t		internal_name;
    gss_buffer_desc	external_name_desc;
    gss_buffer_t	external_name = &external_name_desc;
    gss_OID		name_type;
    gss_OID_desc	token_mech_type_desc;
    gss_OID		token_mech_type = &token_mech_type_desc;
    gss_mechanism	mech;
    int i;
    
    gss_initialize();

    if (context_handle == NULL)
	return GSS_S_NO_CONTEXT;

    /*
     * if context_handle is GSS_C_NO_CONTEXT, allocate a union context
     * descriptor to hold the mech type information as well as the
     * underlying mechanism context handle. Otherwise, cast the
     * value of *context_handle to the union context variable.
     */
    
    if(*context_handle == GSS_C_NO_CONTEXT) {

	union_ctx_id = (gss_union_ctx_id_t)
	    malloc(sizeof(gss_union_ctx_id_desc));

	union_ctx_id->mech_type = (gss_OID)
	    malloc(sizeof(gss_OID_desc));

	/*
	 * get the token mech type, create the context id mech type space
	 * and copy in the OID
	 */

	__gss_get_mech_type(&token_mech_type, input_token_buffer);

	union_ctx_id->mech_type->elements = (void *)
	    malloc(token_mech_type->length);

	union_ctx_id->mech_type->length = token_mech_type->length;
	memcpy(union_ctx_id->mech_type->elements,
	       token_mech_type->elements,
	       token_mech_type->length);

	/* copy the supplied context handle */

	union_ctx_id->internal_ctx_id = *context_handle;
    } else
	union_ctx_id = *context_handle;
    
    /* 
     * get the appropriate cred handle from the union cred struct.
     * defaults to GSS_C_NO_CREDENTIAL if there is no cred, which will
     * use the default credential.
     */
    
    union_cred = (gss_union_cred_t) verifier_cred_handle;
    
    if (verifier_cred_handle != GSS_C_NO_CREDENTIAL) 
	for (i=0; i < union_cred->count; i++) {
	    if((union_cred->mechs_array[i].length == token_mech_type->length)
	       &&
	       (memcmp(union_cred->mechs_array[i].elements,
		       token_mech_type->elements, 
		       token_mech_type->length) == 0)) {
		
		input_cred_handle = union_cred->cred_array[i];
		break;
	    }
	}
    
    /*
     * now select the approprate underlying mechanism routine and
     * call it.
     */
    
    mech = __gss_get_mechanism (token_mech_type);
    if (mech && mech->gss_accept_sec_context) {

	    status = mech->gss_accept_sec_context(
						  mech->context,
						  minor_status,
						  &union_ctx_id->internal_ctx_id,
						  input_cred_handle,
						  input_token_buffer,
						  input_chan_bindings,
						  &internal_name,
						  mech_type,
						  output_token,
						  ret_flags,
						  time_rec,
						  delegated_cred_handle);

	    /* if the call failed, return with failure */

	    if(status != GSS_S_COMPLETE
	       &&
	       status != GSS_S_CONTINUE_NEEDED)
		return(status);

	    /*
	     * if src_name is non-NULL,
	     * convert internal_name into a union name equivalent
	     * First call the mechanism specific display_name()
	     * then call gss_import_name() to create
	     * the union name struct cast to src_name
	     */

	    if(src_name != NULL && status == GSS_S_COMPLETE) {
		temp_status = __gss_display_internal_name (
						     &temp_minor_status,
						     &mech->mech_type,
						     internal_name,
						     external_name,
						     &name_type);

		if (temp_status != GSS_S_COMPLETE) {
			
		    /*
		     * this should never happen, since we just got
		     * the name from the mechanism gss_accept_sec_context
		     * call. However, things that can't happen often do.
		     */
		    if (minor_status)
			*minor_status = temp_minor_status;
		    gss_release_buffer(
				       &temp_minor_status,
				       output_token);
		    __gss_release_internal_name(&temp_minor_status,
					  &mech->mech_type,
					  &internal_name);
		    return(GSS_S_FAILURE);
		}

		/* now create the union name */

		temp_status = gss_import_name(
					      &temp_minor_status,
					      external_name,
					      name_type,
					      src_name);

		if(temp_status != GSS_S_COMPLETE) {
		    if (minor_status)
			*minor_status = temp_minor_status;
		    gss_release_buffer(
				       &temp_minor_status,
				       output_token);
		    __gss_release_internal_name(
					  &temp_minor_status,
					  &mech->mech_type,
					  &internal_name);
		    gss_release_buffer(
				       &temp_minor_status,
				       external_name);
		    return(GSS_S_FAILURE);
		}

		__gss_release_internal_name(
				      &temp_minor_status,
				      &mech->mech_type,
				      &internal_name);
		gss_release_buffer(
				   &temp_minor_status,
				   external_name);
	    }

	if(*context_handle == GSS_C_NO_CONTEXT)
	    *context_handle = (gss_ctx_id_t *) union_ctx_id;

	return(status);
    }
    
    return(GSS_S_BAD_MECH);
}
