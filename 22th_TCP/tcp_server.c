#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#define LISTEN_BACKLOG 5
#define NUM 3333

int main()
{
	int socket_fd,cfd,nbyte,peer_addr_size;
	struct sockaddr_in my_addr,peer_addr;
	char buf[128];
	/*����socket*/
	socket_fd = socket(AF_INET,SOCK_STREAM,0);
	/*�󶨵�ַ*/
	bzero(&my_addr,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(NUM);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(socket_fd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr));
	/*�����˿�*/
	listen(socket_fd, LISTEN_BACKLOG);
	/*�ȴ�����*/
	while(1)
	{
		peer_addr_size = sizeof(struct sockaddr);
      		cfd = accept(socket_fd, (struct sockaddr *) &peer_addr,
                        &peer_addr_size);
                printf("server get connection %s\n",inet_ntoa(peer_addr.sin_addr));
		
		/*�շ�����*/
		nbyte = recv(cfd,buf,128,0);
		buf[nbyte] = "\0";
		printf("receiver : %s\n",buf);
		/*��������*/
		close(cfd);
	}
	close(socket_fd);
	return 0;
}