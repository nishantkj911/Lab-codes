typedef struct
{
	char arr[100];
	int top;
}intStack;

void intpush(int val, intStack* s)
{
	if(s->top == 100)
	{
		printf("Stack Overflow!! Cannot add element\n");
		return;
	}

	s->arr[s->top] = val;
	s->top = s->top + 1;
}

void intpop(intStack* s)
{
	if(s->top == 0)
	{
		printf("Stack Underflow!! Cannot remove element\n");
		return;
	}

	s->arr[(s->top)--] = 0;
}

intStack* binConvert(int dec)
{
	intStack* s = malloc(sizeof(intStack));
	while(dec > 0)
	{
		intpush(dec%2, s);
		dec/=2;
	}

    return s; 
}