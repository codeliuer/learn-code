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
    int ret = 0;
    int sockfd = 0;
    int clifd = 0;
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
    if (ret == -1)
    {
        fprintf(stderr, "bind failure\n");
        return EXIT_FAILURE;
    }

    ret = listen(sockfd, POLLNUMS - 1);

    pollfd[0].fd = sockfd;
    pollfd[0].events = POLLIN;
    while (1)
    {
        ret = poll(pollfd, POLLNUMS, -1);
        if (ret < 0)
        {
            fprintf(stderr, "poll failure\n");
            return EXIT_FAILURE;
        }

        if (pollfd[0].revents == POLLIN)
        {
            clifd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
            if (clifd < 0)
            {
                fprintf(stderr, "accept failure\n");
                return EXIT_FAILURE;
            }

            for (i = 1; i < POLLNUMS; i++)
            {
                if (pollfd[i].fd == 0)
                {
                    pollfd[i].fd = clifd;
                    pollfd[i].events = POLLIN;
                    printf("connect success\n");
                    break;
                }
            }
        }

        for (i = 1; i < POLLNUMS; i++)
        {
            if (pollfd[i].revents == POLLIN)
            {
                char buffer[BUFSIZ] = "";
                read(pollfd[i].fd, buffer, sizeof(buffer));
                write(STDOUT_FILENO, buffer, strlen(buffer));
            }
        }
    }

    return EXIT_SUCCESS;
}
