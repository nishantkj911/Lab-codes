int *pointerGreater(int *a, int *b, int* c)
{	
	if(*a >= *b && *a >= *c)
		return a;
	else if(*b >= *c && *b >= *a)
		return b;
	else if(*c >= *a && *c >= *b)
		return c;

}