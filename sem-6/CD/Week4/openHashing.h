#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define X 31
#define BIGPRIME 1000000007
#define BUCKET_SIZE 10

long calcHash(char *str)
{
    int len = strlen(str);
    long hashValue = 0;
    for (int i = 0; i < len; i++)
    {
        hashValue = ((hashValue * X + str[i])) % BIGPRIME;
    }

    return hashValue;
}

typedef struct a
{
    char *idName;
    int index;
    struct a *next;
} HashNode;

typedef HashNode *HashPtr;
typedef HashPtr *HashTable;

int ind = 0;
HashTable st = NULL;
void initHT()
{
    st = (HashTable)calloc(BUCKET_SIZE, sizeof(HashPtr));
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        st[i] = NULL;
    }
}

void printHT(HashTable st)
{
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        printf("Bucket: %i", i);
        if (st[i] != NULL)
        {
            for (HashPtr j = st[i]; j != NULL; j = j->next)
            {
                printf("---->%s", j->idName);
            }
            printf("\n");
        }
        else
        {
            printf("---->\n");
        }
    }
}

int findInHT(char *str, int *bucket)
{
    long hashValue = calcHash(str);
    int hash = hashValue % BUCKET_SIZE;
    *bucket = hash;
    for (HashPtr i = st[hash]; i != NULL; i = i->next)
    {
        if (strcmp(i->idName, str) == 0)
        {
            return i->index;
        }
    }

    return -1;
}

int manageID(char *str)
{
    int bucketNo, i;
    i = findInHT(str, &bucketNo);
    if (i != -1)
    {
        // printf("ID already added\n");
        return i;
    }

    if (st[bucketNo] != NULL)
    {
        HashPtr temp = (HashPtr)malloc(sizeof(HashNode));
        temp->next = st[bucketNo];
        st[bucketNo] = temp;
        temp->idName = (char *)calloc(strlen(str), sizeof(char));
        strcpy(temp->idName, str);
    }
    else
    {
        st[bucketNo] = (HashPtr)malloc(sizeof(HashNode));
        st[bucketNo]->next = NULL;
        st[bucketNo]->idName = (char *)calloc(strlen(str), sizeof(char));
        strcpy(st[bucketNo]->idName, str);
    }

    return ind;
    // printf("Added to bucket %i\n", bucketNo);
}
