#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pwd.h>
#include <shadow.h>


int
main(int argc, char* argv[])
{
    struct spwd* sp = NULL;
    struct passwd* pw = NULL;

    setspent();
    setpwent();

    while ((pw = getpwnam("root")) != NULL)
    {
        printf("name: %s\n", pw->pw_name);
        printf("passwd: %s\n", pw->pw_passwd);
    }

    while ((sp = getspnam("root")) != NULL)
    {
        printf("name: %s\n", sp->sp_namp);
        printf("passwd: %s\n", sp->sp_pwdp);
    }

    endpwent();
    endspent();

    return EXIT_SUCCESS;
}
