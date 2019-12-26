package Model;

import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Subject {
	int c_id;
	String sub_name;
	
	public Subject(int c_id, String sub_name) {
		this.c_id = c_id;
		this.sub_name = sub_name;
	}
	
	public boolean createNew()
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();

		try 
		{
			
			PreparedStatement ps = connection.conn.prepareStatement("insert into Subject values(default,?,?)");
			ps.setString(2,sub_name);
			ps.setInt(1,c_id);
			count = ps.executeUpdate();
			ps.close();
			connection.close();
			if(count == 1)
			{
				result = true;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return result;
	}
	
	public static boolean update(int sub_id,int c_id,String sub_name)
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update subject set c_id = ?,sub_name=? where sub_id = ?");
			ps.setInt(1,c_id);
			ps.setString(2,sub_name);
			ps.setInt(3,sub_id);
			count = ps.executeUpdate();
			ps.close();
			connection.close();
			if(count == 1)
			{
				result = true;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return result;
	}
	
	public static boolean delete(int sub_id)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from subject where sub_id = ? ;");
			ps.setInt(1, sub_id);
			result = ps.executeUpdate();
			ps.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		if(result==1)
			return true;
		else
			return false;
	}
		
		
		
	
	

}
