package Applets;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.util.Scanner;

public class GCD extends Applet
{

	/**<applet code = "GCD.java" width = 50 height = 50 >
	 * <param name = a value = 60>
	 * <param name = b value = 72></applet>
	 */
	private static final long serialVersionUID = 1L;
	
	int numa, numb ;

	private Scanner input;
	
	public void init()
	{
		this.setBackground(Color.cyan);
		this.setForeground(Color.black);
	}
	
	public void start()
	{
		input = new Scanner(System.in);
		
		System.out.println("Enter the numbers");
		numa = input.nextInt();
		numb = input.nextInt();

			
	}
	
	int calcGCD(int a, int b)
	{
		if(b > a)
			return calcGCD(b, a);
		
		if(b==0)
			return a;
		if(a==0)
			return b;
		
		return calcGCD(b, a%b);
	}
	
	public void paint(Graphics g)
	{
		g.drawString("GCD is " + calcGCD(numa, numb), 50, 50);
	}
	
	

}
