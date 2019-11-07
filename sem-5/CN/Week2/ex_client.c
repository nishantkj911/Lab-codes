#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT_NO 10400

int main(int argc, char const *argv[])
{
	int len, sock_desc, n = 1;
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT_NO);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(addr);

	int res = connect(sock_desc, (struct sockaddr*)&addr, len);
	if(res == -1)
	{
		perror("\nCLIENT ERROR");
		exit(1);
	}

	char buf1[] = "Nishant in CN Lab\0";
	write(sock_desc, buf1, strlen(buf1));
	printf("String from server is:\n");
	char buf2[256];
	// while(n)
	{
		n = read(sock_desc, buf2, sizeof(buf2));
		puts(buf2);
	}

	close(sock_desc);
	return 0;
}