/*
** test opendir is or not follow symbolic links
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>


int
main(int argc, char* argv[])
{
    DIR* pdir = NULL;
    struct dirent* pent = NULL;

    pdir = opendir("link");
    pent = readdir(pdir);
    printf("%s\n", pent->d_name);
    pent = readdir(pdir);
    printf("%s\n", pent->d_name);

    return EXIT_SUCCESS;
}
