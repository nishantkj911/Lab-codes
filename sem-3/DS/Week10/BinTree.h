#include <string.h>

//Done using recursion
typedef struct node
{
	int data; 
	struct node* lchild, * rchild;
}NODE;

NODE* create(NODE* bnode, int x)
{
	if(bnode == NULL)
	{
		// printf("Adding %i to empty tree \n", x);
		//printf("Entered null condition\n");
		bnode = malloc(sizeof(NODE));
		bnode->data = x;
		bnode->lchild = bnode->rchild = NULL;
		return bnode;
	}
	else
	{
		// printf("Adding %i to tree with node %i\n", x, bnode->data);
		//printf("Entered Non null condition\n");
		int lr;
		printf("Left(1) or Right(2)\n");
		scanf("%i", &lr);
		
		if(lr == 1)
			bnode->lchild = create(bnode->lchild, x);
		if(lr == 2)
			bnode->rchild = create(bnode->rchild, x);
		
	}
	if(bnode->data == x)
	{
		printf("Duplicate node\n");
		exit;
	}
	
	return bnode;
}

void inorder(NODE* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->lchild);
		printf("%d\t", ptr->data);
		inorder(ptr->rchild);
	}
}

void postorder(NODE* ptr)
{
	if(ptr != NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\t", ptr->data);
	}
}

void preorder(NODE* ptr)
{
	if(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void iterInorder(NODE* ptr)
{
	if(!ptr)
	{
		printf("The tree is empty\n");
		return;
	}


	NODE* stack[100];
	int tos = -1;
	NODE* node = ptr;

	while(1)
	{
		for(; node != NULL; node = node->lchild)
			stack[++tos] = node;

		node = stack[tos];
		stack[tos--] = NULL;

		if(!node)
			break;

		printf("%i\t", node->data);

		node = node->rchild;

	}
}

void iterPreorder(NODE* ptr)
{
	if(!ptr)
	{
		printf("The tree is empty\n");
		return;
	}

	NODE* stack[100];
	int tos = -1;
	NODE* node = ptr;

	stack[++tos] = node;

	while(1)
	{
		if(tos == -1)
			break;

		node = stack[tos];
		stack[tos--] = NULL;

		if(node != NULL)
			printf("%i\t", node->data);

		if(node->rchild)
			stack[++tos] = node->rchild;

		if(node->lchild)
			stack[++tos] = node->lchild;

	}
}

void iterPostorder(NODE* ptr)
{

	if(!ptr)
	{
		printf("The tree is empty\n");
		return;
	}

	NODE* stack1[100], *stack2[100];
	int tos1 = -1, tos2 = -1;
	NODE* node = ptr;

	stack1[++tos1] = node;

	while(tos1 != -1)
	{
		node = stack1[tos1--];
		stack2[++tos2] = node;

		if(node->lchild)
			stack1[++tos1] = node->lchild;
		if(node->rchild)	
			stack1[++tos1] = node->rchild;
	}

	while(tos2 != -1)
	{
		printf("%i\t", stack2[tos2--]->data);
	}

}