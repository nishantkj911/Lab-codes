#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NO_OF_BUCKETS 10

typedef int *HashTable;
void printHashTable(HashTable ht)
{
    printf("The hash table is\n");
    for (int i = 0; i < NO_OF_BUCKETS; i++)
    {
        ht[i] != INT_MAX ? printf("Bucket %i: %i\n", i, ht[i]) : printf("Bucket %i: Empty\n", i);
    }
    printf("\n");
}

int searchElement(HashTable ht, int key)
{
    printf("searching %i\n", key);
    if (ht[key % NO_OF_BUCKETS] == key)
    {
        printf("No. of successful comparisons: %i\n", 1);
        return 1;
    }

    int comp = 1;
    for (int i = key % NO_OF_BUCKETS + 1; (++comp) && i != key % NO_OF_BUCKETS; i = (i + 1) % NO_OF_BUCKETS)
        if (ht[i] == key)
        {
            printf("No. of successful comparisons: %i\n", comp);
            return 1;
        }

    printf("No. of unsuccessful comparisons: %i\n", comp);
    return 0;
}

void insertIntoHash(HashTable *Ht, int key)
{
    HashTable ht = *Ht;
    //compute hash fn
    int hashVal = key % NO_OF_BUCKETS;
    if (ht[hashVal] == INT_MAX)
    {
        ht[hashVal] = key;
        printf("Inserted %i\n", key);
        return;
    }
    else
    {
        // fprintf(stderr, "The hash value is taken. Cannot insert %i\n", key);
        //re entering value
        int i;
        for (i = (hashVal + 1) % NO_OF_BUCKETS; i != hashVal; i = (i + 1) % NO_OF_BUCKETS)
        {
            if (ht[i] == key)
            {
                printf("Do not enter duplicate values\n");
                return;
            }

            if (ht[i] == INT_MAX)
                break;
        }

        if (i == hashVal)
            printf("No more space left in the table\n");
        else
        {
            printf("Inserted %i\n", key);
            ht[i] = key;
        }
        //no space in table
    }
}

int main(int argc, char const *argv[])
{
    HashTable ht = calloc(NO_OF_BUCKETS, sizeof(int));
    for (int i = 0; i < NO_OF_BUCKETS; i++)
    {
        ht[i] = INT_MAX;
    }
    int temp;
    while (scanf("%i", &temp) != -1)
    {
        insertIntoHash(&ht, temp);
    }

    printHashTable(ht);

    printf("Any searches (1/0)?\n");
    int q;
    scanf("%i", &q);

    printf("Enter the element to search\n");
    // int q;
    scanf("%i", &q);

    printf("%s\n", searchElement(ht, q) ? "Element found" : "Element not found");

    return 0;
}
