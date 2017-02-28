#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static int count = 0;

static void thread_func(void *arg)
{
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

    return EXIT_SUCCESS;
}
