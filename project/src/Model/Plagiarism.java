package Model;
import gst.GreedyStringTiling;
import gst.PlagResult;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.sql.Statement;
import java.util.Vector;

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
	
	public static String clean(String t)
	{

		t=t.replaceAll("\".*\"","[STRING_CONSTANT]");
//
		t=t.replaceAll("(\\\"[^\\\"]*\\\"(?!\\\\))|(//[^\\n]*$|/(?!\\\\)\\*[\\s\\S]*?\\*(?!\\\\)/)","");
		//removes multi line comments
//
//
		t=t.replaceAll(" [ \t]+","");
		//removes spaces and tabs

//
		t=t.replaceAll("#.*","");
		//removes #include statement
//
		t=t.replaceAll("import.*","");
		return t;
	}

	
	
	public static void main(String args[])
	{
		Plagiarism p = new Plagiarism();
		String first = Submission.getProgramFromSub_id(4);
//		String second = p.createStringFromFile("WebContent/WEB-INF/p2.c");

		first=Plagiarism.clean(first);
		System.out.println(first);
//		second=Plagiarism.clean(second);
//
//		PlagResult rs = GreedyStringTiling.run(second,first,2,(float)0.85);
//		System.out.println(rs.__str__());

		


	}

}
