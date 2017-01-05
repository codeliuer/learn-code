#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    pthread_attr_t *attr = (pthread_attr_t *)malloc(sizeof(*attr));
    assert(attr);

    pthread_attr_init(attr);
    pthread_attr_destroy(attr);

    return EXIT_SUCCESS;
}
