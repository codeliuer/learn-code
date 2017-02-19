#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "./sync/process_sync_api.h"


#define OBJ_FILE        "stderr.out"


#define write_lock(fd, offset, whence, len)         \
    lock_reg(fd, F_SETLK, F_WRLCK, whence, offset, len)

#define read_lock(fd, offset, whence, len)         \
    lock_reg(fd, F_SETLK, F_RDLCK, whence, offset, len)


extern int errno;

static int lock_reg(int fd, int state, int lock, int whence, int start, int len)
{
    struct flock flock;

    flock.l_type = lock;
    flock.l_whence = whence;
    flock.l_start = start;
    flock.l_len = len;

    return (fcntl(fd, state, &flock));
}


static void set_fl(int fd, int flag)
{
    int fl;

    fcntl(fd, F_GETFL, &fl);

    fcntl(fd, F_SETFL, fl | flag);
}


int main(int argc, char *argv[])
{
    int fd = 0;
    pid_t pid = 0;
    struct stat stat;
    char buf[10] = "";

    fd = open(OBJ_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    write(fd, "abcdef", 6);

    if (fstat(fd, &stat) < 0)
    {
        fprintf(stderr, "fstat failure\n");
        return EXIT_FAILURE;
    }
    if (fchmod(fd, stat.st_mode & ~S_IXGRP | S_ISGID) < 0)
    {
        fprintf(stderr, "fchmod failure\n");
        return EXIT_FAILURE;
    }

    TELL_WAIT();
    
    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid > 0)
    {
        write_lock(fd, 0, SEEK_SET, 0);
        TELL_CHILD(pid);
        waitpid(pid, NULL, 0);
    }
    else
    {
        WAIT_PARENT();
        set_fl(fd, O_NONBLOCK);

        if (read_lock(fd, 0, SEEK_SET, 0) < 0)
        {
            fprintf(stderr, "child : read_lock successed\n");
        }
        printf("read_lock of already_locked region returns %d\n", errno);

        if (lseek(fd, 0, SEEK_SET) == -1)
        {
            fprintf(stderr, "lseek error\n");
            return EXIT_FAILURE;
        }
        if (read(fd, buf, 2) < 0)
        {
            fprintf(stderr, "read failure\n");
            return EXIT_FAILURE;
        }
        else
        {
            printf("read OK (no mandatory locking), buf = %2.2s\n", buf);
        }
    }

    return EXIT_SUCCESS;
}
