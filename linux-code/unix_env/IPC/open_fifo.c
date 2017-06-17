#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


extern int errno;

int main(int argc, char *argv[])
{
    int fd = 0;

    errno = 0;

    fd = open("/Users/weiliu/learn-code/test.text", O_WRONLY);
    if (fd < 0)
    {
        perror(errno);
    }
    

    return EXIT_SUCCESS;
}
