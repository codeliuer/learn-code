#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sqlite3.h>

#include "query.h"


#define	PUBLIC	//

#define	BIG				(1)
#define	SMALL			(-1)

#define	STRCMP(s1, R,s2)			(strcmp(s1, s2) R 0)
#define	STRECMP(e, s1, R, s2)		((e = strcmp(s1, s2)) R 0)


struct QIN_EPG_t
{
	int					eventId;
	int					duration;
	char *				eventName;
	char *				contentLocal;
	int					serviceId;
	int					tsId;
	struct QIN_EPG_t *	next;
};

struct APK_EPG_t
{
	int					eventId;
	int					duration;
	char *				name;
	char *				description;
	int					serviceIndex;
	struct APK_EPG_t *	next;
};

struct HEAD_t
{
	struct QIN_EPG_t *	pQinHead;
	struct APK_EPG_t *	pApkHead;
};


typedef int (*FPNotify)(void*, int, char**, char**);


static int 
elecmp(struct QIN_EPG_t* pQinNode, struct APK_EPG_t* pApkNode)
{
	int retcmp = 0;

	//printf("%d, %d, %s, %s\n", pQinNode->eventId, pQinNode->duration, pQinNode->eventName, pQinNode->contentLocal);
	//printf("%d, %d, %s, %s\n", pApkNode->eventId, pApkNode->duration, pApkNode->name, pApkNode->description);
	if (pQinNode->eventId != pApkNode->eventId)
	{
		return (pQinNode->eventId > pApkNode->eventId) ? BIG : SMALL;
	}

	if (pQinNode->duration != pApkNode->duration)
	{
		retcmp = (pQinNode->duration > pApkNode->eventId) ? BIG : SMALL;
		printf("retcmp = %d, pQinNode->duration = %d, pApkNode->duration = %d\n", retcmp, pQinNode->duration, pApkNode->duration);
		return retcmp;
	}

	if (STRECMP(retcmp, pQinNode->eventName, !=, pApkNode->name))
	{
		return retcmp > 0 ? BIG : SMALL;
	}

	if (STRECMP(retcmp, pQinNode->contentLocal, !=, pApkNode->description))
	{
		return retcmp > 0 ? BIG : SMALL;
	}

	return 0;
}

static int 
cmp_qin(struct QIN_EPG_t* pNode1, struct QIN_EPG_t* pNode2)
{
	int retcmp = 0;

	if (pNode1->eventId != pNode2->eventId)
	{
		return (pNode1->eventId > pNode2->eventId) ? BIG : SMALL;
	}
	
	if (pNode1->serviceId != pNode2->serviceId)
	{
		return (pNode1->serviceId > pNode2->serviceId) ? BIG : SMALL;
	}

	if (pNode1->tsId != pNode2->tsId)
	{
		return (pNode1->tsId > pNode2->tsId) ? BIG : SMALL;
	}

	return 0;
}

static int
cmp_apk(struct APK_EPG_t* pNode1, struct APK_EPG_t* pNode2)
{
	int retcmp = 0;

	if (pNode1->eventId != pNode2->eventId)
	{
		return (pNode1->eventId > pNode2->eventId) ? BIG : SMALL;
	}

	if (pNode1->serviceIndex != pNode2->serviceIndex)
	{
		return (pNode1->serviceIndex > pNode2->serviceIndex) ? BIG : SMALL;
	}

	if (pNode1->duration != pNode2->duration)
	{
		return (pNode1->duration > pNode2->duration) ? BIG : SMALL;
	}

	if (STRECMP(retcmp, pNode1->name, !=, pNode2->name))
	{
		return retcmp > 0 ? BIG : SMALL;
	}

	if (STRECMP(retcmp, pNode1->description, !=, pNode2->name))
	{
		return retcmp > 0 ? BIG : SMALL;
	}

	return 0;
}

static void
print_q(FILE* pfile, struct QIN_EPG_t* pNode)
{
	fprintf(pfile, "eventId = %4d, duration = %4d, eventName: %s, contentLocal: %s, serviceId = %4d\n", 
			pNode->eventId, pNode->duration, pNode->eventName, pNode->contentLocal, pNode->serviceId);
}

static void
print_a(FILE* pfile, struct APK_EPG_t* pNode)
{
	fprintf(pfile, "eventId = %4d, duration = %4d, name     : %s, description : %s, serviceIndex = %4d\n", 
			pNode->eventId, pNode->duration, pNode->name, pNode->description, pNode->serviceIndex);
}

static void
insert_qin(struct QIN_EPG_t** pphandle, struct QIN_EPG_t* node)
{
	int ret = 0;

	while ((*pphandle != NULL))
	{
		ret = elecmp(*pphandle, (struct APK_EPG_t *)node);
		if (ret == 0)
		{
			print_q(stdout, node);
			return;
		}
		else if (ret > 0)
		{
			node->next = *pphandle;
			*pphandle = node;
			return;
		}
		else
		{
			pphandle = &(*pphandle)->next;
		}
	}

	*pphandle = node;
}

static void
insert_apk(struct APK_EPG_t** pphandle, struct APK_EPG_t* node)
{
	int ret = 0;

	while ((*pphandle != NULL))
	{
		ret = elecmp((struct QIN_EPG_t *)*pphandle, node);
		if (ret == 0)
		{
			print_a(stdout, node);
			return;
		}
		else if (ret > 0)
		{
			node->next = *pphandle;
			*pphandle = node;
			return;
		}
		else
		{
			pphandle = &(*pphandle)->next;
		}
	}

	*pphandle = node;
}

PUBLIC int 
qin_callback(
	void* arg,
	int num,
	char** column_values,
	char** column_names
)
{
	int i = 0;
	struct QIN_EPG_t* node = NULL;
	struct HEAD_t* head = (struct HEAD_t *)arg;

	node = calloc(1, sizeof(*node));
	if (node == NULL)
	{
		fprintf(stderr, "memory failure\n");
		return 0;
	}
	
	for (i = 0; i < num; i++)
	{
		if (STRCMP(column_names[i], ==, "eventId"))
		{
			node->eventId = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "serviceId"))
		{
			node->serviceId = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "duration"))
		{
			node->duration = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "tsId"))
		{
			node->tsId = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "eventName"))
		{
			node->eventName = strdup(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "contentLocal"))
		{
			node->contentLocal = strdup(column_values[i]);
		}
	}

	insert_qin(&head->pQinHead, node);

	return 0;
}

PUBLIC int 
apk_callback(
	void* arg, 
	int num,
	char** column_values,
	char** column_names
)
{
	int i = 0;
	struct APK_EPG_t* node = NULL;
	struct HEAD_t* head = (struct HEAD_t *)arg;

	node = calloc(1, sizeof(*node));
	if (node == NULL)
	{
		fprintf(stderr, "memory failure\n");
		return 0;
	}

	for (i = 0; i < num; i++)
	{
		if (STRCMP(column_names[i], ==, "eventId"))
		{
			node->eventId = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "serviceIndex"))
		{
			node->serviceIndex = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "duration"))
		{
			node->duration = atoi(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "name"))
		{
			node->name = strdup(column_values[i]);
		}
		else if (STRCMP(column_names[i], ==, "description"))
		{
			node->description = strdup(column_values[i]);
		}
	}

	insert_apk(&head->pApkHead, node);

	return 0;
}


PUBLIC struct HEAD_t * 
query(struct HEAD_t* phead , const char* filename, int mode)
{
	int retcode = 0;
	char* perrmsg = NULL;
	sqlite3* phandle = NULL;
	FPNotify callback[] = 
			{
				qin_callback,	apk_callback,
			};

	if (phead == NULL)
	{
		phead = calloc(1, sizeof(*phead));
	}

	retcode = sqlite3_open(filename, &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", sqlite3_errmsg(phandle));
		return NULL;
	}

	retcode = sqlite3_exec(phandle, "SELECT * FROM epg", callback[mode], phead, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		sqlite3_free(perrmsg);
		return NULL;
	}

	sqlite3_close(phandle);

	return phead;
}

PUBLIC void
compare(struct HEAD_t* phead)
{
/*	while (phead->pQinHead != NULL && phead->pApkHead != NULL)
	{
		print_q(stdout, phead->pQinHead);
		print_a(stdout, phead->pApkHead);

		phead->pQinHead = phead->pQinHead->next;
		phead->pApkHead = phead->pApkHead->next;
	}*/
	int ret = 0;
	struct HEAD_t tmp = {NULL, NULL};

	if (phead == NULL)
	{
		return;
	}

#define	qintmp		tmp.pQinHead
#define	apktmp		tmp.pApkHead
	
	qintmp = phead->pQinHead;
	apktmp = phead->pApkHead;
	while ((qintmp != NULL) && (apktmp != NULL))
	{
#define	NONE				"\e[0m"
#define	RED					"\e[0;31m"
#define	GREEN				"\e[0;32m"
#define	CLEAR				"\e[2J"
		ret = elecmp(qintmp, apktmp);
		if (ret > 0)
		{
			print_q(stderr, qintmp);
			print_a(stderr, apktmp);
			printf("ret = %d\n", ret);

			print_a(stdout, apktmp);
			apktmp = apktmp->next;
			printf(RED "不相等" NONE "\n");
		}
		else if (ret < 0)
		{
			print_q(stderr, qintmp);
			print_a(stderr, apktmp);
			printf("ret = %d\n", ret);

			print_q(stdout, qintmp);
			qintmp = qintmp->next;
			printf(RED "不相等" NONE "\n");
		}
		else
		{

		//	printf(GREEN "相等" NONE "\n");
			apktmp = apktmp->next;
			qintmp = qintmp->next;
		}
	}

	if (qintmp != NULL)
	{
		printf("#####################qin##########################\n");
		do {
			print_q(stdout, qintmp);
			qintmp = qintmp->next;
		} while (qintmp != NULL);
	}
	else if (apktmp != NULL)
	{
		printf("#####################apk##########################\n");
		do {
			print_a(stdout, apktmp);
			apktmp = apktmp->next;
		} while (apktmp != NULL);
	}
#undef qintmp
#undef apktmp	
}
