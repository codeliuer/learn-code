#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	int values = 0;

	values = getpriority(PRIO_PGRP, 0);
	printf("values = %d\n", values);

	values = getpriority(PRIO_PROCESS, 0);
	printf("values = %d\n", values);

	values = getpriority(PRIO_USER, 0);
	printf("values = %d\n", values);

	return EXIT_SUCCESS;
}
