typedef struct _node
{
	char data;
	struct _node* link;
}nodec;

nodec* eq(nodec* front)
{
	nodec* rear = front;
	for(; rear!= NULL; rear = rear->link)

	printf("Enter non-repeating sorted characters. To exit '0'\n");
	while(1)
	{
		nodec* ne;
		char x;
		scanf("%c", &x);
		if(x == '0')
			break;

		ne = malloc(sizeof(nodec));
		ne->data = x;
		ne->link = NULL;

		if(front == NULL) 
		{
			front = ne;
			rear = ne;
		}
		else 
		{
			rear->link = ne;
			rear = rear->link;
		}
	}

	return front;
}

