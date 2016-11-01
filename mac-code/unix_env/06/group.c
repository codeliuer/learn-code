#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <grp.h>
#include <unistd.h>


int
main(int argc, char* argv[])
{
    struct group* gp = NULL;

    gp = getgrgid(1);
    if (gp != NULL)
    {
        printf("%s\n", gp->gr_name);
        printf("%s\n", gp->gr_passwd);
        printf("%d\n", gp->gr_gid);
        printf("%s\n", gp->gr_mem[0] == NULL ? "NULL" : gp->gr_mem[0]);
    }

    setgrent();
    while ((gp = getgrent()) != NULL)
    {
        printf("%s ", gp->gr_name);
        printf("%s ", gp->gr_passwd);
        printf("%d ", gp->gr_gid);
        while (*gp->gr_mem != NULL)
        {
            printf("%s  ", *gp->gr_mem);
            gp->gr_mem++;
        }
        printf("\n");
    }
    endgrent();

    printf("NGROUP_MAX = %d\n", NGROUPS_MAX);

    return EXIT_SUCCESS;
}
