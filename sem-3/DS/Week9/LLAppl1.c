#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UnionInters.h"
//#include "scll.h"

int main()
{
	scll* a = NULL, * b = NULL;
	char input[50];

	printf("Keep entering elements or 'q' to quit\n");

	printf("For List 1: \n");
	while(1)
	{
		
		scanf("%s", input);
		if(strcmp(input, "q") == 0)
			break;

		a = addel(a, atoi(input));
	}

	printf("The list 1 is\n");
	display(a);

	//List 2 input starts here
	printf("For List 2: \n");
	while(1)
	{
		
		scanf("%s", input);
		if(strcmp(input, "q") == 0)
			break;

		b = addel(b, atoi(input));
	}

	printf("The list 2 is\n");
	display(b);

	printf("Union(u) or Intersection(i) or Both(b): ");
	scanf(" ");
	scanf("%c", &input[0]);

	if(input[0] == 'u')
	{
		scll* c = unionll(a, b);
		printf("The Union of the two lists is\n");
		display(c);
	}
	else if(input[0] == 'i')
	{
		scll* c = inter(a, b);
		printf("The Intersection of the two lists is\n");
		display(c);
	}
	else if(input[0] == 'b')
	{
		scll* c = unionll(a, b);
		printf("The Union of the two lists is\n");
		display(c);

		c = inter(a, b);
		printf("The Intersection of the two lists is\n");
		display(c);
	}
}