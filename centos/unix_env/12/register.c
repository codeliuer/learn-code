#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include <pthread.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int retcode = 0;
    pthread_mutexattr_t attr = {0};
    pthread_mutex_t lock = {0};

    pthread_mutexattr_init(&attr);

    return EXIT_SUCCESS;
}
