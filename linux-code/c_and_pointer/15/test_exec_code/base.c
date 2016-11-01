#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	N			(10)


static void
test_1printf(void)
{
	int i = 0;

	for (i = 0; i < N; i++)
	{
		printf("%d--", i);
	}
	printf("\n");
}

static void
test_2printf(void)
{
	int i = 0;

	for (i = 0; i < N; i++)
	{
		printf("%d--", i);
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	test_1printf();
	test_2printf();

	return EXIT_SUCCESS;
}
