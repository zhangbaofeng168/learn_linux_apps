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
	/*������ֵ*/
	key = ftok("/work",1);
	/*�����ź���*/
	semid = semget(key,1,IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	ret = semctl(semid,0,GETVAL);
	printf("ret = %d\n",ret);
	/*���ļ�*/
	fd = open("./board.txt",O_RDWR|O_APPEND);
	/*��ȡ�ź���*/
	sops.sem_num = 0;
	sops.sem_op  = -1; 
	semop(semid,&sops,1);
	/*�򹫸��д�롰��ѧ�Ρ�*/
	write(fd,"math",5);
	
	sleep(10);
	
	/*�򹫸��д��ȡ��*/	
	write(fd,"is cancel",12);
	
	/*�ͷ��ź���*/
	sops.sem_num = 0;
	sops.sem_op  = 1;
	semop(semid,&sops,1);
	close(fd);
}