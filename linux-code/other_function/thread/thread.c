#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static void*
threadfunc(void* arg)
{
    sleep(1);

    *(int *)arg = 5;

    return NULL;
}


int
main(int argc, char* argv[])
{
    int a = 9;
    pthread_t pid;

    pthread_create(&pid, NULL, threadfunc, &a);
    while (a == 9)
    {
//        sleep(1);
        printf("a = %d your sister!!!!!!!!!\n", a);
    }

    return EXIT_SUCCESS;
}
