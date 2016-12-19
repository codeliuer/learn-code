#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define print_msg		printf("Enter multiplier: ")

static void clear_stdin_buffer(void)
{
	scanf("%*[^\n]");
	scanf("%*c");
}

static void enter_mul(unsigned long long *ptr)
{
	for (print_msg; scanf("%llu", ptr) != 1; print_msg)
	{
		printf("Enter invalid\n");

		clear_stdin_buffer();
	}
}

int main(int argc, char *argv[])
{
	unsigned long long mul = 0;

	enter_mul(&mul);

	return EXIT_SUCCESS;
}
