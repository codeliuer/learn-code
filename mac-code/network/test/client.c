#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char *argv[])
{
    int ret = 0;
    int sockfd = 0;
    struct sockaddr_in cliaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(2222);
    cliaddr.sin_addr.s_addr = inet_addr("10.211.55.2");

    ret = connect(sockfd, );

    return EXIT_SUCCESS;
}
