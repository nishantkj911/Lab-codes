#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>

int buf[10], readCount = 0;
sem_t wrt, mutex;

void *reader(void *param)
{
	for (int i = 0; i < 10; ++i)
	{
		sleep(rand() % 5);
		sem_wait(&mutex);
		readCount++;
		if(readCount == 1)
			sem_wait(&wrt);
		sem_post(&mutex);

		printf("Reader thread: %i in iteration %i\n", (int) pthread_self() % 6, i);
		for (int i = 0; i < 10; ++i)
		{
			printf("%i ", buf[i]);
		}
		printf("\n");

		sem_wait(&mutex);
		readCount--;
		if(readCount == 0)
			sem_post(&wrt);
		sem_post(&mutex);
	}
}

void *writer(void *param)
{
	for (int i = 0; i < 10; ++i)
	{
		sleep(rand() % 5);
		sem_wait(&wrt);

		printf("WRITER WRITTEN\n");
		for (int i = 0; i < 10; ++i)
		{
			buf[i]*=(i*i) + i - 2;
		}

		sem_post(&wrt);
	}
}

int main(int argc, char const *argv[])
{
	
	sem_init(&wrt, 0, 1);
	sem_init(&mutex, 0, 1);

	pthread_t thid[6];
	for (int i = 0; i < 6; ++i)
	{
		if(i == 3)
		{
			pthread_create(&thid[i], 0, &writer, 0);
		}
		else
		{
			pthread_create(&thid[i], 0, &reader, 0);	
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		pthread_join(thid[i], 0);
	}

	sem_destroy(&mutex);
	sem_destroy(&wrt);
	return 0;
}

