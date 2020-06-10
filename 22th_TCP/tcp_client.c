#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#define NUM 3333

int main()
{
	int socket_fd;
	struct sockaddr_in my_addr;
	/*创建socket*/
	socket_fd = socket(AF_INET,SOCK_STREAM,0);
	/*连接服务器*/
	bzero(&my_addr,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(NUM);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	connect(socket_fd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr));
	/*收发数据*/
	send(socket_fd,"hello",6, 0);
	/*结束连接*/
	close(socket_fd);
	return 0;
}