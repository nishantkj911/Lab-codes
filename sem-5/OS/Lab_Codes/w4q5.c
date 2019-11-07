#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd = creat("/root/Desktop/abc.txt", O_RDWR);
	int n=1;
	
	while(1)
	{
		char* buf = malloc(sizeof(char) * 512);
		char* a = fgets(buf, sizeof(buf), stdin);

		if(a == NULL)
			break;

		write(fd, buf, strlen(buf));
		free(buf);
	}

	close(fd);
	return 0;
}