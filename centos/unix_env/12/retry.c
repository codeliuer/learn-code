#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <pthread.h>


typedef struct timeout_func_t
{
    long int timeout;
    void *(*func)(void);
    void *arg;
} timeout_func_t;

static pthread_mutex_t mutex;

static void register_timeout(timeout_func_t *func)
{
    pthread_t thid; 
    struct timespec spec = {0};

    clock_gettime(CLOCK_REALTIME, &spec);
    spec.tv_sec += func->timeout;

    clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &spec, NULL);

    pthread_create();
}

static void *thread(void* arg)
{
    pthread_mutex_lock(&mutex);

    if (arg == NULL)
    {
        printf("timeout now time is 0\n");
    }
    else
    {
        printf("output base infomation\n");
    }

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_mutexattr_t attr = {0};
    timeout_func_t func = {10, thread, NULL}

    if (pthread_mutexattr_init(&attr) != 0)
    {
        fprintf(stderr, "mutex attr init failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE) != 0)
    {
        fprintf(stderr, "mutex attr set recursive failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_mutex_init(&mutex, &attr) != 0)
    {
        fprintf(stderr, "mutex init failure\n");
        return EXIT_FAILURE;
    }

    pthread_mutex_lock(&mutex);

    register_timeout(&func);

    pthread_mutex_unlock(&mutex);

    pthread_mutexattr_destroy(&attr);
    pthread_mutex_destroy(&mutex);

    pthread_exit(NULL);
}
