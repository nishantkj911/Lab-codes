#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define X 31
#define BIGPRIME 1000000007
#define BUCKET_SIZE 100

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
    char *idType; //function, variable or array
    size_t size;
    long hashValue;
    char *returnType;
    char scope;
} HashNode;

typedef HashNode *SymbolTable;

int ind = 0, noOfBuckets = 1;
SymbolTable st = NULL;
void initHT()
{
    st = (SymbolTable)calloc(noOfBuckets, sizeof(HashNode));
}

void printHT(SymbolTable st)
{
    for (int i = 0; i < ind; i++)
    {
        printf("ID: %s, index: %i, HashValue: %li, Type: %s, Size: %lu, Return Type: %s\n", st[i].idName, st[i].index, st[i].hashValue, st[i].idType, st[i].size, st[i].returnType);
    }
}

size_t toNumber(char *str)
{
    size_t x = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            x = x * 10 + (int)(str[i] - '0');
        }
    }

    return x;
}

int findInHT(char *str, long *bucket)
{
    long hashValue = calcHash(str);
    *bucket = hashValue;
    for (int i = 0; i < ind; i++)
    {
        if (hashValue == st[i].hashValue && strcmp(str, st[i].idName) == 0)
        {
            return st[i].index;
        }
    }

    return -1;
}

void manageID(char *str, int *index, char *idType, size_t size, char *returnType)
{
    long hashVal;
    int i;
    i = findInHT(str, &hashVal);
    if (i != -1)
    {
        // printf("ID %s already added\n", str);
        *index = i;
        return;
    }

    // printf("The identifier '%s' doesn't exist in the symbol Table\n", str);
    if (ind == noOfBuckets)
    {
        st = (SymbolTable)realloc(st, sizeof(HashNode) * 2 * noOfBuckets);
        noOfBuckets *= 2;
    }

    st[ind].index = ind;
    st[ind].hashValue = hashVal;
    st[ind].returnType = calloc(strlen(returnType), sizeof(char));
    st[ind].idName = (char *)calloc(strlen(str), sizeof(char));
    strcpy(st[ind].idName, str);
    st[ind].idType = (char *)calloc(strlen(idType), sizeof(char));
    strcpy(st[ind].idType, idType);
    if (strcmp(idType, "array") == 0)
    {
        st[ind].size = size;
    }
    else if (strcmp(idType, "function") == 0)
    {
        strcpy(st[ind].returnType, returnType);
    }
    *index = ind++;
}