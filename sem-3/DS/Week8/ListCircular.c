#include <stdio.h>
#include <stdlib.h>
#include "nodec.h"
#include "nodeq.h"

int main()
{
	nodec * front1 = NULL, *front2 = NULL;
	node* q;

	printf("For Queue 1\n");
	front1 = eq(front1);
	printf("For Queue 2\n");
	front2 = eq(front2);

	nodec* temp1 = front1;
	nodec* temp2 = front2;

	int firstover1 = 0, firstover2 = 0;
	do
	{
		if(temp1->data < temp2->data)
		{
			printf("Adding element q1 ..%c..\n", temp1->data);
			q = enqueue(q, temp1->data);
			temp1 = temp1->link;

			firstover1 = 1;
		}
		else
		{
			printf("Adding element q2 ..%c..\n", temp2->data);
			q = enqueue(q, temp2->data);
			temp2 = temp2->link;

			firstover2 = 1;
		}
	}while(temp1->data != front1->data || temp2->data != front2->data && (firstover2 == 1 && firstover1 == 1));

	printf("adding rem. elements of q1\n");
	while(temp1->data != front1->data)
	{
		printf("Adding element q1 ..%c..\n", temp1->data);
		q = enqueue(q, temp1->data);
		temp1 = temp1->link;
	}

	printf("adding rem. elements of q2\n");
	while(temp2->data != front2->data)
	{
		printf("Adding element q2 ..%c..\n", temp2->data);
		q = enqueue(q, temp2->data);
		temp2 = temp2->link;
	}

	printf("The new q is: ");
	display(q);

}