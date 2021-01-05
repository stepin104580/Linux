#include "ServerClient.h"

int main()
{
	int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	/* Open a Message Queue in Server Process */
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buf[8192];
	int maxlen=256,prio;
	/* Receive a message from Queue */
	printf("Waiting for message from Client .......\n");
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("msg from client : %s\n",buf);

	/* Toogle the message received */
	for (int i=0; buf[i]!='\0'; i++)
    {
        if (buf[i]>='A' && buf[i]<='Z')
            buf[i] = buf[i] + 'a' - 'A';
        else if (buf[i]>='a' && buf[i]<='z')
            buf[i] = buf[i] + 'A' - 'a';
    }

	/* Send back the processed message to Client through Queue */
	ret = mq_send(mqid,buf,100,100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	/* Close the Queue */
	mq_close(mqid);
	return 0;
}

