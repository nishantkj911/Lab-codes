package p2;

import p1.Max;
import java.util.*;

public class MaxTest
{
	private static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.println("1. Max of 3 integers\n2. Max of decimal nos\n3. Max of ints in array\n4. Max of ints in matrix");
		switch(input.nextInt())
		{
			case 1:
				System.out.println("Enter 3 integers..");
				int max = Max.max(input.nextInt(), input.nextInt(), input.nextInt());
				System.out.println("The max of the entered nos is " + max);
				break;
			case 2:
				System.out.println("Enter 3 floating pt. nos...");
				float max1 = Max.max(input.nextFloat(), input.nextFloat(), input.nextFloat());
				System.out.println("The max of the fl. nos is " + max1);
				break;
			case 3:
				System.out.println("Enter array and 'q' to quit...");
				ArrayList<Integer> a = new ArrayList<>();
				while (true)
				{
					String s = input.next();
					if(s == "q")
						break;
					
					a.add(Integer.parseInt(s));
				}
				System.out.println("The max of the entered array is " + Max.max(a));
				break;
			case 4:
				System.out.println("Dimension of matrix: ");
				int[][] mat = new int[input.nextInt()][input.nextInt()];
				for(int i=0; i<mat.length; i++)
					for(int j=0; j<mat[0].length; j++)
						mat[i][j] = input.nextInt();
				
				
				System.out.println("The max element of the entered matrix is " + Max.max(mat));
				
		}
	}

}
