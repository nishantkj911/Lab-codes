#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addToHeap(int** Arr, int index, int key)
{

    int* arr = *Arr;

    printf("Inserting %i at index %i\n", key, index);
    arr[index] = key;
    if(index == 1)
        return;
    int temp = index;

    while(arr[temp / 2] < arr[temp] && temp > 1)
    {
        // printf("\tWorking on node %i with value %i\n", temp, arr[temp]);
        int swap1 = temp;
        if(temp % 2 == 1)
        {
            // swap1 = arr[temp-1] > arr[temp] ? temp-1 : temp;
            if(arr[temp-1] > arr[temp])
                swap1 = temp-1;
        }

        // printf("\tSwapped %i with index %i and %i with index %i\n", arr[swap1], swap1, arr[temp / 2], temp / 2);
        swap(&arr[swap1], &arr[temp / 2]);

        temp/=2;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no. of elements\n");
    scanf("%i", &n);

    int* arr = (int*) calloc(n+1, sizeof(int));
    printf("Enter the array\n");
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%i", &temp);
        addToHeap(&arr, i, temp);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i+1]); 
    }
    printf("\n");
    return 0;
}
