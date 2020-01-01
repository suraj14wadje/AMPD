package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

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


	public static String getSubjectNameFromSubId(int sub_id)
	{
		String result = "";
		connect connect = new connect();
		try
		{
			PreparedStatement ps= connect.conn.prepareStatement("select sub_name from subject where sub_id = ?");
			ps.setInt(1,sub_id);
			ResultSet rs = ps.executeQuery();

			if(rs.next())
			{
				result = rs.getString("sub_name");

			}
			connect.close();
		}catch (Exception ex)
		{
			connect.close();
			System.out.println(ex);
		}

		return result;
	}


	public static Vector getSubjectNamesFromC_id(int c_id)
	{
		Vector result = new Vector();
		connect connect = new connect();
		try
		{
			PreparedStatement ps= connect.conn.prepareStatement("select sub_name,sub_id from subject where c_id = ?");
			ps.setInt(1,c_id);
			ResultSet rs = ps.executeQuery();

			while (rs.next())
			{
				Vector temp = new Vector();
				temp.add(rs.getString("sub_name"));
				temp.add(rs.getInt("sub_id"));
				result.add(temp);
			}

		}catch (Exception ex)
		{
			System.out.println(ex);
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
