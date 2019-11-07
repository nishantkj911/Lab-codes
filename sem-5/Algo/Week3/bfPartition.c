#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findPowerSet(int* arr, int n, int sum)
{
	int power = (int) pow(2, n);

	for (int i = 0; i < power; ++i)
	{
		int tempSum = 0;
		for (int j = 0; j < n; ++j)
		{
			if(i & (1<<j))
			{
				tempSum+=arr[j];
			}
		}
		// printf("temp sum = %i\n", tempSum);
		if(tempSum == sum)
		{
			printf("The partition is\n");
			for (int j = 0; j < n; ++j)
			{
				if(i & (1<<j))
				{
					printf("%i ", arr[j]);
				}
			}
			printf("\n");
			for (int j = 0; j < n; ++j)
			{
				if(!(i & (1<<j)))
				{
					printf("%i ", arr[j]);
				}
			}
			printf("\n");
			break;
		}
	}
}

void divideSubsets(int* arr, int n)
{
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i];
	}
	if(sum % 2 != 0)
	{
		printf("The array cannot be divided since the total sum is odd\n");
		return;
	}

	findPowerSet(arr, n, sum / 2);
}

int main(int argc, char const *argv[])
{
	int n=-1, maxSize=1, temp;
	int* arr = malloc(sizeof(int));
	printf("Keep entering nos. or 'EOF' char to exit\n");
	while(1)
	{
		int res = scanf("%i", &temp);

		if(res == EOF)
		{
			break;
		}

		if(res != 1)
		{
			printf("Please enter proper input\n");
			continue;
		}
		
		n++;
		if(n == maxSize)
		{
			arr = (int* ) realloc(arr, sizeof(int) * maxSize * 2);
			maxSize*=2;
		}
		arr[n] = temp;
	}

	// printf("Max size of array = %i\n", maxSize);

	divideSubsets(arr, ++n);
	return 0;
}