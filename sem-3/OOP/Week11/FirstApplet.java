import java.awt.*;
import java.applet.*;

/*
<applet code="FirstApplet" width=300 height=100>
</applet>
*/

public class FirstApplet extends Applet
{

	public void init()
	{
		setBackground(new Color(0xfac209));
		setForeground(new Color(0x2bc213));
	}
	
	public void start(){}
	
	public void paint(Graphics g)
	{
		g.setColor(new Color(0x000000));
		g.drawRect(20, 20, 680, 240);
		g.setFont(new Font("Serif", Font.ITALIC | Font.BOLD, 32));
		g.drawString("Welcome to Applet Programming!!", 40, 50);
		
		showStatus("This is status window");
	}
}
	
