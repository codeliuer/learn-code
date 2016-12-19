#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define print_msg		printf("Enter multiplier: ")

static void clear_stdin_buffer(void)
{
	scanf("%*[^\n]");
	scanf("%*c");
}

static void enter_mul(unsigned int *ptr)
{
	for (print_msg; scanf("%u", ptr) != 1; print_msg)
	{
		printf("Enter invalid\n");

		clear_stdin_buffer();
	}
}

static unsigned int *get_buffer(unsigned int mul)
{
	int *array = malloc(mul * 4);
}

static void factorial(unsigned int mul)
{
	unsigned int *array = get_buffer(mul);
}

int main(int argc, char *argv[])
{
	unsigned int mul = 0;

	enter_mul(&mul);

	factorial(mul);

	return EXIT_SUCCESS;
}
