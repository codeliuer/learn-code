#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define ARRAY_NUM(arr)				(sizeof(arr)/sizeof(arr[0]))

/* swap element1 and element2 */
#define SWAP(a, b, tmp, n)						\
	{											\
		memcpy(tmp, a, n);						\
		memcpy(a, b, n);						\
		memcpy(b, tmp, n);						\
	}


#define self_alloc(pp, n, type)					\
	do {										\
		*pp = malloc((n) * sizeof(type));		\
		if (*pp == NULL)						\
		{										\
			fprintf(stderr, "memory failure\n");\
			return;								\
		}										\
	} while (0)

#define self_free(pp)							\
	do {										\
		free(*pp);								\
		*pp = NULL;								\
	} while (0)


/* sort callback */
typedef int (* SORTCB_t)(const void *, const void *);


static void show_int(int *arr, int start, int end);
static void show_string(char **arr, int start, int end);


/*@
 * summary: quick sort 
 * para: arr:	the first address of array
 *		 len:	the length of element
 *		 start:	start index
 *		 end:	end index
 *		 cmp:	callback
 **/
void sort(void *arr, size_t len, int start, int end, SORTCB_t cmp)
{
	int i = 0;
	void *tmp = NULL;
	int last = start;

	if (start >= end)
	{
		return;
	}

	self_alloc(&tmp, len, char);

	/* set flag */
	SWAP(arr+start*len, arr+len*((start+end)/2), tmp, len);
	for (i = start+1; i <= end; i++)
	{
		if (cmp(arr+start*len, arr+i*len))
		{
			last++;
			SWAP(arr+last*len, arr+i*len, tmp ,len);
		}
	}
	SWAP(arr+start*len, arr+last*len, tmp, len);
	
	self_free(&tmp);

	sort(arr, len, start, last-1, cmp);
	sort(arr, len, last+1, end, cmp);
}


/*@ 
 * summary: int compare parameter1 and parameter2 
 * parameter1 > parameter2  return 0
 * parameter1 <= parameter2 return 1
 * error: no
 */
static int 
cmpint(const void *key1, const void *key2)
{
	const int i1 = *(const int *)key1;
	const int i2 = *(const int *)key2;

	return i1 > i2 ? 1 : 0;
}

/*@ 
 * summary: string compare parameter1 and parameter2 
 * parameter1 > parameter2  return 0
 * parameter1 <= parameter2 return 1
 * error: no
 */
static int 
cmpstring(const void *key1, const void *key2)
{
	const char *i1 = *(const char **)key1;
	const char *i2 = *(const char **)key2;

	return (strcmp(i1, i2) > 0) ? 1 : 0;
}

static void
show_int(int *arr, int start, int end)
{
	int i = start;

	printf("display int: ");
	for (i = start; i <= end; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

static void
show_string(char *str[], int start, int end)
{
	int i = 0;

	printf("display string: ");
	for (i = start; i <= end; i++)
	{
		printf("%s  ", str[i]);
	}
	printf("\n");
}


#define sort_int(arr, start, end)			sort(arr, sizeof(int), start, end, cmpint)
#define sort_string(arr, start, end)		sort(arr, sizeof(char *), start, end, cmpstring)
#define show_int(arr, start, end)			show_int(arr, start, end)
#define show_string(arr, start, end)		show_string(arr, start, end)


static void
clear_buffer(void)
{
	scanf("%*[^\n]");
	scanf("%*c");
}

static void 
get_number(int *pn)
{
	printf("The number of array elements = ");
	scanf("%d", pn);
	/* clear stdin buffer */
	clear_buffer();
}

static void
test_int(void)
{
	int i = 0;
	int n = 0;
	int *ptr = NULL;

	get_number(&n);
	self_alloc(&ptr, n, int);

	printf("enter: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ptr[i]);
	}

	sort_int(ptr, 0, n-1);
	show_int(ptr, 0, n-1);

	self_free(&ptr);
}

static void
test_string(void)
{
	int i = 0;
	int n = 0;
	char **pptr = NULL;
	const int length = 100;

	get_number(&n);
	self_alloc(&pptr, n, char *);
	self_alloc(&pptr[0], length*n, char);

	printf("enter:");
	for (i = 0; i < n; i++)
	{
		pptr[i] = pptr[0]+length*i;
		scanf("%s", pptr[i]);
	}

	sort_string((void *)pptr, 0, n-1);
	show_string((void *)pptr, 0, n-1);

	self_free(&pptr[0]);
	self_free(&pptr);
}


int
main(int argc, char* argv[])
{
	test_int();
	test_string();
/*
	char *str[] = 
	{
		"423", "234", "432", "fasdf", "ASDF", "adfas",
	};

	sort_string((void *)str, 0, ARRAY_NUM(str)-1);
	show_string(str, 0, ARRAY_NUM(str)-1);
*/
	return EXIT_SUCCESS;
}
