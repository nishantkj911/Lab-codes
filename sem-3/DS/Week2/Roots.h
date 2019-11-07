void getData(int *a, int *b, int *c)
{
	printf("Please enter the values of a, b and c in ax2 + bx + c, resp... \n");
	scanf("%d %d %d", a, b, c);
}

void quadratic(int *a, int* b, int* c, double* root1, double* root2)
{
	int D = pow(*b, 2) - 4 * (*a) * (*c);

	*root1 = (-(*b) + sqrt(D))/(2 * (*a));
	*root2 = (-(*b) - sqrt(D))/(2 * (*a));
}

void print_roots(double *root1, double *root2)
{
	printf("The roots of the given quadratic equation are %f and %f\n\n", *root1, *root2);
}