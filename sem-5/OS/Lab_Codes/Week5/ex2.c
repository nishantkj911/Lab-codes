#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void* child_thread(void* param)
{
	int id = (int) param;
	printf("Start Thread %i\n", id);
	return (void*) id;
}

int main(int argc, char const *argv[])
{
	pthread_t thread[10];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int ret[10];
	for(int i=0; i<10; i++)
	{
		pthread_create(&thread[i], &attr, &child_thread, (void *)i );
	}

	for (int i = 0; i < 10; ++i)
	{
		pthread_join(thread[i], (void**) &ret[i]);
		printf("End thread %i\n", ret[i]);
	}
	return 0;
}