package package1;

import java.io.File;

public class Listing
{
	public static void main(String[] args)
	{
		if(args.length == 0)
		{
			System.out.println("usage: \"java Listing.java DirectoryName");
			return;
		}
		
		File file = null;
		try
		{
			file = new File(args[0]);
			File paths[] = file.listFiles();
			printContents(paths, 1);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	private static void printContents(File[] paths, int tableLength)
	{
		for(File file: paths)
		{
			for(int i=0; i<tableLength; i++)
			{
				System.out.print("\t");
			}
			if(file.isDirectory())
			{
				System.out.println(">" + file.getName());
				printContents(file.listFiles(), tableLength + 1);
			}
			else
			{
				System.out.println("|" + file.getName());
			}
		}
		
	}
	
	
}
