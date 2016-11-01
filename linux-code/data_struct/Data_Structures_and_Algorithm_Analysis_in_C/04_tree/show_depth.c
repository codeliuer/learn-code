#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>


#define TRUE                (1)
#define FAILURE             (0)


static void show_depth(const char *filename, int depth);


static void
show_name(const char *filename, int depth)
{
    int i = 0;

    for (i = 0; i < depth; i++)
    {
        printf("    ");
    }
    printf("%s\n", filename);
}


static int 
is_dir(const char *filename)
{
    struct stat st;

    if (lstat(filename, &st) < 0)
    {
        fprintf(stderr, "%s get stat failure\n", filename);
        return FAILURE;
    }

    if (S_ISDIR(st.st_mode))
    {
        return TRUE;
    }

    return FAILURE;
}

static void
show_child(const char *filename, int depth)
{
    DIR *dir = NULL;
    struct dirent *ent = NULL;
    char path[PATH_MAX] = "";

    getcwd(path, sizeof(path));
    chdir(filename);

    dir = opendir(filename);
    while ((ent = readdir(dir)) != NULL)
    {
        show_depth(ent->d_name, depth+1);
    }

    chdir(path);
}


static void
show_depth(const char *filename, int depth)
{
    DIR *dir = NULL;
    struct dirent *ent = NULL;

    if (filename == NULL)
    {
        return;
    }

    show_name(filename, depth);
    if (is_dir(filename))
    {
        show_child(filename, depth);
    }
}


int
main(int argc, char * argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out dirname\n");
        return EXIT_FAILURE;
    }

    show_depth(argv[1], 0);

    return EXIT_SUCCESS;
}
