#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/select.h>


int main(int argc, char *argv[])
{
    int i = 0;
    fd_set readfds;
    char buffer[BUFSIZ] = "";

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    while (1)
    {
        if (select(1, &readfds, NULL, NULL, NULL) == -1)
        {
            fprintf(stderr, "select interrupt\n");
            return EXIT_FAILURE;
        }

        for (i = 0; i < 1; i++)
        {
            if (FD_ISSET(i, &readfds))
            {
                read(i, buffer, sizeof(buffer));
                printf("%s", buffer);
                memset(buffer, 0, strlen(buffer));
            }
        }
    }

    return EXIT_SUCCESS;
}
