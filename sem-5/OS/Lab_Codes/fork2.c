#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	char* message;
	int n;
	
	printf("fork program starting\n");
	pid = fork();

	switch(pid)
	{
		case -1: perror("Fork Failed!!!"); exit(1);
		case 0: message = "I am child\n";
				
				n = 3; 
				// fork();
				break;
		default : message = "I am parent\n"; 
					n = 5;
					break;
	}

	for(; n > 0; n--)
	{
		printf("%sMy ID: %i\nMy parent ID: %i\n\n", message, getpid(), getppid());
		sleep(1);
	}

	// wait(NULL);
	if(pid == 0)
	{
		printf("child ending\n");
	}
	else
	{
		printf("Parent ending\n");
	}
	exit(0);
}