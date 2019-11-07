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

	char buf[256], buf1[256];
	struct sockaddr_in addr;

	sd = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT_NO);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("Enter the string: \n");
	fgets(buf, sizeof(buf), stdin);

	int len = sizeof(addr);
	int m = sendto(sd, buf, sizeof(buf), 0, (struct sockaddr*) &addr, len);
	int n = recvfrom(sd, buf1, sizeof(buf1), 0, (struct sockaddr*) &addr, &len);

	printf("The server echo is:\n%s\n", buf1);
	return 0;
}