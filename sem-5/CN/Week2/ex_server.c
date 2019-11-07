#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define port_no 10400

int main(int argc, char const *argv[])
{
	int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("Socket creation error\n");
		return 0;
	}

	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(port_no);
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int status = bind(socket_desc, (struct sockaddr*) &seraddr, sizeof(seraddr));
	if(status == -1)
	{
		printf("Server binding problem\n");
		return 0;
	}

	int queue_len = 5, newsock_desc,n = 1, clilen;
	listen(socket_desc, queue_len);
	struct sockaddr_in client_addr;
	while(1)
	{
		char buf[256];
		printf("server is waiting\n");
		
		clilen = sizeof(client_addr);
		newsock_desc = accept(socket_desc,(struct sockaddr*)&client_addr, &clilen);

		n = read(newsock_desc, &buf, sizeof(buf));
		printf("Message from client: %s\n", buf);
		n = write(newsock_desc, buf, sizeof(buf));

	}

	close(socket_desc);
	return 0;
}