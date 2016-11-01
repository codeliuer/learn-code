#ifndef		__QUERY_H__
#define		__QUERY_H__


#define	MEMORYF			(0)
#define	APKEPGF			(1)


struct HEAD_t;


extern int memory_callback(
	void* arg, 
	int num, 
	char** column_values,
	char** column_names 
);
extern int epg_callback(
	void* arg, 
	int num, 
	char** column_values,
	char** column_names 
);
extern struct HEAD_t* query(
	struct HEAD_t* head,
	const char* filename, 
	int mode
);
extern void compare(struct HEAD_t * phead);


#endif	//__QUERY_H__
