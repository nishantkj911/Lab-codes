import java.util.Scanner;

class TransposeMatrix
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the index of the array: ");
		int o = input.nextInt();
		

		int[][] mat = new int[o][o];

		System.out.println("Please enter the elements of the matrix");
		for(int i=0; i<mat.length; i++)
		{
			for(int j=0; j<mat[0].length; j++)
				mat[i][j] = input.nextInt();
		}

		boolean transpose = trCheck(mat);

		if(transpose)
			System.out.println("Matrix is symmetric");
		else 
			System.out.println("Matrix is non-symmetric");
	}
	
	static boolean trCheck(int[][] mat)
	{
		for(int i=0; i<mat.length; i++)
		{
			for(int j=0; j<mat[0].length; j++)
			{
				if(mat[i][j] != mat[j][i])
					return false;
			}
		}
		
		return true;
	}
}
