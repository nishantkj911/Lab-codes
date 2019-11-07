public class Time
{
	int hr;
	int min;
	int sec;
	
	public Time(int hr, int min, int sec)
	{
		if(sec > 59)
			min+=(sec/60);
		sec%=60;
		if(min > 59)
			hr+=(min/60);
		min%=60;
		
		this.hr = hr;
		this.min = min;
		this.sec = sec;
	}
	
	public Time(int hr,int min)
	{
		this(hr, min, 0);
	}
	
	public Time( int hr)
	{
		this(hr, 0, 0);
	}
	
	public Time()
	{
		this(0);
	}
	
	public String display()
	{
		return hr + ":" + min + ":" + sec;
	}
	
	public Time addTimes(Time c)
	{
		Time out = new Time();
		out.sec = this.sec + c.sec;
		out.min = this.min + c.min;
		out.hr = this.hr + c.hr;
		
		if(out.sec > 59)
			out.min = out.min + (out.sec/60);
		out.sec = out.sec % 60;
		if(out.min > 59)
			out.hr = out.hr + (out.min/60);
		out.min = out.min % 60;
		return out;
	}
	
	public Time subtractTimes(Time t)
	{
		Time out = new Time();
		if(this.sec < t.sec)
		{
			if(this.min > 0)
			{
				this.min--;
				this.sec+=60;
			}
			else
			{
				this.hr--;
				this.min+=59;
				this.sec+=60;
			}
			
		}
		
		if(this.min < t.min)
		{
			this.hr--;
			this.min+=60;
		}
		
		out.sec = this.sec - t.sec;
		out.min = this.min - t.min;
		out.hr = this.hr - t.hr;
		
		return out;
	}
	
	public int compareTimes(Time t2)
	{
		int v1 = (this.hr * 60) + (this.min * 60) + this.sec;
		int v2 = (t2.hr * 60) + (t2.min * 60) + t2.sec;
		if(v1 > v2)
		{
			return 1;
		}
		else if(v1 < v2)
			return -1;
		else return 0;
	}
}
		
