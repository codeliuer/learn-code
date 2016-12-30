#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include <pthread.h>
#include <unistd.h>


static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

static void *func(void *arg)
{
    struct timespec spec = {0};

    clock_gettime(CLOCK_REALTIME, &spec);

    spec.tv_sec += 10;

    sleep (1);
    pthread_mutex_timedlock(&lock, &spec);
 //   pthread_mutex_lock(&lock);

    printf("slave thread\n");

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t tid;

    //pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, func, NULL);

    pthread_mutex_lock(&lock);

    printf("master thread\n");
    sleep(10);

    // printf("errno = %d\n", pthread_mutex_timedlock(&lock, &spec));
    printf("ETIMEDOUT = %d\n", ETIMEDOUT);

    printf("time of day\n");

    pthread_mutex_unlock(&lock);

    sleep(2);
    printf("master over\n");
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}
