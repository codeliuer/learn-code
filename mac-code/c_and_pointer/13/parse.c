#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	NUL				'\0'


int
main(int argc, char* argv[])
{
	while ((*++argv != NULL) && (**argv == '-'))
	{
		while (*++*argv != NUL)
		{
			putchar(**argv);
		}
	}
	putchar('\n');

	return EXIT_SUCCESS;
}
