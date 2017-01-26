#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSTRINGSZ     (4096)


extern char **environ;


static char *get_env(const char *string)
{
    int i = 0;
    size_t len = 0;

    len =  strlen(string);
    for (i = 0; environ[i] != NULL; i++)
    {
        if (environ[i][len] == '=' && strncmp(string, environ[i], len) == 0)
        {
            return environ[i] + strlen(string)+1;
        }
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    char *string = NULL;

    printf("%s\n", (string = get_env("PATH")) ? string : "NULL");
    printf("%s\n", (string = get_env("HOME")) ? string : "NULL");
    printf("%s\n", (string = get_env("SHELL")) ? string : "NULL");

    return EXIT_SUCCESS;
}
