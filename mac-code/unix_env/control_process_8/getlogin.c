#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <uuid/uuid.h>


int 
main(int argc, char *argv[])
{
	char *name = getlogin();
	struct passwd *pwd = NULL;

	printf("%s\n", name);
	
	pwd = getpwnam(name);
	printf("login shell: %s\n", pwd->pw_shell);

	return EXIT_SUCCESS;
}
