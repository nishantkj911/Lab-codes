#include <stdio.h>
#include <stdlib.h>
#include "nQueue.h"

int main()
{
	queue s;
	init(&s);
	int v;
	char q;
	while(1)
	{
		printf("Enqueue(1), Deqeue(2), Display(3)\n");
		scanf("%d", &v);

		if(v==1)
		{
			printf("Input String\n");
			char x[50], y;
			scanf("%c", &q);
			fgets(x, sizeof(x), stdin);
			enqueue(&s, x);
		}
		else if(v==2)
		{
			char* el = dequeue(&s);
			printf("Dequeued string is \"%s\"\n", el);
		}
		else if(v==3)
			display(&s);
		else break;
	}
}