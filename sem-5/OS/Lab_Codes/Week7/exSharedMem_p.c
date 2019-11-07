#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define MEM_KEY 10182

typedef struct $
{
    int mutex;
    char text[BUFSIZ];
} shmStruct;

int main(int argc, char const *argv[])
{
    void *shared_memory = (void *)0;
    int memID = shmget((key_t)MEM_KEY, sizeof(shmStruct), IPC_CREAT | 0666);
    shmStruct *abc;
    // srand((unsigned int) getpid());

    if (memID == -1)
    {
        printf("Error creating shared memory\n");
        exit(EXIT_FAILURE);
    }

    shared_memory = shmat(memID, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        printf("Memory attach failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Memory attached at %X\n", (int)shared_memory);
    abc = (shmStruct *)shared_memory;
    abc->mutex = 0;

    while (1)
    {
        if (abc->mutex)
        {
            if (abc->text == -1)
            {
                break;
            }
            printf("Other one wrote: %i\n", abc->text);
            abc->mutex = 0;
            abc->text += 10;
            sleep(rand() % 4);
        }
    }

    if (shmdt(shared_memory) == -1)
    {
        printf("Detach failed\n");
        exit(EXIT_FAILURE);
    }

    if (shmctl(memID, IPC_RMID, 0) == -1)
    {
        printf("Destroy/ remove failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
