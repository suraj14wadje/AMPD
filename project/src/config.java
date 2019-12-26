import Model.connect;
import java.sql.*;
import java.io.*;

public class config {
	
	Connection conn;
	int num_of_tables = 9;
	String CREATE_TABLE_FILE = "createtable.sql";
	
	public config()
	{
		connect myconnection = new connect(); 
		conn = myconnection.conn;
		if(getTableCount() != num_of_tables)
		{
			System.out.println("some tables not found\n Creating Tables......");
			createTableFromFile();
			System.out.println("table creation is Done..");
			getTableCount();
		}
		try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public int createTableFromFile()
	{
		int count=0;
		InputStream is;
		Statement st;
		try {
			is = new FileInputStream(CREATE_TABLE_FILE);
		BufferedReader buf = new BufferedReader(new InputStreamReader(is)); 
		String line = buf.readLine(); StringBuilder sb = new StringBuilder(); 
		while(line != null)
		{ 
			sb.append(line).append("\n"); line = buf.readLine();
		}
		String fileAsString = sb.toString(); 
		st = conn.createStatement();
		count = st.executeUpdate(fileAsString);
		
		}

	 catch (Exception e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	 }
		return count;
	} 
		
	
	public int getTableCount()
	{
		int count = 0;
		try
		{
			DatabaseMetaData dbmd = conn.getMetaData();
			String type[] = {"TABLE"};
			ResultSet rs = dbmd.getTables(null, null,null,type);
			System.out.println("following are the tables present in database : ");
			while(rs.next())
			{
				count++;
				System.out.println(rs.getString("TABLE_NAME"));
			}
		}
		catch(Exception Ex)
		{
			System.out.println(Ex);
		}
		return count;
	}
	
	public static void main(String args[])
	{
		new config();
	}
	
	

}
