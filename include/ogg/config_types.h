#ifndef _CONFIG_TYPES_H
#define _CONFIG_TYPES_H


#include <stdint.h>
  typedef int16_t ogg_int16_t;
  typedef uint16_t ogg_uint16_t;
  typedef int32_t ogg_int32_t;
  typedef uint32_t ogg_uint32_t;
  typedef int64_t ogg_int64_t;
  typedef uint64_t ogg_uint64_t;

#ifdef CONFIG_OGG_USE_SPIRAM
#undef _ogg_malloc
#undef _ogg_calloc
#undef _ogg_realloc

#define _ogg_malloc   ogg_malloc
#define _ogg_calloc   ogg_calloc
#define _ogg_realloc  ogg_realloc

#include "esp_heap_caps.h"

inline void* ogg_malloc(size_t size)
{
  return heap_caps_malloc(size, MALLOC_CAP_SPIRAM);
}

inline void* ogg_calloc(size_t n, size_t size)
{
  return heap_caps_calloc(n, size, MALLOC_CAP_SPIRAM);
}

inline void* ogg_realloc(void* p, size_t size)
{
  return heap_caps_realloc(p, size, MALLOC_CAP_SPIRAM);
}

#endif

#endif  /* _CONFIG_TYPES_H */

