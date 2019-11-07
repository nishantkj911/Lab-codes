#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>

#define PORTNO 10201

int main()
{
	int len,result,sockfd;
	struct sockaddr_in address;
	int buf[10];
	char b[100];
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1"); 
	address.sin_port=htons(10201);
	len = sizeof(address);
	
	result = connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1)
	{
		perror("\nCLIENT ERROR");

	exit(1);
	}

	printf("\nEnter 10 array elements:\n");
	
	for(int i=0;i<10;i++)
		scanf("%d",buf+i);
	
	write(sockfd,buf,sizeof(buf));
	
	printf("sorted array:\n");
	read(sockfd,buf,sizeof(buf));
	
	int n=sizeof(buf)/sizeof(buf[0]);
	for(int i=0;i<n;i++)
		printf("%d ",buf[i]);
	printf("\n");
	
	read(sockfd,b,sizeof(b));
	puts(b);
	
	close(sockfd);
}
