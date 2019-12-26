package Model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class connect {
	final private String ADDRESS = "localhost:5432/temp";
	final private String USER ="postgres";
	final private String PASS = "1234";
	public Connection conn;
	
	public connect()
	{
		try
		{
			
			Class.forName("org.postgresql.Driver");
			conn = DriverManager.getConnection("jdbc:postgresql://"+ADDRESS,USER,PASS);
			if(conn == null)
			{
				System.out.println("Connection Failed !");
			}
			else
			{
				System.out.println("Connection Successful!");
			}

		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	public void close()
	{
		try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void finalize() throws Throwable
	{
		conn.close();
		//System.out.println("closed succesfully");
	}
		

}
