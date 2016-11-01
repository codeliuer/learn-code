#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SWAP(a, b, tmp, n)						\
	{											\
		memcpy(tmp, a, n);						\
		memcpy(a, b, n);						\
		memcpy(b, tmp, n);						\
	}

static void
show_string(char **arr, int start, int end)
{
	int i = 0;

	for (i = start; i <= end; i++)
	{
		printf("%s   ", arr[i]);
	}
	printf("\n");
}

int
main(int argc, char *argv[])
{
	char *tmp = NULL;
	char *arr[] = 
	{
		"9876543", "87654321", "7654321", "654321",
	};

	void *ptr = (void *)arr;

	tmp = malloc(sizeof(char *));

	show_string(arr, 0, sizeof(arr)/sizeof(arr[0]));
	SWAP(ptr+sizeof(char *)*0, ptr+sizeof(char *)*1, tmp, sizeof(char *));
	show_string(arr, 0, sizeof(arr)/sizeof(arr[0]));

	return EXIT_SUCCESS;
}
