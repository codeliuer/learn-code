#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


typedef struct thread_once
{
    pthread_once_t  initflag;
    pthread_t       thid;
} thread_once;

static void onceflag_add(pthread_t thid)
{

}

static void onceflag_get(pthread_once_t **ppflag)
{
}

static void print(void)
{
    printf("thread_id = %lx\n", pthread_self());
}

void *thread_init(void *arg)
{
    pthread_once_t *pflag = NULL;

    onceflag_get(&pflag);

    pthread_once(pflag, print);

    pthread_exit(NULL);
}

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

int main(int argc, char *argv[])
{
    int i = 0;
    int ret = 0;
    pthread_t thid;

    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&lock);

        ret = pthread_create(&thid, NULL, thread_init, NULL);
        if (ret != 0)
        {
            fprintf(stderr, "thread create failaure = %d\n", i);
        }

        onceflag_add(thid);

        pthread_mutex_unlock(&lock);

    }

    sleep(1);

    return EXIT_SUCCESS;
}
