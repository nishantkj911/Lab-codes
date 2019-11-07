typedef struct node
{
	int data; 
	struct node* lchild, * rchild;
}NODE;

typedef NODE* treeptr;

treeptr* levelOrder(treeptr ptr)
{
	if(!ptr) {
		printf("Empty tree\n");
		return NULL;
	}

	treeptr temp = ptr;
	treeptr* q = malloc(sizeof(treeptr) * 100);
	int last = 0;
	int first = 1;

	while(temp != NULL)
	{
		printf("%i\t", temp->data);

		if(temp->lchild)
			q[++last] = temp->lchild;
		if(temp->rchild)
			q[++last] = temp->rchild;

		temp = q[first++];
	}

	return q;
}

treeptr addToTree(int val, treeptr root)
{
	treeptr temp = root;
	if(!root)
	{
		root = malloc(sizeof(NODE));
		root->lchild = root->rchild = NULL;
		root->data = val;
		// printf("added %i\n", val);
	}
	else if(val < temp->data)
		root->lchild = addToTree(val, temp->lchild);
	else if(val > temp->data)
		root->rchild = addToTree(val, temp->rchild);
	else
		printf("Duplicate Node\n");

	return root;

}

void rightmostVisible(treeptr root)
{
	treeptr* qNew = levelOrder(root);

	//this is printing the rightmost value in a level which is not always the case
	for(int n = 1, i=0; qNew[n] != NULL; n*=2, i++)
		printf("%i\n", qNew[n + i]->data);

}

void freeTree(treeptr ptr)
{
	if(!ptr)
		return;

	if(ptr->lchild == NULL && ptr->rchild == NULL) {
		printf("freeing node %i\n", ptr->data);
		free(ptr);
		return;
	}

	freeTree(ptr->lchild);
	freeTree(ptr->rchild);

	printf("freeing %i\n", ptr->data);
	// free(ptr);
}

int maxDepth(treeptr ptr)
{
	if(!ptr)
		return 0;
	else
	{
		int a = maxDepth(ptr->lchild);
		int b = maxDepth(ptr->rchild);
		int max;
		if(a > b)
			max = a;
		else max = b;

		max++;

		return max;
	}
}

int noOfNodes(treeptr ptr)
{
	if(!ptr)
		return 0;
	else return noOfNodes(ptr->lchild) + noOfNodes(ptr->rchild) + 1; 
}

int printLeaves(treeptr ptr)
{
	static int count = 0;
	if(!ptr)
		return 0;

	if(!ptr->lchild && !ptr->rchild) {
		printf("%i\t", ptr->data);
		count++;
	}

	printLeaves(ptr->lchild);
	printLeaves(ptr->rchild);

	return count;

}

int identicalTrees(treeptr ptr1, treeptr ptr2)
{
	if(!ptr1 && !ptr2)
		return 1;

	if(ptr1->data == ptr2->data)
	{
		if(identicalTrees(ptr1->lchild, ptr2->lchild) 
			&& identicalTrees(ptr1->rchild, ptr2->rchild))
			return 1;	
	}
	else return 0;
}

treeptr copyTree(treeptr ptr)
{
	if(!ptr)
		return NULL;

	treeptr temp = malloc(sizeof(NODE));
	temp->data = ptr->data;
	temp->lchild = copyTree(ptr->lchild);
	temp->rchild = copyTree(ptr->rchild);

}

int checkSiblings(int val1, int val2, treeptr root)
{
	static int val = 0;
	if(!root || (!root->lchild && !root->rchild))
		val = 0;

	if(root->lchild && root->rchild)
	{
		if((root->lchild->data == val1 && root->rchild->data == val2) || (root->rchild->data == val1 && root->lchild->data == val2))
			val = 1;
		else val = 0;
	}

	if(val != 1)
	{
		if(root->lchild)
			val = checkSiblings(val1, val2, root->lchild);


		if(val != 1)
		{
			if(root->rchild)
				val = checkSiblings(val1, val2, root->rchild);
		}
	}

	return val;
}

void printLeftBoundary(treeptr root)
{
	if(!root || (!root->lchild && !root->rchild))
		return;

	if(root->lchild && (root->lchild->lchild  || root->lchild->rchild)) 
	{
		printf("%i\t", root->lchild->data);
		printLeftBoundary(root->lchild);
	}
	else if(root->rchild && (root->rchild->lchild || root->rchild->rchild))
	{
		printf("%i\t", root->rchild->data);
		printLeftBoundary(root->rchild);
	}

}

void printRightBoundary(treeptr root)
{
	if(!root || (!root->lchild && !root->rchild))
		return;

	if(root->rchild && (root->rchild->lchild  || root->rchild->rchild)) 
	{
		printf("%i\t", root->rchild->data);
		printRightBoundary(root->rchild);
	}
	else if(root->lchild && (root->lchild->lchild || root->lchild->rchild))
	{
		printf("%i\t", root->lchild->data);
		printLeftBoundary(root->lchild);
	}

}

void printBoundary(treeptr binTree1)
{
	if(!binTree1)
		return;

	printf("%i\t", binTree1->data);
	// printf("\nThe left boundary is\n");
	printLeftBoundary(binTree1);

	// printf("\nThe leaf nodes are\n"); 
	int num = printLeaves(binTree1);

	// printf("The right boundary is\n");
	printRightBoundary(binTree1);
	printf("\n");
}

/*int hieghtCalc(treeptr ptr)
{
	if(!ptr)
		return 0;
	if(!ptr->lchild && !ptr->rchild)
		return 1;

	if()
}*/