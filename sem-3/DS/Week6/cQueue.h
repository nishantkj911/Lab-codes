#define LENGTH 5

typedef struct
{
	int arr[LENGTH];
	int first;
	int last;
}cqueue;

cqueue* init(cqueue* s)
{
	s->first = -1;
	s->last = -1;

	return s;
}

int enqueue(int a, cqueue* s)
{
	if(((s->last + 1) % LENGTH) == (s->first))
	{
		printf("No space to enqueue\n");
		return 0;
	}

	if(s->first == s->last && s->first == -1)
	{
		s->arr[(++(s->last)) % LENGTH] = a;
		(s->first)++;
		return 1;
	}

	s->arr[(++(s->last)) % LENGTH] = a;
	return 1;
}

void display(cqueue* s)
{
	if(s->first == s->last && s->first == -1)
	{
		printf("Empty Queue\n");
		return;
	}

	int temp = s->first;
	do
	{
		printf("%i\t", s->arr[temp % LENGTH]);
	}
	while((temp++) % LENGTH != s->last);
	printf("\n");
}

int dequeue(int no, cqueue* s)
{
	if(no == 0)
		return 0;
	
	if(no-1 > ((s->last - s->first) % LENGTH))
	{
		dequeue(((s->last - s->first) % LENGTH) + 1, s);
		return 1;
	}

	if(s->first == s->last)
	{
		s->arr[s->first] = 0;
		s->first = s->last = -1;
		return 0;
	}

	s->arr[s->first++] = 0;
	dequeue(no-1, s);
}