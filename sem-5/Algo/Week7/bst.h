#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode
{
	int key;
	struct _treenode* lchild;
	struct _treenode* rchild;
	struct _treenode* parent;
} TreeNode;

typedef TreeNode* Tree;

void findOrInsert(Tree* root, int key)
{
	if(*root == NULL)
	{
		// printf("Empty tree. So inserting at (*root)\n");
		(*root) = (Tree) malloc(sizeof(TreeNode));
		(*root)->key = key;
		(*root)->lchild = (*root)->rchild = NULL;
		(*root)->parent = (*root);
		return;
	}

	// printf("The traversal...\n");
	Tree temp = (*root);
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			printf("Key repeated\n");
			return;
		}
		else if(key < temp->key)
		{
			// printf("Left\n");
			if(temp->lchild == NULL)
			{
				break;
			}
			temp = temp->lchild;
		}
		else
		{
			// printf("Right\n");
			if(temp->rchild == NULL)
				break;
			temp = temp->rchild;
		}
	}

	// printf("The key has not been found. So inserting it here\n");
	Tree temp2 = (Tree) malloc(sizeof(TreeNode));
	temp2->key = key;
	temp2->lchild = temp2->rchild = NULL;
	if(key < temp->key)
	{
		temp->lchild = temp2;
	}
	else
	{
		temp->rchild = temp2;
	}
	temp2->parent = temp;
	return;
}

void inorderTraversal(Tree ptr)
{
	if(ptr != NULL)
	{
		inorderTraversal(ptr->lchild);
		printf("%i ", ptr->key);
		inorderTraversal(ptr->rchild);
	}
}

void postorderTraversal(Tree ptr)
{
	if(ptr != NULL)
	{
		postorderTraversal(ptr->lchild);
		postorderTraversal(ptr->rchild);
		printf("%d  ", ptr->key);
	}
}

void preorderTraversal(Tree ptr)
{
	if(ptr != NULL)
	{
		printf("%d  ", ptr->key);
		preorderTraversal(ptr->lchild);
		preorderTraversal(ptr->rchild);
	}
}


Tree createTree()
{
	Tree bst = NULL;

	int key;
	printf("Keep entering nos or 'Ctrl+D' to exit\n");

	while(1)
	{
		int ret = scanf("%i", &key);
		if(ret == EOF)
		{

			break;
		}
		if(ret == 1)
		{
			findOrInsert(&bst, key);
		}
		else
		{
			// printf("res = %i\n", ret);
			printf("Enter proper input\n");
			scanf("%*[^\n]");
		}

	}
	return bst;
}

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

int findBalanceFactor(Tree bst)
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

/* Tree createBinaryTree()
{
	Tree t = NULL;

	
} */