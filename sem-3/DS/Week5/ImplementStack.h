typedef struct
{
	int arr[100];
	int top;
}stack;

void push(char val, stack* s)
{
	if(s->top == 99)
	{
		printf("Stack Overflow!! Cannot add element\n");
		return;
	}
	
	s->top = s->top + 1;
	s->arr[s->top] = val;
}

int pop(stack* s)
{
	if(s->top == -1)
	{
		printf("Stack Underflow!! Cannot remove element\n");
		return 0;
	}
	
	int ret = s->arr[s->top];
	s->arr[(s->top)--] = 0;

	return ret;
}