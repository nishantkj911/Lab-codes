#include <stdio.h>
#include <stdlib.h>

typedef struct abc
{
	int key;
	struct abc* next;
} HashNode;
typedef HashNode* HashPtr;
typedef HashPtr* HashTable;

#define NO_OF_BUCKETS 13

void insertIntoTable(HashTable* Ht, int key)
{
	HashTable ht = *Ht;

	int index = key % NO_OF_BUCKETS;

	if(ht[index] == NULL)
	{
		ht[index] = (HashPtr) malloc(sizeof(HashNode));
		ht[index]->key = key;
		ht[index]->next = NULL;
		return;
	}

	HashPtr temp = (HashPtr) malloc(sizeof(HashNode));
	temp->key = key;
	temp->next = ht[index];
	ht[index] = temp;

}

void printHashTable(HashTable ht)
{
	for (int i = 0; i < NO_OF_BUCKETS; ++i)
	{
		if (ht[i] == NULL)
		{
			printf("No elements in  bucket %i\n", i);
			continue;
		}
		printf("For bucket %i the elements are: ", i);
		for(HashPtr temp = ht[i]; temp != NULL; temp = temp->next)
			printf("%i ", temp->key);
		printf("\n");
	}
}

int searchInHashTable(HashTable ht, int key)
{
	int hashValue = key % NO_OF_BUCKETS;

	int comp = 0;
	for(HashPtr temp = ht[hashValue]; temp != NULL; temp = temp->next)
		if((++comp) && temp->key == key) 
		{
			printf("No of key comparisons for successful is %i\n", comp);
			return 1;
		}

	printf("No of key comparisons for unsuccessful is %i\n", comp);
	return 0;
}

int main(int argc, char const *argv[])
{
	HashTable ht = (HashTable) calloc(NO_OF_BUCKETS, sizeof(HashPtr));

	for (int i = 0; i < NO_OF_BUCKETS; ++i)
	{
		ht[i] = NULL;
	}

	printf("Keep entering nos. or 'Ctrl + D' to exit\n");
	int temp;
	while(scanf("%i", &temp) != -1)
	{
		insertIntoTable(&ht, temp);

	}

	printHashTable(ht);

	printf("Enter something to search\n");
	scanf("%i", &temp);

	char* str = searchInHashTable(ht, temp) ? "Key found" : "Key Not found";
	printf("%s\n", str);
	return 0;
}