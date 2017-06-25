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
    void *addr = NULL;

    fd = open("/dev/zero", O_RDWR);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }
    
    addr = mmap();

    return EXIT_SUCCESS;
}
