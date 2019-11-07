import java.util.Scanner;

public class CommaGenerator2
{
	static Scanner input=new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Enter Number : ");
		String str=input.next();
		StringBuilder a=new StringBuilder(str);
		
		for(int i=a.length()-1, j=0; i>=0; i--)
		{
			j++;
			if(j%3==0 && i!=0)
				a.insert(i, ',');
		}
		System.out.println("String is : " + a);
	}
}
