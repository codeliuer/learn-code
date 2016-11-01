#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef true
#define true			(1)
#endif //true

#ifndef false
#define false			(0)
#endif //false


#define INTERVAL		(10)

#define ARR_NUM(arr)	(sizeof(arr)/sizeof(arr[0]))


static int 
max_value(int n)
{
	int max = 1;

	do {
		max *= 10;
	} while ((n /= 10) != 0);

	return max;
}


static int 
is_self_cntrl_num(int n, int total)
{
	int max = max_value(n);

	if ((total-n) % max == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static int 
CalcAutomorphicNumbers(int data)
{
	int n = 0;
	int num = 0;
			    
	for (n = 0; n <= data; n++)
	{
		if (is_self_cntrl_num(n, n*n))
		{
			printf("%d %d\n", n, n*n);
			num++;
		}
	}
				    
	return num;
}


int
main(int argc, char *argv[])
{
	int data = 0;
		    
	while (scanf("%d", &data) == 1)
	{
		printf("%d\n", CalcAutomorphicNumbers(data));
	}
			    
	return EXIT_SUCCESS;
}
