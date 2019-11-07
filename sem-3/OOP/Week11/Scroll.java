package Applets;

import java.applet.*;
import java.awt.*;

public class Scroll extends Applet implements Runnable
{
	/**<applet code = "Scroll.java" width = 50 height = 50> </applet> */
	
	Thread th = null;
	String text = "Hello World                       ";
	
	public void init()
	{
		setBackground(Color.CYAN);
		setForeground(Color.blue);
	}

	private static final long serialVersionUID = 1L;
	
	public void start()
	{
		th = new Thread(this);
		th.start();
	}
	

	@Override
	public void run()
	{
		char ch;
		try 
		{
			while(true)
			{
				repaint();
				Thread.sleep(150);
				ch = text.charAt(0);
				text = text.substring(1, text.length()) + ch;
			}
		}
		catch (InterruptedException e)
		{
			System.out.println("Exception Handled");
		}
	}
	
	public void paint(Graphics g)
	{
		g.drawString(text, 50, 50);
		g.setColor(Color.BLACK);
	}
	
}
