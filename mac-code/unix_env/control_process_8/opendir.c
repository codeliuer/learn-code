#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <dirent.h>

#include <unistd.h>
#include <fcntl.h>


static void
common(DIR *dir)
{
    struct dirent *ent = NULL;

    while ((ent = readdir(dir)) != NULL)
    {
        printf("%s\n", ent->d_name);
    }
}

static void
mul_process(DIR *dir)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return;
    }
    else if (pid == 0)
    {
        int fd = open("opendir.c", O_RDONLY) /* dirfd(dir) */;
        char str[10] = "";

        snprintf(str, 10, "%d", fd);

        execl("./stream", "stream", str, (char *)0);
        exit(EXIT_SUCCESS);
    }
    else
    {
        sleep(1);
    }
}

int
main(int argc, char *argv[])
{
    DIR *dir = opendir("/");
    if (dir == NULL)
    {
        fprintf(stderr, "open directory failure\n");
        return EXIT_FAILURE;
    }

    mul_process(dir);

    closedir(dir);

    return EXIT_SUCCESS;
}
