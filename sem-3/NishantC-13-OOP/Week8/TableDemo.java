class Table
{
	synchronized static void display(int a)
	{
		for(int i=1; i<=10; i++)
		{
			System.out.println(a + " * " + i + " = " + (a*i));
		}
	}
}

class DisplayTable extends Thread
{
	Table tab;
	Thread t;
	int a;
	
	DisplayTable(String name, Table tab, int a)
	{
		t = new Thread(this, name);
		this.tab = tab;
		this.a = a;
		
		t.start();
	}
	
	@Override
	public void run()
	{
		Table.display(a);
	}
}

public class TableDemo
{
	public static void main(String[] args)
	{
		Table tab1 = new Table();
		
		DisplayTable d1 = new DisplayTable("5's Table", tab1, 5);
		DisplayTable d2 = new DisplayTable("7's Table", tab1, 7);
		
		try
		{
			d1.t.join();
			d2.t.join();
		}
		catch(InterruptedException exc)
		{
			System.out.println("Main thread interrupted");
		}
		
	}
}
