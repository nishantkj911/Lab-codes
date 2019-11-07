#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ASCII_SIZE 128

int *computeTable(char *pattern, int len)
{
	int *shiftTable = (int *)calloc(ASCII_SIZE, sizeof(int));

	for (int i = len - 2; i >= 0; --i)
	{
		if (shiftTable[pattern[i]] <= 0)
		{
			shiftTable[pattern[i]] = len - i - 1;
		}
	}

	for (int i = 0; i < ASCII_SIZE; ++i)
	{
		if (shiftTable[i] == 0 && i != pattern[len - 1])
		{
			shiftTable[i] = len;
		}
	}

	return shiftTable;
}

int stringMatching(char *text, int textLen, char *pattern, int patLen, int *shiftTable)
{
	for (int i = 0; i <= textLen - patLen;)
	{
		int j, match;
		for (j = patLen - 1, match = 0; j >= 0; j--)
		{
			if (pattern[j] != text[i + j])
			{
				if (j == patLen - 1)
				{
					int shift = shiftTable[text[i + patLen - 1]];
					// printf("Characters %c and %c don't match. So shifting by %i for letter %c\n", pattern[j], text[i+j], shift, text[i + patLen - 1]);
					i += shift;
					break;
				}
				else
				{
					int shift = shiftTable[text[i + j]] - match;
					// printf("Characters %c and %c don't match. So shifting by %i for letter %c\n", pattern[j], text[i+j], shift, text[i + j]);
					i += shift;
					break;
				}
			}

			match++;
		}
		if (j < 0)
		{
			return i;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	printf("Enter the text\n");
	char *text = (char *)calloc(INT_MAX, sizeof(char));
	scanf("%[^\n]%*c", text);
	int textLen = strlen(text);
	// printf("Length of the text is %i\n", textLen);

	printf("Enter the pattern\n");
	char *pattern = (char *)calloc(INT_MAX, sizeof(char));
	scanf("%[^\n]%*c", pattern);
	int patLen = strlen(pattern);
	// printf("Length of the pattern is %i\n", patLen);

	int *shiftTable = computeTable(pattern, patLen);
	int ind;
	if ((ind = stringMatching(text, textLen, pattern, patLen, shiftTable)) == -1)
	{
		printf("Pattern is not there in the string\n");
	}
	else
		printf("Pattern found at index %i\n", ind);

	return 0;
}