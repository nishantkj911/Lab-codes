import java.util.Scanner;

class SumOf2Matrices
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the no. of rows in the array: ");
		int r = input.nextInt();
		System.out.print("Please enter the no. of columns in the array: ");
		int c = input.nextInt();

		int[][] mat1 = new int[r][c];
		int[][] mat2 = new int[r][c];
		int[][] matOut = new int[r][c];

		System.out.println("Please enter the elements of the matrix1");
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
				mat1[i][j] = input.nextInt();
		}
		
		System.out.println("Please enter the elements of the matrix1");
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
				mat2[i][j] = input.nextInt();
		}

		sumOfMatrices(mat1, mat2, matOut);
		
		System.out.println("The sum of the given matrices is ");
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
				System.out.print(matOut[i][j] + "\t");
			System.out.println();
		}
	}
	
	static void sumOfMatrices(int[][] mat1, int[][] mat2, int[][] matOut)
	{
		for(int i=0; i<mat1.length; i++)
		{
			for(int j=0; j<mat1[0].length; j++)
				matOut[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}
