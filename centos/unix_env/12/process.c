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


static int getfd(size_t len)
{
    int fd = 0;

    fd = open(SHARED_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintinfo(stderr, "open %s file failure\n", SHARED_FILE);
        assert(fd < 0);
    }

    if (ftruncate(fd, len) < 0)
    {
        fprintinfo(stderr, "truncate executable failure\n");
        assert(0);
    }

    return fd;
}

static pthread_mutexattr_t *getmapspace(void)
{
    size_t len = sizeof(pthread_mutexattr_t);
    pthread_mutexattr_t *attr = NULL;

    attr = (pthread_mutexattr_t *)mmap(NULL, len, PROT_WRITE|PROT_READ, MAP_SHARED, len, 0);
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
        fprintinfo(stderr, "munmap failure\n");
        assert(retcode);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int retcode = 0;

    pthread_mutexattr_t *attr = NULL;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    printinfo("main function\n");

    printinfo("enter getmapspace function\n");
    attr = getmapspace();
    printinfo("quit getmapspace function\n");

    retcode = pthread_mutexattr_init(attr);
    pthread_mutexattr_setpshared(attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&mutex, attr);

    printinfo("thread lock attribute set success\n");

    printinfo("stack lock\n");

    pthread_mutex_lock(&mutex);

    printinfo("sleep 10 second\n");
    sleep(10);
    printinfo("process start run\n");

    pthread_mutex_unlock(&mutex);

    printinfo("quit lock\n");

    pthread_mutex_destroy(&mutex);

    attr = freemapspace(attr);

    return EXIT_SUCCESS;
}
