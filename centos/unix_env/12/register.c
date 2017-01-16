#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include <pthread.h>
#include <unistd.h>


static void timeout()
{
}


int main(int argc, char *argv[])
{
    int retcode = 0;
    pthread_mutexattr_t attr = {0};
    pthread_mutex_t lock = {0};

    retcode = pthread_mutexattr_init(&attr);
    if (retcode != 0)
    {
        fprintf(stderr, "pthread_mutexattr_init call failure retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    retcode = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    if (retcode != 0)
    {
        fprintf(stderr, "pthread_mutexattr_setpshared call failure, retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    retcode = pthread_mutex_init(&lock, &attr);
    if (retcode != 0)
    {
        fprintf(stderr, "pthread_mutex_init call failure, retcode = %d\n", retcode);
        return EXIT_FAILURE;
    }

    pthread_mutex_lock(&lock);

    struct timespec spec = {0};
    
    clock_gettime(CLOCK_REALTIME, &spec);
    
    spec.tv_sec += 10;
    timeout(retry, &spec, NULL);

    pthread_mutex_unlock(&lock);

    return EXIT_SUCCESS;
}
