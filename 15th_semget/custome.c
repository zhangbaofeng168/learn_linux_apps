#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>    
#include <sys/stat.h>

void main()
{
	key_t key;
	int semid;
	struct sembuf sops;
	int ret;
	
	key = ftok("/work",2);
	//*创建信号量*/
	semid = semget(key,1,IPC_CREAT);
	
	//获取信号量
	sops.sem_num = 0;
	sops.sem_op  = -1;
	sops.sem_flg = SEM_UNDO;
	ret = semop(semid,&sops,1);
	printf("ret = %d\n",ret);
	//*取走产品*/
	system("cp ./product.txt ./ship/");
}