#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode
{
	int key;
	struct _treenode* lchild;
	struct _treenode* rchild;
} TreeNode;

typedef TreeNode* Tree;

Tree findOrInsert(Tree root, int key)
{
	if(root == NULL)
	{
		// printf("Empty tree. So inserting at root\n");
		root = (Tree) malloc(sizeof(TreeNode));
		root->key = key;
		root->lchild = root->rchild = NULL;
		return root;
	}

	// printf("The traversal...\n");
	Tree temp = root;
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			printf("Key repeated\n");
			return root;
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
	return root;
}

void inorderTraversal(Tree ptr)
{
	if(ptr != NULL)
	{
		inorderTraversal(ptr->lchild);
		printf("%d  ", ptr->key);
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
			bst = findOrInsert(bst, key);
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

/* Tree createBinaryTree()
{
	Tree t = NULL;

	
} */