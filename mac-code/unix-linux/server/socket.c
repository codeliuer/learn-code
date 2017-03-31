#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

static int child(int sockfd)
{
    int ret = 0;
    int clifd = 0;
    char buffer[BUFSIZ] = "";
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);

    ret = accept(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    if (ret < 0)
    {
        fprintf(stderr, "accept failure\n");
        return EXIT_FAILURE;
    }

    write(sockfd, );
}

int main(int argc, char *argv[])
{
    int ret = 0;
    int sockfd = 0;
    struct sockaddr_in sockaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(2222);
    sockaddr.sin_addr.s_addr = inet_addr("10.211.55.2");

    ret = bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (ret < 0)
    {
        fprintf(stderr, "bind failure\n");
        return EXIT_FAILURE;
    }

    ret = listen(sockfd, 100);
    if (ret < 0)
    {
        fprintf(stderr, "failure");
        return EXIT_FAILURE;
    }

    child(sockfd);

    return EXIT_SUCCESS;
}
