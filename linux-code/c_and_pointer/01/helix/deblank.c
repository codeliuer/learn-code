#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define NUL			'\0'

#define OUT			0
#define IN			1


static void
deblank(char *string)
{
	int flag = OUT;
	char *tmp = string;

	while (*tmp != NUL)
	{
		if (flag == OUT && isspace(*tmp))
		{
			flag = IN;
			*string++ = *tmp;
		}
		else if (flag == IN && !isspace(*tmp))
		{
			*string++ = *tmp;
			flag = OUT;
		}
	}

	*string = NUL;
}


int
main(int argc, char *argv[])
{
	int len = 0;
	char string[BUFSIZ] = "";

	while (fgets(string, sizeof(string), stdin) != NULL)
	{
		len = strlen(string);
		if (string[len-1] == '\n')
		{
			string[len-1] = NUL;
		}

		deblank(string);

		printf("%s\n", string);
	}

	return EXIT_SUCCESS;
}
