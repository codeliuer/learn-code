#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


static void *thread(void *arg)
{
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    pthread_attr_t attr;

    if (pthread_attr_init(&attr) != 0)
    {
        fprintf(stderr, "thread attribute init failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thid, &attr, thread, NULL) != 0)
    {
        fprintf("thread create failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_getstacksize(&attr, &size) != 0)
    {
        fprintf(stderr, "get stack size failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_destroy(&attr) != 0)
    {
        fprintf(stderr, "thread destroy\n");
        return EXIT_FAILURE;
    }

    printf("thread stack size = %lu\n", size);

    return EXIT_SUCCESS;
}
