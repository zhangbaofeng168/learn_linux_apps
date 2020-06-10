#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
	int id;
	id = getpid();
	printf("process id = %d\n",id);
}