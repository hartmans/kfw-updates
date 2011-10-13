/* To the extent possible under law, Painless Security, LLC has waived
 * all copyright and related or neighboring rights to GSS-API Memory
 * Management Header. This work is published from: United States.
 */

#ifndef GSSAPI_ALLOC_H
#define GSSAPI_ALLOC_H

#ifdef _WIN32
#include "winbase.h"
#endif
#include <string.h>

static inline void
gssalloc_free(void * value)
{
    if (value) {
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

static inline void *
gssalloc_calloc(size_t count, size_t size)
{
#if _WIN32
    return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, count * size);
#else
    return calloc(count, size);
#endif
}

static inline char *
gssalloc_strdup(const char *str)
{
    int size = strlen(str)+1;
    char *copy = gssalloc_malloc(size);
    if (copy) {
        strlcpy(copy, str, size);
    }
    return copy;
}

#endif
