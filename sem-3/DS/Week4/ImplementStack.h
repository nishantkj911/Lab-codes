typedef struct
{
	char arr[100];
	int top;
}charstack;

void push(char val, charstack* s)
{
	if(s->top == 99)
	{
		printf("Stack Overflow!! Cannot add element\n");
		return;
	}
	
	s->top = s->top + 1;
	s->arr[s->top] = val;
}

void pop(charstack* s)
{
	if(s->top == -1)
	{
		printf("Stack Underflow!! Cannot remove element\n");
		return;
	}

	s->arr[(s->top)--] = 0;
}