#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <time.h>

#define PORTNO 10201

int main()
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	
	time_t  time_raw_format;
	struct tm * ptr_time;
	/*time(&time_raw_format);
	ptr_time = localtime (&time_raw_format);*/
	
	listen(sockfd,5);
	
	while(1)
	{
		char buf[256];

		printf("server waiting");

		clilen=sizeof(cliaddr);
		newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
		
		n=read(newsockfd,buf,sizeof(buf));
		printf("\n Message from client:\n %s\n", buf);

		time(&time_raw_format);
		ptr_time = localtime (&time_raw_format);
		
		char buf2[256];
		int n = sprintf(buf2, "Time: %s P-ID: %d\n", asctime(ptr_time), getpid());

		n=write(newsockfd,buf2,sizeof(buf2));
	}
	
	close(sockfd);
}