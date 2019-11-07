#include <string.h>
#include "ImplementStack.h"

int solve(char* str)
{
	stack* st = malloc(sizeof(stack));
	int len = strlen(str);
	int res;

	for(int i=len-1; i>=0; i--)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			push(str[i]-48, st);
			continue;
		}

		switch(str[i])
		{
			case '+':
				res = (pop(st)) + (pop(st));
				push(res, st);
				break;
			case '-':
				res = (pop(st)) - (pop(st));
				push(res, st);
				break;
			case '*':
				res = (pop(st)) * (pop(st));
				push(res, st);
				break;
			case '/':
				res = (pop(st)) / (pop(st));
				push(res, st);
				break;
			case '%':
				res = (pop(st)) % (pop(st));
				push(res, st);
				break;
		}
	}

	return res;
}
