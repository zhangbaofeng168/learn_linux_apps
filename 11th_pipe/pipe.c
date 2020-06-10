#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int fd[2];
	char buf[10];
	pid_t pid;
	/*创建管道*/
	pipe(fd);
	/*创建子进程*/
	pid = fork();
	if(pid > 0)
	{
		/*父进程*/
		write(fd[1],"hello",6);
		/*等待子进程*/
		wait();
		close(fd[1]);
		exit(0);
	}
	
	if(pid == 0)
	{
		/*子进程*/
		read(fd[0],buf,6);
		printf("read data = %s\n",buf);
		close(fd[0]);
		exit(0);
	}	
	
		
}