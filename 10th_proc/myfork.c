 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 void main()
 {
 	pid_t pid;
 	//pid = fork();/*�ӽ��̴�fork����֮��ʼ����*/
 	pid = vfork();
 	if(pid>0)
 	{
 		printf("parent program\n");
 		exit(0);
 	}
 	else
 	{
 		printf("child program\n");
 		exit(0);
 	}
 	
 }