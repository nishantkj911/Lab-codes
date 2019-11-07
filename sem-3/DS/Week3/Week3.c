#include <stdio.h>
#include "LengthOfString.h"
#include "Palindrome.h"
#include "stringCopy.h"
#include "MatrixMultiply.h"
#include "TowerOfHanoi.h"


int main()
{
	while(1)
	{
		printf("Problem no. \n1. Matrix Multiplication\n2. Length of String\n3. String Copy\n4. Palindrome Check\n5. Tower of Hanoi\n6. Quit\n");
		int ch;
		scanf("%d", &ch);
		
		//initialization
		char str1[100];
		char str2[100];
		int len = 0, n, mat1[10][10], mat2[10][10], matOut[10][10] = {0}, m1, m2, n1, n2;

		switch(ch)
		{
			case 1:
				printf("Rows and colums for matrix 1: ");
				scanf("%i %i", &m1, &m2);
				printf("Rows and colums for matrix 2: ");
				scanf("%i %i", &n1, &n2);

				if(m2 != n1)
				{
					printf("Invalid matrix multiplication");
					break;
				}

				printf("matrix 1\n");
				for(int i=0; i<m1; i++)
				{
					for(int j=0; j<m2; j++)
					{
						scanf("%i", &mat1[i][j]);
					}
					
				}


				printf("matrix 2\n");
				for(int i=0; i<n1; i++)
				{
					for(int j=0; j<n2; j++)
					{
						scanf("%i", &mat2[i][j]);
					}
					
				}

				multiply(m1, n1, mat1, m2, n2, mat2, matOut);

				for(int i=0; i<m1; i++)
				{
					for(int j=0; j<n2; j++)
					{
						printf("%i\t", matOut[i][j]);
					}
					printf("\n");
				}

				break;
				
			case 2: 
				printf("Enter a string: ");
				scanf("%s", str1);

				len = strlength(str1, 0);

				printf("The length is %i\n", len);
				break;

			case 3:
				printf("Enter a string: ");
				scanf("%s", str1);

				copier(str1, str2, 0);

				printf("The other string value: %s\n", str2);

				break;

			case 4:
				printf("Enter a string");
				scanf("%s", str1);
				for(int i=0; str1[i] != '\0'; i++)
					len++;

				n = isPalindrome(str1, 0, len-1);

				if(n)
				{
					printf("Is a Palindrome\n");
				}
				else 
				{
					printf("Not a palindrome\n");
				}
				break;

			case 5: 
				printf("Enter the no. of disks\n");
				scanf("%d", &len);

				n = tower(len, 'A', 'B', 'C');
				printf("no of moves taken are %i\n", n);
				break;
				
			case 6: 
				return 0;
		}
	}
}