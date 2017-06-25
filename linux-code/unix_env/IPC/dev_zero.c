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

    close(fd); // mmap success and close fd

    TELL_WAIT();

    if ((pid = fork()) < 0)
    {
        perror("fork failure: ");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        int i = 0;

        for (i = 0; i < 1000; i+=2)
        {
            if (update(&i) != i)
            {
                fprintf(stderr, "process sync failure, i = %d\n", i);
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
        
    }

    return EXIT_SUCCESS;
}
