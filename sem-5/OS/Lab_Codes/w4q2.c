#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	pid_t pid = fork();

	if(pid == -1)
	{
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid == 0)
	{
		printf("Child process executing!!\n");
		execlp("/root/Documents/Labs/OS_Lab/opq1", "opq1", (char *) 0);
	}
	else
	{
		printf("Parent of Q2\n");
		printf("I'll terminate.\n");
	}
	return 0;
}