#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> a44185cd41addb9fcc26b72436c831fe28612e2a

#include <unistd.h>


int
main(int argc, char *argv[])
{
<<<<<<< HEAD
    printf("uid = %d\n", getuid());
    printf("euid = %d\n", geteuid());
    printf("setuid = %d\n", setuid(100));
    printf("euid = %d\n", geteuid());

    return EXIT_SUCCESS;
=======
	printf("uid = %d\n", getuid());
	printf("euid = %d\n", geteuid());
	printf("setuid: %d\n", setuid(0));
	printf("euid = %d\n", geteuid());

	return EXIT_SUCCESS;
>>>>>>> a44185cd41addb9fcc26b72436c831fe28612e2a
}
