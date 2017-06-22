#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>


static int fetch(void)
{
    int fd = 0;
    int id = 0;

    fd = open();
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
