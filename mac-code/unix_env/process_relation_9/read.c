#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define NUL			'\0'


int main(int rgc, char *argv[])
{
	char buffer[BUFSIZ] = "";

	printf("current read process id = %d, ppid = %d\n", getpid(), getppid());

	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		if (buffer[strlen(buffer)-1] == '\n')
		{
			buffer[strlen(buffer)-1] = NUL;
		}
		printf("%s\n", buffer);
	}
	
	sleep(2);

	return EXIT_SUCCESS;
}
