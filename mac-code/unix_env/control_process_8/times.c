#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>

#include <unistd.h>


static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(const char *);


int
main(int argc, char *argv[])
{
	int i = 0;

	setbuf(stdout, NULL);

	for (i = 1; i < argc; i++)
	{
		do_cmd(argv[i]);
	}

	return EXIT_SUCCESS;
}


static void 
do_cmd(const char *cmd)
{
	struct tms starttms = {0};
	struct tms endtms = {0};
	clock_t start = 0;
	clock_t end = 0;

	printf("cmd : %s\n", cmd);
	if ((start = times(&starttms)) < 0)
	{
		fprintf(stderr, "times start failure\n");
		exit(EXIT_FAILURE);
	}

	if (system(cmd) < 0)
	{
		fprintf(stderr, "system failure\n");
		exit(EXIT_FAILURE);
	}

	if ((end = times(&endtms)) < 0)
	{
		fprintf(stderr, "times end failure\n");
		exit(EXIT_FAILURE);
	}

	pr_times(end-start, &starttms, &endtms);
}


static void 
pr_times(clock_t real, struct tms *starttms, struct tms *endtms)
{
	static long clktck = 0;

	if (clktck == 0)
	{
		if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
		{
			fprintf(stderr, "sysconf error\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("  real: %7.2f\n", real/(double)clktck);
	printf("  user: %7.2f\n", (endtms->tms_utime - starttms->tms_utime)/(double)clktck);
	printf("  sys : %7.2f\n", (endtms->tms_stime - starttms->tms_stime)/(double)clktck);
	printf("child user: %7.2f\n", (endtms->tms_cutime - starttms->tms_cutime)/(double)clktck);
	printf("child sys : %7.2f\n", (endtms->tms_cstime - starttms->tms_cstime)/(double)clktck);
}
