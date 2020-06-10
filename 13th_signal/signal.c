#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

void my_fun(int a)
{
	printf("signal deal!\n");
}

void main()
{
	signal(SIGINT,my_fun);
	pause();
}