#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <pthread.h>


static pthread_mutex_t lock;

static void *threadfunc(void *arg)
{
    pthread_mutex_lock(&lock);

    printf("locked and thread over\n");

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int retcode = 0;
    pthread_t thid;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setrobust(&attr, PTHREAD_MUTEX_ROBUST);

    pthread_mutex_init(&lock, &attr);

    pthread_create(&thid, NULL, threadfunc, NULL);
    pthread_join(thid, NULL);

    if ((retcode = pthread_mutex_lock(&lock)) == EOWNERDEAD)
    {
        pthread_mutex_consistent(&lock);
        pthread_mutex_unlock(&lock);
    }

    printf("retcode = %d\n", retcode);
    printf("EOWNERDEAD = %d\n", EOWNERDEAD);

    if ((retcode = pthread_mutex_lock(&lock)) == EOWNERDEAD)
    {
        fprintf(stderr, "pthread_mutex_consistent failure\n");
        return EXIT_FAILURE;
    }

    printf("pthread_mutex_consistent success\n");

    return EXIT_SUCCESS;
}
