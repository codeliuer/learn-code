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
    int ret = 0;
    int sockfd = 0;
    struct sockaddr_in seraddr;
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    struct pollfd pollfd[POLLNUMS] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(2222);
    seraddr.sin_addr.s_addr = inet_addr("10.211.55.10");

    ret = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    return EXIT_SUCCESS;
}
