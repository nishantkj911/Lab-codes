#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
volatile int counter = 0;

void *method(void *param)
{
	for (int i = 0; i < 10; ++i)
	{
		pthread_mutex_lock(&mutex);
		counter++;
		printf("Count = %i\n", counter);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t thid[2];
	pthread_mutex_init(&mutex, 0);
	pthread_create(thid, 0, &method, 0);
	pthread_create(thid+1, 0, &method, 0);

	pthread_join(thid[0], 0);
	pthread_join(thid[1], 0);
	pthread_mutex_destroy(&mutex);
	return 0;
}