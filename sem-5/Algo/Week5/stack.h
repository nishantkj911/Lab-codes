#include <stdio.h>
#include <stdlib.h>

typedef struct _stack
{
	int key;
	struct _stack* next;
} StackNode;

typedef StackNode* Stack;

Stack pop(Stack st)
{
	// printf("Popping\n");
	if(st == NULL)
	{
		printf("Empty Stack\n");
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
		st = (Stack) malloc(sizeof(StackNode));
		st->key = key;
		st->next = NULL;
		// return;
		return st;
	}

	// printf("pushing to existing stack\n");
	Stack temp = (Stack) malloc(sizeof(StackNode));
	temp->key = key;
	temp->next = st;
	st = temp;
	// return;
	return st;
}