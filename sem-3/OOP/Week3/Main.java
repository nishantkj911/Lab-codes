import java.util.Scanner;

class Main
{
	static Scanner input = new Scanner(System.in); 
	public static void main(String[] args)
	{
		while(true)
		{
			System.out.print("Which problem you want to solve? (1. Complex  2. Time  3. Mixer 4. Stack  5. Exit) ");
			int ch = input.nextInt();
		
			switch(ch)
			{
				case 1:
					complexPrblm();
					break;
					
				case 2:
					timePrblm();
					break;
				
				case 3:
					stackPrblm();
					break;

				case 4:
					mixerPrblm();
					break;
				
				case 5:
					return;
			}
		}
	}

	static void complexPrblm()
	{
		System.out.print("Enter the 1st complex no. ");
		Complex c1 = new Complex(input.nextInt(), input.nextInt());

		System.out.print("Enter the 2nd complex no. ");
		Complex c2 = new Complex(input.nextInt(), input.nextInt());
	
		System.out.println("The two nos. are " + c1.print() + " and " + c2.print());
		Complex cAdd = c1.addComplex(c2);
		Complex cSub = c1.subtractComplex(c2);
	
		System.out.println("The sum is " + cAdd.print());
		System.out.println("The difference is " + cSub.print());
	}

	static void timePrblm()
	{
		System.out.print("Enter the 1st time. ");
		Time t1 = new Time(input.nextInt(), input.nextInt(), input.nextInt());

		System.out.print("Enter the 2nd time. ");
		Time t2 = new Time(input.nextInt(), input.nextInt(), input.nextInt());
		
		System.out.println("The two given times are " + t1.display() + " and " + t2.display());		
		System.out.println("The sum of the two is " + (t1.addTimes(t2)).display());
		System.out.println("The difference of the two is " + (t1.subtractTimes(t2)).display());
		switch(t1.compareTimes(t2))
		{
			case 1:
				System.out.println(t1.display() + " is greater than " + t2.display());
				break;
			case -1:
				System.out.println(t2.display() + " is greater than " + t1.display());
				break;
			case 0:
				System.out.println(t1.display() + t2.display() + " are of equal values");
				break;
		}
		
	}
	
	static void stackPrblm()
	{
		System.out.print("Enter length ");
		int len = input.nextInt();
		Stack s = new Stack();
		for(int i = 0; i<len; i++)
		{
			System.out.print("Enter value ");
			s.push(input.nextInt());
		}
		
		System.out.println("The stack");
		s.display();
		
		System.out.print("Enter removal length");
		len = input.nextInt();
		for(int i=0; i<len; i++)
			s.pop();
		
		System.out.println("The stack again");
		s.display();
	}
	
	static void mixerPrblm()
	{
		Mixer ar1 = new Mixer();
		ar1.accept();
		
		Mixer ar2 = new Mixer();
		ar2.accept();
		
		Mixer ans = new Mixer();
		ans = ar1.mix(ar2);
		
		ans.display();
	}

}
	
