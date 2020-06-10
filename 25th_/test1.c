#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	pid_t pid;
	int i = 0,fd,flag;
	/*�����ӽ���*/
	pid = fork();
	if(pid < 0)
	{
		printf("fork errr\n");
		return -1;
	}
	if(pid > 0)
		return 0;
	/*��������ն�*/
	setsid();
	
	/*�ı乤��Ŀ¼*/
	chdir("/");
	
	/*�������*/
	umask(0);
	
	/*�رմ򿪵��ļ�*/
	for(i = 0;i < 65535;i++)
		close(i);
	/*�ػ����̵Ĺ���*/
	flag = 1;
	while(1)
	{
		if(flag == 1 && (fd = open("/tmp/hello.log",O_CREAT|O_APPEND|O_WRONLY,0600)))
		{
			printf("open err!\n");
			flag = 0;
			return -1;
		}
		
		write(fd,"hello",6);
		close(fd);
		sleep(1);
	}
}

