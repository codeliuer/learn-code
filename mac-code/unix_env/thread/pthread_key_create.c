#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <pthread.h>


extern int errno;

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    pthread_key_t key;

    pthread_key_create(&key, NULL);

    errno = 0;
    ptr = pthread_getspecific(key);
    printf("errno = %d\n", errno);
    if (ptr == NULL)
    {
        fprintf(stderr, "pthread_getspecific(key)\n");
        return EXIT_FAILURE;
    }
    printf("%p\n", ptr);

    return EXIT_SUCCESS;
}
