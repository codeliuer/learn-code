/*@
 * quick sort
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define self_alloc(pptr, width)					\
	do {										\
		if ((*pptr = malloc(width)) == NULL)	\
		{										\
			fprintf(stderr, "memory failure\n");\
			return;								\
		}										\
	} while (0)

#define self_free(pptr)							\
	do {										\
		free(*pptr);							\
		*pptr = NULL;							\
	} while (0)


typedef int (* SORTCB_t)(const void *, const void *);


static int
cmp_string(const void *key1, const void *key2)
{
	const char *str1 = (const char *)key1;
	const char *str2 = (const char *)key2;

	return (strcmp(str1, str2) > 0) ? 1 : 0;
}


void
sort(void *arr, int width, int start, int end, SORTCB_t cmp)
{
	int i = 0;
	int last = start;
	void *tmp = NULL;

	if (start >= end)
	{
		return;
	}

	self_alloc(&tmp, width);

#define SWAP(arr, i1, i2, tmp, width)				\
	do{												\
		memcpy(tmp, arr+i2*width, width);			\
		memcpy(arr+i2*width, arr+i1*width, width);	\
		memcpy(arr+i1*width, tmp, width);			\
	} while (0)

	SWAP(arr, start, (start+end)/2, tmp, width);
	for (i = start; i <= end; i++)
	{
		if (cmp(arr+start*width, arr+i*width))
		{
			last++;
			SWAP(arr, i, last, tmp, width);
		}
	}
	SWAP(arr, start, last, tmp, width);

	self_free(&tmp);

//	sort(arr, width, start, last-1, cmp);
//	sort(arr, width, last+1, end, cmp);
}

static void
show(char **arr, int start, int end)
{
	int i = 0;

	for (i = start; i <= end; i++)
	{
		printf("%s\n", arr[0]);
	}
}

static void 
show_int(int *arr, int start, int end)
{
	int i = 0;

	for (i = start; i <= end; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}

static int 
cmp_int(const void *key1, const void *key2)
{
	const int v1 = *(const int *)key1;
	const int v2 = *(const int *)key2;

	return v1 > v2 ? 1 : 0;
}

int
main(int argc, char * argv[])
{
	char *arr[] = 
	{
		"1234567", "azxsqw", "qwefda", "4321123", "adfasdfasd",
		"plmkoijn", "njiokplm", "asdfadf", "431312", "asdfadf",
		"gfafsff", "mnbvguhj", "rqwerfda", "hujnibghy", "asdfafdas", 
		"reqwer", "asdfasdf", "njiuhb", "aaaaaaaaa", "bbbbbbbb",
	};

	int a[] = {10, 2, 3, 4, 5,};

	sort(a, sizeof(int), 0, 4, cmp_int);
	show_int(arr, 0, 4);

	//sort((char *)arr, sizeof(char *), 0, sizeof(arr)/sizeof(arr[0]), cmp_string);
	//show(arr, 0, sizeof(arr)/sizeof(arr[0]));

	return EXIT_SUCCESS;
}
