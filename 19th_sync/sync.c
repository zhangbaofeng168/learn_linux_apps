#include <pthread.h>
#include <stdio.h>

pthread_t stu_id[2];
int num = 0;
pthread_mutex_t mut;
pthread_cond_t cond_ready = PTHREAD_COND_INITIALIZER;
void *stu_a()
{
	int i;
	/*扫五次地*/
	for(i=0;i<5;i++)
	{
		/*扫一次地*/
		pthread_mutex_lock(&mut);
		num++;
		if(num >= 5)
		{
			printf("student A has finish work!\n");
			pthread_cond_signal(&cond_ready);
		}
		pthread_mutex_unlock(&mut);
		/*休息*/
		sleep(1);
	}
	
	/*退出*/
	pthread_exit(NULL);
}

void *stu_b()
{
	pthread_mutex_lock(&mut);
	if(num<5)
		pthread_cond_wait(&cond_ready,&mut);
	num = 0;
	pthread_mutex_unlock(&mut);
	printf("student B has finish work!\n");
	
	/*退出*/
	pthread_exit(NULL);
}
int main()
{
	/*创建互斥锁*/
	pthread_mutex_init(&mut,NULL);
	/*创建A同学线程*/
	pthread_create(&stu_id[0], NULL,stu_a, NULL);
	/*创建B同学线程*/
	pthread_create(&stu_id[1], NULL,stu_b, NULL);
	/*等待A线程结束*/
	pthread_join(stu_id[0],NULL);
	/*等待B线程结束*/
	pthread_join(stu_id[1],NULL);
}