#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffNode
{
    char ch;
    int freq;
    struct huffNode *lchild;
    struct huffNode *rchild;
} node;

typedef node HuffmanNode;

typedef HuffmanNode *HuffmanTree;

void swap(HuffmanTree *a, HuffmanTree *b)
{
    HuffmanTree temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HuffmanTree *arr, int i, int n)
{
    if (2 * i > n)
        return;

    if (i == 0)
        return;
    int swap1 = 2 * i;
    if (2 * i + 1 <= n)
    {
        // printf("Two children\n");
        if (arr[2 * i + 1]->freq < arr[2 * i]->freq)
            swap1 = 2 * i + 1;
    }
    else
    {
        // printf("One child\n");
    }

    if (arr[swap1]->freq < arr[i]->freq)
    {
        // printf("Swapping %c and '%c': %i %i\n", arr[swap1].ch, arr[i].freq, swap1, i);
        swap(&arr[swap1], &arr[i]);
        heapify(arr, swap1, n);
    }
}

void deleteLeast(HuffmanTree *arr, int *n)
{
    swap(&arr[1], &arr[*n]);
    heapify(arr, 1, --(*n));
}

void heapifyingWhole(HuffmanTree *Arr, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        // printf("HEapifying %i\n", i);
        heapify(Arr, i, n);
    }
}

void printHuffmanTree(HuffmanTree tree)
{
    if (tree == NULL)
        return;

    printf("char: %c\tfreq: %i\n", tree->ch, tree->freq);
    printHuffmanTree(tree->lchild);
    printHuffmanTree(tree->rchild);
}

HuffmanTree createHuffmanTree(HuffmanTree *arr, int n)
{
    if (n == 1)
        return arr[1];

    HuffmanTree lchild = malloc(sizeof(HuffmanNode));
    lchild->ch = arr[1]->ch;
    lchild->freq = arr[1]->freq;
    lchild->lchild = arr[1]->lchild;
    lchild->rchild = arr[1]->rchild;
    printf("deleting frist\n");
    deleteLeast(arr, &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%c ", arr[i]->ch);
    }
    printf("\n");
    // printf("Deleted least\n");
    // printf("%c\n", arr[1].ch);
    HuffmanTree rchild = malloc(sizeof(HuffmanNode));
    rchild->ch = arr[1]->ch;
    rchild->freq = arr[1]->freq;
    rchild->lchild = arr[1]->lchild;
    rchild->rchild = arr[1]->rchild;
    printf("deleting second\n");
    deleteLeast(arr, &n);

    printf("Creating tree\n");
    HuffmanTree tree = malloc(sizeof(node));
    tree->ch = '$';
    tree->freq = lchild->freq + rchild->freq;
    tree->lchild = lchild;
    tree->rchild = rchild;

    printf("Adding to node\n");
    arr = realloc(arr, sizeof(node) * ++n);
    printf("Yo1 %i\n", n);
    arr[n] = tree;
    heapify(arr, n / 2, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%c ", arr[i]->ch);
    }
    printf("\n\n");

    printHuffmanTree(tree);

    tree = createHuffmanTree(arr, n);
}

void createSoln(HuffmanTree t, char c)
{
    if (t == NULL)
        return;

    if (t->lchild == NULL && t->rchild == NULL)
    {
        int ch;
        if (c == 'l')
            ch = '0';
        if (c == 'r')
            ch = '1';
        printf("\nfor %c: %c", t->ch, ch);
        return;
    }

    createSoln(t->lchild, 'l');
    if (c == 'l')
        printf("0");
    if (c == 'r')
        printf("1");
    createSoln(t->rchild, 'r');
    if (c == 'l')
        printf("0");
    if (c == 'r')
        printf("1");

    return;
}

int main(int argc, char const *argv[])
{
    //Taking input of the message
    char *str = malloc(sizeof(char) * BUFSIZ);
    memset(str, '\0', BUFSIZ);
    // printf("Enter the message to be sent\n");
    scanf("%[^\n]%*c", str);

    HuffmanTree *arr = calloc(1, sizeof(HuffmanTree));
    int size = 1;
    // printf("fuck you\n");
    for (int i = 0; i < strlen(str); i++)
    {
        int flag = 0;
        for (int j = 0; j < size; j++)
        {

            if (arr[j] != NULL && arr[j]->ch == str[i])
            {
                flag = 1;
                arr[j]->freq++;
            }
        }

        if (!flag)
        {
            // printf("Adding %c to the array\n", str[i]);
            arr = realloc(arr, sizeof(HuffmanTree) * ++size);
            arr[size - 1] = malloc(sizeof(HuffmanNode));
            arr[size - 1]->ch = str[i];
            arr[size - 1]->freq = 1;
            arr[size - 1]->lchild = arr[size - 1]->rchild = NULL;
        }
    }

    heapifyingWhole(arr, --size);
    for (int i = 1; i <= size; i++)
    {
        printf("Char: %c\tFrequency%i\n", arr[i]->ch, arr[i]->freq);
    }

    HuffmanTree t = createHuffmanTree(arr, size);
    printf("fuck\n");

    printHuffmanTree(t);

    printf("The code is\n");
    createSoln(t, '\0');
    printf("\n");
    return 0;
}
