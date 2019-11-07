#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int fcfsDisk(int *arr, int currPtr, int n)
{
    int noOfDiskMovements = 0;

    for (int i = 0; i < n; i++)
    {
        int n = arr[i] - currPtr;
        if (n < 0)
            n = -n;
        noOfDiskMovements += n;
        currPtr = arr[i];
    }

    return noOfDiskMovements;
}

int SSTFAlgo(int *arr, int currPtr, int n)
{
    printf("At %i\n", currPtr);
    int *finish = calloc(n, sizeof(int));
    int noOfDiskMovements = 0;
    for (int j = 0; j < n; j++)
    {
        int min = INT_MAX, minDist = INT_MAX;
        // finding shortest dist from currPtr
        for (int i = 0; i < n; i++)
        {
            int curDist = arr[i] - currPtr;
            if (curDist < 0)
                curDist = -curDist;

            // printf("Current distance from %i to %i is %i\n", currPtr, arr[i], curDist);

            if (!finish[i] && curDist < minDist)
            {
                // printf("Found new min at %i\n", arr[i]);
                min = i;
                minDist = curDist;
            }
        }

        // printf("Attending %i and adding %i\n", arr[min], minDist);
        noOfDiskMovements += minDist;
        finish[min] = 1;
        currPtr = arr[min];
    }

    return noOfDiskMovements;
}

int checkAllFinished(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!arr[i])
            return 0;
    }

    return 1;
}

int arrContains(int *arr, int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            printf("%i is contained\n", a);
            return i;
        }
    }

    return -1;
}

int SCANAlgo(int *arr, int currPtr, int n)
{
    int noOfDiskMovements = 0;
    int direction = -1;
    int *finish = calloc(n, sizeof(int));
    printf("hello\n");
    while (!checkAllFinished(finish, n))
    {
        int tempCurr = currPtr;
        while (1)
        {
            if (direction == -1)
            {
                tempCurr--;
                printf("decrementing\n");
            }
            else
            {
                tempCurr++;
                printf("incrementing\n");
            }

            if (tempCurr == 200
            )
                return noOfDiskMovements;
            if (tempCurr == 0)
            {
                printf("changed direction\n");
                direction = 1;
            }
            int index = arrContains(arr, n, tempCurr);
            if (index != -1 && !finish[index])
            {
                printf("Attending %i\n", tempCurr);
                int dist = currPtr - tempCurr;
                if (dist < 0)
                    dist = -dist;

                noOfDiskMovements += dist;
                currPtr = tempCurr;
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("No of disk requests\n");
    int n;
    scanf("%i", &n);

    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Where is the pointer now?\n");
    int ptr;
    scanf("%i", &ptr);

    int dm = fcfsDisk(arr, ptr, n);
    printf("\nFCFS\nNo. of disk movements are: %i\n", dm);

    dm = SSTFAlgo(arr, ptr, n);
    printf("\nSSTF\nNo. of disk movements are: %i\n", dm);

    dm = SCANAlgo(arr, ptr, n);
    printf("\nSCAN\nNo. of disk movements are: %i\n", dm);
    return 0;
}
