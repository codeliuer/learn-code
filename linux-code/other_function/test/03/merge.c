#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#define MAX_DATA		(50000000)

#define MAX_HEAD		(10000)


#define	my_mergesort	mergesort


static void
init_array(int **ppa, int max)
{
	int i = 0;

	srand(time(NULL));

	for (i = 0; i < max; i++)
	{
		(*ppa)[i] = rand();
	}
}


static void
find_head(int *pa, int nums, int max)
{
	int i = 0;
	int len = 0;

	for (i = 0; i < max; i += nums)
	{
		len = (max-i) > nums ? nums : (max-i);

		my_mergesort(pa+i, , sizeof(*pa), cmp_int);
	}
}


static void
uninit_array(int *ppa)
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
