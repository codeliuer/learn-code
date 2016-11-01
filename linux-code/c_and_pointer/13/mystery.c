#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	STRING				"123456789A"

static void
mystery(int num)
{
	num += 5;
	num /= 10;
	printf("%s\n", STRING+10-num);
}

int
main(int argc, char* argv[])
{
	int i = 0;

	for (i = 0; i < 100; i++)
	{
		mystery(i);
	}

	return EXIT_SUCCESS;
}
