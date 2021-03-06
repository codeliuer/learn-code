#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include <unistd.h>
#include <pthread.h>
#include <bits/local_lim.h>



extern int errno;

static void *make_space(void)
{
    void *stack = (void *)malloc(PTHREAD_STACK_MIN);
    assert(stack);

    printf("address : %p\n", stack);

    return stack;
}


static void destroy_space(void *stack)
{
    free(stack);
}

static void *thread_func(void *arg)
{
    int var = 0;

    printf("var address = %p\n", &var);

    pthread_exit(NULL);
}

static void create_thread(void *stack)
{
    int retcode = 0;
    pthread_t thid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setstack(&attr, stack, PTHREAD_STACK_MIN);

    errno = 0;
    retcode = pthread_create(&thid, &attr, thread_func, NULL);
    if (retcode != 0)
    {
        fprintf(stderr, "create thread failure\n", strerror(errno));
        return;
    }

    pthread_attr_destroy(&attr);
}

static void quit(void)
{
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    void *stack = make_space();

    create_thread(stack);

    destroy_space(stack);

    quit();

//    return EXIT_SUCCESS;
}
