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

    pthread_key_create(&key, my_free);

    tmp = malloc(sizeof(int));
    *(unsigned int *)tmp = 4;
    pthread_setspecific(key, tmp);

    value = pthread_getspecific(key);
    if (value == NULL)
    {
        fprintf(stderr, "thread private key not relation\n");

    }
    else
    {
        fprintf(stderr, "inter = %d\n", *(unsigned int *)value);
    }

    return EXIT_SUCCESS;
}
