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

static int quit(int retcode, const char *msg)
{
    fprintinfo("%s\n", msg);

    return retcode; 
}


int main(int argc, char *argv[])
{
    int fd = 0;
    int retcode = 0;
    void *addr = NULL;
    struct stat st = {0};

    fd = open(MMAP_FILE, O_RDWR);
    if (fd < 0)
    {
        return quit("open %s file failure", EXIT_FAILURE);
    }

    retcode = stat(MMAP_FILE, &st);
    if (retcode != 0)
    {
    }

    addr = mmap(NULL, );

    return EXIT_SUCCESS;
}
