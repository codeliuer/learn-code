/*
** test network
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <netdb.h>


extern int errno;

int
main(int argc, char* argv[])
{
    struct netent* pnet = NULL;

    while ((pnet = getnetent()) != NULL)
    {
        printf("name: %s\n", pnet->n_name);
    }

    return EXIT_SUCCESS;
}
