import java.util.Scanner;

class LinearSearch
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the length of the array: ");
		int len = input.nextInt();
		int[] arr = new int[len];

		System.out.println("Enter the elements of the array: ");
		for(int i=0; i<len; i++)
		{
			arr[i] = input.nextInt();
		}
		
		System.out.print("Please enter the element to be searched");
		int search = input.nextInt();

		boolean found = linSearch(arr, search);

		if(found)
			System.out.println("Found");
		else 
			System.out.println("Not Found");
	}
	
	static boolean linSearch(int[] arr,int search)
	{
		for(int i=0; i<arr.length; i++)
		{
			if(arr[i] == search)
				return true;
		}
		
		return false;
	}
}
