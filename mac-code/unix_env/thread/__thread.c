#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


static void *thread(void *arg)
{
   __thread static int value = 0;

    value += 1;

    printf("thread id = %p, value = %d\n", pthread_self(), value);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int i = 0;
    pthread_t thid;

    for (i = 0; i < 10; i++)
    {
        pthread_create(&thid, NULL, thread, NULL);
    }

    sleep(1);

    return EXIT_SUCCESS;
}
