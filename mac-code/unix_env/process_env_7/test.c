/*
** test enter point
*/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <pthread.h>


static void *
threadfunc(void* arg)
{
    usleep(10000);
    printf("pthread_exit()\n");
    sleep(2);
    printf("study\n");

    pthread_exit(NULL);
}

int
main(int argc, char* argv[])
{
    pthread_t th;

    pthread_create(&th, NULL, threadfunc, NULL);

    sleep(1);

    return EXIT_SUCCESS;
}
