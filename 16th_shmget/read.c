#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>

struct shard_use_st
{
	int write_by_you;
	char some_text[2048];
};

int main()
{
	key_t key;
	int shmid;
	int running = 1;
	struct shard_use_st *shared_stuff;
	/*������ֵ*/
	key = ftok("/work",0);
	/*��ȡ�����ڴ�*/
	shmid = shmget(key,sizeof(shared_stuff),IPC_CREAT);
	/*ӳ�乲���ڴ�*/
	shared_stuff = (struct shard_use_st *)shmat(shmid, NULL,0);
	shared_stuff->write_by_you = 0;
	/*ʹ�ù����ڴ�*/
	while(running)
	{
		if(shared_stuff->write_by_you)
		{
			printf("write process write:%s\n",shared_stuff->some_text);
			shared_stuff->write_by_you = 0;
			
			if(!strncmp(shared_stuff->some_text,"end",3))
				running = 0;
		}
	}
	/*���빲���ڴ�*/
	shmdt((const void *)shared_stuff);
	/*ɾ�������ڴ�*/
	shmctl(shmid,IPC_RMID,0);
	
	return 0;
	
}