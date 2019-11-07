#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 10200

int main()
{
	int sockfd;
	struct sockaddr_in addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// memset(&addr, '0', sizeof(addr));
	int n=1;
	if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) != -1)
	{
		// while(n)
		//Not working with the while loop for some reason
		{
			// printf("In loop\n");
			char buf2[256];
			n = read(sockfd, buf2, sizeof(buf2));
			printf(" %s\n", buf2);
		}
		
		char buf[] = "Thank You";
		write(sockfd, buf, strlen(buf));

	}
	else
	{
		perror("\nClient Error\n");
		exit(1);
	}

	close(sockfd);
}