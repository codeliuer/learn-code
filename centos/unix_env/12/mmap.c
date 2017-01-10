#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <self_io.h>

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#define Mmap_FILE           "shared"


int main(int argc, char *argv[])
{
    int fd = 0;
    void *addr = NULL;
    struct stat st = {0};

    fd = open(MMAP_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintinfo(stderr, "open %s file failure\n", MMAP_FILE);
        return EXIT_FAILURE;
    }

    addr = mmap(NULL, );

    return EXIT_SUCCESS;
}
