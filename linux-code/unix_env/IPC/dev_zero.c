#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/mman.h>

#include "process_sync/sync.h"

static int update(int *v)
{
    return (*v)++;
}

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
        pid = getpid();

        for (i = 0; i < 1000; i+=2)
        {
            if (update((int *)addr) != i)
            {
                fprintf(stderr, "child process sync failure, i = %d\n", i);
                return EXIT_FAILURE;
            }

            printf("child start ##############\n");
            TELL_PARENT(pid);
            WAIT_PARENT();
        }
    }
    else
    {
        int i = 0;
        pid = getpid();

        for (i = 1; i < 1000; i+=2)
        {
            WAIT_CHILD();
            printf("parent start   @@@@@@@@@@@@@@\n");

            if (update((int *)addr) != i)
            {
                fprintf(stderr, "parent process sync failure, i = %d\n", i);
                return EXIT_FAILURE;
            }

            TELL_CHILD(pid);
        }
    }

    munmap(addr, sizeof(int));

    return EXIT_SUCCESS;
}
