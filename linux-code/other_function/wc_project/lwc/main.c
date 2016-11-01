/*
** main file
** the library name: libcommon.so
** the extern interface: common()
*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include <unistd.h>
#include <sys/types.h>

#include "common.h"


#define ROOT                    (0)


#ifndef false
#define false                   (0)
#endif //false

#ifndef true
#define true                    (1)
#endif //true

#define LIBRARY_NAME            "libcommon.so"
#define INTERFACE_NAME          "common"


#ifdef unix
typedef unsigned char bool;
#endif //unix


typedef int (*PFuncPtr)(int, char**);


static int 
main_common(int argc, char* argv[])
{
    char* error = NULL;
    void* phandle = NULL;
    PFuncPtr pfunc = NULL;

    phandle = dlopen(LIBRARY_NAME, RTLD_LAZY);
    if (phandle == NULL)
    {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(phandle);
        return EXIT_FAILURE;
    }

    dlerror();  /* clear any existing error */

    /*
    ** the C99 standard leaves casting from "void *"
    ** to a function pointer undefined
    */
    *(void **)&pfunc = dlsym(phandle, INTERFACE_NAME);
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        dlclose(phandle);
        return EXIT_FAILURE;
    }

    (*pfunc)(argc, argv);

    dlclose(phandle);

    return EXIT_SUCCESS;
}

static bool
is_root(void)
{
//    printf("uid = %d\n", getuid());
    return (geteuid() == ROOT) ? true : false; 
}


int
main(int argc, char* argv[])
{
//    main_common(argc, argv);
    if (!is_root())
    {
        fprintf(stderr, "An unprivileged user, the program requires privileges\n");
        return EXIT_FAILURE;
    }
    wc_main(argc, argv);

    return EXIT_SUCCESS;
}
