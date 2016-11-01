#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <sys/stat.h>


#define	N						(2)
#define	DB_FILENAME				"school.db"
#define	New(type, size)			(type *)getMemory(size)
#define	New_Array(type, size)	(type *)getMemory(size*sizeof(type))


#pragma pack(1)

typedef struct S_SCHOOL_t
{
	unsigned short		id;
	char *				sname;
	unsigned char		pid;
	char *				py;
	struct S_SCHOOL_t*	next;
} S_SCHOOL_t;

typedef struct S_PROVINCE_t
{
	unsigned short			id;
	char *					pname;
	struct S_PROVINCE_t	*	next;
} S_PROVINCE_t;

#pragma pack()


typedef struct MEMORY_POOL_t
{
	void *			pfirstPtr;
	void *			ptmpPtr;
	unsigned int	remainLen;		/* 用于调试，理论上总是大于0 */
} MEMORY_POOL_t;

typedef struct PROVINCE_TB_t
{
	struct S_PROVINCE_t *	pProvince;
	struct S_PROVINCE_t *	pMove;
} PROVINCE_TB_t;

typedef struct SCHOOL_TB_t
{
	struct S_SCHOOL_t *		pSchool;
	struct S_SCHOOL_t *		pMove;
} SCHOOL_TB_t;


static MEMORY_POOL_t gMemoryPool = {NULL, NULL, 0};
static SCHOOL_TB_t gSchoolMm = {NULL, NULL};
static PROVINCE_TB_t gProvinceMm = {NULL, NULL};

static void *
getMemory(size_t size)
{
	void* tmp = gMemoryPool.ptmpPtr;

	gMemoryPool.ptmpPtr += size;
	gMemoryPool.remainLen -= size;

	printf("remainlen = %d\n", gMemoryPool.remainLen);

	return tmp;
}

static void
initMemoryPool(int size)
{
	gMemoryPool.pfirstPtr = malloc(N*size);
	gMemoryPool.ptmpPtr = gMemoryPool.pfirstPtr;
	gMemoryPool.remainLen = (int)(N*size);

	printf("memory pool size = %d\n", size);
}

static void
applyMemoryPool(const char* pathname)
{
	struct stat st;

	stat(pathname, &st);

	initMemoryPool(st.st_size);
}

#define	COPY(ptr, type, str)		(ptr = New(type, strlen(str)+1), strcpy(ptr, str))

static int 
callback1(void* ptr, int num, char** column_value, char** column_name)
{
	PROVINCE_TB_t* pProvince = (PROVINCE_TB_t *)ptr;

	if (pProvince->pProvince == NULL)
	{
		pProvince->pProvince = New(S_PROVINCE_t, sizeof(*pProvince->pProvince));
		pProvince->pMove = pProvince->pProvince;
	}
	else
	{
		pProvince->pMove->next = New(S_PROVINCE_t, sizeof(*pProvince->pMove->next));
		pProvince->pMove = pProvince->pMove->next;
	}

	pProvince->pMove->id = (int)atoi(column_value[0]);
	COPY(pProvince->pMove->pname, char, column_value[1]);

	pProvince->pMove->next = NULL;

	return 0;
}

static int 
callback2(void* ptr, int num, char** column_value, char** column_name)
{
	SCHOOL_TB_t* pSchool = (SCHOOL_TB_t *)ptr;

	if (pSchool->pSchool == NULL)
	{
		pSchool->pSchool = New(S_SCHOOL_t, sizeof(*pSchool->pSchool));
		pSchool->pMove = pSchool->pSchool;
	}
	else
	{
		pSchool->pMove->next = New(S_SCHOOL_t, sizeof(*pSchool->pMove));
		pSchool->pMove = pSchool->pMove->next;
	}

	pSchool->pMove->id = (int)atoi(column_value[0]);
	COPY(pSchool->pMove->sname, char, column_value[1]);
	pSchool->pMove->pid = (int)atoi(column_value[2]);
	COPY(pSchool->pMove->py, char, column_value[3]);

	pSchool->pMove->next = NULL;

	return 0;
}

static int
readAllData(sqlite3* phandle)
{
	int ret = 0;
	char* errMsg = NULL;

	ret = sqlite3_exec(phandle, "SELECT * FROM s_province", callback1, (void *)&gSchoolMm, &errMsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "query s_province  return code = %d, errmsg: %s\n", ret, errMsg);
		sqlite3_free(errMsg);
		return ret;
	}

	ret = sqlite3_exec(phandle, "SELECT * FROM s_school", callback2, (void *)&gSchoolMm.pSchool, &errMsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "query s_school return code = %d, errMsg: %s\n", ret, errMsg);
		sqlite3_free(errMsg);
		return ret;
	}

	return 0;
}

static int
preCondition(sqlite3** pphandle)
{
	int ret = 0;
	const char* pathname = DB_FILENAME;

	ret = sqlite3_open(pathname, pphandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "open %s failure, return code = %d\n", DB_FILENAME, ret);
		return ret;
	}

	applyMemoryPool(pathname);
	readAllData(*pphandle);

	return 0;
}

static int
backupAction(sqlite3* phandle)
{
	return 0;
}

static int
postCondition(sqlite3* phande)
{

	return 0;
}

static void
show(void)
{
	S_SCHOOL_t* tmp = gSchoolMm.pSchool; 

	while (tmp != NULL)
	{
		printf("%15d%15s%15d%15s\n", tmp->id, tmp->sname, tmp->pid, tmp->py);
		tmp = tmp->next;
	}

	printf("%d\n", gMemoryPool.remainLen);
}

int
main(int argc, char* argv[])
{
	int ret = 0;
	sqlite3* phandle = NULL;

	/* 前置条件 */
	ret = preCondition(&phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "pre-condition failure, return code = %d\n", ret);
		return EXIT_FAILURE;
	}

	/* 备份动作 */
	ret = backupAction(phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "backup action failure, return code = %d\n", ret);
		return EXIT_FAILURE;
	}

	show();

	/* 后置条件 */
	ret = postCondition(phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "post condition failure, return code = %d\n", ret);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
