#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	uid_t uid;
	uid_t euid;
	uid_t sid;

	getresuid(&uid, &euid, &sid);

	printf("original -- ");
	printf("uid[%d], euid[%d]\n", getuid(), geteuid());

	if (seteuid(getuid()) < 0)
	{
		printf("seteuid failure\n");
	}

	printf("setuid -- ");
	printf("uid[%d], euid[%d]\n", getuid(), geteuid());

	if (setuid(0) < 0)
	{
		printf("seteuid failure\n");
	}

	printf("set root id -- ");
	printf("uid[%d], euid[%d]\n", getuid(), geteuid());

	return EXIT_SUCCESS;
}
