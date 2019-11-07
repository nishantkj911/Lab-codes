#include <math.h>
#include <stdio.h>
#include "AddPointers.h"
#include "PointersDesc.h"
#include "Roots.h"
#include "PrintArray.h"

int main()
{
	//variable declarations required
	int num1, num2, num3, numOut, arr[100];
	int** max;
	int *p;
	double r1, r2;

	do
	{
		printf("Enter a program number\n(1. AddPointers, \n2. Find greater of 3 (using pointers) \n3. Find roots of quadratic function \n4. Print array using pointers \n5. Quit): ");
		int input;
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				printf("Please enter the two numbers: ");
				scanf("%d %d", &num1, &num2);

				addPointers(&numOut, &num1, &num2);

				printf("The sum of %d and %d is %d\n\n", num1, num2, numOut);
				break;

			case 2: //pointer problem with specifications
				printf("Please enter the three numbers: ");
				scanf("%d %d %d", &num1, &num2, &num3);


				*max = pointerGreater(&num1, &num2, &num3);

				printf("The greater of %d, %d and %d is %d\n(This is done by using pointer to pointer concept)\n\n", num1, num2, num3, **max);
				break;

			case 3: //quadratic functions and its specifications
				getData(&num1, &num2, &num3);
				quadratic(&num1, &num2, &num3, &r1, &r2);
				print_roots(&r1, &r2);

				break;

			case 4:
				printf("Please enter the length of the array: ");
				scanf("%d", &num1);

				printf("enter the elements of the array.\n");
				for(int i=0; i<num1; i++)
					scanf("%d", &arr[i]);

				printArray(arr, &num1);
				break;

			case 5:
				return 0;

			default:
				printf("Please enter valid program number\n");
		}
		
	}while(1);
}