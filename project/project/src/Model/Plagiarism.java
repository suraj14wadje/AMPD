package Model;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.sql.Statement;

public class Plagiarism {
	String code;
	String processed;
	String file_name;
	
	
	public String createStringFromFile(String file_name)
	{
		InputStream is;
		String str="";
		Statement st;
		try {
			is = new FileInputStream(file_name);
		BufferedReader buf = new BufferedReader(new InputStreamReader(is)); 
		String line = buf.readLine(); 
		StringBuilder sb = new StringBuilder(); 
		while(line != null)
		{ 
			sb.append(line).append("\n"); line = buf.readLine();
		}
		str = sb.toString(); 
		
		}catch(Exception ex)
		{
			System.out.println(ex);
		}
		
		return str;
	}
	
	
	public static void main(String args[])
	{
		Plagiarism p = new Plagiarism();
		String t = p.createStringFromFile("WebContent/WEB-INF/web.xml");
		String code[] = t.split("\n");
		for(int i = 0;i<code.length;i++)
		{
			if(code[i].isBlank())
				
			code[i]=code[i].replaceAll("\\s+"," ");
			System.out.println(code[i]);
		}
	}

}
