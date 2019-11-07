#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* next;
	struct node* prev;
} Node;

typedef Node* queue;

typedef struct _que
{
	queue first, last;
	queue list;
} Queue;

Queue enqueue(Queue q, int key)
{
	if(q.list == NULL)
	{
		// printf("Empty Queue\n");
		q.list = malloc(sizeof(Node));
		q.list->key = key;
		q.list->next = q.list->prev = NULL;
		q.first = q.list;
		q.last = q.list;
		return q;
	}

	queue temp = malloc(sizeof(Node));
	temp->key = key;
	q.last->next = temp;
	temp->prev = q.last;
	q.last = temp;
	return q;
}

void printQ(Queue q)
{
	for (queue temp = q.first; temp != NULL; temp = temp->next)
	{
		printf("%i ", temp->key);
	}
	printf("\n");
}

Queue dequeue(Queue q)
{
	if(q.list == NULL)
	{
		fprintf(stderr, "%s\n", "Queue is empty");
		return q;
	}

	if(q.first == q.last)
	{
		queue temp = q.first;
		q.first = q.last = q.list = NULL;
		free(temp);
		return q;
	}
	queue temp = q.first;
	q.first = q.first->next;
	free(temp);
	q.first->prev = NULL;

	return q;
}

int peek(Queue q)
{
	return q.first->key;
}

Queue initQ()
{
	Queue q;
	q.last = q.first = q.list = NULL;
	return q;
}