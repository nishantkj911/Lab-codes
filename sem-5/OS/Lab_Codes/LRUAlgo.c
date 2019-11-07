#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int checkInFrames(int* frames, int pn, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(frames[i] == pn)
            return 1;
    }

    return 0; 
}

int findReplacementFrame(int* arr, int* frames, int n, int fs, int index)
{
    int max = INT_MIN, minI = INT_MAX;
    int dist;
    for(int i = 0; i < fs; i++)
    {
        if(frames[i] == -1)
            return i;

        dist = index;
        for(int j = index; j >= 0; j--)
        {
            if(arr[j] == frames[i])
            {
                dist = i - j;
                break;
            }
        }

        if(dist > max)
        {
            max = dist;
            minI = i;
        }
    }

    printf("max dist: %i\n", dist);
    return minI;    
}

void LRUAlgo(int *arr, int n, int fs)
{
    int *frames = calloc(fs, sizeof(int));
    // initFrames(&arr, fs);
    for (int i = 0; i < n; i++)
    {
        frames[i] = -1;
    }

    printArray(frames, fs);
    int ph = 0, pf = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkInFrames(frames, arr[i], fs))
        {
            printf("Page hit!!\n");
            ph++;
        }
        else
        {
            pf++;
            printf("Page fault occured for page %i\n", arr[i]);

            int replace = findReplacementFrame(arr, frames, n, fs, i);
            printf("replace %i\n", replace);
            frames[replace] = arr[i];

        }
            printArray(frames, fs);
    }

    printf("No. of page faults: %i\nNo. of page hits: %i\n", pf, ph);
}

int main(int argc, char const *argv[])
{
    printf("Input size\n");
    int n;
    scanf("%i", &n);

    printf("Frame size\n");
    int fs;
    scanf("%i", &fs);

    printf("Enter sequence\n");
    int *arr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    LRUAlgo(arr, n, fs);

    return 0;
}
