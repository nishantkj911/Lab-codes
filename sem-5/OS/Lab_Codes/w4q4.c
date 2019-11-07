#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

#define ITER 15


//Creating orphan process
int main(int argc, char const *argv[])
{
	pid_t pid = fork();

	if(pid == -1)
	{
		fprintf(stderr, "%s\n", "Fork failed");
	}
	else if(pid == 0)
	{
		for (int i = 0; i < ITER; ++i)
		{
			printf("Child process, ID: %i\tParent ID: %i\n", getpid(), getppid());
			// printf("Child sleeping\n");
			sleep(1);
		}
		printf("Child Terminating\n");
	}
	else
	{
		printf("Parent process\tID: %i\n", getpid());
		/*printf("Waiting for child\n");
		wait(NULL);
		printf("Child returned so parent terminating\n");*/
		sleep(2);
		printf("Parent terminating\n");
	}
	exit(0);
}