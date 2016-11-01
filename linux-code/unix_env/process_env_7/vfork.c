#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> a44185cd41addb9fcc26b72436c831fe28612e2a

#include <unistd.h>


int
main(int argc, char *argv[])
{
<<<<<<< HEAD
    if (fork() == 0)
    {
        printf("son\n");
    }
    else
    {
        printf("parent\n");
    }   

    exit(EXIT_SUCCESS);
=======
	if (vfork() == 0)
	{
		printf("son\n");
	}
	else
	{
		printf("parent\n");
	}

	return EXIT_SUCCESS;
>>>>>>> a44185cd41addb9fcc26b72436c831fe28612e2a
}
