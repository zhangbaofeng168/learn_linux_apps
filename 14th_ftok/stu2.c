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
	struct sembuf sops2;
	int ret;
	/*创建键值*/
	key = ftok("/work",1);
	/*创建信号量*/
	semid = semget(key,1,IPC_CREAT);
	ret = semctl(semid,0,GETVAL);
	printf("ret = %d\n",ret);
	
	/*打开文件*/
	fd = open("./board.txt",O_RDWR|O_APPEND);
	/*获取信号量*/
	sops2.sem_num = 0;
	sops2.sem_op  = -1;
	sops2.sem_flg = SEM_UNDO;
	semop(semid,&sops2,1);
	/*向公告板写入“英语课”*/
	
	write(fd,"English test",15);
	
	
	/*释放信号量*/
	sops2.sem_num = 0;
	sops2.sem_op  = 1;
	semop(semid,&sops2,1);
	close(fd);
}