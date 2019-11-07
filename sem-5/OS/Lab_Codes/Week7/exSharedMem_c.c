#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <string.h>

#define MEM_KEY 10182

typedef struct $
{
    int mutex;
    char text;
} shmStruct;

int main(int argc, char const *argv[])
{
    int memID = shmget((key_t)MEM_KEY, sizeof(shmStruct), IPC_CREAT | 0666);
    if (memID == -1)
    {
        printf("Memory getting failed\n");
        exit(EXIT_FAILURE);
    }
    void *memLoc = (void *)0;
    shmStruct *foo;

    memLoc = shmat(memID, (void *)0, 0);
    if (memLoc == (void *)-1)
    {
        printf("Memory attach failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Memory attached to %X\n", (int)memLoc);
    foo = (shmStruct *)memLoc;
    foo->mutex = 1;

    int buf;
    while (1)
    {
        while (foo->mutex)
        {
            sleep(1);
            // printf("Waiting for other process\n");
        }

        printf("Enter numbers\n");
        scanf("%i", &buf);
        foo->text = buf;
        foo->mutex = 1;
        if (buf == -1)
            break;
    }
    if (shmdt(memLoc) == -1)
    {
        printf("Detach error\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
