#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "TreeAppl1.h"
	
int main()
{
	printf("Keep entering nos and 'q' to quit\n");

	NODE* binTree1 = NULL;

	char input[100];
	printf("For Tree 1\n");
	while(1)
	{
		fgets(input, 100, stdin);
		if(strcmp(input, "q\n") == 0)
			break;

		binTree1 = addToTree(atoi(input), binTree1);
		
	}

	printf("\nLevel Order for 1\n");
	levelOrder(binTree1);

	/*treeptr binTree2 = copyTree(binTree1);
	printf("\nLevel Order for 2\n");
	levelOrder(binTree2);*/
/*
	printf("\nRightmost Visible\n");
	rightmostVisible(binTree2);
*/

/*	printf("\nMax depth of the tree is %i\n", maxDepth(binTree2));
	printf("No of nodes in  the tree are %i\n", noOfNodes(binTree2));
*/
	/*printf("\nThe boundary of the tree is\n");
	printBoundary(binTree1);*/

//	printf("\nThey are in %i no \n", num);

/*	if(identicalTrees(binTree2, binTree1))
		printf("\nThey are identical\n");
	else
		printf("\nThey are not identical\n");
*/

	printf("\nFreeing Tree\n");
	freeTree(binTree1);


/*
	int num1, num2;
	printf("\nEnter 2 values to compare: \n");
	scanf("%i %i", &num1, &num2);

	if(checkSiblings(num1, num2, binTree1))
		printf("They are siblings\n");
	else
		printf("They are not siblings\n");
*/

}
