#include <stdio.h>
#include <stdlib.h>

#define YOLO 1029

int main(int argc, char *argv[])
{
	printf("Hello, # world\n");
	int n[10], b, d;
	scanf("%i %i", &n[1], &n[4]);
	char c = 'o';
	for (int i = 0; i < 10; i++)
	{
		n[i] = i + 3;
		printf("\n");
		if (i == 4)
			break;
	}
	return 0;
}