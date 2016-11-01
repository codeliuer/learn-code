#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#define TEST_FILE           "log"


static void
file_attribute(const char* file)
{
    struct stat st;

    errno = 0;
    if (access(file, F_OK) < 0)
    {
        fprintf(stderr, "%s %s\n", file, strerror(errno));
        return;
    }

    errno = 0;
    if (stat(file, &st) < 0)
    {
        fprintf(stderr, "%s: %s\n", file, strerror(errno));
        return;
    }

#if defined(linux)
    printf("last access: %s", ctime(&st.st_atime));
    printf("last data modification: %s", ctime(&st.st_mtime));
    printf("last status change: %s", ctime(&st.st_ctime));
#endif  //linux
}


int
main(int argc, char* argv[])
{
    int fd = 0;

    file_attribute(TEST_FILE);
    if ((fd = open(TEST_FILE, O_SYNC|O_RDWR)) < 0)
    {
        perror(TEST_FILE);
        return EXIT_FAILURE;
    }
    write(fd, "test", strlen("test"));
    printf("---------------------------------------------------------\n");
    file_attribute(TEST_FILE);
    close(fd);
    printf("---------------------------------------------------------\n");
    file_attribute(TEST_FILE);

    return EXIT_SUCCESS;
}
