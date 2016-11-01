#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	int num = 0;
	char buffer[BUFSIZ] = "";

	setbuf(stdin, buffer);

	scanf("%d", &num);
	printf("num = %d\n", num);
	printf("%s", buffer);

	return EXIT_SUCCESS;
}
