/*
** test gcc -rdynamic
** 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "common.h"
#include "error.h"


typedef int (*FPfunc)(int, char**);


static void
main_common(int argc, char* argv[])
{
    char* error = NULL;
    void* phandle = NULL;
    FPfunc func = NULL;

    phandle = dlopen("libcommon.so", RTLD_LAZY);
    if (phandle == NULL)
    {
        l_fprint(stderr, "%s\n", dlerror());
        return ;
    }

    /* clear any existing error */
    dlerror();

    /*
    ** the C99 standard leaves casting from "void *"
    ** to a function pointer undefined
    ** the assignment used below is the POSIX.1-2003 
    ** workaround; see the rationale for the POSIX
    ** specification of dysym().
    */
    *(void **)(&func) = dlsym(phandle, "common");

    if ((error = dlerror()) != NULL)
    {
        l_fprint(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    (*func)(argc, argv);

    dlclose(phandle);

    return ;
}


int
main(int argc, char* argv[])
{
    main_common(argc, argv);

    return EXIT_SUCCESS;
}
