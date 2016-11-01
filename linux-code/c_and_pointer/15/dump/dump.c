#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	NUL				'\0'


static void
dump_string(const char* string)
{
}

static void
dump_stdin(void)
{
	char name[FILENAME_MAX] = "";

	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1] = NUL;

	dump_string(name);
}

int
main(int argc, char* argv[])
{
	if (argc == 1)
	{
		dump_stdin();
	}
	else if (argc == 2)
	{
		dump_string(argv[1]);
	}
	else
	{
		fprintf(stderr, "Usage: ./a.out <filename>\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
