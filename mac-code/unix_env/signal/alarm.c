#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>
#include <pwd.h>


static char *get_username(void)
{
#if defined(__APPLE__) && defined(__MACH__)
	return "weiliu";
#elif defined(UNIX)
	return "parallels";
#else
	return NULL;
#endif
}


static void do_func(int signo)
{
	struct passwd *rootptr = NULL;

	printf("in signal handler\n");
//	if ((rootptr = getpwnam("root")) == NULL)
//	{
//		perror("getpwnam root info error");
//		exit(EXIT_FAILURE);
//	}

	alarm(1);
}


int main(int argc, char *argv[])
{
	struct passwd *ptr = NULL;

	signal(SIGALRM, do_func);
	alarm(1);

	for (;;)
	{
	//	getpwnam("weiliu");
		if ((ptr = getpwnam(get_username())) == NULL)
		{
			perror("getpwnam error");
			exit(EXIT_FAILURE);
		}
	
		if (strcmp(ptr->pw_name, get_username()) != 0)
		{
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
		}
	}

	return EXIT_SUCCESS;
}
