#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{ 
  int data;
  struct NODE *left,*right;
}node;

void Insert(node *head, int x)
{ 
	node *temp=(node *)malloc(sizeof(node));
  	temp->data=x;
  	if(head->left==head)
   	{ 
   		head->right=head->left=temp;
    	temp->left=temp->right=head;
	}	
  	else 
   	{ 
   		temp->right=head->right;
    	head->right->left=temp;
     	head->right=temp;
     	temp->left=head;
   	}
}

void Display(node *head)
{ 
	for(node *temp=head->right;temp!=head;temp=temp->right)
   	printf("%d",temp->data);

}

void Add(node *one,node *two,node *res)
{ 
	int c=0,sum;
	node *temp1=one->left;
	node *temp2=two->left;

	while(temp1!=one && temp2!=two)
	{ 
		sum=temp1->data+temp2->data+c;
		c=0;
		if(sum>9)
		c=1;
		Insert(res,sum%10);
		temp1=temp1->left;
		temp2=temp2->left;
	}

	if(temp1==one && temp2==two && c==1)
		Insert(res,1);
	for(;temp1!=one;temp1=temp1->left)
	{ 
		Insert(res,temp1->data+c);
		c=0;
	}

	for(;temp2!=two;temp2=temp2->left)
	{ 
		Insert(res,temp2->data+c);
		c=0;
	}  
}
