void printArray(int a[], int* len)
{
	int *p = a;

	printf("The array enter is ");
	for(int i=0; i < (*len); i++)
		printf("%d\t", *(p+i));

	printf("\nThis is printed using pointer addition\n\n");
}