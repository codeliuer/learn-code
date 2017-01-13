#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv)
{
    int fd = open("shared", O_RDWR);
    pthread_mutex_t *mutex = mmap(NULL, sizeof(*mutex), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    printf("try to get lock\n");
    pthread_mutex_lock(mutex);
    printf("process pid = %d get lock\n", getpid());
    sleep(1);
    printf("free lock\n");
    pthread_mutex_unlock(mutex);

    return EXIT_SUCCESS;
}
