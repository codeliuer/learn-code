#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <poll.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define POLLNUMS        (10)


int main(int argc, char *argv[])
{
    int sockfd = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
