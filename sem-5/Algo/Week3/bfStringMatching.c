#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringMatching(char* text, int texLen, char* pattern, int pattLen)
{
	// printf("hey\n");
	int opCount=0;
	for (int i = 0; i < texLen; ++i)
	{
		int j=0, k=0;
		// opCount++;
		for (k=0, j = i; ++opCount && (k < pattLen && pattern[k] == text[j]); k++, j++);
		if(k == pattLen)
		{
			printf("The op count is %i\n", opCount);
			return i;
		}
	}

	printf("The op count is %i\n", opCount);
	return -1;
}

int main(int argc, char const *argv[])
{
	printf("Enter the text\n");	
	char* text=(char* ) malloc(2147483647 * sizeof(char));
	fgets(text, 2147483647, stdin);
	int texLen = strlen(text);
	// printf("Text length %i\n", texLen);
	// printf("text is: %s", text);
	
	printf("Enter the pattern\n");
	char* pattern=(char* ) malloc(2147483647 * sizeof(char));
	fgets(pattern, 2147483647, stdin);
	int pattLen = strlen(pattern);
	// printf("Pattern length %i\n", pattLen);
	// printf("pattern is: %s", pattern);

	int index = stringMatching(text, texLen, pattern, pattLen);
	if(index == -1)
	{
		printf("The pattern has not been found\n");
	}
	else
	{
		printf("The pattern was found at %i index\n", index);
	}
	return 0;
}