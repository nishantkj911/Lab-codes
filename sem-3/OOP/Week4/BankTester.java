import java.util.Scanner;

class BankAcc
{
	private String name;
	private int accNo;
	private	String type;
	private int balance;
	private	static double rate = 7.5;
	
	BankAcc(String n, int acc, String t, int b)
	{
		name = n;
		accNo = acc;
		type = t;
		balance = b;
	}
	
	BankAcc()
	{
		this("", 00000000, "Savings", 10000);
	}
	
	void depositMoney(int amt)
	{
		balance+=amt;
	}
	
	void withdrawMoney(int amt)
	{
		if(balance - amt < 0)
		{
			System.out.println("Insufficient funds!!");
			return;
		}
		
		balance-=amt;
	}
	
	void displayDetails()
	{
		System.out.println("Name: " + name);
		System.out.println("AccNo: " + accNo);
		System.out.println("Type: " + type);
		System.out.println("Balance: " + balance);
		System.out.println();
		System.out.println();
	}
	
	static void displayROI()
	{
		System.out.println("Rate of Interest: " + rate);
		System.out.println();
		System.out.println();
	}
}

class BankTester
{
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		System.out.print("Enter Details");
		BankAcc acc1 = new BankAcc(input.nextLine(), input.nextInt(), input.next(), input.nextInt());
		acc1.displayDetails();
		
		System.out.print("Enter amt. to withdraw.. ");
		acc1.withdrawMoney(input.nextInt());
		acc1.displayDetails();

		System.out.print("Enter amt. to deposit.. ");
		acc1.depositMoney(input.nextInt());
		acc1.displayDetails();
		
		BankAcc.displayROI();
		
	}	
}
