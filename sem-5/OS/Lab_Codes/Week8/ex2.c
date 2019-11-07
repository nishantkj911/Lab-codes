#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t semaphore;

void* func1(void* param)
{
	printf("Thread 1\n");
	sem_post(&semaphore);
}

void* func2(void* param)
{
	sem_wait(&semaphore);
	printf("Thread 2\n");
}

int main(int argc, char const *argv[])
{
	pthread_t th[2];
	sem_init(&semaphore, 0, 1);
	pthread_create(&th[0], 0, func1, 0);
	pthread_create(&th[1], 0, func2, 0);

	pthread_join(th[0], 0);
	pthread_join(th[1], 0);
	sem_destroy(&semaphore);

	return 0;
}