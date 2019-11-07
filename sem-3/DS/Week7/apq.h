#define LEN 10
#define ERR 322848

typedef struct 
{
	int arr[LEN];
	int front, rear;
}deq;

deq* init(deq* q)
{
	q->front = q->rear = -1;
}

void insertFront(int val, deq* q)
{
	if(q->front == -1)
	{
		q->front = q->rear = LEN / 2;
		q->arr[q->front] = val;
		return;
	}

	if(q->front == 0)
	{
		printf("Cannot add in front anymore\n");
		return;
	}

	q->arr[--q->front] = val;

}

void insertRear(int val, deq* q)
{
	if(q->rear == -1)
	{
		q->front = q->rear = LEN / 2;
		q->arr[q->rear] = val;
		return;
	}

	if(q->rear == LEN-1)
	{
		printf("Cannot add at the back anymore\n");
		return;
	}

	q->arr[++q->rear] = val;
}

int pqMinDelete(deq* q)
{
	int j = q->front;
	for(int i=q->front + 1; i<=q->rear; i++)
	{
		if(q->arr[i] < q->arr[j])
			j=i;
	}

	int temp = q->arr[j]; 
	q->arr[j] = ERR;

	if(q->front == ERR)
	{
		q->front++;
	}

	if(q->rear == ERR)
	{
		q->rear++;
	}

	return temp;
}

void display(deq* q)
{
	if(q->front == -1) 
	{
		printf("Empty Queue\n");
		return;
	}

	printf("The queue is: \n");
	for(int i=q->front; i<=q->rear; i++)
	{
		if(q->arr[i] == ERR)
			continue;

		printf("%d\t", q->arr[i]);
	}
}