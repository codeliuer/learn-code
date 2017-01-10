#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <self_io.h>

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#define MMAP_FILE           "shared"


int main(int argc, char *argv[])
{
    int fd = 0;
    int retcode = 0;
    void *addr = NULL;
    struct stat st = {0};

    printinfo("open filename: %s\n", MMAP_FILE);
    fd = open(MMAP_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintinfo(stderr, "open %s file failure\n", MMAP_FILE);
        return EXIT_FAILURE;
    }

    printinfo("stat filename: %s\n", MMAP_FILE);
    retcode = stat(MMAP_FILE, &st);
    if (retcode != 0)
    {
        fprintinfo(stderr, "get %s file stat failure\n", MMAP_FILE);
        return EXIT_FAILURE;
    }

    addr = mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MMAP_SHREAD, fd, 0);
    if (addr == NULL)
    {
        fprintinfo(stderr, "");
    }

    return EXIT_SUCCESS;
}
