#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include <unistd.h>


#define DEFAULT_VALUES	(0)

#define INTERVAL		(10)


static int count = 0;
static struct timespec start;


static void
checktime(const char *s)
{
	struct timespec spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);

	if (spec.tv_sec >= start.tv_sec && spec.tv_nsec >= start.tv_sec)
	{
		printf("%s count over = %d\n", s, count);
		exit(EXIT_SUCCESS);
	}
}


static int
get_priority(int argc, char *argv[])
{
	if (argc >= 2)
	{
		return atoi(argv[1]);
	}

	return DEFAULT_VALUES;
}

int
main(int argc, char *argv[])
{
	char *s = NULL;
	pid_t pid;
	int priority = get_priority(argc, argv);

	clock_gettime(CLOCK_MONOTONIC, &start);
	start.tv_sec += INTERVAL;
	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		s = "child";
		if (nice(priority) == -1 && errno != 0)
		{
			printf("failure\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		s = "parent";
	}

	for (;;)
	{
		count++;
		checktime(s);
	}

	return EXIT_SUCCESS;
}
