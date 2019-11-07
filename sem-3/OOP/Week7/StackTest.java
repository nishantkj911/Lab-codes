import java.util.*;

interface Stack
{
	void push(int a);
	int pop();
}

class FixedStack implements Stack
{
	int[] arr;
	int top;
	
	FixedStack (int len)
	{
		arr = new int[len];
		top=-1;
	}
	
	public void push(int a)
	{
		if(top+1 == arr.length)
		{
			System.out.println("Stack Overflow!! Cannot add element");
			return;
		}
		
		arr[++top] = a;
		 
	}
	
	public int pop()
	{
		if(top == -1) {
			System.out.println("Stack Underflow!! Cannot remove element");
			return -32276;
		}
		int a = arr[top];
		arr[top--] = 0;
		return a;
	}
	
}

class DynamicStack implements Stack
{
	int[] arr;
	int top;
	
	DynamicStack()
	{
		arr = new int[1];
		top = -1;
	}
	
	public void push(int a)
	{
		if(top+1 == arr.length)
		{
			int[] arr2 = new int[2*arr.length];
			for(int i=0; i<arr.length; i++)
				arr2[i] = arr[i];
				
			this.arr = arr2;
		}
		
		arr[++top] = a;
		 
	}
	
	public int pop()
	{
		if(top == -1) {
			System.out.println("Stack Underflow!! Cannot remove element");
			return -32276;
		}
		int a = arr[top];
		arr[top--] = 0;
		return a;
	}
}

class StackTest
{
	private static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.println("1. Fixed\n2. Dynamic");
		switch(input.nextInt())
		{
			case 1:
				System.out.println("Enter the length of stack");
				FixedStack fs = new FixedStack(input.nextInt());
				Stack st = fs;
				
				System.out.println("Input the elements");
				for(int i=0; i<fs.arr.length; i++)
				{
					st.push(input.nextInt());
				}
				
				
				System.out.println("Fixed Stack is: ");
				for(int i=fs.top; i>=0; i--)
				{
					System.out.println(st.pop() + "\t");
				}
				break;
				
			case 2:
				DynamicStack ds = new DynamicStack();
				System.out.println("Keep entering nos. and 'q' to exit");
				Stack st1 = ds;
				while(true)
				{
					String s = input.next();
					if(s.compareTo("q") == 0)
						break;
						
					st1.push(Integer.parseInt(s));
				}
				
				System.out.println("Dynamic Stack is :");
				for(int i=ds.top; i>=0; i--)
				{
					System.out.println(st1.pop() + "\t");
				}
				break;
			default:
				System.out.println("Invalid Input");
		}
	}
}
