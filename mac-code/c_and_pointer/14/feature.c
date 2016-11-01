#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define	FEATRUE1			(0)
#define	FEATRUE2			(0)
#define	FEATRUE3			(0)


int
main(int argc, char* argv[])
{
#if FEATRUE1
	printf("featrue1\n");
#elif FEATRUE2
	printf("featrue2\n");
#elif FEATRUE3
	printf("featrue3\n");
#else
	printf("else\n");
#endif	//FEATRUE1

#if defined(FEATRUE1)
	printf("__LINE__ = %d\n", __LINE__);
#elif defined(FEATRUE2)
	printf("__LINE__ = %d\n", __LINE__);
#elif defined(FEATRUE3)
	printf("__LINE__ = %d\n", __LINE__);
#endif	//FEATRUE1

	return EXIT_SUCCESS;
}
