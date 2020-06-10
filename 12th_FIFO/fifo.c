#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
	int fd_fifo;
	/*创建FIFO文件*/
	mkfifo("/tmp/myfifo", 0666);
	
	/*打开FIFO文件*/
	fd_fifo = open("/tmp/myfifo",O_WRONLY);
	
	/*写入数据*/
	write(fd_fifo,"hello",6);
	
	/*关闭文件*/
	close(fd_fifo);
}