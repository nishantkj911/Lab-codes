#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

 
 
int main()
{
	int i, j, t;

	char inbuffer[81];
	char searchkey[81];

	char dict[10][20];

	int hval, cnt = 0;

	init_hashtable();

	printf("Dictionary Creation Starts now: Enter the word and its meaning list\n");

	while(1)
	{
		cnt = 0;
		printf("Enter the word: type \"end\" to terminate\n");

		scanf("%s", inbuffer);

		if(strcmp(inbuffer, "end") == 0)
			break;

		printf("Enter the synonyms: To terminate the list type\"#\"\n");

		while(strcmp(inbuffer, "#") != 0)
		{
			strcpy(dict[cnt], inbuffer);
			scanf("%s", inbuffer);
			cnt++;
		}

		i = 0;

		while(i < cnt)
		{
			hval = getHashVal(dict[i]);
			insert_htable(dict[i], hval);

			j = 0;
			t = 0;

			while(j <= cnt)
			{
				if(i != j)
					addtomeanlist(dict[j], hval, t++);

				j++;
			}

			i++;
		}
	}

	display();

	display_meanings_hashtable();

	printf("Enter the key to be searched\n");
	scanf("%s", searchkey);

	search_hash_table(searchkey);

	return 0;
}   
		 
				
		

