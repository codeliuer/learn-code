#include <stdio.h>
#include <stdlib.h>
#include <self_io.h>

#include <unistd.h>
#include <pthread.h>

#include "../api.h"


int main(int argc, char *argv[])
{
    pthread_mutex_t *addr = mapaddr_init(sizeof(*addr), MAP_PROCESS_SHARED);
    if (addr == NULL)
    {
        printinfo("get thread mutex space failure\n");
        return EXIT_FAILURE;
    }

    pthread_mutexattr_init(addr);
    pthread_mutexattr_setpshared(addr, );

    return EXIT_SUCCESS;
}
