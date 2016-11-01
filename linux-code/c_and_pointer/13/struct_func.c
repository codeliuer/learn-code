#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE_t
{
	int			values;
	int			(*make_values)(void);
};


static int func(void)
{
	return 100;
}

int
main(int argc, char* argv[])
{
	struct NODE_t node = {0, func};

	printf("%d\n", node.make_values());

	return EXIT_SUCCESS;
}

















