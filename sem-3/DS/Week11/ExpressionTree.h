typedef struct node
{
	char data;
	struct node* lchild, * rchild;
}treenode;

typedef treenode* treeptr;

treeptr createnode(char c)
{
	treeptr ret = malloc(sizeof(treenode));
	ret->data = c;
	ret->lchild = ret->rchild = NULL;

	return ret;
}

treeptr makeTree(char* postfix)
{
	treeptr stack[100];
	int tos = -1;

	for(int i=0; postfix[i] != '\0'; i++)
	{
		treeptr temp = createnode(postfix[i]);

		if(postfix[i] >= '0' && postfix[i] <= '9')
			stack[++tos] = temp;

		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%')
		{
			temp->rchild = stack[tos--];
			temp->lchild = stack[tos--];

			stack[++tos] = temp;
		}
	}

	return stack[tos--];
}

char evalTree(treeptr root)
{
	if(!root) {
		printf("Empty tree\n");
		return 0;
	}

	if(root->data >= '0' && root->data <= '9') {
		return root->data;
	}

	switch(root->data)
	{
		case '+': root->data = ((evalTree(root->lchild) - 48) + (evalTree(root->rchild) - 48)) + 48;
			break;
		case '-': root->data = ((evalTree(root->lchild) - 48) - (evalTree(root->rchild) - 48)) + 48;
			break;
		case '*': root->data = ((evalTree(root->lchild) - 48) * (evalTree(root->rchild) - 48)) + 48;
			break;
		case '/': root->data = ((evalTree(root->lchild) - 48) * (evalTree(root->rchild) - 48)) + 48;
			break;
		case '%': root->data = ((evalTree(root->lchild) - 48) % (evalTree(root->rchild) - 48)) + 48;
			break;
		default:
			printf("Checked all Operator cases\n");
	}

	// printf("Result is %i\n", root->data - 48);
	return root->data;
	
}