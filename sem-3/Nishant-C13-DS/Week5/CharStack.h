typedef struct
{
	char arr[100];
	int top;
}charstack;

void charpush(char val, charstack* s)
{
	if(s->top == 99)
	{
		printf("Stack Overflow!! Cannot add element\n");
		return;
	}
	
	s->top = s->top + 1;
	s->arr[s->top] = val;
}

char charpop(charstack* s)
{
	if(s->top == -1)
	{
		printf("Stack Underflow!! Cannot remove element\n");
		return 0;
	}

	char res = s->arr[(s->top)];

	s->arr[(s->top)--] = 0;

	return res;
}