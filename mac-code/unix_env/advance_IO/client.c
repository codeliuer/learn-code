#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
    int retcode = 0;
    int sockfd = 0;
    struct sockaddr_in addr = {0};
    char buffer[BUFSIZ] = "";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "socket failure\n");
        return EXIT_FAILURE;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2222);
    addr.sin_addr.s_addr = inet_addr("10.211.55.10");

    retcode = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (retcode < 0)
    {
        fprintf(stderr, "connect failure\n");
        return EXIT_FAILURE;
    }

    while (1)
    {
    }

    return EXIT_SUCCESS;
}
