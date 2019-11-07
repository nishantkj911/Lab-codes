import java.util.Scanner;

class UsingScanner
{
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args)
	{
		int a = input.nextInt();
		int b = 12;
		System.out.println("Your no. + 12 is " + (a + b));
	}
}
