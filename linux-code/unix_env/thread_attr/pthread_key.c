#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    void *value = NULL;
    pthread_t thid;
    pthread_key_t key;

    pthread_key_create(&key, free);
    value = malloc(sizeof(int));
    pthread_setspecific(key, value);

    return EXIT_SUCCESS;
}
