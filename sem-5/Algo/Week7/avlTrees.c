#include "bst.h"

void rotateRight(Tree* Root)
{
	Tree root = *Root;
	/*Tree p = root->lchild;
	p->parent = root->parent;

	Tree temp = p->rchild;
	p->rchild = root;
	root->lchild = temp;
	temp->parent = root;
	root->parent = p;

	if(p->parent->lchild == root)
	{
		p->parent->lchild = p;
	}
	else
	{
		p->parent->rchild = p;
	}*/
	Tree g = root;
	Tree p = g->lchild;

	if(g->parent == g)
		p->parent = p;
	else
	{
		p->parent = g->parent;
		if(p->parent->lchild == g)
		{
			p->parent->lchild = p;
		}
		else
		{
			p->parent->rchild = p;
		}
	}


	g->lchild = p->rchild;
	if(g->lchild != NULL)
		g->lchild->parent = g;

	p->rchild = g;
	g->parent = p;

	*Root = p;
}

void rotateLeft(Tree* Root)
{
	Tree root = *Root;
	/*Tree p = root->rchild;
	p->parent = root->parent;

	Tree temp = p->lchild;
	p->lchild = root;
	root->rchild = temp;
	temp->parent = root;
	root->parent = p;

	if(p->parent->lchild == root)
	{
		p->parent->lchild = p;
	}
	else
	{
		p->parent->rchild = p;
	}*/

	Tree g = root;
	Tree p = g->rchild;

	if(g->parent == g)
		p->parent = p;
	else{

		p->parent = g->parent;
		if(p->parent->lchild == g)
		{
			p->parent->lchild = p;
		}
		else
		{
			p->parent->rchild = p;
		}
	}


	g->rchild = p->lchild;
	if(g->rchild != NULL)
		g->rchild->parent = g;

	p->lchild = g;
	g->parent = p;

	*Root = p;
}

void doubleRightLeft(Tree* Root)
{
	Tree g = *Root;
	Tree p = g->rchild;
	Tree c = p->lchild;
	Tree ccl = c->lchild;
	Tree ccr = c->rchild;

	c->parent = g->parent;

	if(c->parent->lchild == g)
	{
		c->parent->lchild = c;
	}
	else
		c->parent->rchild = c;

	c->rchild = p;
	p->parent = c;

	p->lchild = ccr;
	if (ccr != NULL)
	{
		ccr->parent = p;
	}

	c->lchild = g;
	g->parent = c;

	g->rchild = ccl;
	if(ccl != NULL)
		ccl->parent = g;

	*Root = c;
}

void doubleLeftRight(Tree* Root)
{
	Tree root = *Root;
	/*rotateLeft(&(root->lchild));
	preorderTraversalroot;
	printf("\n");
	
	rotateRight(root);
	preorderTraversalroot;
	printf("\n");
*/
	/*int flag = 0;
	if(*Root->parent = *Root)
		flag = 1;*/
	Tree g = *Root;
	Tree p = g->lchild;
	Tree c = p->rchild;
	Tree ccl = c->lchild;
	Tree ccr = c->rchild;

	c->parent = g->parent;

	if(c->parent->lchild == g)
	{
		c->parent->lchild = c;
	}
	else
		c->parent->rchild = c;

	c->lchild = p;
	p->parent = c;

	p->rchild = ccl;
	if (ccl != NULL)
	{
		ccl->parent = p;
	}

	c->rchild = g;
	g->parent = c;

	g->lchild = ccr;
	if(ccr != NULL)
		ccr->parent = g;

	*Root = c;
}

void findFaultyNode(Tree* Root, int key)
{
	if(*Root == NULL)
		return;

	Tree root = *Root;
	int bf = findBalanceFactor(root);
	if(bf >= 2)
	{
		printf("Fault at %i bf is 2\n", root->key);
		int bfLeft = findBalanceFactor(root->lchild);
		if(bfLeft == 1)
		{
			rotateRight(Root);
		}
		else if(bfLeft == -1)
		{
			doubleLeftRight(Root);
		}
		else
			findFaultyNode(&(root->lchild), key);
	}
	else if(bf <= -2)
	{
		printf("Fault at %i bf is -2\n", root->key);
		int bfRight = findBalanceFactor(root->rchild);
		if(bfRight == -1)
		{
			printf("bf right -1\n");
			rotateLeft(Root);
		}
		else if(bfRight == 1)
		{
			printf("bf right 1\n");
			doubleRightLeft(Root);
		}
		else
			findFaultyNode(&(root->rchild), key);
	}
	else if(root->key > key)
	{
		printf("Okay at %i. Going left\n", root->key);
		findFaultyNode(&(root->lchild), key);
	}
	else
	{
		printf("Okay at %i. Going right\n", root->key);
		findFaultyNode(&(root->rchild), key);
	}
}

void avlTreeInsertion(Tree* root, int key)
{
	findOrInsert(root, key);
	printf("Insertion done\n");
	findFaultyNode(root, key);
	/*printf("\nPreorder traversal\n");
	preorderTraversal(*root);
	printf("\n");*/
}

Tree createAVLTree()
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
			avlTreeInsertion(&bst, key);
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


int main(int argc, char const *argv[])
{
	Tree bst = createAVLTree();

	printf("The preorder traversal of the AVL Tree\n");
	preorderTraversal(bst);
	printf("\n");
	return 0;
}