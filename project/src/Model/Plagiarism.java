package Model;
import gst.GreedyStringTiling;
import gst.PlagResult;
import org.json.simple.JSONObject;

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
		
		t=t.replaceAll("/\\*(.|\\n)*?\\*/","\n");
		//removes multi line comments
		
		
		t=t.replaceAll("//.*\n","");
		//removes single line comments
		
		t=t.replaceAll(" [ \t]+","");
		//removes spaces and tabs
		
		t=t.replaceAll("#.*\n","");
		//removes #include statement
		
		t=t.replaceAll("import.*\n","");
		
		t=t.replaceAll("\n+","\n");
		
		t=t.replaceAll("^\n","");
		//removes blank lines
		
		return t;
	}
	
	
	public static void main(String args[])
	{
//		Plagiarism p = new Plagiarism();
//		String first = p.createStringFromFile("WebContent/WEB-INF/p1.c");
//		String second = p.createStringFromFile("WebContent/WEB-INF/p2.c");
//		first=Plagiarism.clean(first);
//		second=Plagiarism.clean(second);
//
//		PlagResult rs = GreedyStringTiling.run(second,first,2,(float)0.85);
//		System.out.println(rs.__str__());
		JSONObject obj=new JSONObject();
		obj.put("eStatus",true);
		obj.put("signStatus",false);



System.out.println(obj.toJSONString());
		System.out.println(user_data.isEmailAvailable("suraj14wasfddje@gmail.com"));
		
	}

}
