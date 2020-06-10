#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define msg_sz (1024)

struct my_msgbuf {
               long mtype;       /* message type, must be > 0 */
               char mtext[msg_sz];    /* message data */
};
int msg_id;
void childprocess()
{
	struct my_msgbuf msg_buf; 
	while(1)
	{
		/*������Ϣ*/
		msgrcv(msg_id, &msg_buf, sizeof(msg_buf), 0,0);
		/*��ӡ��Ϣ*/
		printf("msg text: %s\n",msg_buf.mtext);
	}
}
int main()
{
	key_t  key;
	int i;
	int cpid;
	/*key = ftok("/work",0);*/
	/*1.������Ϣ����*/
	msg_id = msgget(1024,IPC_EXCL);
	/*2.���������ӽ���*/
	for(i=0;i<3;i++)
	{
		cpid = fork();
		if(cpid < 0)
		{
			printf("creat childprocess fail!\n");
			return 0;
		}
		else if(0 == cpid)
			childprocess();
	}
	
	return 0;
}
