package p1;

import java.util.Scanner;

abstract class Figure
{
	protected int a;
	protected int b;
	abstract void areaCalc();
}

class Rectangle extends Figure
{
	Rectangle (int a, int b)
	{
		this.a = a;
		this.b = b;
	}
	
	void areaCalc()
	{
		System.out.println("Area of the rectangle: " + (a*b));
		return;
		
	}
}

class Triangle extends Figure
{
	Triangle (int a, int b)
	{
		this.a = a;
		this.b = b;
	}
	
	void areaCalc()
	{
		System.out.println("Area of the triangle: " + ((a*b)/2));
		return;
	}
}

class Square extends Figure
{
	Square (int a)
	{
		this.a = a;
	}
	
	void areaCalc()
	{
		System.out.println("Area of the square: " + (a*a));
		return;
	}
}

public class FigureTest
{
	private static Scanner input = new Scanner(System.in);
	public static void main(String[] args)
	{
		System.out.println("Enter two integers: ");
		int a = input.nextInt();
		int b = input.nextInt();
		
		Rectangle r = new Rectangle(a, b);
		Square s = new Square(a);
		Triangle t = new Triangle(a, b);
		Figure figure;
		
		figure = r;
		figure.areaCalc();
		
		figure = s;
		figure.areaCalc();
		
		figure = t;
		figure.areaCalc();
		
	}

}
