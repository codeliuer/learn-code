#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


#define TEST_FILE		"eof.c"


static void
test(void)
{
	FILE *pf = fopen(TEST_FILE, "r+");
	if (pf == NULL)
	{
		fprintf(stderr, "open failure %s failure\n", TEST_FILE);
		return;
	}

	fseek(pf, 0, SEEK_END);
	
	if (getc(pf) == EOF)
	{
		printf("I love EOF\n");
		printf("%ld\n", ftell(pf));
	}

	fseek(pf, 100, SEEK_END);

	fwrite("\n", 1, 1, pf);

	fseek(pf, 20, SEEK_END);

	if (getc(pf) == EOF)
	{
		printf("I love EOF\n");
		printf("%ld\n", ftell(pf));
	}

	struct stat st;

	stat(TEST_FILE, &st);

	printf("%ld\n", st.st_size);
}


int
main(int argc, char *argv[])
{
	test();

	return EXIT_SUCCESS;
}
