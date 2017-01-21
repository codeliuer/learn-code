#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int condition = 0;

static void *thread_func(void *arg)
{
    pthread_mutex_lock(&lock);
    while (condition == 0)
    {
        pthread_cond_wait(&cond, &lock);

        printf("condition = %d\n", condition);
    }
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
    pthread_t thid;

    pthread_create(&thid, NULL, thread_func, NULL);

    pthread_mutex_lock(&lock);

    condition = 100;

    pthread_mutex_unlock(&lock);

    sleep(1);

    return EXIT_SUCCESS;
}
