#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
	int fd_fifo;
	char buf[10];

	/*��FIFO�ļ�*/
	fd_fifo = open("/tmp/myfifo",O_RDONLY);
	
	/*д������*/
	read(fd_fifo,buf,6);
	printf("read data = %s\n",buf);
	/*�ر��ļ�*/
	close(fd_fifo);
	unlink("/tmp/myfifo");
}