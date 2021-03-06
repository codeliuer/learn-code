/* 
 *      * linux setuid example 
 */

#include  <stdio.h>
#include  <stdlib.h>

#include  <unistd.h>
#include <fcntl.h>


void test_read_file(const char *name)  
{  
	int fd = -1;  
	
	fd = open(name, O_RDWR);  
	if(fd < 0)  
	{  
		printf("=[ERROR]:read failed.\n");  
	}  
	else  
	{  
		printf("=[OK]: read fuccessful\n");  
		close(fd);  
	}  

}  

//打印uid和euid.  
void p_states(void)  
{  
	int uid = 0;  
	int euid = 0;  
	
	printf("-----Current states--------------------------\n");  
	printf("real uid\t %d\n",getuid());  
	printf("effective uid\t %d\n",geteuid());  
	printf("---------------------------------------------\n");  
}  

//调用setuid  
void run_setuid_fun(int uid)  
{  
	if(setuid(uid) == -1)  
	{  
		printf("=[ERROR]:setuid(%d) error\n", uid);  
	}  
	p_states();  
}  
                                                                                    ///调用seteuid  
void run_seteuid_fun(int uid)  
{  
	if(seteuid(uid)== -1)  
	{  
		printf("=[ERROR]:seteuid(%d) error\n", uid);  
	}  
	p_states();  
}  


int 
main()       
{
	int t_re = 0;  

	const char *file = "root_only.txt";  
    
	printf("\nTEST 1:\n");  
    
	p_states();  
	//此时real uid = login user id  
	//effective uid = root  
	//saved uid = root  
	
	test_read_file(file);  
      
	printf("\nTEST 2:seteuid(getuid())\n");  
    
	run_seteuid_fun(getuid());  
    
	//[2]此时 real uid= login user id  
	//     effective uid = login user id  
	//     saved uid = root  
    
	test_read_file(file);  
    
	printf("\nTEST 3:seteuid(0)\n");  
    
	run_seteuid_fun(0);  
    
	//read uid = lonin user id  
	//effective uid = root  
	//saved uid = root  
    
	test_read_file(file);  
    
	printf("\nTEST 4:setuid(0)\n");  
    
	run_setuid_fun(0);  
    
	//real uid = root  
	//effective uid = root  
	//saved uid= root  
    
	test_read_file(file);  
    

    
	printf("\nTEST 5 setuid(503)\n");  
    
	run_setuid_fun(503);  
    
	//real uid = login user id  
	//effective id = login user id  
	//saved uid = login user id  
    
	test_read_file(file);  
    
	printf("\nTEST 6:seruid(0)\n");  
    
	//read uid = login user id  
	//effective uid = login user id  
	//saved uid = login user id  
    
	run_setuid_fun(0);  
	test_read_file(file);  
    
	return 0;  					
}  
