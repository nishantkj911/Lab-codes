class NumericFns<T extends Number>
{
	T num;
	
	NumericFns (T num)
	{
		this.num = num;
	}
	
	void reciprocal()
	{
		System.out.println("Reciprocal is " + (1/num.doubleValue())); 
	}
	
	void fraction()
	{
		double frac = num.doubleValue() - num.intValue();
		System.out.println("The fractional part is " + frac);
	}
	
	void absEqual(NumericFns<? extends Number> o)
	{
		if( Math.abs(num.doubleValue()) == Math.abs(o.num.doubleValue()))
		{
			System.out.println("The absolute values are equal");
		}
		else
		{
			System.out.println("The absolute values are not equal");
		}
	}
	
}

class BoundsDemo
{
	public static void main(String[] args)
	{
		NumericFns<Integer> n1 = new NumericFns<>(78);
		NumericFns<Double> n2 = new NumericFns<>(5.458);
		
		n1.reciprocal();
		n1.fraction();
		
		n2.reciprocal();
		n2.fraction();
		
		n1.absEqual(n2);
	}
}
