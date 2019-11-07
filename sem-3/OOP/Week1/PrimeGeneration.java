import java.util.Scanner;

class PrimeGeneration
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the no. of prime nos wanted: ");
		int no = input.nextInt();
		for(int count=0, i=2; count<no; i++)
		{
			if(isPrime(i))
			{
				System.out.print(i + "  ");
				count++;
			}
			
		}	
		System.out.println();
	}
	
	static boolean isPrime(int n)
	{
		for(int i = 2; i <= n/2 ; i++)
		{
			if(n % i == 0)
				return false;
		}
 		
		return true;
	}
}
