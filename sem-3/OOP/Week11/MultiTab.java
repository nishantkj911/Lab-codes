package Applets;

import java.applet.*;
import java.util.*;
import java.awt.*;



public class MultiTab extends Applet
{
	/**<applet code = "MultiTab.java" width = 50 height = 50> </applet> */
	
	
	private static final long serialVersionUID = 1L;
	int nstr;
	Scanner sc = new Scanner(System.in);
	
	public void start()
	{
		System.out.println("Enter the number: ");
		nstr = sc.nextInt();
	}
	
	public void paint(Graphics g)
	{
		for(int i=1; i<11; i++)
		{
			g.drawString(nstr + " * " + i + " = " + (nstr*i) + "\n", 60, 20*i);
//			g.setColor(Color.white);
		}
	}
}
