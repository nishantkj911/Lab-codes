import java.util.Scanner;

class InsertDelete
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the length of the array");
		int len = input.nextInt();
		int[] arr = new int[len+1];
	
		for(int i=0; i<len; i++)
		{
			arr[i] = input.nextInt();
		}

		System.out.print("1. Insertion, 2. Deletion: ");
		int choice = input.nextInt();
		
		switch(choice)
		{
			case 1:
				insertion(arr);
				break;
				
			case 2:
				deletion(arr);
				break;
		}
		
	}
		
	static void insertion(int[] arr)
	{
		System.out.print("Please enter the element to be inserted");
		int ele = input.nextInt();
		System.out.print("Please enter the position of the new element");
		int pos = input.nextInt();
		pos--;
		
		for(int i=arr.length - 2; i>=pos; i--)
		{
			arr[i-1] = arr[i];
		}
		
		arr[pos] = ele;
		
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i] + "\t");
		System.out.println();
	}
	
	static void deletion(int[] arr)
	{
		System.out.print("Please enter the position of the to be deleted");
		int pos = input.nextInt();
		pos--;
		
		for(int i=pos; i<=arr.length-2; i++)
		{
			arr[i+1] = arr[i];
		}
		
		for(int i=0; i<arr.length-2; i++)
			System.out.print(arr[i] + "\t");
		System.out.println();
	}
}
