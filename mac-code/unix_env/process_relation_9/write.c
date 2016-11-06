#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
	printf("current write process id = %d, ppid = %d\n", getpid(), getppid());

	sleep(1);

	return EXIT_SUCCESS;
}
