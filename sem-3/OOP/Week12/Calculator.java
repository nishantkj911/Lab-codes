import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*<applet code = "Calculator.java" width = 300 height = 300> </applet> */

public class Calculator extends JApplet
{
	JButton compute;
	JLabel jl1;
	JTextField jtf1;
	JTextField jtf2;
	JLabel jl2;
	JLabel jl3;
	JLabel jl4;
	JLabel jl5;
	JLabel jl6;	
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
		catch(Exception e) {}
	}
		
	public void makeGUI()
	{
		compute = new JButton("Compute");
		jtf1 = new JTextField(10);
		jtf2 = new JTextField(10);
		jl1 = new JLabel("Sum: ");
		jl2 = new JLabel("Difference: ");
		jl3 = new JLabel("Product: ");
		jl4 = new JLabel("Quotient");
		jl5 = new JLabel("Num1:");
		jl6 = new JLabel("Num2:");
		
		setLayout(new FlowLayout());
		add(jl5);
		add(jtf1);
		add(jl6);
		add(jtf2);
		add(jl1);
		add(jl2);
		add(jl3);
		add(jl4);
		add(compute);
		
		compute.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent ae)
					{
						calculate();
					}
					
		});
		
	}
	
	void calculate()
	{
		double a,b;
		a = Double.parseDouble(jtf1.getText());
		b = Double.parseDouble(jtf2.getText());
		
		jl1.setText("Sum: " + (a + b));
		jl2.setText("Difference: " + (a - b));
		jl3.setText("Product: " + (a * b));
		jl4.setText("Quotient: " + (a / b));												
	}
}
