/*
** test file system device number
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/stat.h>


extern int errno;


static void
file_device(const char* file)
{
    struct stat st;

    if (lstat(file, &st) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    printf("major = %d, minor = %d\n", major(st.st_dev), minor(st.st_dev));
    if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
    {
        printf(" (%s) rdev = %d/%d\n", 
                S_ISCHR(st.st_mode) ? "character" : "block",
                major(st.st_mode), minor(st.st_mode));
    }
}


int
main(int argc, char* argv[])
{
    int i = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage ./a.out filename1, ...\n");
        return EXIT_FAILURE;
    }

    for (i = 1; i < argc; i++)
    {
        file_device(argv[i]);
    }

    return EXIT_SUCCESS;
}
