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
	/*创建键值*/
	key = ftok("/work",0);
	/*创建共享内存*/
	shmid = shmget(key,sizeof(shared_stuff),IPC_CREAT);
	if(shmid == -1)
	{
		printf("creat shmid fail!\n");
		return 0;
	}
	/*映射共享内存*/
	shared_stuff = (struct shard_use_st *)shmat(shmid, NULL,0);
	/*使用共享内存*/
	while(running)
	{
		while(shared_stuff->write_by_you)
		{
			sleep(1);
			printf("wait read process!\n");
		}
		/*获取用户输入*/
		fgets(buf,TEXT_SIZE,stdin);
		/*将输入的字符拷贝到共享内存*/
		strncpy(shared_stuff->some_text,buf,TEXT_SIZE);
		shared_stuff->write_by_you = 1;
		
		if(!strncmp(buf,"end",3))
			running = 0;
	}
	/*脱离共享内存*/
	shmdt((const void *)shared_stuff);
	
	return 0;
}

