/*
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "common.h"
#include "other.h"
#include "error.h"


typedef int (*FPfunc)(int, const char* string);


static void
test_main(int argc, const char* str)
{
    char* error = NULL;
    FPfunc func = NULL;
    void* phandle = NULL;

    phandle = dlopen("libother.so", RTLD_LAZY);
    if (phandle == NULL)
    {
        l_fprint(stderr, "%s\n", dlerror());
        return ;
    }

    dlerror(); /* clearn any existing error */

    *(void **)(&func) = dlsym(phandle, "other");
    if ((error = dlerror()) != NULL)
    {
        l_fprint(stderr, "%s\n", error);
        return ;
    }

    (*func)(argc, str);

    dlclose(phandle);
}


int
common(int argc, char* argv[])
{
    if (argc != 2)
    {
        l_fprint(stderr, "failure\n");
        return EXIT_FAILURE;
    }

    l_print("continue\n");

    test_main(argc, argv[1]);

    return EXIT_SUCCESS;
}
