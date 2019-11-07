#include "bst.h"

int findNoOfNodes(Tree bst)
{
	// static int i=0;
	if(bst == NULL)
	{
		// i++;
		return 0;
	}
	else
	{
		/*i+=2;
		printf("i = %i\n", i);*/
		return findNoOfNodes(bst->lchild) + findNoOfNodes(bst->rchild) + 1;
	}	
}

int main(int argc, char const *argv[])
{
	Tree bst = createTree();

	int noOfNodes = findNoOfNodes(bst);
	printf("The no of nodes in the tree is %i\n", noOfNodes);
	scanf("%i", &bst);
	return 0;
}