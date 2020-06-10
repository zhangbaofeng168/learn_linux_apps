#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int fd[2];
	char buf[10];
	pid_t pid;
	/*�����ܵ�*/
	pipe(fd);
	/*�����ӽ���*/
	pid = fork();
	if(pid > 0)
	{
		/*������*/
		write(fd[1],"hello",6);
		/*�ȴ��ӽ���*/
		wait();
		close(fd[1]);
		exit(0);
	}
	
	if(pid == 0)
	{
		/*�ӽ���*/
		read(fd[0],buf,6);
		printf("read data = %s\n",buf);
		close(fd[0]);
		exit(0);
	}	
	
		
}