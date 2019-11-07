import java.util.Scanner;

class Combinations
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the value of n: ");
		int n = input.nextInt();
		System.out.print("Please enter the value of r: ");
		int r = input.nextInt();
		
		System.out.println(n + "C" + r + " is " + comb(n, r));
	}

	static int fact(int no)
	{
		if(no == 1)
			return 1;
		else return no * fact(no - 1);
	}

	static int comb(int n, int r)
	{
		return fact(n)/(fact(n - r) * fact(r));
	}	
}
