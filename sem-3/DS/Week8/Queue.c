#include <stdio.h>
#include <stdlib.h>
#include "nodeq.h"

int main()
{
	node* front, *rear;
	front = NULL;
	//this is a dummy var not to be cared for
	char* sldk;
	int ch;
	while(1)
	{
		printf("Choose an option\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
		scanf("%d", &ch);
		scanf("%c", sldk);
		if(ch==1)
		{
			char x;
			printf("Input Number\n");
			scanf("%c", &x);
			front = enqueue(front, x);
		}

		else if(ch==2)
			front = dequeue(front);
		else if (ch==3)
			display(front);
		else return 0;
	}
}
