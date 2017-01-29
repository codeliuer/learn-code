#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static void *thread_func(void *arg)
{
    int i = 0;
    int j = 0;
    int oldstate = 0;
    int state = PTHREAD_CANCEL_ASYNCHRONOUS;

    pthread_setcanceltype(state, &oldstate);

    for (i = 0; i < 1000000000; i++)
    {
        for (j = 0; j < 1000000000; j++)
        {
            ;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thid;

    pthread_create(&thid, NULL, thread_func, NULL);

    sleep(1);
    pthread_cancel(thid);

    pthread_exit(NULL);
//    return EXIT_SUCCESS;
}
