#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/types.h>


#define	TRUE				(1)
#define	forever_true()		while(TRUE) 
#define	print(format, ...)	fprintf(stderr, format, ##__VA_ARGS__)

extern int errno;

int
main(int argc, char* argv[])
{
	int sockfd = 0;
	int retcode = 0;
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	char buffer[BUFSIZ] = "";
	socklen_t clen = sizeof(struct sockaddr);

	errno = 0;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("%d\n", errno);

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(2222);
	saddr.sin_addr.s_addr = INADDR_ANY;

	retcode = bind(sockfd, (struct sockaddr *)&saddr, sizeof(saddr));
	printf("retcode = %d, errno = %d\n", retcode, errno);

	forever_true()
	{
		retcode = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&caddr, &clen);
		printf("retcode = %d\n", retcode);
		printf("%s\n", inet_ntoa(caddr.sin_addr));
		printf("%s", buffer);
		memset(buffer, 0, strlen(buffer));
	}

	return EXIT_SUCCESS;
}
