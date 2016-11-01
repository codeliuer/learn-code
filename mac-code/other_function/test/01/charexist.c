#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



#define NUL			'\0'


bool 
isAllCharExist(char *pShortString, char *pLongString)
{
	int i = 0;
	int j = 0;
	int slen = strlen(pShortString);
	int llen = strlen(pLongString);
					    
	if (slen > llen)
	{
		return false;
	}

	for (i = slen-1; i < llen; i++)
	{
		if (pLongString[i] == pShortString[slen-1])
		{
			for (j = 0; j < slen; j++)
			{
				if (pLongString[i-slen+1+j] != pShortString[j])
				{
					break;
				}
			}

			if (j == slen)
			{
				return true;
			}
		}
	}

	return false;
}


int
main(int argc, char *argv[])
{
	int slen = 0;
	int llen = 0;
	char sstr[BUFSIZ] = "";
	char lstr[BUFSIZ] = "";
					    
	while (fgets(sstr, sizeof(sstr), stdin) != NULL
			&& fgets(lstr, sizeof(lstr), stdin) != NULL)
	{
		slen = strlen(sstr);
		llen = strlen(lstr);

		if (sstr[slen-1] == '\n')
		{
			sstr[slen-1] = NUL;
		}
		if (lstr[llen-1] == '\n')
		{
			lstr[llen-1] = NUL;
		}

		printf("%s\n", isAllCharExist(sstr, lstr) ? "true" : "false");
	}

	return EXIT_SUCCESS;
}
