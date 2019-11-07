#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>

#define PORTNO 10200

int main()
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	fd_set readfds,testfds;
	int i,value;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	
	time_t  time_raw_format;
	struct tm * ptr_time;
	time ( &time_raw_format);
	ptr_time = localtime ( &time_raw_format );

	listen(sockfd,5);
	FD_ZERO(&readfds);
	FD_SET(sockfd,&readfds);
	
	while(1)
	{
		printf("server waiting");
		char buf[256];
		int fd,nread;
		testfds = readfds;


		int result=select(FD_SETSIZE,&testfds,(fd_set*)0,(fd_set*)0,(struct timeval*)0);

		for(fd=0;fd<FD_SETSIZE;fd++)
		{

			if(FD_ISSET(fd,&testfds))
			{
				if(fd==sockfd)
				{
					clilen=sizeof(clilen);
					newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
					FD_SET(newsockfd,&readfds);
					printf("adding client on fd %d\n",newsockfd);
				}

				else
				{ 
					ioctl(fd,FIONREAD,&nread);
					
					if(nread==0)
					{
						close(fd);
						FD_CLR(fd,&readfds);
						printf("removing client on fd %d\n",fd);
					}
					else
					{
						n=read(fd,buf,sizeof(buf));
						sleep(5);
						printf("serving client on fd %d\n",fd);
					    printf("\n Message from client %s\n",buf);
				        int n=sprintf(buf,"Time: %s Pid: %d\n", asctime(ptr_time), getpid());
				        write(newsockfd,buf,sizeof(buf));
				    }
				}
			}
		}
	}
	close(sockfd);
}