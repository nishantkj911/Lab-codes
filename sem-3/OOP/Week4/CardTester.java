import java.util.Scanner;

class Card
{
	int rank;
	char suit;
	

	Card(int r , char s)
	{
		rank=r;
		suit=s;
	}

	char getSuit()
	{
		return suit;	
	}

	int getRank()
	{		
		return rank;
	}
}


public class CardTester
{
	static Scanner input = new Scanner(System.in);
	public static void main(String args[])
	{
		Card cards[] = new Card[5];
		int rankCount[]={0,0,0,0,0};
		int i=0;
		for(i = 0; i <5; i++)
		{
                    System.out.println("Input card " + (i+1) +  "'s rank and suit.. ");
                    cards[i] = new Card(input.nextInt(), (input.next()).charAt(0));	
		}

		for(i =0; i <5; i++)
		{
                    int rank=cards[i].getRank();
                    for(int j=0; j<5;j++)
                    {
                        if(rank==cards[j].getRank())		
                            rankCount[i]++;	
                    }		
		}
		for(i=0; i<5;i++)
                {
                    if(rankCount[i]==2||rankCount[i]==3)		
			continue;	
                    else		
			break;	
		}
		if(i == 5)
			System.out.println("Full House");
		else
			System.out.println("Not a Full House");	
	}
}
