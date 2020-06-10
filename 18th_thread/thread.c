#include <pthread.h>
#include <stdio.h>

pthread_t thread_id[2];
int number = 0;
pthread_mutex_t mut;
void * worker1()
{
	int i=0;
	
	printf("I am worker1\n");
	
	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		printf("worker1 number is %d\n",number);
		
		sleep(1);
	}
	pthread_exit(NULL);
}

void * worker2()
{
	int i=0;
	
	printf("I am worker2\n");
	
	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		printf("worker2 number is %d\n",number);
		
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	/*����������*/
	pthread_mutex_init(&mut,NULL);
	/*�����߳�1*/
	pthread_create(&thread_id[0], NULL,worker1, NULL);
	/*�����߳�2*/
	pthread_create(&thread_id[1], NULL,worker2, NULL);
	/*�ȴ��߳�1����*/
	pthread_join(thread_id[0],NULL);
	/*�ȴ��߳�2����*/
	pthread_join(thread_id[1],NULL);
	return 0;	
}