#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>


static void *thread_func(void *arg)
{
    printf("stackaddr = %ld\n", sysconf(_SC_THREAD_ATTR_STACKADDR));
    printf("stacksize = %ld\n", sysconf(_SC_THREAD_ATTR_STACKSIZE));

    sleep(1);

    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
    pthread_t thid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&thid, &attr, thread_func, NULL);

    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
//    return EXIT_SUCCESS;
}
