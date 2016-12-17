#include <stdio.h>
#include <stdlib.h>


#define print_addr(format, v, ...)		printf("%s: " format, __func__, v, ##__VA_ARGS__)

int main(int argc, char *argv[])
{
	print_addr("%s", "what\n");

	return EXIT_SUCCESS;
}
