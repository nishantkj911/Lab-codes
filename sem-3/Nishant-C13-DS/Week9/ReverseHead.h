#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
	char data[20];
	struct NODE * left,*right;
}node;

void Insert(node **Left,node **Right,char *x)
{ 
	node *temp=(node *)malloc(sizeof(node));
		strcpy(temp->data,x);
		if(*Right==NULL)
		{ 
			// printf("First\n");
			temp->left=temp->right=NULL;
			*Right=*Left=temp;
		}
		else
		{ 	
			// printf("Second\n");
				temp->right=NULL;
				temp->left=*Right;
				(*Right)->right=temp;
				*Right=temp;
		}
}

void Display(node **list)
{ 
	for(node *temp=*list;temp!=NULL;temp=temp->right)
		printf("%s\t",temp->data);
	printf("\n");
}

void Reverse(node **Left,node **Right)
{ 
	node *temp2;
		for(node *temp=(*Right);temp!=NULL;temp=temp->right)
		{	 
			temp2=temp->right;
			temp->right=temp->left;
			temp->left=temp2;
		}
		temp2=*Left;
		*Left=*Right;
		*Right=temp2;
}
