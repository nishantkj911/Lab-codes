#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}sllnode;

typedef sllnode* sllptr;

sllptr addNode(int val, sllptr head)
{
	printf("Adding %i\n", val);
	sllptr temp = head;
	while(temp)
	{
		printf("not null\n");
		temp = temp->link;
	}

	sllptr temp2 = malloc(sizeof(sllnode));
	temp2->data = val;
	temp2->link = NULL;
	printf("new node created\n");

	if(!head)
	{
		return temp2;
	}
	temp = temp2;

	printf("link adjusments done\n");
	return head;
}

void display(sllptr head)
{
	sllptr temp = head;
	while(temp != NULL)
	{
		printf("%i\t", temp->data);
	}
}

void insertNext(sllptr prev, int val)
{
	sllptr temp = malloc(sizeof(sllnode));
	temp->link = prev->link;
	prev->link = temp;
}

void combineLists(sllptr list1, sllptr list2)
{
	sllptr temp1 = list1, temp2 = list2;

	while(temp1 != NULL && temp2 != NULL)
	{
		insertNext(temp1, temp2->data);

		temp1 = temp1->link->link;
		temp2 = temp2->link;
	}

}

