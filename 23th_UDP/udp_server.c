#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>


#define NUM 3333
#define MSG_SZ 128

int main()
{
	int sfd;
	struct sockaddr_in my_addr,client_addr;
	char buf[MSG_SZ];
	int size_addr,rcv_leng;
	/*创建一个socket*/
	sfd = socket(AF_INET,SOCK_DGRAM, 0);
	/*绑定地址*/
	bzero(&my_addr,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(NUM);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr));
	
	/*收数据*/
	while(1)
	{
		size_addr = sizeof(struct sockaddr);
		bzero(buf,sizeof(buf));
		/*接收客户端的数据*/
		rcv_leng = recvfrom(sfd, buf, MSG_SZ, 0,(struct sockaddr *)&client_addr, &size_addr);
		buf[rcv_leng] = 0;
		printf("receive buf: %s\n",buf);
		/*发送数据到客户端*/
		sendto(sfd, buf,MSG_SZ, 0,(struct sockaddr *)&client_addr, sizeof(struct sockaddr));
	}
	/*断开连接*/
	close(sfd);
	return 0;
}