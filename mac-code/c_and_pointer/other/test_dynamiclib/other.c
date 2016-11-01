/*
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "other.h"
#include "error.h"


typedef void (*FPfunc)(void);


static void
plugin(void)
{
    void* phandle = NULL;
    FPfunc func = NULL;
    char* error = NULL;

    phandle = dlopen("libplugin.so", RTLD_LAZY);
    if (phandle == NULL)
    {
        l_fprint(stderr, "%s\n", dlerror());
        return ;
    }

    dlerror(); /* clear any existing error */

    *(void **)&func = dlsym(phandle, "plugin");
    if ((error = dlerror()) != NULL)
    {
        l_fprint(stderr, "%s\n", error);
        return ;
    }

    (*func)();

    dlclose(phandle);
}


int 
other(int argc, const char* string)
{
    l_print("%p\n", string);
    l_print("%s\n", string);

    plugin();

    return EXIT_SUCCESS;
}
