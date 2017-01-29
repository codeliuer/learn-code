#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static void *thread_func(void *arg)
{
    int state = PTHREAD_CANCEL_ENABLE;
    int oldstate = 0;

    printf("PTHREAD_CANCEL_ENABLE = %d\n", PTHREAD_CANCEL_ENABLE);
    printf("PTHREAD_CANCEL_DISABLE = %d\n", PTHREAD_CANCEL_DISABLE);

    /* enable canceled */
    pthread_setcancelstate(state, &oldstate);

    printf("oldstate = %d\n", oldstate);

    sleep(10);

    printf("thread canceled\n");

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
