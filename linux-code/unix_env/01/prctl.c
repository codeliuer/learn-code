#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#if defined(unix)
#include <sys/prctl.h>
#endif  //unix


static void *
func(void* arg)
{
    char name[BUFSIZ] = "";

#if defined(unix)
    prctl(PR_SET_NAME, (unsigned long)"xxx");
    prctl(PR_GET_NAME, (unsigned long)name);
#endif //unix

    printf("%s\n", name);

	return NULL;
}


int
main(int argc, char* argv[])
{
    pthread_t pthid;

    pthread_create(&pthid, NULL, func, NULL);
    pthread_join(pthid, NULL);

    return EXIT_SUCCESS;
}
