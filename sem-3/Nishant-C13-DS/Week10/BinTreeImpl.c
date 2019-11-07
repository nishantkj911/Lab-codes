#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

int main()
{
	char lr;
	int inp;

	NODE* bintree = NULL;
	while (1)
	{
		printf("Enter a number or '0' to quit\n");
		scanf("%i", &inp);

		if(inp == 0)
			break;

		bintree = create(bintree, inp);
	}

	printf("\nINORDER\n");
	inorder(bintree);
	
	printf("\nPREORDER\n");
	preorder(bintree);
	
	printf("\nPOSTORDER\n");
	postorder(bintree);

	printf("\nITERATIVE INORDER\n");
	iterInorder(bintree);

	printf("\nITERATIVE PREORDER\n");
	iterPreorder(bintree);

	printf("\nITERATIVE POSTORDER\n");
	iterPostorder(bintree);

	printf("\n");

}