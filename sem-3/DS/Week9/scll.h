typedef struct _node
{
	int data;
	struct _node* link;
}scll;

scll* addel(scll* entry, int val)
{
	if(entry == NULL)
	{
		scll* temp = malloc(sizeof(scll));
		temp->data = val;
		entry = temp; 
		entry->link = entry;

		// printf("Queue created with element %d\n", temp->data);
		return entry;
	}
	scll* temp = malloc(sizeof(scll));
	temp->data = val;

	temp->link = entry->link;
	entry->link = temp;
	entry = temp;

	// printf("Element %d added\n", temp->data);
	return entry;
}

void display(scll* entry)
{
	if(entry == NULL)
	{
		printf("Empty circular linked list\n");
		return;
	}

	scll* temp = entry;

	do
	{
		printf("%d\t", temp->data);
		temp = temp->link;
	}while(temp->data != entry->data);

	printf("\n");
}