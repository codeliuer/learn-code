#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	SYSTEM			(16)

#define	TRAN_STRING		"0123456789abcdef"


int
main(int argc, char* argv[])
{
	int quo = 0;
	int num = 0;

	printf("enter num =");
	scanf("%d", &num);

	while (num != 0)
	{
		quo = num % SYSTEM;
		num /= SYSTEM;

		putchar(*(TRAN_STRING+quo));
	}
	putchar('\n');

	return EXIT_SUCCESS;
}
