#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

typedef struct $
{
    long int type;
    char text[BUFSIZ];
} mssgStruct;

#define MSSG_KEY 1028

//sender
int main(int argc, char const *argv[])
{
    char buf[BUFSIZ];
    int mssgId = msgget((key_t)MSSG_KEY, IPC_CREAT | 0666);
    mssgStruct send;
    if (mssgId == -1)
    {
        printf("Message ID creation ERRRRR!!\n");
        exit(EXIT_FAILURE);
    }

    int running = 1;
    printf("Enter text or 'end' to exit\n");
    while (1)
    {
        scanf("%[^\n]%*c", buf);
        // int len = strlen(buf);

        // printf("Length: %i\n", len);
        send.type = 1;
        strcpy(send.text, buf);

        // printf("Send text: %s\n", send.text);
        int status = msgsnd(mssgId, &send, BUFSIZ, 0);
        if (status == -1)
        {
            printf("Sending error\n");
            exit(EXIT_FAILURE);
        }
        if (strncmp(buf, "end", 3) == 0)
            break;
    }

    printf("Message(s) sent successfully\n");
    exit(EXIT_SUCCESS);
}
