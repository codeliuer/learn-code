#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    int ret = 0 ;
    int fd[2] = {0};
    struct stat st;
    struct stat inst;

    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe failure: ");
        return EXIT_FAILURE;
    }

    fstat(fd[0], &st);

    printf("%d\n", S_ISFIFO(st.st_mode));

    fstat(0, &inst);
    printf("%d\n", S_ISFIFO(inst.st_mode));
    printf("%d\n", S_ISREG(inst.st_mode));
    printf("%d\n", S_ISCHR(inst.st_mode));

    return EXIT_SUCCESS;
}
