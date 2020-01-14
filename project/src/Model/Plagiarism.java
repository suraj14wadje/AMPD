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


		t=t.replaceAll(" [ \t]+","");
		//removes spaces and tabs

//
		t=t.replaceAll("#include.*","");
		//removes #include statement
//
		t=t.replaceAll("import.*","");
		return t;
	}

	
	
	public static void main(String args[])
	{
		Plagiarism p = new Plagiarism();
		String first,second;
		int i = 32,j=33;
		PlagResult pr;

		first = Submission.getProgramFromSub_id(i);
		second = Submission.getProgramFromSub_id(j);
//		System.out.print("matching "+i+" and "+j);
//		pr = GreedyStringTiling.run(first,second,2,(float) 0.80);
//
//		System.out.println(" match : "+pr.similarity*100);



		for(i =42;i<45;i++)
		{
			for(j = 42;j<45;j++)
			{
				if(i!=j)
				{
					first = Submission.getProgramFromSub_id(i);
					second = Submission.getProgramFromSub_id(j);
					System.out.print("matching "+i+" and "+j);

					pr = GreedyStringTiling.run(first,second,2,(float) 0.60);


					System.out.println(" match : "+pr.similarity*100);
					System.out.println("similarity "+i +": "+pr.id1+" "+j+": "+pr.id2);



				}
			}
		}

		


	}

}
