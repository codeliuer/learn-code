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
    int i = 0;
    int nums = 0;
    int retcode = 0;
    int sockfd = 0;
    int clientfd = 0;
    char buffer[BUFSIZ] = "";

    struct pollfd *pollfd = NULL;
    struct sockaddr_in addrin = {0};

    socklen_t clientlen = 0;
    struct sockaddr_in clientaddr = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    addrin.sin_family = AF_INET;
    addrin.sin_port = htons(2222);
    addrin.sin_addr.s_addr = inet_addr("10.211.55.10");

    retcode = bind(sockfd, (struct sockaddr *)&addrin, (socklen_t)sizeof(addrin));
    if (retcode == -1)
    {
        fprintf(stderr, "bind failure\n");
        return EXIT_FAILURE;
    }

    listen(sockfd, 100);

    pollfd = (struct pollfd *)calloc(1, sizeof(*pollfd) * POLLNUMS);
    pollfd[0].fd = sockfd;
    pollfd[0].events = POLLIN;
    pollfd[0].revents = POLLIN;
    while (1)
    {
        nums = poll(pollfd, POLLNUMS, -1);
        if (pollfd[0].revents == POLLIN)
        {
            clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
            printf("client connect address");
            for (i = 0; i < nums; i++)
            {
                if (pollfd[i].fd == 0)
                {
                    pollfd[i].fd = clientfd;
                    pollfd[i].events = POLLIN;
                }
            }
        }
        for (i = 1; i < nums; i++)
        {
            read(pollfd[i].fd, buffer, sizeof(buffer));
            printf("%s", buffer);
            memset(buffer, 0, strlen(buffer));
        }
    }

    return EXIT_SUCCESS;
}
