#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    pthread_t thid;
    pthread_key_t key;

    pthread_key_create(&key, free);
    pthread_setspecific();

    return EXIT_SUCCESS;
}
