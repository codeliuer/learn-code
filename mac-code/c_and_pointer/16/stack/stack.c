#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"


#define STACK_API       //module extern interface


struct STACK
{
    STACK_TYPE*       pValues;
    struct STACK        *next;
};

struct STACK_HANDLE
{
    struct STACK        handle;
};


STACK_API int 
stack_init(STACK_HANDLE** pphandle)
{
#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD

    *pphandle = malloc(sizeof(*pphandle));
    if (*pphandle == NULL)
    {
        fprintf(stderr, "memory failure\n");
        return STACK_ERRCODE_MEMORY;
    }

#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD

    return STACK_ERRCODE_SUCCESS;
}


STACK_API int 
push(STACK_HANDLE* phandle, STACK_TYPE* values)
{
#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD

#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD
}


STACK_API int 
pop(STACK_HANDLE* phandle, STACK_TYPE* values)
{
#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD

#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD
}


STACK_API int 
stack_destroy(STACK_HANDLE* phandle)
{
#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD

#if defined(MUL_PROCESS)
#endif  //MUL_PROCESS

#if defined(SINGLE_THREAD)
#endif  //MUL_THREAD
}
