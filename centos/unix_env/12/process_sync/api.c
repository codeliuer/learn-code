#include <stdio.h>
#include <stdlib.h>
#include <self_io.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "api.h"


#define SHARED_FILE         "shared"


#define INVALID_TAG         (-1)


static int file_open(const char *filename)
{
}

static void file_close(int fd)
{
}

static int validlength(int fd, int length)
{
    int retcode = 0;
    struct stat st = {0};

    retcode = fstat(fd, &st);
    if (retcode < 0)
    {
        fprintinfo(stderr, "get file stat failure\n");
        return retcode;
    }

    if (length > st.st_size)
    {
        retcode = ftruncate(fd, length);
        if (retcode < 0)
        {
            fprintinfo(stderr, "ffile truncate failure\n");
            return retcode;
        }
    }

    return length;
}

static int validtag(int tag)
{
    if (tag == MAP_PROCESS_SHARED)
    {
        return MAP_SHARED;
    }
    else if (tag == MAP_THREAD_SHARED)
    {
        return MAP_PRIVATE;
    }
    else
    {
        return INVALID_TAG;
    }
}


static int fd = 0;
/*#############################################################*/
void *mapaddr_init(size_t length, int tag)
{
    int valid_len = 0;
    int valid_tag = 0;
    void *addr = NULL;

    fd = file_open(SHARED_FILE);
    if (fd < 0)
    {
        fprintinfo(stderr, "open file %s failure\n", SHARED_FILE);
        return NULL;
    }

    valid_len = validlengh(fd, length);
    if (valid_len < 0)
    {
        fprintinfo(stderr, "get valid length failure\n");
        file_close(fd);
        return NULL;
    }

    valid_tag = validtag(tag);
    if (valid_tag < 0)
    {
        fprintinfo(stderr, "tag not support\n");
        file_close(fd);
        return NULL;
    }

    addr = mmap(NULL, valid_len, PROT_READ|PROT_WRITE, valid_tag, fd, 0);
    if (addr == NULL)
    {
        fprintinfo(stderr, "mmap failure\n");
        file_close(fd);
        return NULL;
    }

    return addr;
}


int mapaddr_destroy(void *addr, size_t length)
{
    int retcode = 0;

    retcode = munmap(addr, length);
    if (retcode < 0)
    {
        fprintinfo(stderr, "munmap execuable failure\n");
        return EXIT_FAILURE;
    }

    retcode = close(fd);
    if (retcode < 0)
    {
        fprintinfo(stderr, "close %s failure\n", SHARED_FILE);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
