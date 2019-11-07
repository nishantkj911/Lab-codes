#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


// write a c program which reads a number from the user and displays the maximum digit in the parent 
// and minimum in the child process
int main(int argc, char const *argv[])
{
	int num;
	printf("Enter the number\n");
	int res = scanf("%i", &num);
	if(res != 1)
	{
		fprintf(stderr, "%s\n", "Enter proper Input");
		return 1;
	} 

	pid_t pid = fork();
	if(pid == -1)
	{
		fprintf(stderr, "Fork Failed\n");
	}
	else if(pid == 0)
	{
		int temp = num, mindig = 9;
		while(temp > 0)
		{
			if(temp % 10 < mindig)
				mindig = temp % 10;

			temp/=10;
		}

		printf("Minimum Digit: %i\n", mindig);
	}
	else
	{
		int temp = num, maxdig = 0;
		printf("num: %i\n", num);
		while(temp > 0)
		{

			if(temp % 10 > maxdig)
				maxdig = temp % 10;

			temp/=10;
		}
		if(num == 0)
			maxdig = 0;

		printf("Maximum Digit: %i\n", maxdig);
	}
	return 0;
}