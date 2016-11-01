#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <fcntl.h>


#define TEST_NAME           "file.hole"
#define DEV_NAME            "/dev/null"



static int 
open_file(const char* name, int mode)
{
    int fd = open(name, mode);
    assert(fd >= 0);

    return fd;
}


int
main(int argc, char* argv[])
{
    int n = 0;
    int nums = 0;
    char buffer[BUFFSIZE] = "";

    int infd = open_file(TEST_NAME, O_RDWR);
    int outfd = open_file(DEV_NAME, O_WRONLY);

    while ((n = read(infd, buffer, sizeof(buffer))) > 0)
    {
        nums++;
        write(outfd, buffer, n);
    }
    printf("BUFFSIZE = %d\n", BUFFSIZE);

    return EXIT_SUCCESS;
}
