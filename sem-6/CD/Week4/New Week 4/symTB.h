#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

typedef char *string;
struct $
{
	int index;
	string type;
	string retType;
	string name;
	char scope;
	int args_num;
	int *args;
	int size;
};

typedef struct $ tabCon;

tabCon *st;
int hashify(string name)
{
	int num = 1;
	int hash = 0;
	for (int i = 0; i < strlen(name); ++i)
	{
		hash = hash + name[i] * num;
		num++;
	}
	hash %= 101;
	return hash;
}

tabCon *init()
{
	tabCon *st = (tabCon *)calloc(101, sizeof(struct $));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		st[i].name = NULL;
		st[i].type = NULL;
		st[i].retType = NULL;
		st[i].scope = 'L';
	}

	return st;
}

tabCon *insert(tabCon *st, int i, string name, int size, string type, char scope, int args_num, int *args, string retType)
{

	st[i].name = calloc(strlen(name), sizeof(char));
	strcpy(st[i].name, name);
	st[i].type = calloc(strlen(type), sizeof(char));
	strcpy(st[i].type, type);
	st[i].retType = calloc(strlen(retType), sizeof(char));
	strcpy(st[i].retType, retType);
	st[i].scope = scope;
	st[i].size = size;

	st[i].args_num = args_num;
	st[i].args = calloc(args_num, sizeof(int));
	for (int j = 0; j < args_num; j++)
		st[i].args[j] = args[j];

	return st;
}

int toNum(char *arr)
{
	int rem = 0;
	for (size_t i = 0; i < strlen(arr); i++)
	{
		rem = rem * 10 + (arr[i] - '0');
	}
	return rem;
}

int search(tabCon *st, string name)
{
	int hash = hashify(name);

	for (int i = hash;; i = (i + 1) % MAX_SIZE)
	{
		if (st[i].name != NULL)
		{
			if (strcmp(st[i].name, name) == 0)
				return i;
		}
		else
		{
			return i;
		}
	}
}
void printST(tabCon *st)
{
	printf("The symbol Table is\n");
	for (int i = 0; i < 101; i++)
	{
		if (st[i].name != NULL)
		{
			printf("index: %d\tname: '%s'\ttype: %s\treturn Type: %s\tSize: %i\tScope: %c\tNo. of Args: %i%c", i, st[i].name, st[i].type, st[i].retType, st[i].size, st[i].scope, st[i].args_num, st[i].args_num > 0 ? '\t' : '\n');
			if (st[i].args_num > 0)
			{
				printf("Arguments (hash index): ");
				for (size_t j = 0; j < st[i].args_num; j++)
				{
					printf("%i ", st[i].args[j]);
				}
				printf("\n");
			}
		}
	}
}
