#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    void *tmp = NULL;
    void *value = NULL;
    pthread_t thid;
    pthread_key_t key;

    pthread_key_create(&key, free);
    value = pthread_getspecific(key);
    if (value == NULL)
    {
        fprintf(stderr, "thread private key not relation\n");

    }

    return EXIT_SUCCESS;
}
