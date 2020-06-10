/**********************
�ļ���:  file_cp.c
����ʱ��:2015/10/28
�����ߣ� baofeng
�ļ�����:ʵ�ּ򵥵��ļ����ƹ���
**************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/********************
��������main
������argv[1] Դ�ļ�
      argv[2] Ŀ���ļ�
���ܣ������ļ�
*********************/
int main(int args,char* argv[])
{
	int fd1,fd2;
	int ret_num;
	char buf[512];
	/*��Դ�ļ�*/
	fd1 = open(argv[1],O_RDWR);
	if(fd1 < 0)
	{
		printf("NO source file\n");
		return 0;
	}
	/*��Ŀ���ļ�*/
	fd2 = open(argv[2],O_RDWR|O_CREAT,0775);
	/*��Դ�ļ���ȡ����*/
	while(ret_num = read(fd1,buf,512))
	{
		/*д�����ݵ�Ŀ���ļ�*/
		write(fd2,buf,ret_num);
	}
	/*�ر��ļ�*/
	close(fd1);
	close(fd2);
	return 0;
}