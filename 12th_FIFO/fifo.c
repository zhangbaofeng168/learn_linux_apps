#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
	int fd_fifo;
	/*����FIFO�ļ�*/
	mkfifo("/tmp/myfifo", 0666);
	
	/*��FIFO�ļ�*/
	fd_fifo = open("/tmp/myfifo",O_WRONLY);
	
	/*д������*/
	write(fd_fifo,"hello",6);
	
	/*�ر��ļ�*/
	close(fd_fifo);
}