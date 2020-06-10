#include <sys/types.h>    
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void main()
{
	int fd;
	key_t key;
	int semid;
	struct sembuf sops;
	
	key = ftok("/work",2);
	/*�����ź���*/
	semid = semget(key,1,IPC_CREAT);
	semctl(semid,0,SETVAL,0);
	/*������Ʒ-�ļ�*/
	fd = open("./product.txt",O_RDWR|O_CREAT,0775);

	/*��Ϣ*/
	sleep(20);
	
	/*���ļ�д������*/	
	write(fd,"product is finished",25);
	
	close(fd);
	
	/*�ͷ��ź���*/
	sops.sem_num = 0;
	sops.sem_op  = 1;
	
	semop(semid,&sops,1);
}
