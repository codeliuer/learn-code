#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("signo = %d\n", signo);
}


int main(int argc, char *argv[])
{
	char buffer[BUFSIZ] = "";

	signal(SIGINT, do_func);

	printf("%ld\n", read(STDIN_FILENO, buffer, sizeof(buffer)));
	printf("%s\n", buffer);

	return EXIT_SUCCESS;
}
