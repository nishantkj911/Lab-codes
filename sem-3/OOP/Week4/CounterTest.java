import java.util.Scanner;

class Counter
{
	static int count=0;
	
	Counter()
	{
		count++;
	}
	
	void showCount()
	{
		System.out.println(count + " instances of Counter class are created");
	}
}

class CounterTest
{
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		System.out.println("Creating 3 elements");
		Counter a = new Counter();
		Counter b = new Counter();
		Counter c = new Counter();
		
		showCount();
	}
}
