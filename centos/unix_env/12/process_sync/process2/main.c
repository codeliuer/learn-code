#include <stdio.h>
#include <stdlib.h>
#include <self_io.h>

#include <unistd.h>
#include <pthread.h>

#include "../api.h"


int main(int argc, char *argv[])
{
    int retcode = 0;
    pthread_mutexattr_t attr;
    pthread_mutex_t *addr = NULL;

    addr = mapaddr_init(sizeof(*addr), MAP_PROCESS_SHARED);
    if (addr == NULL)
    {
        printinfo("get thread mutex space failure\n");
        return EXIT_FAILURE;
    }

    retcode = pthread_mutexattr_init(&attr);
    if (retcode != 0)
    {
        fprintinfo(stderr, "thread mutexattr init failure retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    retcode = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    if (retcode != 0)
    {
        fprintinfo(stderr, "thread mutexattr shared failure, retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    retcode = pthread_mutex_init(addr, &attr);
    if (retcode != 0)
    {
        fprintinfo(stderr, "thread mutex init failure retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    retcode = pthread_mutex_lock(addr);
    if (retcode != 0)
    {
        fprintinfo(stderr, "thread mutex lock failure\n");
        return EXIT_FAILURE;
    }

    printinfo("current process pid = %d\n", getpid());
    sleep(10);

    pthread_mutex_unlock(addr);

//    pthread_mutex_destroy(addr);

    mapaddr_destroy(addr, sizeof(*addr));

    return EXIT_SUCCESS;
}
