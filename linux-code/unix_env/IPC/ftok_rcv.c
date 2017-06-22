#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MIDFILE         "midfile"

static int fetch(void)
{
    int id = 0;
    int fd = 0;
    char buffer[BUFSIZ] = "";

    fd = open(MIDFILE, O_RDONLY);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }
}

int main(int argc, char *argv[])
{
    int msgid;

    if ((msgid = fetch()) < 0)
    {
        fprintf(stderr, "fetch failure\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}