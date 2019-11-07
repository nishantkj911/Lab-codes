import java.util.Scanner;

class Roots
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please input the values of a, b, c in 'ax2 + bx + c' : ");
		int a = input.nextInt();
		int b = input.nextInt();
		int c = input.nextInt();

		double D = Math.pow(b, 2) - (4 * a * c);
		double root1 = (-b + Math.sqrt(D))/(2 * a);
		double root2 = (-b - Math.sqrt(D))/(2 * a);
		
		System.out.println("The roots of " + a + "x2 + " + b + "x + " + c  + " are " + root1 + " and " + root2); 
	}

	
}
