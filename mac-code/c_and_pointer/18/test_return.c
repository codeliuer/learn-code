#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int
test(void)
{
    int a = 3;

    a + 3;

    return 
#if !defined(unix)
	(a+3)
#endif	//unix
	;
}

int
main(int argc, char* argv[])
{
    printf("%d\n", test());
#if defined(unix)
	printf("%d\n", unix);
#endif	//unix

    return EXIT_SUCCESS;
}
