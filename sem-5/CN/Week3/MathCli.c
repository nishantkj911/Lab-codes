#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PN 10200

int main(int argc, char const * argv [])
{
	struct sockaddr_in cliaddr;
	int sockfd,clilen,a,b;
	int buf[2];
	char ch[5];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	cliaddr.sin_port=htons(PN);
	clilen=sizeof(cliaddr);
	
	int result=connect(sockfd,(struct sockaddr*) &cliaddr,clilen);
	if(result==-1)
	{
		perror("\n Client error");
		exit(1);
	}
	
	printf("\nEnter operator:\n");
	gets(ch);
	printf("\nEnter two numbers:");
	
	scanf("%d %d", &a, &b);
	buf[0]=a;
	buf[1]=b;

	// printf("b: %d",buf[1]);
	write(sockfd,buf,sizeof(buf));
	write(sockfd,ch,sizeof(ch));
	
	read(sockfd,buf,sizeof(buf));
	
	printf("answer:%d",buf[0]);
	close(sockfd);
}

