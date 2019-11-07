#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImplementStack.h"
#include "DtoBin.h"

int main()
{
	while(1)
	{
		printf("Problem no. \n1. Stack Implementation\n2. Palindrome Check\n3. Convert decimal to binary\n4. Quit\n");
		int ch;
		scanf("%d", &ch);
		
		//initialization
		int no;
		char* s = malloc(sizeof(char) * 100);
		char p;
		charstack* st = malloc(sizeof(charstack));

		switch(ch)
		{
			case 1:
				printf("Enter the no of chars to be entered..");
				scanf("%d", &no);


				pop(st);

				//this is for omitting the enter char pressed after 'no' input
				scanf("%c", &p);

				for(int i=0; i<no; i++)
				{
					scanf("%c", &p);
					push(p, st);

					//this is for omitting the enter char pressed after 'p' input
					scanf("%c", &p);
				}

				while(st->top >= 0)
				{
					printf("%c", st->arr[st->top]);
					pop(st);
				}
				printf("\n");

				
				break;
				
			case 2:

				printf("Enter the String\n");
    			scanf("%s", s);

    			//checkPal(s); //here no acts as 'isPal'
    			
			    for (int i = 0; s[i] != '\0'; i++)
			    {
			        push(s[i], st);
			    }

			    no=1;
			    for (int i = 0;  i<(strlen(s)/2);i++)
			    {
			        if (st->arr[st->top] == st->arr[no])
			        {
			            pop(st);
			            no++;
			        }
			        else
			        {
			            printf("%s is not a palindrome\n", s);
			            break;
			        }
			    }

			    if(!(no == ((strlen(s)/2) + 1)))
			    	break;

    			printf("%s is a palindrome\n", s);

				break;

			case 3:
				printf("Enter the no. to be converted.. ");
				scanf("%d", &no);
				intStack* s = binConvert(no);

				printf("bin eq. of %i is \n", no);
				while(s->top >= 0)
				{
					if(s-> top - 1 < 0)
						break;
					printf("%d", s->arr[s->top-1]);
					intpop(s);
				}
				printf("\n");

				free(s);
				break;

			case 4:
				return 0;
		}

		free(s);
		free(st);
	}
}