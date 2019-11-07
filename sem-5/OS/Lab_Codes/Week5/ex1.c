#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void* thread_code(void* param)
{
	printf("In thread\n");
	pthread_exit((void *)0 );
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, 0);
	
	printf("In main \n");
	pthread_join(thread, 0);
	return 0;
}