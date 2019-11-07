#include "bst.h"

/*int findBalanceFactor(Tree bst)
{
	return height(bst->lchild) - height(bst->rchild);
}

void inOrderBalanceFactor(Tree bst)
{
	if(bst == NULL)
		return;

	inOrderBalanceFactor(bst->lchild);
	int bf = findBalanceFactor(bst);
	printf("Balance factor for node with value %i is %i\n", bst->key, bf);
	inOrderBalanceFactor(bst->rchild);
	// return bf;

}
*/
int main(int argc, char const *argv[])
{
	Tree bst = createTree();

	// printf("Balance factor for tree with root %i is %i\n", bst->key, findBalanceFactor(bst));
	inOrderBalanceFactor(bst);
	return 0;
}