#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static void* return_thread(void *arg)
{
    printf("return thread start sleep\n");

    sleep(5);

    return (void *)2;
}

int main(int argc, char *argv[])
{
    void *retcode = NULL;
    pthread_t thid;

    if (pthread_create(&thid, NULL, return_thread, NULL) != 0)
    {
        fprintf(stderr, "thread create failure\n");
        return EXIT_FAILURE;
    }

//    pthread_join(thid, &retcode);

//    printf("new thread quit code = %d\n", *(int *)&retcode);

    printf("master thread quit\n");

    pthread_exit(NULL);
}
