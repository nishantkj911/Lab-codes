#define LENGTH 10

typedef struct 
{
	int arr[LENGTH];
	int top[2];
}twoStack;

twoStack* twoinit(twoStack* s)
{
	s->top[0] = -1;
	s->top[1] = LENGTH;
}

void twopush(int val, twoStack* s, int num)
{
	if(s->top[0] + 1 == s->top[1])
		printf("pushing not possible\n");
	switch(num)
	{
		case 0:
			s->arr[++s->top[0]] = val;
			break;
		case 1:
			s->arr[--s->top[1]] = val;
			break;
	}
}

int twopop(twoStack* s, int a)
{
	int ret;
	switch(a)
	{
		case 1:
			if(s->top[a] == LENGTH)
			{
				printf("Cannot remove element. Stack is empty\n");
				return 0;
			}
			else {
				ret = s->arr[s->top[1]];
				s->arr[s->top[1]--] = 0;
				return ret;
			}
		case 0:
			if(s->top[a] == -1)
			{
				printf("Cannot remove element. Stack is empty\n");
				return 0;
			}
			else {
				ret = s->arr[s->top[0]];
				s->arr[(s->top[0])--] = 0;
				return ret;
			}

	}
}