#include <stdio.h>
#include <stdlib.h>

typedef struct _stack
{
	int key;
	struct _stack* next;
} Node;

typedef Node* Stack;

Stack pop(Stack st)
{
	// printf("Popping\n");
	if(st == NULL)
	{
		printf("Empty Stack\n");
		return NULL;
	}
	Stack temp = st;
	if(st->next != NULL)
	{
		st = st->next;
	}
	else
	{
		free(temp);
		return NULL;
	}

	free(temp);
	// return;
	return st;
}

int peek(Stack st)
{
	if(st != NULL)
	{
		return st->key;
	}
	else
	{
		return -1;
	}
}

Stack push(Stack st, int key)
{
	if(st == NULL)
	{
		// printf("Empty stack\n");
		st = (Stack) malloc(sizeof(Node));
		st->key = key;
		st->next = NULL;
		// return;
		return st;
	}

	// printf("pushing to existing stack\n");
	Stack temp = (Stack) malloc(sizeof(Node));
	temp->key = key;
	temp->next = st;
	st = temp;
	// return;
	return st;
}