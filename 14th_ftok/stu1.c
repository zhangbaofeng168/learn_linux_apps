#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void main()
{
	int fd;
	key_t key;
	int semid;
	struct sembuf sops;
	int ret;
	/*创建键值*/
	key = ftok("/work",1);
	/*创建信号量*/
	semid = semget(key,1,IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	ret = semctl(semid,0,GETVAL);
	printf("ret = %d\n",ret);
	/*打开文件*/
	fd = open("./board.txt",O_RDWR|O_APPEND);
	/*获取信号量*/
	sops.sem_num = 0;
	sops.sem_op  = -1; 
	semop(semid,&sops,1);
	/*向公告板写入“数学课”*/
	write(fd,"math",5);
	
	sleep(10);
	
	/*向公告板写入取消*/	
	write(fd,"is cancel",12);
	
	/*释放信号量*/
	sops.sem_num = 0;
	sops.sem_op  = 1;
	semop(semid,&sops,1);
	close(fd);
}