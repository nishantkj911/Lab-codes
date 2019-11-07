import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;

/*<applet code = "Circle.java" width = 300 height = 300 > </applet>*/

public class Circle extends JApplet
{
	JLabel area;
	JLabel radius;
	JLabel dia;
	JLabel circum;
	
	int r;
	
	public void init()
	{
		try
		{
			SwingUtilities.invokeAndWait(new Runnable() {
						public void run()
						{
							makeGUI();
						}
			});
		}
		catch(Exception e){}
		
	}
	
	public void makeGUI()
	{
		r = (int) (Math.random() * 80);
		double d = 2 * r;
		double c = 2 * Math.PI * r;
		double a = Math.PI * r * r;
		
		radius = new JLabel("Radius");
		dia = new JLabel("Diameter");
		circum = new JLabel("Circumference");
		area = new JLabel("Area");
		
		setLayout(new FlowLayout());
		
		radius.setText("Radius: " + r);
		dia.setText("Diameter: " + d);
		circum.setText("Circumference: " + c);
		area.setText("Area: " + a);
		
		add(radius);
		add(dia);
		add(circum);
		add(area);
		
		repaint();
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		
		g.drawOval(100, 100, r, r);
	}
}
