#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PN 10200

int main(int argc, char const * argv [])
{
	struct sockaddr_in seraddr,cliaddr;
	int sockfd,newsockfd,clilen,n=1;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(PN);
	bind(sockfd,(struct sockaddr*) &seraddr,sizeof(seraddr));
	
	listen(sockfd,5);
	
	newsockfd=accept(sockfd,(struct sockaddr*) &cliaddr,&clilen);

	while(1)
	{   
		printf("\nserver is waiting");
		int buf[2];
		
		read(newsockfd,buf,sizeof(buf));
		int a= buf[0];
		int b= buf[1];
		int ans[1];
		char ch[1];
		read(newsockfd,ch,sizeof(ch));
		char op=ch[0];
		switch (op)
		{
			case '+': ans[0]=a+b;
			break;
			case '-':ans[0]=a-b;
			break;
			case '*': ans[0]=a*b;
			break;
			case '/':ans[0]=a/b;
			break;
			default: ans[0]=0;
		}

		write(newsockfd, ans ,sizeof(ans));
		printf("Answer is Evaluated and sent\n");
		
	}
	close(sockfd);
}