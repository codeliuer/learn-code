/*
** passwd file function
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pwd.h>


int
main(int argc, char* argv[])
{
    struct passwd* pw;

    pw = getpwuid(0);
    printf("name: %s\n", pw->pw_name);
    printf("passwd: %s\n", pw->pw_passwd);
    printf("uid = %d\n", pw->pw_uid);
    printf("gid = %d\n", pw->pw_gid);
    printf("infomation: %s\n", pw->pw_gecos);
    printf("home: %s\n", pw->pw_dir);
    printf("shell: %s\n", pw->pw_shell);

    pw = getpwnam("parallels");
    printf("name: %s\n", pw->pw_name);
    printf("passwd: %s\n", pw->pw_passwd);
    printf("uid = %d\n", pw->pw_uid);
    printf("gid = %d\n", pw->pw_gid);
    printf("infomation: %s\n", pw->pw_gecos);
    printf("home: %s\n", pw->pw_dir);
    printf("shell: %s\n", pw->pw_shell);

    printf("==================================================\n");
    printf("==================================================\n");
    printf("==================================================\n");

    setpwent();
    while ((pw = getpwent()) != NULL)
    {
        printf("%s,", pw->pw_name);
        printf("%s,", pw->pw_passwd);
        printf("%d,", pw->pw_uid);
        printf("%d,", pw->pw_gid);
        printf("%s,", pw->pw_gecos);
        printf("%s,", pw->pw_dir);
        printf("%s\n", pw->pw_shell);
    }
    endpwent();

    return EXIT_SUCCESS;
}
