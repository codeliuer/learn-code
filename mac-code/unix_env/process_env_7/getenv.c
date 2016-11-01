/*
** environment
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DO_ENV(name)        do_env(#name)


static void 
do_env(const char* name)
{
    char *value = getenv(name);
    printf("%s = %s\n", name, value);
}


int
main(int argc, char* argv[])
{
    DO_ENV(COLUMNS);
    DO_ENV(DATEMSK);
    DO_ENV(HOME);
    DO_ENV(LANG);
    DO_ENV(LC_ALL);
    DO_ENV(LC_COLLATE);
    DO_ENV(LC_CTYPE);
    DO_ENV(LC_MESSAGES);
    DO_ENV(LC_MONETARY);
    DO_ENV(LC_NUMERIC);
    DO_ENV(LC_TIME);
    DO_ENV(LINES);
    DO_ENV(LOGNAME);
    DO_ENV(MSGVERB);
    DO_ENV(NLSPATH);
    DO_ENV(PATH);
    DO_ENV(PWD);
    DO_ENV(SHELL);
    DO_ENV(TERM);
    DO_ENV(TMPDIR);
    DO_ENV(TZ);

    return EXIT_SUCCESS;
}
