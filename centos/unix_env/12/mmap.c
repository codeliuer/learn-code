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
    printinfo("open filename: %s, fd = %d\n", MMAP_FILE, fd);

    printinfo("stat filename: %s\n", MMAP_FILE);
    retcode = stat(MMAP_FILE, &st);
    if (retcode != 0)
    {
        fprintinfo(stderr, "get %s file stat failure\n", MMAP_FILE);
        return EXIT_FAILURE;
    }

    printinfo("blocksize = %ld, total size = %ld, protection = %d\n", st.st_blksize, st.st_size, st.st_mode);

    printinfo("mmap fd: %d, size = %ld, attribute: (prot = %d, shared = %d)\n", fd, st.st_size, PROT_READ|PROT_WRITE, MAP_SHARED);
    addr = mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == NULL)
    {
        fprintinfo(stderr, "");
    }

    printinfo("addr = %p\n", addr);

    return EXIT_SUCCESS;
}
