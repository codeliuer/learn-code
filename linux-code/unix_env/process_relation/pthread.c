#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


static void printtid(const char *statement)
{
    printf("%s current process pid = %d\n", statement, getpid());

    printf("%s current thread id = %lx\n", statement, pthread_self());
}

static void *thread(void *arg)
{
    printtid("new thread ");

    return (void *)NULL;
}


int main(int argc, char *argv[])
{
    pthread_t thid;

    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        fprintf(stderr, "pthread_create failure\n");
        return EXIT_FAILURE;
    }

    printtid("main thread ");

    sleep(1);

    return EXIT_SUCCESS;
}
