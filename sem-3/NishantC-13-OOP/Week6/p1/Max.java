package p1;

import java.util.*;

public class Max
{
	public static int max(int a, int b, int c)
	{
		if(a>=b && a>=c)
			return a;
		if(b>=c && b>=a)
			return b;
		return c;
	}
	
	public static float max(float a, float b, float c)
	{
		if(a>=b && a>=c)
			return a;
		if(b>=c && b>=a)
			return b;
		return c;
	}
	
	public static int max(ArrayList<Integer> a)
	{
		int max = 0;
		for(int a1 : a)
		{
			if(a1 > max)
				max = a1;
		}
		
		return max;
	}
	
	public static int max(int[][] a)
	{
		int max = 0;
		for(int i=0; i<a.length; i++)
			for(int j=0; j<a[0].length; j++)
			{
				if(a[i][j] > max)
					max = a[i][j];
			}
		return max;
	}
}
