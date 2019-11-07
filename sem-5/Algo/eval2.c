#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int genSubsetSum(int* arr, int n)
{
	int power = (int) pow(2, n);

	int sum = 0;
	for (int i = 0; i < power; ++i)
	{
		int last = -1, first = -1;
		printf("In loop of %i\n", i);
		for (int j = 0; j < n; ++j)
		{
			printf("\tIn loop of %i\n", j);
			if(i & (1<<j))
			{
				if (first == -1)
				{
					first = j;
				}

				last = j;
				printf("%i ", arr[j]);

			}
			printf("	Last and first resp: %i\t%i\n", last, first);
		}
		printf("\n");
		
		printf("\nThe last: %i\tThe first: %i\n", arr[last], arr[first]);
		sum += (arr[last] - arr[first]);
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of elements in the set\n");
	scanf("%i", &n);

	int* arr = (int*) calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &arr[i]);
	}

	int ans = genSubsetSum(arr, n);
	printf("The sum of first and last of each subset is %i\n", ans);
	return 0;
}