#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>


#define DEFAULT_STACK_SIZE          (1024 * 1024 * 8)


static void *thread_func(void *arg)
{
    int var = 0;

    printf("thread var address = %p\n", &var);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int retcode = 0;
    size_t stacksize = 0;
    pthread_t thid;
    void *stackaddr = NULL;
    size_t getstacksize = 0;
    pthread_attr_t thread_attr;
//    void * setstackaddr = malloc(DEFAULT_STACK_SIZE * 2);
    void *setstackaddr = NULL;
    printf("malloc address = %p\n", setstackaddr);

    if (pthread_attr_init(&thread_attr) != 0)
    {
        fprintf(stderr, "thread attriabute init failure\n");
        return EXIT_FAILURE;
    }
/*
    if (pthread_attr_setstacksize(&thread_attr, DEFAULT_STACK_SIZE) != 0)
    {
        fprintf(stderr, "set stack size failure\n");
        return EXIT_FAILURE;
    }
*/
    if (pthread_attr_setstack(&thread_attr, &setstackaddr, DEFAULT_STACK_SIZE) != 0)
    {
        fprintf(stderr, "thread set stack failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thid, &thread_attr, thread_func, NULL) != 0)
    {
        fprintf(stderr, "create thread failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_getstacksize(&thread_attr, &stacksize) != 0)
    {
        fprintf(stderr, "get thread stack size failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_getstack(&thread_attr, &stackaddr, &getstacksize) != 0)
    {
        fprintf(stderr, "get stack failure\n");
        return EXIT_FAILURE;
    }

    printf("thread stack start address = %p\n", stackaddr);
    printf("thread stack size = %lu\n", getstacksize);

    if (pthread_attr_destroy(&thread_attr) != 0)
    {
        fprintf(stderr, "thread attriabute destroy failure\n");
        return EXIT_FAILURE;
    }

    printf("stack size = %lu\n", stacksize);

    sleep(1);

    return EXIT_SUCCESS;
}
