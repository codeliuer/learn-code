#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>

static void quit(void *arg)
{
    printf("cleanup: %s\n", (char *)arg);
}

static void *thread1(void *arg)
{
    pthread_cleanup_push(quit, "thread 1 first handler");
    pthread_cleanup_push(quit, "thread 1 second handler");
    printf("thread 1 push complete\n");

    if (arg)
    {
        return (void *)1;
    }

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    return (void *)1;
}

static void *thread2(void *arg)
{
    pthread_cleanup_push(quit, "thread 2 first handler");
    pthread_cleanup_push(quit, "thread 2 second handler");
    printf("thread 2 push complete\n");

    if (arg)
    {
        pthread_exit((void *)2);
    }

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
    int         err = 0;
    pthread_t   tid1, tid2;
    void        *tret = NULL;

    err = pthread_create(&tid1, NULL, thread1, (void *)1);
    if (err)
    {
        fprintf(stderr, "pthread_create 1 failure\n");
        exit(EXIT_FAILURE);
    }

    err = pthread_create(&tid2, NULL, thread2, (void *)2);
    if (err)
    {
        fprintf(stderr, "pthread_create 2 failure\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(tid1, NULL) && pthread_join(tid2, NULL))
    {
        fprintf(stderr, "pthread_join failure\n");
        exit(EXIT_FAILURE);
    }

    printf("thread 2 exit code %ld\n", (long)tret);

    sleep(1);

    return EXIT_SUCCESS;
}
