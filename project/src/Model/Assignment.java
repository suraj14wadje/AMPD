package Model;

import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Assignment {
	private String a_name;
	private int s_no;
	
	public Assignment(String a_name, int s_no) {
		this.a_name = a_name;
		this.s_no = s_no;
	}
	
	public boolean createNew()
	{
		boolean result=false;
		int count = 0;
		
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("insert into Assignment values(default,?,?);");
			ps.setString(1,a_name);
			ps.setInt(2,s_no);
			count = ps.executeUpdate();
			if(count == 1)
			{
				result = true;
			}
			connection.close();
			ps.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return result;
	}
	
	public static boolean update(int id,String a_name,int sub_id)
	{
		boolean result = false;
		int count =  0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update table assignment set a_name = ?,sub_id = ? where a_no = ?");
			ps.setString(1,a_name);
			ps.setInt(2,sub_id);
			count = ps.executeUpdate();
			ps.close();
			connection.close();
			if(count == 1)
			{
				result = true;
			}
			
		}catch(Exception ex)
		{
			System.out.println(ex);
		}
		
		
		
		
		return result;
	}
	
	public static boolean delete(int a_no)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from assignment where a_no = ? ;");
			ps.setInt(1, a_no);
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
