#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


extern int errno;

static void sig_hup(int signo)
{
	printf("SIGHUP received, pid = %ld\n", (long)getpid());
}


static void pr_ids(char *name)
{
	printf("%s: pid = %ld,  ppid = %ld, prgp = %ld, tpgrp = %ld\n", name, 
			(long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}


int main(int argc, char *argv[])
{
	char c;
	pid_t pid;

	pr_ids("parent");
	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		pr_ids("child");
		signal(SIGHUP, sig_hup);
		kill(getpid(), SIGTSTP);
		pr_ids("child");
		if (read(STDIN_FILENO, &c, 1) != 1)
		{
			printf("read error %d on controlling TTY\n", errno);
		}
	}
	else
	{
		sleep(5);
	}

	return EXIT_SUCCESS;
}
