/**********************
*�ļ���:timer.c
*����ʱ��:2105-10-30
*����:baofeng
*�ļ�����:ʱ�亯������
**************************/
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main(int args,char **argv)
{
	time_t sec_num;
	//struct tm *tm_now;
	char *time_string;
	struct timeval tm_val;
	
	/*�������ʱ��gettimeofday�������Ի��΢��ʱ��*/
	//sec_num = time(NULL);  
	//printf("time = %d\n",sec_num);
	/*��ø�������ʱ��*/
	//tm_now = gmtime(&sec_num);
	/*��ñ���ʱ��*/
	/*tm_now = localtime(&sec_num);
	printf("%d-%d\n",tm_now->tm_hour,tm_now->tm_min);*/
	
	/*time_string = asctime(tm_now);
	printf("%s",time_string);*/
	
	/*time_string = ctime(&sec_num);
	printf("%s",time_string);*/
	
	gettimeofday(&tm_val,NULL);
	time_string = ctime(&(tm_val.tv_sec));//tm_val.tvusec ΢��
	
	printf("%s",time_string);	

	return 0;
}