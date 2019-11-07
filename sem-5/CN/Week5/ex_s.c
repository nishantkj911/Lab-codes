#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT_NO 9704

int main(int argc, char const *argv[])
{
	int sd;

	char buf[256];
	struct sockaddr_in sadd, cadd;

	sd = socket(AF_INET, SOCK_DGRAM, 0);

	sadd.sin_family = AF_INET;
	sadd.sin_port = htons(PORT_NO);
	sadd.sin_addr.s_addr = inet_addr("127.0.0.1");

	int result = bind(sd, (struct sockaddr*)&sadd, sizeof(sadd));
	int len = sizeof(cadd);

	int m = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr*)&cadd, &len);

	printf("The server send is %s\n", buf);

	int n = sendto(sd, buf, sizeof(buf), 0, (struct sockaddr*)&cadd, len);
	return 0;
}