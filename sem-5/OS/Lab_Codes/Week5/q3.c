#include "header.h"

typedef struct _prime
{
	int min, max;
} PrimeLimits;

void* genPrime(void* limits)
{
	PrimeLimits* lim = (PrimeLimits*) limits;

	for(int i = lim->min; i <= lim->max; i++)
	{
		int primeFlag = 1;
		for (int j = 2; j < i; ++j)
		{
			if(i % j == 0) 
			{
				primeFlag = 0;
				break;
			}
		}

		if(primeFlag == 1)
		{
			printf("%i ", i);
		}
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	PrimeLimits primeLimits;

	printf("Enter the limits\n");
	scanf("%i %i", &primeLimits.min, &primeLimits.max);

	pthread_t thid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&thid, &attr, &genPrime, &primeLimits);

	pthread_join(thid, NULL);
	return 0;
}