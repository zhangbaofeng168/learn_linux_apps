/**********************
*文件名:timer.c
*创建时间:2105-10-30
*作者:baofeng
*文件描述:时间函数操作
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
	
	/*获得日历时间gettimeofday函数可以获得微妙时间*/
	//sec_num = time(NULL);  
	//printf("time = %d\n",sec_num);
	/*获得格林威治时间*/
	//tm_now = gmtime(&sec_num);
	/*获得本地时间*/
	/*tm_now = localtime(&sec_num);
	printf("%d-%d\n",tm_now->tm_hour,tm_now->tm_min);*/
	
	/*time_string = asctime(tm_now);
	printf("%s",time_string);*/
	
	/*time_string = ctime(&sec_num);
	printf("%s",time_string);*/
	
	gettimeofday(&tm_val,NULL);
	time_string = ctime(&(tm_val.tv_sec));//tm_val.tvusec 微妙
	
	printf("%s",time_string);	

	return 0;
}