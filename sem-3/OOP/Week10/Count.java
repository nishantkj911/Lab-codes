package package1;

import java.io.*;


public class Count
{

	public static void main(String[] args) throws IOException
	{
		int char_count = 0, line_count = 0, words = 0, nos = 0;
		boolean isNo = false;
		char ch;
		
		FileReader fr = new FileReader("");
		BufferedReader br = new BufferedReader(fr);
		String str;
		
		while((str = br.readLine()) != null)
		{
			char_count+=str.length();
			for(int i=0; i<str.length(); i++)
			{
				ch = str.charAt(i);
				if(ch=='.')
					line_count++;
				if(ch==' ')
					words++;
				if(ch>47 && ch<58)
					isNo = true;
				else if(isNo)
				{
					isNo = false;
					nos++;
				}
			}
		}
		
		System.out.println("\nCharacters: " + char_count + "\nLines: " + 
				line_count + "\nWords: " + words + "\nNumbers: " + nos);

		
		br.close();
		fr.close();
	}

}
