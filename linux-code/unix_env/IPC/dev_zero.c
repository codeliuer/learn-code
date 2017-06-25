#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/mman.h>

#include "process_sync/sync.h"


int main(int argc, char *argv[])
{
    int fd;
    pid_t pid;
    void *addr = NULL;

    fd = open("/dev/zero", O_RDWR);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }
    
    addr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, fd, 0);
    if (addr == NULL)
    {
        perror("mmap failure: ");
        return EXIT_FAILURE;
    }

    TELL_WAIT();

    pid = fork();

    return EXIT_SUCCESS;
}
