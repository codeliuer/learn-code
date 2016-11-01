#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>


static void
copyfile(int destfile, int srcfile)
{
    int n = 0;
    char buffer[BUFSIZ] = "";

    while ((n = read(srcfile, buffer, sizeof(buffer))) > 0)
    {
        write(destfile, buffer, n);
        printf("buffer: %s", buffer);
    }
}


int
main(int argc, char* argv[])
{
//    copyfile(STDOUT_FILENO, STDIN_FILENO);
    char buffer[BUFSIZ] = "1111111111111111111112222222222222222222222223333333333333";

//    int n = read(STDIN_FILENO, buffer, sizeof(buffer));
//    write(STDOUT_FILENO, buffer, strlen(buffer));

#if defined(unix)
    printf("nbytes = %ld, max: %ld\n", sizeof(SSIZE_MAX), SSIZE_MAX);
#elif defined(__APPLE__) &&  defined(__MACH__)
    printf("nbytes = %lu, max: %ld\n", sizeof(SSIZE_MAX), SSIZE_MAX);
#endif //unix

    return EXIT_SUCCESS;
}
