#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc ,char *argv[])
{
    clockid_t clockid; 

    pthread_condattr_getclock(NULL, &clockid);

    printf("clockid = %d\n", clockid);

    return EXIT_SUCCESS;
}
