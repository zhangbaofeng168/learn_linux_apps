#include <stdio.h>

void myprintf(int res)
{
	printf("result = %d \n",res);
}

void main(void)
{
	int i;
	long result = 0;
	for(i=1; i<=100; i++)
	{
		result += i;
	}
	myprintf(result);
}