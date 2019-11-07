#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>

typedef struct $
{
    long int type;
    char text[BUFSIZ];
} mssgStruct;

#define MSSG_KEY 1028

int main(int argc, char const *argv[])
{
    int mssgID = msgget((key_t)MSSG_KEY, IPC_CREAT | 0666);
    if (mssgID == -1)
    {
        printf("Message get EERRRR!!\n");
        exit(EXIT_FAILURE);
    }
    mssgStruct recv;
    int rcvMssgType = 0;

    while (1)
    {
        char *buf = calloc(CHAR_MAX, sizeof(char));
        // printf("Size: %i\n", sizeof(buf));
        int status = msgrcv(mssgID, &recv, BUFSIZ, (long int)rcvMssgType, 0);
        strcpy(buf, recv.text);
        if (status == -1)
        {
            printf("Recieve ERRRRR\n");
            exit(EXIT_FAILURE);
        }
        else if (strncmp(buf, "end", 3) == 0)
            break;
        else
        {
            printf("Y!\n");
            // strcpy(buf, recv.text);
            printf("The sender wrote: %s\n", recv.text);
        }
    }

    if (msgctl(mssgID, IPC_RMID, 0) == -1)
    {
        printf("remove failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
