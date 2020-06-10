#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define msg_sz (1024)

struct my_msgbuf 
{
               long mtype;       /* message type, must be > 0 */
               char mtext[msg_sz];    /* message data */
};

int main()
{
	key_t  key;
	int msg_id;
	int running = 1;
	struct my_msgbuf msg_buf; 
	int msg_type;
	char buf[256];
	/*key = ftok("/work",0);*/
	/*1.������Ϣ����*/
	msg_id = msgget(1024,IPC_CREAT);
	/*2.����Ϣ������Ϣ����*/
	while(running)
	{
		printf("please input message type,0 for quit!\n");
		scanf("%d",&msg_type);
		if(!msg_type)
			return 0;
		printf("please input message content!\n");
		
		/*2.1��ȡ��������*/
		scanf("%s",buf);
		msg_buf.mtype = msg_type;
		strcpy(msg_buf.mtext,buf);
		/*2.2���͵���Ϣ����*/
		msgsnd(msg_id, &msg_buf, sizeof(msg_buf), 0);
	}
	/*3.ɾ����Ϣ����*/
	msgctl(msg_id, IPC_RMID, NULL);
	return 0;
}
