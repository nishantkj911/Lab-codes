#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

#define FIFO_NAME "flowThroughMe"

int main(int argc, char const *argv[])
{
    int res;
    if (access(FIFO_NAME, F_OK) == -1)
    {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0)
        {
            printf("Error in creating fifo\n");
            exit(EXIT_FAILURE);
        }
    }

    int arr[4];
    printf("Enter 4 integers\n");
    for (int i = 0; i < 4; i++)
    {
        scanf("%i", &arr[i]);
    }

    int opMode = O_WRONLY;
    int pipeFd = open(FIFO_NAME, opMode);

    int bytesSent = 0;
    if (pipeFd != -1)
    {
        while (bytesSent < sizeof(arr))
        {
            res = write(pipeFd, &arr, sizeof(arr));
            if (res == -1)
            {
                printf("Error writing\n");
                exit(EXIT_FAILURE);
            }
            bytesSent += sizeof(arr);
        }
        (void)close(pipeFd);
    }
    else
    {
        printf("Error opening the pipe\n");
        exit(EXIT_FAILURE);
    }

    printf("Process Finished %i\n", getpid());
    exit(EXIT_SUCCESS);
}