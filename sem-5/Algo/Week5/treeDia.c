#include "bst.h"

int height (Tree bst)
{
	if(bst == NULL)
		return 0;

	if(bst->lchild == NULL && bst->rchild == NULL)
	{
		return 1;
	}

	int lHeight = -1, rHeight = -1;
	if (bst->lchild != NULL)
	{
		lHeight = height(bst->lchild);
	}

	if (bst->rchild != NULL)
	{
		rHeight = height(bst->rchild);
	}

	int height = rHeight > lHeight ? rHeight : lHeight;
	return ++height;

}

int diameter(Tree bst)
{
	if(bst == NULL)
		return 0;

	if(bst->lchild == NULL && bst->rchild == NULL)
		return 1;

	// printf("finding dia for %i\n", bst->key);
	int a = diameter(bst->lchild);
	int b = diameter(bst->rchild);
	int c = height(bst->lchild) + height(bst->rchild) + 1;
	
	if(a > b && a > c)
		return a;
	else if(b > a && b > c)
		return b;
	else
		return c;
}

int main(int argc, char const *argv[])
{
	Tree bst = createTree();

	printf("The diameter of the tree is %i\n", diameter(bst));
	return 0;
}