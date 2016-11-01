#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	OTHER

static char string[] = 
	{
		"liuwei,		\
		luxiaofeng,		\
		huangtianjiao,"
#if defined(OTHER)
		"other1,		\
		other2"
#endif	//OTHER
	};

#define	iCfgOpt_case_area		(8)
#define	forCaseOfChinaNet		(8)

static const char *pSqlCreateChannelTable = 
"CREATE TABLE channel(\
		satelliteId     INTEGER NOT NULL DEFAULT 0,\
		tunerId         INTEGER NOT NULL DEFAULT 0,\
		tunerType       VARCHAR(10) NOT NULL DEFAULT 'dvbc',\
		tsId            SMALLINT NOT NULL DEFAULT 0,\
		frequency       INT NOT NULL DEFAULT 0,\
		symbolRate      INT NOT NULL DEFAULT 0,\
		modulation      VARCHAR(10) NOT NULL DEFAULT 'qam64',\
		polarization    VARCHAR(10) NOT NULL DEFAULT '',\
		indexChannel    INTEGER NOT NULL PRIMARY KEY,\
		networkId       SMALLINT NULL DEFAULT 0,\
		oriNetworkId    SMALLINT NULL DEFAULT 0,"
#if (iCfgOpt_case_area == forCaseOfChinaNet) 
		"data1           VARCHAR(60) NULL,\
		data2           VARCHAR(60) NULL,\
		data3           VARCHAR(60) NULL,\
		data4           VARCHAR(60) NULL,\
		data5           VARCHAR(60) NULL"
#endif  //(iCfgOpt_case_area == forCaseOfChinaNet) 
		");";


int
main(int argc, char* argv[])
{
	printf("%s\n", string);
	printf("%s\n", pSqlCreateChannelTable);

	return EXIT_SUCCESS;
}
