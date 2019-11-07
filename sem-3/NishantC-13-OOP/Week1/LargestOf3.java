import java.util.Scanner;

class LargestOf3
{
	public static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		int a, b, c;
		a = input.nextInt();
		b = input.nextInt();
		c = input.nextInt();
		
		System.out.println("Highest of " + a + ", " + b + " and " + c + " is " + largest(a, b, c));
	}

	

	static int largest(int a, int b, int c)
	{
		if(a >= b && a >= c)
		{
			return a;
		}
		else if(b >= c && b >= a)
		{
			return b;
		}
		else if(c >= a && c >= b)
		{
			return c;
		}
		
		return a;
	}
}	
