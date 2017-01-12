#include <stdio.h>
#include <stdlib.h>
#include <self_io.h>

#include <unistd.h>
#include <pthread.h>

#include "../api.h"


int main(int argc, char *argv[])
{
    int retcode = 0 ;
//    pthread_mutexattr_t attr;
    pthread_mutex_t *addr = NULL;

    addr = mapaddr_init(sizeof(*addr), MAP_PROCESS_SHARED);
    if (addr == NULL)
    {
        printinfo("get thread mutex space failure\n");
        return EXIT_FAILURE;
    }
/*
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(addr, &attr);
*/
    retcode = pthread_mutex_lock(addr);
    if (retcode != 0)
    {
        fprintinfo(stderr, "thread mutex failure\n");
        return EXIT_FAILURE;
    }

    printinfo("current process pid = %d\n", getpid());
    sleep(1);

    pthread_mutex_unlock(addr);

//    pthread_mutex_destroy(addr);

    mapaddr_destroy(addr, sizeof(*addr));

    return EXIT_SUCCESS;
}
