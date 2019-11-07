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

void sortArray(int a[],int n)
{
	int min=0;


	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}

		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

   

int main()
{
	int sockfd,newsockfd,portno,clilen;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	int buf[10];
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	
	listen(sockfd,5);
	while(1)
	{
		clilen=sizeof(clilen);
		newsockfd=accept(sockfd,(struct sockaddr*) &cliaddr,&clilen);

		if(fork()==0)
		{
			read(newsockfd,buf,sizeof(buf));
			printf("Array received");

			sortArray(buf,10);
			
			write(newsockfd,buf,sizeof(buf));
			
			char b[100];
			int n=sprintf(b,"Process Id:%d",getpid());
			write(newsockfd,b,strlen(b));
			
			close(newsockfd);
			exit(0);
		}
		else
			close(newsockfd);
		
		fflush(stdout);
	}
}