#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

extern int errno;

static int child(void)
{
    int ret = 0;
    int sockfd = 0;
    struct sockaddr_in sockaddr;
    char buffer[BUFSIZ] = "";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(2222);
    sockaddr.sin_addr.s_addr = inet_addr("10.211.55.2");

    errno = 0;
    ret = connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (ret != 0)
    {
        fprintf(stderr, "connect failure, errno = %d\n", errno);
        return EXIT_FAILURE;
    }

    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    return 0;
}


int main(int argc, char *argv[])
{
    int i = 0;
    pid_t pid;

    for (i = 0; i < 200; i++)
    {
        if ((pid = fork()) < 0)
        {
            fprintf(stderr, "fork failure\n");
        }
        else if (pid == 0)
        {
            child();
            exit(0);
        }
    }
    
    return EXIT_SUCCESS;
}
