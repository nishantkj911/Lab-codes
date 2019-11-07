#include "LongHead.h"

int main()
{ 
	long x,y,temp;
	node *head1=(node *)malloc(sizeof(node));
	head1->left=head1->right=head1;
	node *head2=(node *)malloc(sizeof(node));
	head2->left=head2->right=head2;
	node *head3=(node *)malloc(sizeof(node));
	head3->left=head3->right=head3;


	printf("Enter first number:");
	scanf("%ld",&x);
	temp=x;
	while(temp>0)
	{ 
		Insert(head1,temp%10);
		temp/=10;
	}

	printf("Enter second number:");
	scanf("%ld",&x);
	temp=x;
	while(temp>0)
	{
		Insert(head2,temp%10);
		temp/=10;
	}

	printf("\n");
	Add(head1,head2,head3);
	printf("  ");
	Display(head1);
	printf(" + ");
	Display(head2);
	printf(" = ");
	Display(head3);
 	printf("\n");
}
