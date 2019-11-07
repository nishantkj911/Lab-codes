import java.util.Scanner;
class Date
{
	private int day;
	private int month;
	private int year;
	private int counnt;
	private int Total_Days;
	private int i;

	Date(int d,int m,int y)
	{
		day=d;
		month=m;
		year=y;
		cnt=0;
	}
	public int daysSinceJan1()
	{
		for(i=1;i<=month-1;i++)
		{
			if(i==2)
			{
				if((year%400==0)||((year%100!=0)&&(year%4==0)))
					cnt+=29;
				else
					cnt+=28;
			}	

			else if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				cnt+=31;
			else
				cnt+=30;
			}
		Total_Days=cnt+day;
		return Total_Days;
	}
}
public class DateDemo{
	public static void main(String args[])
	{
		int d,m,y;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the day \n");
		d=sc.nextInt();
		System.out.println("Enter the month \n");
		m=sc.nextInt();
		System.out.println("Enter the year \n");
		y=sc.nextInt();
		Date dat = new Date(d,m,y);
		System.out.println("the total number of days = "+dat.daysSinceJan1());
	}
}

