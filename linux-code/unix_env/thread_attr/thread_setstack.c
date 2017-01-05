#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


static void thread_func(void *arg)
{
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    pthread_attr_t attr;
    void *base = (void *)malloc(PTHREAD_STACK_MIN + 0x4000);

    if (pthread_attr_init(&attr) != 0)
    {
        fprintf(stderr, "thread attribute init failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_setstack(&attr, base, PTHREAD_STACK_MIN + 0x4000) != 0)
    {
        fprintf(stderr, "thread attrabute stack set failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thid, &attr, thread_func, NULL) != 0)
    {
        fprintf(stderr, "create thread failure\n");
        return EXIT_FAILURE;
    }

    if (pthread_attr_destroy(&attr) !0 0)
    {
        fprintf(stderr, "thread attrabute destroy faialure\n");
        return EXIT_FAILURE;
    }

    sleep (1);

    return EXIT_SUCCESS;
}
