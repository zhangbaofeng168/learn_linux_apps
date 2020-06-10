/**********************
文件名:  file_cp.c
创建时间:2015/10/28
创建者： baofeng
文件描述:实现简单的文件复制功能
**************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/********************
函数名：main
参数：argv[1] 源文件
      argv[2] 目标文件
功能：复制文件
*********************/
int main(int args,char* argv[])
{
	int fd1,fd2;
	int ret_num;
	char buf[512];
	/*打开源文件*/
	fd1 = open(argv[1],O_RDWR);
	if(fd1 < 0)
	{
		printf("NO source file\n");
		return 0;
	}
	/*打开目标文件*/
	fd2 = open(argv[2],O_RDWR|O_CREAT,0775);
	/*从源文件读取数据*/
	while(ret_num = read(fd1,buf,512))
	{
		/*写入数据到目标文件*/
		write(fd2,buf,ret_num);
	}
	/*关闭文件*/
	close(fd1);
	close(fd2);
	return 0;
}