#include <stdio.h>
#include <stdlib.h>

#define YOLO 1029

// this is a test file for my input

int main(int argc, char const *argv[])
{
	printf("Hello, # world\n");
	int n[10];
	/* this is a three line
    comment for testing the analyser
    if it works or not */
	char c;
	for (int i = 0; i < 10; i++)
	{
		n[i] = i + 3;
		if (i == 4)
			break;
	}
	return 0;
}