#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>
#include <bits/local_lim.h>


int main(int argc, char *argv[])
{
    void *stack = (void *)malloc(PTHREAD_STACK_MIN);

    return EXIT_SUCCESS;
}
