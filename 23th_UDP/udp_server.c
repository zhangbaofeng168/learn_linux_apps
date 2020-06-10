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
	/*����һ��socket*/
	sfd = socket(AF_INET,SOCK_DGRAM, 0);
	/*�󶨵�ַ*/
	bzero(&my_addr,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(NUM);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr));
	
	/*������*/
	while(1)
	{
		size_addr = sizeof(struct sockaddr);
		bzero(buf,sizeof(buf));
		/*���տͻ��˵�����*/
		rcv_leng = recvfrom(sfd, buf, MSG_SZ, 0,(struct sockaddr *)&client_addr, &size_addr);
		buf[rcv_leng] = 0;
		printf("receive buf: %s\n",buf);
		/*�������ݵ��ͻ���*/
		sendto(sfd, buf,MSG_SZ, 0,(struct sockaddr *)&client_addr, sizeof(struct sockaddr));
	}
	/*�Ͽ�����*/
	close(sfd);
	return 0;
}