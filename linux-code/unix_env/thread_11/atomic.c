#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static int count = 0;

static void *thread_func(void *arg)
{
    int i = 0;

    for (i = 0; i < 20000; i++)
    {
        __sync_fetch_and_add(&count, 1);
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    pthread_t tid;

    for (i = 0; i < 10; i++)
    {
        pthread_create(&tid, NULL, thread_func, NULL);
    }

    __sync_synchronize();

    printf("count = %d\n", count);

    return EXIT_SUCCESS;
}
