#include <stdio.h>
#include "SumOfArray.h"
#include "LinearSearch.h"
#include "Largest.h"
#include "SumOf2Matrices.h"

int main()
{
	int len = 100, arr[len], searchE, r = 100, c = 100, mat1[r][c], mat2[r][c], matOut[r][c];
	do
	{
		int program;
		printf("Please select a program to run: 1. SumOfArray   2. Linear Search   3. SumOf2Matrices  4. LargestOflist  5. Quit... ");
		scanf("%d", &program);

		switch(program)
		{
			case 1: printf("Please enter the length of the array: ");
					scanf("%d", &len);

					printf("Please enter all the elements of the array: ");
					for(int i=0; i<len; i++)
					{
						scanf("%d", &arr[i]);
					}
 
					printf("The sum of the given array is %d\n", sumOfArray(arr, len));
					break;

			case 2: printf("Please enter the no of elements going to be entered: ");
					scanf("%d", &len);

					printf("Please enter all the elements: ");
					for(int i=0; i<len; i++)
					{
						scanf("%d", &arr[i]);
					}

					printf("Enter the element to be searched in the array");
					scanf("%d", &searchE);

					if(linSearch(arr, len, searchE) == 1)
						printf("Found!!");
					else printf("Not Found!!");
					break;
 
			case 4: printf("Please enter the no of elements going to be entered: ");
					scanf("%d", &len);

					printf("Please enter all the elements: ");
					for(int i=0; i<len; i++)
					{
						scanf("%d", &arr[i]);
					}

					printf("The largest of the entered elements is %d", largest(arr, len));
					break;

			case 3: printf("Please enter the no of rows in the matrix: ");
					scanf("%d", &r);
					printf("Please enter the no. of columns in the matrix: ");
					scanf("%d", &c);

					printf("Taking elements of 1st Matrix\n");
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							printf("Please enter the element of row %d column %d.. ", i + 1, j + 1);
							scanf("%d", &mat1[i][j]);
						}
					}

					printf("Taking elements of 2nd Matrix\n");
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							printf("Please enter the element of row %d column %d.. ", i + 1, j + 1);
							scanf("%d", &mat2[i][j]);
						}
					}

					sumOfMatrix(mat1, mat2, r, c, matOut);

					
					printf("The matrix is \n");
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							printf("%d\t", matOut[i][j]);
						}
						printf("\n");
					}
					break;

			case 5:
				return 0;
					
			default: printf("Please enter a valid program no. ");
		}
	}while(1);
	
}
