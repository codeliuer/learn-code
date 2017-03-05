#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char *argv[])
{
    int sockfd = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
