#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
 
#define TEXT_SIZE (2048)
struct shard_use_st
{
	int write_by_you;
	char some_text[TEXT_SIZE];
};

int main()
{
	key_t key;
	int shmid;
	int running = 1;
	struct shard_use_st *shared_stuff;
	char buf[TEXT_SIZE];
	/*������ֵ*/
	key = ftok("/work",0);
	/*���������ڴ�*/
	shmid = shmget(key,sizeof(shared_stuff),IPC_CREAT);
	if(shmid == -1)
	{
		printf("creat shmid fail!\n");
		return 0;
	}
	/*ӳ�乲���ڴ�*/
	shared_stuff = (struct shard_use_st *)shmat(shmid, NULL,0);
	/*ʹ�ù����ڴ�*/
	while(running)
	{
		while(shared_stuff->write_by_you)
		{
			sleep(1);
			printf("wait read process!\n");
		}
		/*��ȡ�û�����*/
		fgets(buf,TEXT_SIZE,stdin);
		/*��������ַ������������ڴ�*/
		strncpy(shared_stuff->some_text,buf,TEXT_SIZE);
		shared_stuff->write_by_you = 1;
		
		if(!strncmp(buf,"end",3))
			running = 0;
	}
	/*���빲���ڴ�*/
	shmdt((const void *)shared_stuff);
	
	return 0;
}

