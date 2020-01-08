package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class Class_1 {
	
	String name;
	
	Class_1(String name)
	{
		this.name = name;
	}
	
	public boolean createNew()
	{
		boolean result=false;
		int count = 0;
		
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("insert into class values(default,?);");
			ps.setString(1,name);
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


	public static Vector getClassAndBatchNamesFromT_id(int t_id)
	{
		Vector result = new Vector();
		connect connect = new connect();
		try{
			PreparedStatement statement = connect.conn.prepareStatement("select batch_name,class_name,b_id from class,batch where class.c_id = batch.c_id and t_id=?;");
			statement.setInt(1,t_id);
			ResultSet rs = statement.executeQuery();
			while (rs.next())
			{
				String class_name = rs.getString("class_name");
				String batch_name = rs.getString("batch_name");
				int b_no = rs.getInt("b_id");
				Vector temp = new Vector();
				temp.add(class_name);
				temp.add(batch_name);
				temp.add(b_no+"");

				result.add(temp);
			}
			connect.close();
		}catch (Exception ex)
		{
			System.out.println(ex);
		}
		return result;
	}


	public static Vector getAllClassNames()
	{
		Vector result = new Vector();
		connect connect = new connect();
		try{
			PreparedStatement statement = connect.conn.prepareStatement("select class_name,c_id from class ;");

			ResultSet rs = statement.executeQuery();
			while (rs.next())
			{
				String class_name = rs.getString("class_name");
				int c_id = rs.getInt("c_id");
				Vector temp = new Vector();
				temp.add(class_name);
				temp.add(c_id+"");
				result.add(temp);
			}
			connect.close();
		}catch (Exception ex)
		{
			System.out.println(ex);
		}
		return result;
	}


	public static Vector getClassNamesFromT_id(int t_id)
	{
		Vector result = new Vector();
		connect connect = new connect();
		try{
			PreparedStatement statement = connect.conn.prepareStatement("select class_name,c_id from class where c_id in (select c_id from batch where t_id = ? );");
			statement.setInt(1,t_id);
			ResultSet rs = statement.executeQuery();
			while (rs.next())
			{
				String class_name = rs.getString("class_name");
				int c_id = rs.getInt("c_id");
				Vector temp = new Vector();
				temp.add(class_name);
				temp.add(c_id+"");

				result.add(temp);
			}
			connect.close();
		}catch (Exception ex)
		{
			System.out.println(ex);
		}
		return result;
	}
	public static boolean update(int id,String name)
	{
		boolean result = false;
		int count =  0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update table class set class_name = ? where c_id = ?");
			ps.setString(1,name);
			ps.setInt(2,id);
			ps.close();
			connection.close();
			count = ps.executeUpdate();
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
	
	public static boolean delete(int c_id)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from class where c_id = ? ;");
			ps.setInt(1, c_id);
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
