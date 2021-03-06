#include <stdio.h>
#include <stdlib.h>

typedef struct _dllNode
{
	int key;
	struct _dllNode* left;
	struct _dllNode* right;
} DoublyLinkedList;

typedef DoublyLinkedList* DLLNode;

DLLNode addFront(DLLNode dll, int key)
{
	if(dll == NULL)
	{
		dll = malloc(sizeof(DoublyLinkedList));
		dll->key = key;
		dll->left = dll->right = NULL;
		return dll;
	}

	DLLNode temp = malloc(sizeof(DoublyLinkedList));
	temp->key = key;
	temp->right = dll;
	temp->left = NULL;
	dll->left = temp;
	dll = temp;

	return dll;
}

void printList(DLLNode dll)
{
	if(dll == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		printf("The Doubly linked list is: \n");
		while(dll != NULL)
		{
			printf("%i  ", dll->key);
			dll = dll->right;
		}
	}
	printf("\n");
}

void findNode(DLLNode dll, int value)
{
	int* arr = (int*) malloc(sizeof(int));
	int len = 1, actLen = 0;
	if(dll == NULL)
	{
		printf("List is empty hence not found\n");
	}
	else
	{
		int i=0;
		for(DLLNode temp = dll; temp != NULL; temp = temp->right, i++)
		{
			if(temp->key == value)
			{
				arr[actLen++] = i;
				if(actLen == len)
				{
					arr = (int*) realloc(arr, len * 2);
					len *= 2;
				}
			}

		}

		if(actLen == 0)
		{
			printf("No occurraces found\n");
			return;
		}

		printf("The indices of all occurraces of %i are: \n", value);
		for(int i=0; i<actLen; i++)
		{
			printf("%i  ", arr[i]);
		}
		printf("\n");
	}
}

DLLNode deleteAllOccurrances(DLLNode dll, int value)
{
	int* arr = (int*) malloc(sizeof(int));
	int len = 1, actLen = 0;
	if(dll == NULL)
	{
		printf("List is empty hence not found\n");
	}
	else
	{
		int i=0;
		for(DLLNode temp = dll; temp != NULL; temp = temp->right, i++)
		{
			// printf("i = %i\n", i);
			if(i == 0 && temp->key == value)
			{
				temp = temp->right;
				temp->left = NULL;
				dll = temp;
			}
			else if(temp->right == NULL && temp->key == value)
			{
				temp = temp->left;
				temp->right = NULL;
			}
			else if(temp->key == value)
			{
				//deletion code
				temp->right->left = temp->left;
				temp->left->right = temp->right;
				temp = temp->left; 

			}
			else
			{
				continue;
			}

			arr[actLen++] = i;
			if(actLen == len)
			{
				arr = (int*) realloc(arr, len * 2);
				len *= 2;
			}

			// printList(dll);
		}

		if(actLen == 0)
		{
			printf("No deletions\n");
			return dll;
		}

		printf("The deletions are done at the indices:\n");
		for(int i=0; i<actLen; i++)
		{
			printf("%i  ", arr[i]);
		}
		printf("\n");
	}

	return dll;
}

DLLNode insertBefore(DLLNode dll, int value, int check)
{
	if(dll == NULL)
	{
		printf("List is empty hence not added\n");
		return dll;
	}
	
	for(DLLNode temp = dll; temp != NULL; temp = temp->right)
	{
		if(temp->key == check)
		{
			DLLNode temp2 = malloc(sizeof(DoublyLinkedList));
			temp2->key = value;
			temp->left->right = temp2;
			temp2->left = temp->left;
			temp->left = temp2;
			temp2->right = temp;
			// printf("Insertion done\n");
			return dll;
		}

	}

	printf("%i was not found hence %i is not being added\n", check, value);
	return dll;
}

int main()
{
	// DoublyLinkedList l1;
	/*int a;
	printf("Enter an integer:\n");
	scanf("%i", &a);
	printf("The integer you entered is %i\n", a);
*/
	DLLNode dll = NULL;

	int key;
	printf("Insert integers or press 'Ctrl+D' to end\n");
	while (1)
	{
		int ret = scanf("%d", &key);
		if(ret == EOF)
			break;
		
		// printf("%i\n", key);
		if(ret == 1)
		{
			dll = addFront(dll, key);
		}
		else
		{
			printf("Enter valid input (only integers)...\n");
			scanf("%*[^\n]");
		}
	}

	printList(dll);

	//Finding Node, given the key
	/*printf("Enter the no. to find occurrances of\n");
	int val;
	scanf("%i", &val);

	findNode(dll, val);*/


	//Insert to the left of given no.
	/*printf("Enter the number to be inserted:\n");
	int val;
	scanf("%i", &val);
	printf("This will be added before? \n");
	int chk;
	scanf("%i", &chk);

	dll = insertBefore(dll, val, chk);
	printList(dll);*/

	//Delete alloccurrances
	/*printf("Enter the no. to delete occurrances of\n");
	int val;
	scanf("%i", &val);

	dll = deleteAllOccurrances(dll, val);*/

	printList(dll);
}