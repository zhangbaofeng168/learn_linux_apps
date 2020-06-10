 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 void main()
 {
 	pid_t pid;
 	int cnt = 0;
 	//pid = fork();
 	pid = vfork();
 	cnt++;
 	printf("cnt = %d\n",cnt);
 	exit(0);

 	
 }