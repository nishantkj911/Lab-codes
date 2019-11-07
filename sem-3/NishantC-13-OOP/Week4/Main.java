import java.util.Scanner;

class Main
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		while(true)
		{
			System.out.print("Which problem you want to solve? (1. Card  2. Time  3. Mixer 4. Stack  5. Exit) ");
			int ch = input.nextInt();
		
			switch(ch)
			{
				case 1:
					cardPrblm();
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
	
	static cardPrblm()
	{
		System.out.println("Enter the 5 cards(rank and suit)");
		Card no1 = Card(input.nextInt(), (input.next()).charAt(0));
		Card no2 = Card(input.nextInt(), (input.next()).charAt(0));
		Card no3 = Card(input.nextInt(), (input.next()).charAt(0));
		Card no4 = Card(input.nextInt(), (input.next()).charAt(0));
		Card no5 = Card(input.nextInt(), (input.next()).charAt(0));
	
	
	
	}
}
