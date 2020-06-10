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
	/*创建键值*/
	key = ftok("/work",0);
	/*获取共享内存*/
	shmid = shmget(key,sizeof(shared_stuff),IPC_CREAT);
	/*映射共享内存*/
	shared_stuff = (struct shard_use_st *)shmat(shmid, NULL,0);
	shared_stuff->write_by_you = 0;
	/*使用共享内存*/
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
	/*脱离共享内存*/
	shmdt((const void *)shared_stuff);
	/*删除共享内存*/
	shmctl(shmid,IPC_RMID,0);
	
	return 0;
	
}