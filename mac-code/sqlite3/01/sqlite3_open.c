#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include <unistd.h>


#define DBFILENAME      "db"
#define OPEN_MODE       SQLITE_OPEN_READONLY|SQLITE_OPEN_CREATE

static const char sqlCreateTable[] =
{
    "CREATE TABLE Books                         \
        (                                       \
            Id_P int,                           \
            LastName varchar(255),              \
            FirstName verchar(255),             \
            Address varchar(255),               \
            City varchar(255),                  \
            expand1 blob,                       \
            expand2 blob,                       \
            PRIMARY KEY (Id_P)                  \
        )"
};

static const char sqlInsertData[] = 
{
    "INSERT INTO Persons (LastName, FirstName) (xiaofeng, lu)"
};

static int 
callback(void* arg, int num, char** pprow, char** ppcol)
{
    int i = 0;

    printf("num = %d\n", num);

    for (i = 0; i < num ; i++)
    {
        printf("%10s %10s\n", ppcol[i], pprow[i]);
    }

    return 0;
}


int
main(int argc, char* argv[])
{
    int ret = 0;
    sqlite3* handle = NULL;

    /*
    ** 分配资源，初始化必要的数据结构
    */
    sqlite3_initialize();
    sqlite3_open(DBFILENAME, &handle);

    /* 创建表 */
//    ret = sqlite3_exec(handle, sqlCreateTable, NULL, NULL, NULL);
//    printf("line = %d, ret = %d\n", __LINE__, ret);

    /* 插入数据 */
//    ret = sqlite3_exec(handle, "UPDATE Books SET expand1=100, expand2=200 WHERE Id_P=101", NULL, NULL, NULL);
//    printf("ret = %d\n", ret);
    
    /* 查询字段 */
//    sqlite3_exec(handle, "SELECT * FROM Persons", callback, NULL, NULL);

    sqlite3_close(handle);
    /*
    ** 释放sqlite_initialize()分配的资源
    */
    sqlite3_shutdown();

    exit(EXIT_SUCCESS);
}
