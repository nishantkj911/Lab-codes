#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	fork();
	printf("hi\n");
	fork();
	printf("hi\n");
	fork();
	printf("hi\n");
}