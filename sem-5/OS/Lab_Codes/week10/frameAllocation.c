#include <stdio.h>
#include <stdlib.h>

int bestFit(int** availableSizes, int avail, int* frameSizes, int frame)
{
	for (int j = 0; j < frame; ++j)
	{
		int minI=-1;
		for (int i = 0; i < avail; ++i)
		{
			if(minI < 0 && (*availableSizes)[i] > frameSizes[j])
			{
				minI = i;
			}
			else if((*availableSizes)[minI] > (*availableSizes)[i] && (*availableSizes)[i] > frameSizes[j])
				minI = i;
		}
		
		if (minI >= 0)
		{
			printf("Allocating %iK memory to %iK frame\n", (*availableSizes)[j], frameSizes[j]);
			(*availableSizes)[j] -= frameSizes[j];
			
		}
		else
		{
			printf("No space left for process with %iK size. Replacement needed\n", frameSizes[j]);
			
		}
	}
	return 0;
}

int worstFit(int** availableSizes, int avail, int* frameSizes, int frame)
{
	for (int j = 0; j < frame; ++j)
	{
		int maxI=0;
		for (int i = 1; i < avail; ++i)
		{
			if((*availableSizes)[maxI] < (*availableSizes)[i])
				maxI = i;
		}
		
		if (frameSizes[j] <= (*availableSizes)[maxI])
		{
			printf("Allocating %iK memory to %iK frame\n", (*availableSizes)[j], frameSizes[j]);
			(*availableSizes)[j] -= frameSizes[j];
			
		}
		else
		{
			printf("No space left for process with %iK size. Replacement needed\n", frameSizes[j]);
			
		}
	}
	return 0;
}

int firstFit(int** availableSizes, int avail, int* frameSizes, int frame)
{
	for (int i = 0, j = 0; i < frame; ++i)
	{
		for (j = 0; j < avail && (*availableSizes)[j] < frameSizes[i]; ++j);

		if(j == avail)
		{
			printf("No space left for process with %iK size. Replacement needed\n", frameSizes[i]);
		}
		else
		{
			printf("Allocating %iK memory to %iK frame\n", (*availableSizes)[j], frameSizes[i]);
			(*availableSizes)[j] -= frameSizes[i];
		}

	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int size1 = 0, maxSize1 = 1;
	int* arr = (int*) calloc(10, sizeof(int));
	int* arr2 = (int*) malloc(sizeof(int));

	printf("Enter the memory holes in order (in KBs)\n");
	int temp;
	while(scanf("%i", &temp) != EOF)
	{
		if(size1 == maxSize1)
		{
			arr = (int*) realloc(arr, sizeof(int) * maxSize1 * 2);
			maxSize1*=2;
		}
		arr[size1++ - 1] = temp;
	}

	printf("Enter the process sizes who want to enter, in order (in KBs)\n");
	// int* arr2 = malloc(sizeof(int));
	int size2 = 0, maxSize2 = 1;
	while(scanf("%i", &temp) != EOF)
	{
		if(size2 == maxSize2)
		{
			arr2 = realloc(arr2, sizeof(int) * maxSize2 * 2);
			maxSize2*=2;
		}
		arr2[size2++ - 1] = temp;
	}

	firstFit(&arr, size1, arr2, size2);
	return 0;
}
