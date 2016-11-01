#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
	char buffer[BUFSIZ] = "";
	FILE* fp = fopen("touch", "r");

	while (fgets(buffer, sizeof(buffer), fp))
	{
		printf("%s\n", buffer);
		sleep(10);
	}

	return EXIT_SUCCESS;
}
