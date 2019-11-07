#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchWord(int i, int n, char *str,  char *word,  int *wordStart,  int *len,  int *noOfOccurrances)
{
    int flag = 1;
    int strIndex = wordStart[i] + 1;
    int endIndex = i == n - 1 ? *len : wordStart[i+1];
    for (int j = i == 0 ? 0 : strIndex, k = 0; j < endIndex; j++, k++)
    {
        // printf("'%c' '%c' char scanning\n", word[k], str[j]);
        if (word[k] != str[j])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        // printf("Incrememnting\n");
        noOfOccurrances[0]++;
    }
}

int main(int argc, char const *argv[])
{
    char *str = calloc(BUFSIZ, sizeof(char));
    char *word = calloc(BUFSIZ, sizeof(char));

    printf("Enter the string to be searched\n");
    scanf("%[^\n]%*c", str);

    printf("Enter the word to be searched for\n");
    scanf("%s", word);

    int noOfOccurrences = 0;
    int len = strlen(str), wordLen = strlen(word), noOfWords = 0, maxSize = 1;
    int *spaces = calloc(1, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            if(noOfWords == maxSize)
            {
                maxSize *= 2;
                spaces = realloc(spaces, sizeof(int) * maxSize);
            }
            
            spaces[noOfWords++] = i;
        }
    }

    if(spaces[noOfWords - 1] != len - 1)
    {
        if(noOfWords == maxSize)
        {
            maxSize++;
            spaces = realloc(spaces, sizeof(int) * maxSize);
        }
        spaces[noOfWords++] = len - 1;

    }
    for (int i = 0; i < noOfWords; i++)
    {
        printf("%i ", spaces[i]);
    }
    printf("\n");
    
    int *noc = malloc(sizeof(int));
    for (int i = 0; i < noOfWords; i++)
    {
        // printf("Iter: %i\n", i);
        searchWord(i, noOfWords, str, word, spaces, &len, noc);
        // printf("sdjkfn: %i\n", noc[0]);
    }

    printf("no of occ: %i\n", noc[0]);
    return 0;
}


