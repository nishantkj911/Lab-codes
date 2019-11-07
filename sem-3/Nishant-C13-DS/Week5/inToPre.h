#include <string.h>
#include "CharStack.h"

void convert(char* str)
{
	int len = strlen(str);
	charstack *ans = malloc(sizeof(char) * 100);
	charstack opr;

	for(int i=len-1; i>=0; i--)
	{
		if(str[i] == ')')
		{
			// printf("adding ..%c.. to operator stack\n", str[i]);
			charpush(str[i], &opr);
			continue;
		}

		if(str[i] >= '0' && str[i] <= '9')
		{
			// printf("adding ..%c.. to ans stack\n", str[i]);
			charpush(str[i], ans);
			continue;
		}

		if(str[i] == '(')
		{
			do
			{
				// printf("adding ..%c.. to ans stack\n", opr.arr[opr.top]);
				charpush(charpop(&opr), ans);

			}while(opr.arr[opr.top] != ')');

			charpop(&opr);
			continue;
		}

		//printf("simply adding ..%c.. to operator stack\n", str[i]);
		charpush(str[i], &opr);
	}

	while(ans->top > 0)
	{
		printf("%c", ans->arr[ans->top]);
		charpop(ans);
	}
	printf("\n");

	free(ans);

}