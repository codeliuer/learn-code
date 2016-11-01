#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


#define DATA_MAX			(50000000)

#define MAX_HEAD			(10000)

#define my_mersort			mergesort
#define my_qsort			qsort


static int
cmp_int(const void *data1, const void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}


static void
show_data(int *pa, int nums)
{
	int i = 0;

	for (i = 0; i < nums; i++)
	{
		printf("%-12d", pa[i]);
	}
	printf("\n");
}


static void
init_data(int **ppa, int nums)
{
	int i = 0;
//
	srand(time(NULL));

	*ppa = malloc(nums * sizeof(*ppa));
	assert(*ppa);

	for (i = 0; i < nums; i++)
	{
		(*ppa)[i] = rand();
	}
}


static void
uninit_data(int **ppa)
{
	free(*ppa);
	*ppa = NULL;
}


static void 
find_data(int *pa, int heads, int max)
{
	int i = 0;
	int j = 0;

	/**
	 * 10000 data before sorting an array
	 */
	my_qsort(pa, heads, sizeof(int), cmp_int);

	for (i = heads; i < max; i++)
	{
		if (pa[i] <= pa[0])
		{
			continue;
		}

		for (j = 1; j < heads; j++)
		{
			if (pa[i] > pa[j])
			{
				pa[j-1] = pa[j];
			}
		}

		pa[j-1] = pa[i];
	}

	show_data(pa, heads);
}


int
main(int argc, char *argv[])
{
	int *pa = NULL;

	init_data(&pa, DATA_MAX);
	find_data(pa, MAX_HEAD, DATA_MAX);
	uninit_data(&pa);

	return EXIT_SUCCESS;
}
