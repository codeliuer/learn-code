#include <stdio.h>
#include <stdlib.h>


#define print(a)		printf("%s", #a)
#define print2(a)		print(a)
#define newline			putchar('\n')

#define b				2

int main(int argc, char *argv[])
{
	print2(b);
	newline;

	return EXIT_SUCCESS;
}
