#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apq.h"

int main()
{
	//initialization
	deq* que = malloc(sizeof(que));
	int a;
	que = init(que);
	printf("Enter the no of nos. to be entered\n");
	scanf("%d", &a);

	for(int i=0, val, q; i<a; i++)
	{
		printf("Enter the value to enter into queue: ");
		scanf("%d", &val);
		printf("Enter -1 or 1 for front or rear resp.: ");
		scanf("%d", &q);

		switch(q)
		{
			case -1:
				insertFront(val, que);
				break;
			case 1:
				insertRear(val, que);
				break;
			default:
				printf("Invalid queue location\n");
				i--;
		}
	}

	display(que);

	printf("Enter the no of nos. to be remove\n");
	scanf("%d", &a);

	for(int i=0; i<a; i++)
	{
		pqMinDelete(que);
	}

	display(que);

}