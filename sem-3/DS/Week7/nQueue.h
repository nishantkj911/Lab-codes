#include <string.h>
#define MAX 5

typedef struct $
{
	int front, rear, size;
	char item[MAX][50];
}queue;

void init(queue* ps)
{
	ps->rear = MAX - 1;
	ps->front = 0;
	ps->rear = 0;
}

int isFull(queue* ps)
{
	if(ps->size == MAX)
		return 1;
	else return 0;
}

int isEmpty(queue* ps)
{
	return ps->size == 0;
}

void enqueue(queue* ps, char x[])
{
	if(!isFull(ps))
	{
		int n;
		printf("Enter rear(1) or front(2): ");
		scanf("%d", &n);

		if(n==1)
		{
			ps->rear=(ps->rear+1) % MAX;
			strcpy(ps->item[ps->rear], x);
			ps->size++;
		}
	}
	else
	{
		ps->front = (MAX + ps->front) % MAX;
		strcpy(ps->item[ps->front], x);
		ps->size++;
	}
}

char* dequeue(queue* ps)
{
	if(isEmpty(ps))
		return 0;

	char* n = ps->item[ps->front];
	strcpy(ps->item[ps->front++], "");
	return n;
}

void display(queue* ps)
{
	int i = ps->front;
	int j = ps->rear;

	for(i; i != j; i = (i+1) % MAX)
		printf("%s\n", ps->item[i]);
}