#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#define MAX_DATA			(50000000)

#define MAX_HEAD			(10000)


#define my_qsort			qsort


static void
init_array(int **ppa, int max)
{
	int i = 0;

	srand(time(NULL));

	*ppa = malloc(max * sizeof(**ppa));
	assert(*ppa);

	for (i = 0; i < max; i++)
	{
		(*ppa)[i] = rand();
	}
}


static void 
merge(int *pa, int *pb, int *dest, int nums)
{
	int i = 0;

	for (i = 0; i < nums; i++)
	{
		if (*pa > *pb)
		{
			*dest++ = *pa;
		}
		else
		{
			*dest++ = *pb;
		}
	}
}


static int 
cmp_int(const void *data1, const void *data2)
{
	return *(int *)data1 - *(int *)data2;
}


static void
show_array(int *pa, int nums)
{
	int i = 0;

	for (i = 0; i < nums; i++)
	{
		printf("%-12d", pa[i]);
	}
	printf("\n");
}


static void
find_head(int *pa, int nums, int max)
{
	my_qsort(pa, max, sizeof(int), cmp_int);

	show_array(pa, nums);
}


static void
uninit_array(int **ppa)
{
	free(*ppa);
	*ppa = NULL;
}


int
main(int argc, char *argv[])
{
	int *pa = NULL;

	init_array(&pa, MAX_DATA);
	find_head(pa, MAX_HEAD, MAX_DATA);
	uninit_array(&pa);

	return EXIT_SUCCESS;
}
