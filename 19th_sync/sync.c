#include <pthread.h>
#include <stdio.h>

pthread_t stu_id[2];
int num = 0;
pthread_mutex_t mut;
pthread_cond_t cond_ready = PTHREAD_COND_INITIALIZER;
void *stu_a()
{
	int i;
	/*ɨ��ε�*/
	for(i=0;i<5;i++)
	{
		/*ɨһ�ε�*/
		pthread_mutex_lock(&mut);
		num++;
		if(num >= 5)
		{
			printf("student A has finish work!\n");
			pthread_cond_signal(&cond_ready);
		}
		pthread_mutex_unlock(&mut);
		/*��Ϣ*/
		sleep(1);
	}
	
	/*�˳�*/
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
	
	/*�˳�*/
	pthread_exit(NULL);
}
int main()
{
	/*����������*/
	pthread_mutex_init(&mut,NULL);
	/*����Aͬѧ�߳�*/
	pthread_create(&stu_id[0], NULL,stu_a, NULL);
	/*����Bͬѧ�߳�*/
	pthread_create(&stu_id[1], NULL,stu_b, NULL);
	/*�ȴ�A�߳̽���*/
	pthread_join(stu_id[0],NULL);
	/*�ȴ�B�߳̽���*/
	pthread_join(stu_id[1],NULL);
}