#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

int main()
{
	printf("Keep entering nos and 'q' to quit\n");

	sllptr list = NULL;

	char input[100];
	while(1)
	{
		fgets(input, 100, stdin);
		if(strcmp(input, "q\n") == 0)
			break;

		list = addElement(atoi(input), list);
	}

	printf("Printing the list\n");
	sllptr temp = list;
	while(!temp) 
	{
		printf("%i\t", temp->data);
		temp = temp->link;
	}
}