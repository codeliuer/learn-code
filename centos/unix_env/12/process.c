#include <stdio.h>
#include <stdlib.h>
#include <self_io.h>
#include <assert.h>

#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>


#define SHARED_FILE         "shared"


static int getfd(void)
{
    int fd = 0;

    fd = open(SHARED_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintinfo(stderr, "open %s file failure\n", SHARED_FILE);
        assert(fd < 0);
    }
}

static pthread_mutexattr_t *getmapspace(void)
{
    pthread_attr_t *attr = NULL;

    attr = mmap(NULL, sizeof(*attr), PROT_WRITE|PROT_READ, MAP_SHARED, getfd(), 0);
    assert(attr);

    printinfo("thread attribute address = %p\n", attr);

    return attr;
}

static pthread_mutexattr_t *freemapspace(pthread_mutexattr_t *attr)
{
    int retcode = 0;

    retcode = munmap(attr, sizeof(*attr));
    if (retcode < 0)
    {
        fprintinfo("munmap failure\n");
        assert(retcode);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int fd = 0;
    pthread_mutexattr_t *attr = NULL;

    printinfo("main function\n");

    attr = getmapspace();
    pthread_mutexattr_init(attr);
    pthread_mutexattr_setpshared(attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_lock(attr);

    printinfo("sleep 10 second\n");
    sleep(10);
    printinfo("process start run\n");

    pthread_mutex_unlock(attr);
    pthread_mutex_destroy(attr);

    attr = freemapspace(attr);

    return EXIT_SUCCESS;
}
