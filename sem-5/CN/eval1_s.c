#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#define PORT 10200

int main()
{
	int sockfd, newsockfd, clilen;
	struct sockaddr_in seraddr, cliaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORT);
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*) &seraddr, sizeof(seraddr));

	listen(sockfd, 5);

	clilen = sizeof(cliaddr);

	int n=1;
	while(1)
	{
		printf("Server is Waiting\n");

		newsockfd = accept(sockfd, (struct sockaddr*) &cliaddr, &clilen);

		char buf[] = "Welcome to ---- server";
		write(newsockfd, buf, strlen(buf));

		// while(n)
		{
			char buf2[256];
			n = read(newsockfd, &buf2, sizeof(buf2));
			printf("%s\n", buf2);
		}

		close(newsockfd);
	}

	close(sockfd);
}