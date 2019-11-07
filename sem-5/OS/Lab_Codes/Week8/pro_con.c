#include <stdio.h>
#include <pthread.h>
#include <wait.h>
#include <semaphore.h>

int buf[5], f, r;
sem_t mutex, full, empty;

void* produce(void* arg)
{
    int i, item;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("produced item is %i\n", i);

        buf[(++r) % 5] = i;
        sleep(1);

        sem_post(&mutex);
        sem_getvalue(&full, &item);
        sem_post(&full);
        printf("Full %u\n", item);
    }
}

void* consume(void* arg)
{
    int item, i;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        sem_getvalue(&full, &item);
        printf("Full %u\n", item);

        item = buf[(++f) % 5];
        printf("Consumed item is %i\n", item);

        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 1);
    sem_init(&empty, 0, 5);

    pthread_create(&tid1, 0, produce, 0);
    pthread_create(&tid2, 0, consume, 0);

    pthread_join(tid1, 0);
    pthread_join(tid2, 0);

    return 0;
}
