import java.util.Scanner;

class BubbleSort
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

		bubbleSort(arr);
		
		System.out.print("The sorted array is: ");
		for(int i=0; i<arr.length; i++)
		    System.out.print(arr[i] + "\t");
		
		System.out.println();
    }
    
    
    //This method sorts it in ascending order
    static void bubbleSort(int[] arr)
    {
        for(int sortedArray=arr.length-1; sortedArray>=0; sortedArray--)
        {
            for(int i=sortedArray; i<arr.length-1; i++)
            {
                if(arr[i] > arr[i+1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
    }    
}
