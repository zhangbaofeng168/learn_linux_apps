#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>


#define NUM 3333
#define MSG_SZ 128
int main(int argc,char **argv)
{
	int cfd;
	struct sockaddr_in my_addr,server_addr;
	int size_addr,rcv_len;
	char buf[MSG_SZ];
	
	if(argc != 2)
	{
		printf("Usage %s server_ip\n",argv[0]);
		return 0;
	}
	/*创建一个socket*/
	cfd = socket(AF_INET,SOCK_DGRAM, 0);

	bzero(&my_addr,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(NUM);
        inet_aton(argv[1],&my_addr.sin_addr);
	
	/*发数据*/
	printf("please enter msg: ");
	fgets(buf,MSG_SZ,stdin);
	sendto(cfd, buf,MSG_SZ, 0,(struct sockaddr *)&my_addr, sizeof(struct sockaddr));
	/*接收服务器发来的数据*/
	bzero(buf,sizeof(buf));
	size_addr = sizeof(struct sockaddr);
	rcv_len = recvfrom(cfd, buf, MSG_SZ, 0,(struct sockaddr *)&server_addr, &size_addr);
	buf[rcv_len] = 0;
	printf("receive from server: %s\n",buf);
	/*断开连接*/
	close(cfd);
	return 0;
	
}