#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "memory.h"


PUBLIC void*
getblock(size_t len)
{
    void* tmp = NULL;

    tmp = malloc(len);
    assert(tmp);

    memset(tmp, 0, len);

    return tmp;
}
