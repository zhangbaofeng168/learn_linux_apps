#include <unistd.h>
#include <stdio.h>

void main()
{
	execl("/bin/ls","ls","/work",NULL);	
}