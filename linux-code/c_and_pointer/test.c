#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SWAP(a, b)				\
		{						\
			char *t;			\
			memcpy(&t, a, 8);	\
			memcpy(a, b, 8);	\
			memcpy(b, &t, 8);	\
		}


static void
swap(void *arr, int start, int end)
{
	int i = 0;
	char *parr = arr;

	char *tmp = malloc(sizeof(char *));;

	{
		memcpy(tmp, &parr[start*sizeof(char *)], sizeof(char *));
		memcpy(&parr[start*sizeof(char *)], &parr[end*sizeof(char *)], sizeof(char *));
		memcpy(&parr[end*sizeof(char *)], tmp, sizeof(char *));
	}

	free(tmp);
	tmp = NULL;

	for (i = start; i <= end; i++)
	{
		printf("%s\n", ((char **)arr)[i]);
	}
}


int
main(int argc, char *argv[])
{
	char *str[] = 
		{
			"1234", 
			"2345",
		};

	swap(str, 0, 1);

//	printf("a = %s, b = %s\n", str[0], str[1]);

	return EXIT_SUCCESS;
}
