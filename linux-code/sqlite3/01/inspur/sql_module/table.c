/*
** test the control that database version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define INT						(0x00)
#define INTEGER					(0x01)
#define TINYINT					(0x02)
#define SMALLINT				(0x04)
#define MEDIUMINT				(0x08)
#define BIGINT					(0x10)
#define UNSIGNED_BIG_INT		(0x20)
#define INT2					(0x40)
#define INT8					(0x80)

#define REAL					(0x100)
#define DOUBLE					(0x200)
#define DOUBLE_PRECISION		(0x400)
#define FLOAT					(0x800)

#define NUMERIC					(0x10000l)
#define DECIMAL					(0x20000l)
#define BOOLEAN					(0x40000l)
#define DATE					(0x80000l)
#define DATETIME				(0x100000l)

#define decimal(m, n)			(DECIMAL | ((m) << CHAR_BIT) | (n))

#define BLOB					(0x200000l)

#define CHARACTER				(0x1000000l)
#define VARCHAR					(0x2000000l)
#define VARYING_CHARACTER		(0x4000000l)
#define NCHAR					(0x8000000l)
#define NATIVE_CHARACTER		(0x10000000l)
#define NVARCHAR				(0x20000000l)
#define TEXT					(0x40000000l)
#define CLOB					(0x80000000l)

#define character(bytes)		((CHARACTER) | (bytes))
#define varchar(bytes)			((VARCHAR | (bytes)))
#define vycharacter(bytes)		((VARYING_CHARACTER) | (bytes))
#define nchar(bytes)			(NCHAR | (bytes))
#define native_character(bytes)	((NATIVE_CHARACTER) | (bytes))
#define nvarchar(bytes)			((NVARCHAR) | (bytes))


#define CLEAR					(0)
#define	ADDFLAG					(1)
#define AUTOKEY					(2)

#define ROWID					(0)
#define WITHOUT_ROWID			(1)


typedef struct TABLE_BODY_t
{
	char			*name;
	unsigned int	type;
	char			*cnstrnt;
	char			*def;
	int				addflag;
} TABLE_BODY_t;


typedef struct TABLE_t
{
	char			*tablename;
	int				fast;
	TABLE_BODY_t	body[];
} TABLE_t;


static const char* row[] = 
		{
			"",			"WITHOUT ROWID"
		};

static struct TABLE_t program_table = 
{
	"program", ROWID,
	/* table body information */
	"indexProgram",	 INTEGER,		"NOT NULL PRIMARY KEY",	  NULL,				ADDFLAG, 
	"systemId",		 SMALLINT,		"NULL",					  NULL,				ADDFLAG,
	"tunerId",		 SMALLINT,		"NOT NULL",				  "DEFAULT 0",		ADDFLAG,
//	"tunerType",	 varchar(10),	"NOT NULL",				  "DEFAULT 'dvbc'",	ADDFLAG,
	"networkId",	 SMALLINT,		"NULL",					  NULL,				ADDFLAG,
	"tsId",			 SMALLINT,		"NOT NULL",				  "DEFAULT 0",		ADDFLAG,
	"frequency"      INT,			"NOT NULL",				  "DEFAULT 0",		ADDFLAG,
	"serviceId"      SMALLINT,		"NOT NULL",				  "DEFAULT 0",		ADDFLAG,
	"type",          TINYINT,		"NOT NULL",				  "DEFAULT 0",		ADDFLAG,
	"pmtPID",        SMALLINT		"NULL",					  "",				ADDFLAG,
	"pcrPID",        SMALLINT		"NULL",					  "",				ADDFLAG,
	"logicId",       SMALLINT		"NOT NULL"				  "DEFAULT 0",		ADDFLAG,
	"volume",        TINYINT		"NOT NULL"				  "DEFAULT 0",		ADDFLAG,
	NULL,
};


#define get_type(type)		#type

static const char *
create_program(void)
{
	char* sql = NULL;
}

char *
sql_create_table(int table)
{
	switch (table)
	{
	case PROGRAM:
		return create_program();
		break;
	case EPG:
		return NULL;
		break;
	default:
		fprintf(stderr, "parameter = %d not supported\n", table);
		return NULL;
		break;
	}
}
