#include "ReverseHead.h"

int main()
{ 
	node *front=NULL,*rear=NULL;
		int no;
		char x[20];

		printf("Enter the no. of strings  to enter\n");
		scanf("%d", &no);

		for(int i=0; i<no; i++)
		{
			printf("Enter element: ");
			scanf("%s",x);
		Insert(&front,&rear,x);
		}
		Display(&front);

	printf("Reversing\n");
	Reverse(&front,&rear);
	printf("Reversed Array is\n");

	Display(&front);
}
