#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd = open("/root/Desktop/abc.txt", O_RDONLY);

	int wc=0, lc=0, cc = 0;
	char* buf = malloc(sizeof(char) * 512);
	while(1)
	{
		int res = read(fd, buf, sizeof(buf));
		if(res == 0) 
		{
			free(buf);
			break;
		}
		else if(res == -1)
		{
			fprintf(stderr, "%s\n", "Reading error");
			break;
		}
		else
		{
			cc+=strlen(buf);
			printf("%s..\n", buf);
			for (int i = 0; i < strlen(buf); ++i)
			{
				if(buf[i] == ' ' && buf[i-1] != ' ')
				{
					wc++;
				}
				if(buf[i] == '\n')
					lc++;
			}
			if(buf[strlen(buf)-1] != ' ')
				wc++;
		}
		
	}

	printf("Word count: %i\nCharacter count: %i\nLine Count: %i\n", wc, cc, lc);
	return 0;
}