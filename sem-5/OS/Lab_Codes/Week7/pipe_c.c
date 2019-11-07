#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

#define FIFO_NAME "flowThroughMe"

int main(int argc, char const *argv[])
{
    int openMode = O_RDONLY;
    int pipeFd = open(FIFO_NAME, openMode);

    int buf;
    if (pipeFd == -1)
    {
        printf("Opening failure\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (read(pipeFd, &buf, sizeof(int)) > 0)
            printf("Value: %i\n", buf);
        (void)close(pipeFd);
    }

    exit(EXIT_SUCCESS);
}
