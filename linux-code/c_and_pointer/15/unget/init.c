#include <stdio.h>
#include <assert.h>

#include "init.h"


PUBLIC FILE *
init(char* filename)
{
	FILE* pfile = fopen(filename, "r");
	assert(pfile != NULL);

	return pfile;
}


PUBLIC void
uninit(FILE* pfile)
{
	if (fclose(pfile) == EOF)
	{
		perror("close file");
	}
}
