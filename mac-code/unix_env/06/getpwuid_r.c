/*
** test getpwuid_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <pwd.h>


int
main(int argc, char* argv[])
{
	long int max = sysconf(_SC_GETPW_R_SIZE_MAX);
	char* ptr = malloc(max);
	struct passwd pw = {NULL};
	struct passwd* result = NULL;

	int retcode = getpwuid_r(atoi(argv[1]), &pw, ptr, max, &result);
	if (result == NULL)
	{
		if (retcode == 0)
		{
			printf("not found\n");
		}
		else
		{
			errno = retcode;
			printf("getpwuid_r");
		}

		exit(EXIT_FAILURE);
	}

	printf("max = %ld\n", max);
	printf("%p\n", ptr);
	printf("%p\n", pw.pw_name);
	printf("%p\n", pw.pw_passwd);
	printf("%s\n", ptr);

	return EXIT_SUCCESS;
}
