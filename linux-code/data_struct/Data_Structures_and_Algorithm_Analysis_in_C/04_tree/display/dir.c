/*
** interface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "dir.h"


#define INVATER             (4)

#define get_abs(path, len)  getcwd(path, len)
#define set_abs(path)       chdir(path)


static void atom(const char *path, int depth);


static void
print_file(const char *path, int depth)
{
    int i = 0;

    for (i = 0; i < depth; i++)
    {
        putchar(' ');
    }
    printf("%s\n", path);
}


static void
func(const char *path, int depth)
{
    DIR *dir = NULL;
    struct dirent *ent = NULL;

    print_file(path, depth);

    dir = opendir(path);
    if (dir == NULL)
    {
        return;
    }

    while ((ent = readdir(dir)) != NULL)
    {
        if ((strcmp(ent->d_name, ".") == 0)
            || (strcmp(ent->d_name, "..") == 0))
        {
            continue;
        }

        if (ent->d_type == DT_REG)
        {
            print_file(ent->d_name, depth+INVATER);
        }
        else if (ent->d_type == DT_DIR)
        {
            chdir(path);
            func(ent->d_name, depth+INVATER);
            chdir("..");
        }
    }
    closedir(dir);
}


void
show_dir(const char *pathname)
{
    char abs[PATH_MAX+1] = "";
    char current[PATH_MAX+1] = "";

    get_abs(abs, sizeof(abs));

    set_abs(pathname);
    get_abs(current, sizeof(current));

    func(current, 0);

    set_abs(abs);
}
