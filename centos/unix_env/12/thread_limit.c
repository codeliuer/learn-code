#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("thread quit max number = %ld\n", sysconf(_SC_THREAD_DESTRUCTOR_ITERATIONS));
    printf("able create key max = %ld\n", sysconf(_SC_THREAD_KEYS_MAX));
    printf("thread stack min = %ld\n", sysconf);

    return EXIT_SUCCESS;
}
