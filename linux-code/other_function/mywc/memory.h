#ifndef     __MALLOC_H__
#define     __MALLOC_H__

#include "macro.h"


#define New(type)               (type *)getblock(sizeof(type))
#define New_Array(type, len)    (type *)getblock(sizeof(type) * len)
#define Delete(ptr)             do {free(ptr), ptr = NULL;} while (0)


extern void* getblock(size_t len);


#endif  //__MALLOC_H__
