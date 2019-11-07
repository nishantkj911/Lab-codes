#include <stdio.h>
#include <stdlib.h>

#define YOLO 1029

int main(int argc, char const *argv[])
{
	printf("Hello, # world\n");
	int n[10];
	char c;
	for (int i = 0; i < 10; i++)
	{
		n[i] = i + 3;
		if (i == 4)
			break;
	}
	return 0;
}