#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>


#define MOD_FILE        "stderr.out"


static int writew_lock(int fd, int whence, int offset, int len)
{
    struct flock flock;

    flock.l_type = F_WRLCK;
    flock.l_whence = whence;
    flock.l_start = offset;
    flock.l_len = len;

    return fcntl(fd, F_SETLKW, &flock);
}

int main(int argc, char *argv[])
{
    int fd = 0;

    fd = open(MOD_FILE, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", writew_lock(fd, SEEK_SET, 10, 10));
    sleep(5);

    lseek("");
    write(fd, "AAAAACCCCC", 10);

    close(fd);

    return EXIT_SUCCESS;
}
