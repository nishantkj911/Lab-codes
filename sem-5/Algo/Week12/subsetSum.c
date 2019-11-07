#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
} TreeNode;

typedef TreeNode* Tree;

void findSoln(Tree t)
{
	if(t->parent != t)
	{
		if(t->key - t->parent->key != 0)
			printf("%i ",  t->key - t->parent->key);
		findSoln(t->parent);
	}
}

void preorderTraversal(Tree t, int d)
{
	if(t == NULL)
	{
		// printf("Null\n");
		return;
	}

	if(t->key == d)
	{
		printf("soln\n");
		findSoln(t);
		printf("\n");

	}
	// printf("%i ", t->key);
	preorderTraversal(t->lchild, d);
	preorderTraversal(t->rchild, d);
}

Tree createSSTree(Tree t, int* arr, int d, int index, int n)
{
	if(index >= n)
		return t;
	// Tree t = *tr;
	if(t == NULL)
	{
		// printf("found node null\n");
		t = calloc(1, sizeof(TreeNode));
		t->parent = t;
		t->key = 0;
		t->lchild = t->rchild = NULL;
	}

	if (t->key > d)
	{
		return t;
	}

	if(t->lchild == NULL)
	{
		if (t->key + arr[index] <= d)
		{
			// printf("found lchild null\n");
			t->lchild = calloc(1, sizeof(TreeNode));
			t->lchild->key = t->key + arr[index];
			t->lchild->parent = t;
			// printf("giving %i value to lchild\n", t->key + arr[index]);
			createSSTree(t->lchild, arr, d, index+1, n);
		}
	}

	if(t->rchild == NULL)
	{
		if (index != n-1 && t->key < d)
		{
			// printf("found rchild null\n");
			t->rchild = calloc(1, sizeof(TreeNode));
			t->rchild->parent = t;
			t->rchild->key = t->key;
			// printf("giving %i value to rchild\n", t->key);
			createSSTree(t->rchild, arr, d, ++index, n);	
		}
	}

	return t;
}

void findSubsetSums(int* arr, int d, int n)
{
	Tree ssTree = NULL;
	// printf("Creating ssTree\n");
	ssTree = createSSTree(ssTree, arr, d, 0, n);
	// printf("creation over\n");
	preorderTraversal(ssTree, d);
	printf("\n");
	// postorderTraversal(ssTree);
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of elements in the set\n");
	scanf("%i", &n);

	printf("Enter the elements\n");
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &arr[i]);
	}

	printf("Enter the sum\n");
	int d;
	scanf("%i", &d);

	findSubsetSums(arr, d, n);
	return 0;
}