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
    FILE *fp = NULL;
    char buffer[BUFSIZ] = "";

    fp = fopen(MIDFILE, "r");
    if (fp != NULL)
    {
        perror("open failure: ");
        return EXIT_SUCCESS;
    }

    fgets()
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
