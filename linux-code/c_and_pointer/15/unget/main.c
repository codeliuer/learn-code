#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "ungetc.h"


#define	FILENAME		"/Users/weiliu/gitline.log"


int
main(int argc, char* argv[])
{
	int ch;
	FILE* pfile = NULL;

	pfile = init(FILENAME);
	if (pfile == NULL)
	{
		perror("file open failure");
		return EXIT_FAILURE;
	}

	while ((ch = ungetc_v2(pfile)) != EOF)
	{
		putchar(ch);
	}

	uninit(pfile);

	return EXIT_SUCCESS;
}
