#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char* argv[])
{
	setbuf(stdin, NULL);

	ungetc('a', stdin);
	ungetc('b', stdin);
	ungetc('c', stdin);
	ungetc('d', stdin);
	ungetc('e', stdin);

	fseek(stdin, 0, SEEK_END);

	putchar(getchar());
	putchar(getchar());
	putchar(getchar());
	putchar(getchar());
	putchar(getchar());

	putchar('\n');

	return EXIT_SUCCESS;
}
