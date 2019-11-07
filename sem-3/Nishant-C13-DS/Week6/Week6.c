#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cQueue.h"
#include "dcQueue.h"

int main()
{
	while(1)
	{
		printf("Problem no. \n1. Circular queue\n2. Double Circular queue\n3. Quit\n");
		int ch;
		scanf("%d", &ch);
		
		//initialization
		char* input = malloc(sizeof(char) * 100);
		cqueue* q = malloc(sizeof(cqueue)); 
		int temp;
		dcq_p dq = malloc(sizeof(dcq));

		switch(ch)
		{
			case 1:
				q = init(q);
				printf("Keep entering nos. or 'q' to quit\n");
				while(1)
				{
					scanf("%s", input);
					if(strcmp(input, "q") == 0)
						break;
					temp = enqueue(atoi(input), q);
					if(!temp)
						break;
				}
				if(!temp)
					printf("Showing the existing circ. queue\n");
				else 
					printf("The queue is\n");
				display(q);

				printf("Enter the no of elements to dequeue: ");
				scanf("%i", &temp);

				temp = dequeue(temp, q);
				display(q);
				if(temp == 1)
					printf("Excess dequeue requested. Not possible\n");
				break;
			case 2:
				printf("Enter the no. of nos to be inputted\n");
				scanf("%i", &temp);

				for(int i=0, qno, val; i<temp; i++)
				{
					printf("Input the value to input: ");
					scanf("%i", &val);

					printf("Input the q to input to(1 or 2): ");
					scanf("%i", &qno);

					dcqenqueue(dq, val, qno);
				}

				dcqdisplay(*dq, 1);
				dcqdisplay(*dq, 2);

				break;
			case 3:
				return 0;
		}

	}
}
