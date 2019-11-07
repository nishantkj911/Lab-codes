#include <pthread.h>
int counter = 0;

void* func(void* param)
{
	counter++;
}

int main(int argc, char const *argv[])
{
	pthread_t th1, th2;
	pthread_create(&th1, 0, func, 0);
	pthread_create(&th2, 0, func, 0);

	pthread_join(th1, 0);
	pthread_join(th2, 0);

	return 0;
}