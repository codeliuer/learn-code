#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define DEALWITHERROR(v)                                \
    do{                                                 \
        if ((v) < 0)                                    \
        {                                               \
            printf("%s: %s[%d] %s \n", __FILE__,        \
                    __FUNCTION__, __LINE__, #v);        \
            exit(EXIT_FAILURE);                         \
        }                                               \
    } while (0)


static void 
transfile(int destfd, const char* filename)
{
    int srcfd = 0;
    char string[BUFSIZ] = "";
    
    DEALWITHERROR(srcfd = open(filename, O_RDONLY));

    while (read(srcfd, string, sizeof(string)))
    {
        send(destfd, string, strlen(string), 0);
    }
}


int
main(int argc, char* argv[])
{
    int sockfd = 0;
    struct sockaddr_in addr;

    if (argc != 3)
    {
        fprintf(stderr, "./execfile IP filename\n");
        exit(EXIT_FAILURE);
    }

    DEALWITHERROR(sockfd = socket(AF_INET, SOCK_STREAM, 0));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2222);
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    DEALWITHERROR(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)));
    transfile(sockfd, argv[2]);

    return EXIT_SUCCESS;
}
