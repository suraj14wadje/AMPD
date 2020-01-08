package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

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
			e.printStackTrace();
		}
		
		
		return result;
	}

	public static int getAssignmentCountFromSub_id(int s_id)
	{
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select count(a_no) from Assignment where sub_id = ?;");
			ps.setInt(1,s_id);
			ResultSet rs = ps.executeQuery();
			rs.next();
			connect.close();
			return rs.getInt(1);

		}catch (Exception ex)
		{
			connect.close();
		}
		return 0;

	}

	public static int getSubject_IdFroma_no(int a_no)
	{
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select sub_id from Assignment where a_no = ?;");
			ps.setInt(1,a_no);
			ResultSet rs = ps.executeQuery();
			rs.next();

			int result = rs.getInt(1);
			connect.close();
			return result;

		}catch (Exception ex)
		{
			System.out.println(ex);
			connect.close();
		}
		return 0;

	}


	public static String getAssNameFromA_no(int a_no)
	{
		String result="";

		connect connection = new connect();

		try {
			PreparedStatement ps = connection.conn.prepareStatement("select a_name from assignment where a_no = ?;");
			ps.setInt(1,a_no);

			ResultSet rs = ps.executeQuery();
			if(!rs.next())
			{
				connection.close();
				return null;
			}else {
				result = rs.getString("a_name");
			}
			connection.close();

		}catch(Exception ex)
		{
			System.out.println(ex);
		}


		return result;
	}



	public static Vector getAssNameAndNoFromSubId(int sub_id)
	{
		Vector result=new Vector();

		connect connection = new connect();

		try {
			PreparedStatement ps = connection.conn.prepareStatement("select a_no,a_name from assignment where sub_id = ? order by a_no desc");
			ps.setInt(1,sub_id);
			ResultSet rs = ps.executeQuery();
			if(!rs.next())
			{
				connection.close();
				return null;
			}else {
				do{
					Vector temp = new Vector();
					temp.add(rs.getString("a_no"));
					temp.add(rs.getString("a_name"));
					result.add(temp);

				}while (rs.next());
			}
			connection.close();

		}catch(Exception ex)
		{
			System.out.println(ex);
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
