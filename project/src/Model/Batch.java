package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class Batch {
	
	String batch_name;
	int c_id;
	int t_id;
	public Batch(String batch_name, int c_id, int t_id) {
		super();
		this.batch_name = batch_name;
		this.c_id = c_id;
		this.t_id = t_id;
	}

	public static Vector getBatchNameFromC_id(int c_id)
	{
		Vector result = new Vector();
		connect connect = new connect();
		try{
			PreparedStatement statement = connect.conn.prepareStatement("select batch_name,b_id from batch where  c_id=?;");
			statement.setInt(1,c_id);
			ResultSet rs = statement.executeQuery();
			while (rs.next())
			{
				String batch_name = rs.getString("batch_name");
				int b_id = rs.getInt("b_id");
				Vector temp = new Vector();
				temp.add(batch_name);
				temp.add(b_id+"");

				result.add(temp);
			}
			connect.close();
		}catch (Exception ex)
		{
			System.out.println(ex);
		}
		return result;
	}
	
	public boolean createNew()
	{
		boolean result=false;
		int count = 0;
		
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("insert into batch values(default,?,?,?);");
			ps.setString(1,batch_name);
			ps.setInt(2,c_id);
			ps.setInt(3,t_id);
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



	
	public static boolean update(int id,String batch_name,int c_id,int b_id)
	{
		boolean result = false;
		int count =  0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update batch set batch_name = ?,c_id = ?,t_id = ? where b_id = ?");
			ps.setString(1,batch_name);
			ps.setInt(2,c_id);
			ps.setInt(3,b_id);
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
	
	public static boolean delete(int b_id)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from batch where b_id = ? ;");
			ps.setInt(1, b_id);
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
