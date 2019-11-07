public class Stack
{
	private int[] arr;
	private int tos;
	
        
	public Stack()
	{
		arr = new int[200];
		tos = 0;
	}
	
	public void push(int a)
	{
		if(this.tos >= this.arr.length)
		{
			System.out.println("Stack Overflow!! Cannot add element");
			return;
		}
		this.arr[tos] = a;
		this.tos++;
	}
	
	public void pop()
	{
		if(tos == 0)
		{
			System.out.println("Stack Underflow!! Cannot remove element");
			return;
		}
		this.tos--;
		this.arr[tos] = 0;
	}
	
	public void display()
	{
		for(int i=this.tos-1; i>=0; i--)
		{
			System.out.println(this.arr[i]);
		}
	}
}
	
