public class Complex
{
	int re;
	int im;
	
	public Complex(int re1, int im1)
	{
		this.re = re1;
		this.im = im1;
	}
	
	public Complex(int re2)
	{
		this(re2, 0);
	}
	
	public Complex()
	{
		this(0, 0);
	}
	
	public String print()
	{
		if(this.im < 0)
		{
			return this.re + " - " + Math.abs(this.im) + "i";
		}
		else
			return this.re + " + " + this.im + "i";
	}
	
	public Complex addComplex(Complex c)
	{
		Complex out = new Complex();
		out.re = this.re + c.re;
		out.im = this.im + c.im;
		return out;
	}
	
	public Complex subtractComplex(Complex c2)
	{
		Complex out = new Complex();
		out.re = this.re - c2.re;
		out.im = this.im - c2.im;
		return out;
	}
}




