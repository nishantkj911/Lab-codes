class Q
{
	int n;
	boolean valueSet = false;

	synchronized int get()
	{
		while(!valueSet)
		{
			try 
			{
				wait();
			}
			catch(InterruptedException exc)
			{
				System.out.println("Caught");
			}
		}
		
		System.out.println("Get: " + n);
		valueSet = false;
		notify();
		
		return n;
	}
	
	synchronized int put(int n)
	{
		while(valueSet)
		{
			try 
			{
				wait();
			}
			catch(InterruptedException exc)
			{
				System.out.println("Caught");
			}
		}
		
		this.n = n;
		System.out.println("Put: " + n);
		valueSet = true;
		notify();
		
		return n;
	}
	
	
}

class Producer implements Runnable
{
	Q q;

	public Producer(Q q)
	{
		this.q = q;
		
		new Thread(this, "Producer").start();
	}

	@Override
	public void run()
	{
		int n=0;
		while(true)
		{
			q.put(n++);
		}
		
	}
}

class Consumer implements Runnable
{
	Q q;

	public Consumer(Q q)
	{
		this.q = q;
		
		new Thread(this, "Consumer").start();
	}

	@Override
	public void run()
	{
		while(true)
		{
			q.get();
		}
		
	}
}

public class ProdCons
{
	public static void main(String[] args)
	{
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		
		System.out.println("Press 'Ctrl + C' to stop");
	}
}
