#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>


int main(int argc, char *argv)
{
    int fd = open("shared", O_RDWR);
    pthread_mutexattr_t attr;
    pthread_mutex_t *mutex = mmap(NULL, sizeof(*mutex), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    pthread_mutexattr_init(&attr);
    pthread_mutex_attr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(mutex, &attr);

    pthread_mutexattr_destroy(&attr);

    pthread_mutex_lock(mutex);
    printf("process pid = %d get lock\n", getpid());
    sleep(100);
    pthread_mutex_unlock(mutex);

    pthread_

    return EXIT_SUCCESS;
}
