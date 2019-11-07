#include <stdio.h>
#include <stdlib.h>

typedef struct _btree
{
	int key;
	struct _btree* lchild;
	struct _btree* rchild;
} BinaryNode;

typedef BinaryNode* Tree;

int countLeafNodes(Tree root)
{
	static int count =0;
	if(root == NULL)
	{
		return count;
	}

	if(root->lchild == NULL && root->rchild == NULL)
	{
		return ++count;
	}

	if (root->lchild != NULL)
	{
		count = countLeafNodes(root->lchild);
	}

	if (root->rchild != NULL)
	{
		count = countLeafNodes(root->rchild);
	}

	return count;
}

int countNonLeafNodes(Tree root)
{
	static int count =0;
	if(root == NULL)
	{
		return count;
	}

	if(root->lchild == NULL && root->rchild == NULL)
	{
		return count;
	}

	++count;
	if (root->lchild != NULL)
	{
		count = countNonLeafNodes(root->lchild);
	}

	if (root->rchild != NULL)
	{
		count = countNonLeafNodes(root->rchild);
	}

	return count;
}

Tree createTree(Tree root, int key)
{
	if(root == NULL)
	{
		root = (Tree) malloc(sizeof(BinaryNode));
		root->key = key;
		root->lchild = root->rchild = NULL;
		return root;
	}

	if(key < root->key)
	{
		root->lchild = createTree(root->lchild, key);
	}
	else if(key > root->key)
	{
		root->rchild = createTree(root->rchild, key);
	}
	else
	{
		printf("do not repeat nodes\n");
		return root;
	}

	return root;
}

void inoder(Tree root)
{
	if(root == NULL)
	{
		return;
	}

	inoder(root->lchild);
	printf("%i ", root->key);
	inoder(root->rchild);
} 	

int main(int argc, char const *argv[])
{
	Tree btree = NULL;
	int temp = 0;
	printf("Keep entering nodes or press 'Ctrl + D' to exit\n");
	while(1)
	{
		int res = scanf("%i", &temp);

		if(res == EOF)
		{
			break;
		}

		if(res != 1)
		{
			printf("Please enter proper input\n");
			continue;
		}

		btree = createTree(btree, temp);
	}

	/*inoder(btree);
	printf("\n");*/
	printf("The no. of leaf nodes are %i\n", countLeafNodes(btree));
	printf("The no. of non-leaf nodes are %i\n", countNonLeafNodes(btree));
	return 0;
}

