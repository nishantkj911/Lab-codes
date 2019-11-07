class PyramidGenerator
{
	public static int n = 5;
 
	public static void main(String[] args)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j = 0; j<i; j++)
			{
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
