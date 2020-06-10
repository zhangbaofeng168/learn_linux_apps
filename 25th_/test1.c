#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	pid_t pid;
	int i = 0,fd,flag;
	/*创建子进程*/
	pid = fork();
	if(pid < 0)
	{
		printf("fork errr\n");
		return -1;
	}
	if(pid > 0)
		return 0;
	/*脱离控制终端*/
	setsid();
	
	/*改变工作目录*/
	chdir("/");
	
	/*清除掩码*/
	umask(0);
	
	/*关闭打开的文件*/
	for(i = 0;i < 65535;i++)
		close(i);
	/*守护进程的工作*/
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

