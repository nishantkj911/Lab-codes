#include "sll.h"
#include <string.h>

int main()
{
	printf("Keep entering nos and 'q' to exit\n");

	sllptr list1 = NULL;

	char input[100];
	while(1)
	{
		fgets(input, 100, stdin);
		if(strcmp(input, "q\n") == 0)
			break;

	list1 = addNode(atoi(input), list1);
	// display(list1);
		
	}

	sllptr list2 = NULL;

	while(1)
	{
		fgets(input, 100, stdin);
		if(strcmp(input, "q\n") == 0)
			break;

	list2 = addNode(atoi(input), list2);
	// display(list1);
		
	}

	combineLists(list1, list2);

	display(list1);
}