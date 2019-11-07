#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _dynarr
{
	int size, maxSize;
	int arr[1];
} DynamicArray;

int calcGCDConsecInt(int a, int b)
{
	if(a == b)
	{
		return a;
	}

	for(int i = (a < b ? a : b); i>=1; i--)
	{
		if(a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
}

int* primeNosTill(int n)
{
	int prime[n+1];
	for(int i = 2; i <= sqrt(n); i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(prime[j] == 0 && j % i == 0)
			{
				prime[j] = 1;
			}
		}
	}
}

int* findFactors(int n)
{
	int* prime = primeNosTill(n);
}

int calcGCDMiddleSchool(int a, int b)
{
	int* factorsA = findFactors(a);
	int* factorsB = findFactors(b);


}

int main()
{
	int a, b;
	printf("Enter the two numbers to find GCD: ");
	int ret = scanf("%i %i", &a, &b);

	if(ret != 2)
	{
		printf("Enter proper inputs please\n");
		return 0;
	}

	printf("Which method? (1. Consecutive integers   2. Middle School Method): ");
	int choice, gcd;
	scanf("%i", &choice);
	switch(choice)
	{
		case 1: gcd = calcGCDConsecInt(a, b);
				printf("The GCD of %i and %i is %i\n", a, b, gcd);
				break;

		case 2: gcd = calcGCDMiddleSchool(a, b); 
				printf("The GCD of %i and %i is %i\n", a, b, gcd);
				break;

		default: printf("Enter proper choice\n");
	}

	return 0;
}