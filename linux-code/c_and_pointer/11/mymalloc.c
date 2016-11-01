#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define malloc          Do_not_directly_call_malloc
#define MALLOC(num, type)   (type *)alloc(num*sizeof(type))

static void*
alloc(size_t size)
{
    void* ptr = malloc(size);

    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failure\n");
    }

    return ptr;
}


int
main(int argc, char* argv[])
{
    void* ptr = malloc(sizeof(*ptr));

    return EXIT_SUCCESS;
}
