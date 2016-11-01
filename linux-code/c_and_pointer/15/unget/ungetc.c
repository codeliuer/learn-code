#include <stdlib.h>
#include <string.h>

#include "ungetc.h"


struct BufInfo_t
{
	size_t			size;
	char*			tmp;
	char			buffer[BUFSIZ];
};


PUBLIC int
ungetc_v2(FILE* pfile)
{
	static struct BufInfo_t info = {0, NULL, "",}; 

	if (info.size == 0)
	{
		info.tmp = fgets(info.buffer, BUFSIZ, pfile);
		if (info.tmp == NULL)
		{
			return EOF;
		}

		info.size = strlen(info.buffer);
	}

	info.size--;

	return *info.tmp++;
}
