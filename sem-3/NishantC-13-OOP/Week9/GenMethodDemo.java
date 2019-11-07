class GenMethod
{
	public static <T> void dispArr(T[] arr)
	{
		System.out.println("The array of " + arr[0].getClass() + " is: ");
		for(int i=0; i<arr.length; i++)
		{
			System.out.println(arr[i] + "\t");
		}
	}
	
}

class GenMethodDemo
{
	public static void main(String[] args)
	{
		Integer[] intArr = {129, 0, -584, 435, -654};

		Double[] douArr = {52.107, 543.019, -9.4};
		
		String[] strArr = {"Nishant", "Kartikeya", "Joshyabhatla"};
		
		GenMethod.dispArr(intArr);
		GenMethod.dispArr(douArr);
		GenMethod.dispArr(strArr);
	}
}
	
	
