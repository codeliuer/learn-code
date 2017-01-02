#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    pthread_t thid;
    pthread_attr_t attr;

    if (pthread_attr_init(&attr) != 0)
    {
        fprintf(stderr, "");
    }

    return EXIT_SUCCESS;
}
