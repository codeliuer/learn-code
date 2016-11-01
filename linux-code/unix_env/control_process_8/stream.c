#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#include <dirent.h>

#include <unistd.h>


extern int errno;


int
main(int argc, char *argv[])
{
    errno = 0;

    int fd = atoi(argv[--argc]);
/*    DIR *dir = fdopendir(fd);     // close directory stream
    printf("%s\n", strerror(errno));

    struct dirent *ent = NULL;

    errno = 0;
    while ((ent = readdir(dir)) != NULL)
    {
        printf("%s\n", strerror(errno));
        printf("%s\n", ent->d_name);
    }
*/

    char buffer[BUFSIZ] = "";

    while (read(fd, buffer, sizeof(buffer)) > 0)
    {
        printf("%s", buffer);
    }

    return EXIT_SUCCESS;
}
