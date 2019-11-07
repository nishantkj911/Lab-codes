#include <stdio.h>
#include <stdlib.h>

#define LEN 100


int main()
{
	char* ptr[LEN];
	char input[LEN];
	fgets(input, LEN, stdin);

	int words = 1;
	ptr[0] = malloc(sizeof(char) * LEN);
	for(int i=0, line = 0, let = 0; input[i] != '\n'; i++)
	{
		if(input[i] == ' ')
		{
			let=0;
			words++;
			ptr[++line] = malloc(sizeof(char) * LEN);
			continue;
		}

		ptr[line][let++] = input[i];
	}

	printf("The 2d array is\n");
	for(int i=0; i<words; i++)
	{
		/*if(ptr[i] == NULL)
			break;*/
		printf("Row %i: %s\n", i, ptr[i]);
	}

}