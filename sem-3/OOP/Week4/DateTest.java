import java.util.Scanner;

class Date
{
	int day;
	int mon;
	int yr;
	
	Date(int d, int m, int y)
	{
		if(d > 31 || m > 12)
		{
			System.out.println("Enter valid Data!!");
			return;
		}
		
		day = d;
		mon = m;
		yr = y;
	}
	
	int daysSinceJan1()
	{
		int count = 0; 
		for(int i=1;i<mon;i++)
		{
			if(i==2)
			{
				if((yr%400==0) || ((yr%100!=0) && (yr%4==0)))
					count+=29;
				else
					count+=28;
			}	

			else if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				count+=31;
			else
				count+=30;
		}
		
		
		return count + day;
	}
}

class DateTest
{
	static Scanner input = new Scanner(System.in);
	public static void main(String args[])
	{
		int d,m,y;
		System.out.println("Enter day");
		d=input.nextInt();
		System.out.println("Enter month");
		m=input.nextInt();
		System.out.println("Enter year");
		y=input.nextInt();
		Date today = new Date(d,m,y);
		System.out.println("the total number of days = " + today.daysSinceJan1());
	}
}
