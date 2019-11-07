import java.util.Scanner;

class Matrix
{
	int r, c;
	int[][] mat;
	
	Matrix (int r, int c)
	{
		this.r = r;
		this.c = c;
		
		mat = new int[this.r][this.c];
	}
	
	void init()
	{
		System.out.println("Enter the elements of the matrix " + r + "x" + c);
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				mat[i][j] = MatDemo.input.nextInt();
			}
		}
	}
	
	void display()
	{
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				System.out.print(mat[i][j] + "\t");
			}
			System.out.println();
		}
	}
	
	
}

class ImplThread implements Runnable
{
	Thread t;
	int[] arr;
	int total = 0;
	
	public ImplThread(int[] arr)
	{
		t = new Thread(this);
		this.arr = arr;
		
		t.start();
	}

	@Override
	public void run()
	{
		for(int a: arr)
		{
			total+=a;
		}
		
	}
}

class MatDemo
{
	public static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.println("Rows: ");
		int r = input.nextInt();
		System.out.println("Columns: ");
		int c = input.nextInt();
		
		Matrix mat = new Matrix(r, c);
		mat.init();
		mat.display();
		
		ImplThread[] thrds = new ImplThread[r];
		
		for(int i=0; i<thrds.length; i++)
		{
			thrds[i] = new ImplThread(mat.mat[i]);
		}
		
			
		try
		{
			for(int i=0; i<thrds.length; i++)
				thrds[i].t.join();
		}
		catch(InterruptedException exc)
		{
			System.out.println("Main thread interrupted");
		}
		
		int totalSum = 0;
		for(int i=0; i<thrds.length; i++)
		{
			totalSum += thrds[i].total;
		}
		
		System.out.println("The sum of matrix is " + totalSum);
	}
}