#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
	int fd_fifo;
	char buf[10];

	/*打开FIFO文件*/
	fd_fifo = open("/tmp/myfifo",O_RDONLY);
	
	/*写入数据*/
	read(fd_fifo,buf,6);
	printf("read data = %s\n",buf);
	/*关闭文件*/
	close(fd_fifo);
	unlink("/tmp/myfifo");
}