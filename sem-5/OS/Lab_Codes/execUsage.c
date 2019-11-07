#include <sys/types.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid = fork();

	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed\n");
	}
	else if(pid == 0)
	{
		execlp("/bin/ls", "ls", "-a", NULL);
	}
	else
	{
		wait(NULL);
		printf("Child Complete\n\n");
		exit(0);
	}
}