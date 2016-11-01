#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOT_KEY         (0)
#define KEY             (1)

#define PROGRAM_S       "program"

#define KEY_FORMAT      "PRIMARY KEY(%s)"

#define SQL_CREATE_TABLE(table)             \
    "CREATE TABLE " table "(%s)"


struct SQL_CREATE_INFO_t
{
    char *          pname;
    char *          ptype;
    char *          pvalues;
    char *          pformat;
    unsigned char   flag;
};

struct SQL_OPRATION_t
{
    void (*pCreateFunc)();
    void (*pAddFunc)();
    struct SQL_CREATE_INFO_t pcreate_info;
};

typedef char* pchar_t;

static struct SQL_CREATE_INFO_t gCreateProgram[] = 
    {
        {"indexProgram", "INTEGER", "NOT NULL DEFAULT 0", "%d", NOT_KEY,},
        {"audioIndex", "INTEGER", "NOT NULL DEFAYLT 0", "%d", NOT_KEY},
        {"type", "TINYINT", "NULL", "%w", NOT_KEY},
        {"key", "INTEGER", "NULL", "%w", KEY},
        {"add", "INTEGER", NULL, "%w", KEY},

        {NULL},
    };


static void
get_field(char* str, struct SQL_CREATE_INFO_t* pSql)
{
    int n = 0;
    int sum = 0;
    char ptr[BUFSIZ] = "";

    while (pSql != NULL)
    {
        if (pSql->pname != NULL)
        {
            n = sprintf(str, "%s ", pSql->pname);
            str += n;
        }
        else
        {
            break;
        }

        if (pSql->ptype != NULL)
        {
            n = sprintf(str, "%s ", pSql->ptype);
            str += n;
        }
        if (pSql->pvalues != NULL)
        {
            n = sprintf(str, "%s", pSql->pvalues);
            str += n;
        }
        if (pSql->flag == KEY)
        {
            n = sprintf(ptr+sum, "%s", pSql->pname);
            sum += n;
        }

        n = sprintf(str, "%s", ",");
        str += n;
        pSql++;
    }

    if (sum != 0)
    {
        sprintf(str, KEY_FORMAT, ptr);
    }
}

static void 
create_format(char* buffer, char* psql, struct SQL_CREATE_INFO_t* pCreateSql)
{
    char str[BUFSIZ] = "";

    get_field(str, pCreateSql);
    sprintf(buffer, psql, str);
}

int
main(int argc, char* argv[])
{
    pchar_t name = NULL;
    char buffer[BUFSIZ] = "";

    create_format(buffer, SQL_CREATE_TABLE(PROGRAM_S), gCreateProgram);
    printf("%s\n", buffer);

    return EXIT_SUCCESS;
}
