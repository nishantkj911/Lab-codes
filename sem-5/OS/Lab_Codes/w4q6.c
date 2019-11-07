#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd1 = open("/root/Desktop/abc.txt", O_RDONLY);
	int fd2 = creat("/root/Desktop/def.txt", O_RDWR);


	while(1)
	{
		char* buf = malloc(sizeof(char) * 512);
		int ret = read(fd1, buf, sizeof(buf));
		if(ret == 0)
		{
			free(buf);
			break;
		}
		else if(ret == -1)
		{
			fprintf(stderr, "%s\n", "Reading error");
		}
		else
		{
			write(fd2, buf, strlen(buf));
		}
		free(buf);
	}
	close(fd1);
	close(fd2);
	return 0;
}