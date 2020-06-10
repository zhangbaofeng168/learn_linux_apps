#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main()
{
	int fd1,fd2,ret;
	char buf[10];
	fd1 = open("/work/hello.c",O_RDWR);
	if(fd1 < 0)
		printf("open err!\n");
	ret = read(fd1,buf,5);
	strcpy(&buf[5],"\0");
	printf("%s\n",buf);
	lseek(fd1,0,SEEK_CUR);
	write(fd1,"nihao",5);
	close(fd1);
	
}
