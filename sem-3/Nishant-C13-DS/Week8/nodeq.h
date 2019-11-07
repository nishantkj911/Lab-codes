typedef struct node
{
	char data;
	struct node* link;
}node;

node* enqueue(node* front, char x)
{
	node* a, * temp;
	a = malloc(sizeof(node));
	a->link = NULL;
	a->data = x;

	if(front == NULL)
		return a;

	temp = front;
	while(temp->link != NULL)
	{
		temp = temp->link;
	}

	temp->link = a;

	return front;
}

node* dequeue(node* front)
{
	node* temp;
	char d;
	if(front == NULL)
	{
		printf("Empty\n");
		return front;
	}

	d = front->data;
	printf("Dequeued element is %c\n", d);
	front = front->link;
	return front;
}

void display(node* front)
{
	if(front==NULL) {
		printf("Empty Queue\n");
		return;
	}

	node* temp = front;

	while(temp!=NULL)
	{
		printf("%c\t", temp->data);
		temp = temp->link;
	}
}

