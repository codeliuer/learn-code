#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <grp.h>


int
main(int argc, char* argv[])
{
	int num = 0;
	gid_t* pt = NULL;

	num = getgroups(0, pt);
	if (num < -1)
	{
		fprintf(stderr, "failure\n");
		return EXIT_FAILURE;
	}

	printf("groups number = %d\n", num);
	pt = malloc(sizeof(*pt) * num);
	if (getgroups(num, pt) < 0)
	{
		fprintf(stderr, "failure\n");
		return EXIT_FAILURE;
	}
	while (num--)
	{
		printf("group gid = %d\n", pt[num]);
	}

	return EXIT_SUCCESS;
}
