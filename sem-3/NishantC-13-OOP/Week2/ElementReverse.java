import java.util.Scanner;

class ElementReverse
{
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.print("Please enter the length of the array");
		int len = input.nextInt();
		int[] arr = new int[len];

		for(int i=0; i<len; i++)
		{
			arr[i] = input.nextInt();
		}

		revArray(arr);

		for(int i=0; i<arr.length; i++)
		    System.out.print(arr[i] + "\t");
		
		System.out.println();
	}


	static void revArray(int[] arr)
	{
		int temp;
		for(int i=0; i<arr.length/2; i++)
		{
			//Swaping elements
			temp = arr[i];
			arr[i] = arr[arr.length - i - 1];
			arr[arr.length - i - 1] = temp;
		}
	}
}
		
		
