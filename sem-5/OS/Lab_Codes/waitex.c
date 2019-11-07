#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid, pid2;
	char* message;
	int n;
	
	printf("fork program starting\n");
	pid = fork(); //Note: the child process starts executing from the next line of the fork st. not from the start
	printf("Dishari\n");
	pid2 = fork();

	printf("Yo!!\n");
	// if(pid == -1 || pid2 == -1)
	if(pid == -1)
	{
		perror("ERROR!! Child not created");
	}
	// else if(pid == 0 || pid2 == 0) 
	else if (pid == 0)
	{
		int pid_c = getpid();
		printf("I'm the child %i and my parent is: %i\n", pid_c, getppid());
		for(int i = 0; i<pid_c % 10; i++)
		{
			printf("%i waiting\n", pid_c);
			sleep(1);
		}
		exit(0);
	}
	else
	{
		// fork();
		// int pidc = waitpid(pid, &n, 0);
		printf("I'm the parent! id: %i\n", getpid()	);
		// printf("Child %i returned %d\n", pid, n);
	}
	exit(0);
}