#include <stdio.h>
#include <stdlib.h>
#include "ExpressionTree.h"

int main()
{
	char input[100];

	printf("Enter postfix expression\n");
	scanf("%s", input);

	treeptr exprtree = makeTree(input);
	// printf("Tree made\n");

	printf("The evaluated value is %i\n", evalTree(exprtree) - 48);
}