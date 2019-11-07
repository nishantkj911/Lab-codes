typedef struct node
{
	int data;
	struct node* link;	
}sllnode;

typedef sllnode* sllptr;

sllptr addElement(int val, sllptr list)
{
	if(!list) 
	{
		printf("adding to null\n");
		list = malloc(sizeof(sllnode));
		list->data = val;
		list->link = NULL;

		return list;
	}


	printf("Adding to existing\n");
	sllptr temp = list;
	while(!temp)
		temp = temp->link;

	temp->link = malloc(sizeof(sllnode));
	temp = temp->link;

	temp->data = val;
	temp->link = NULL;

	return list;
}