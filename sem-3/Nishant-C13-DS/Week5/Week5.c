#include <stdio.h>
#include <stdlib.h>
#include "preEval.h"
#include "inToPre.h"
#include "twoStacks.h"

int main()
{
	while(1)
	{
		printf("Problem no. \n1. Prefix Evaluation\n2. Infix to Prefix\n3. Two Stacks in array \n4. Quit\n");
		int ch;
		scanf("%d", &ch);
		
		//initialization
		char expr[100];
		charstack* ans;
		char* ansS = malloc(sizeof(char) * 10);
		int a, st, val;
		twoStack* ts = malloc(sizeof(twoStack));


		switch(ch)
		{
			case 1:
				printf("Enter the prefix expression: ");
				scanf("%s", expr);

				int res = solve(expr);

				printf("result = %i\n", res);
				break;
			case 2:
				printf("Enter the fully parenthesized infix expression: ");
				scanf("%s", expr);

				convert(expr);
				
				break;
			case 3:
				ts = twoinit(ts);
				printf("Enter the no. of nos to be entered\n");
				scanf("%d", &a);

				for(int i=0; i<a; i++)
				{
					printf("value to push\n");
					scanf("%d", &val);
					printf("which stack to push(1 or 2)\n");
					scanf("%d", &st);

					twopush(val, ts, st-1);
				}

				printf("Stack 1:\n");
				for(int i=ts->top[0]; i>-1; i--)
				{
					printf("%d\n", ts->arr[i]);
				}

				printf("Stack 2:\n");
				for(int i=ts->top[1]; i<LENGTH; i++)
				{
					printf("%d\n", ts->arr[i]);
				}				
				break;
			case 4:
				return 0;
		}

	}
}