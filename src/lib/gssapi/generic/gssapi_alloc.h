/* To the extent possible under law, Painless Security, LLC has waived
 * all copyright and related or neighboring rights to GSS-API Memory
 * Management Header. This work is published from: United States.
 */

#ifndef GSSAPI_ALLOC_H
#define GSSAPI_ALLOC_H

#ifdef _WIN32
#include "winbase.h"
#endif

static inline void
gssalloc_free(void * value)
{
    if (value)
    {
#if _WIN32
        HeapFree(GetProcessHeap(), 0, value);
#else
        free(value);
#endif
    }
}

static inline void * 
gssalloc_malloc(size_t size)
{
#if _WIN32
    return HeapAlloc(GetProcessHeap(), 0, size);
#else
    return malloc(size);
#endif
}

static inline char *
gssalloc_strdup(const char *str)
{
    char *copy = gssalloc_malloc(strlen(str)+1);
    if (copy) {
        strcpy(copy, str);
    }
    return copy;
}

#endif
