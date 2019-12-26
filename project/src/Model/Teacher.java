package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Teacher extends user_data {
	
	String firstName;
	String lastName;
	public Teacher(String email, String password, String firstName, String lastName) {
		super(email, password);
		this.firstName = firstName;
		this.lastName = lastName;
	}
	@Override
	public boolean createNew() {
		// TODO Auto-generated method stub
		
		boolean result;
		int count;
		connect connection = new connect();
		result = super.createNew();
		if(result)
		{
			try {
				PreparedStatement ps = connection.conn.prepareStatement("insert into Teacher values(default,?,?,?);");
				ps.setString(1,firstName);
				ps.setString(2,lastName);
				ps.setString(3,super.getEmail());
				count = ps.executeUpdate();
				ps.close();
				connection.close();
				
				if(count == 1)
					result = true;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		}
		else
		{
			result =  false;
		}
		
		return result;
	}
	
	public static boolean update(String email,String firstName,String lastName)
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update teacher set first_name=?,last_name=? where email = ? ");
			ps.setString(1,firstName);
			ps.setString(2,lastName);
			ps.setString(3,email);
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
	
	public static boolean delete(int t_id)
	{
		boolean result=false;
		String email;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select email from teacher where t_id = ? ;");
			ps.setInt(1, t_id);
			ResultSet rs = ps.executeQuery();
			rs.next();
			email = rs.getString("email");
			result = user_data.delete(email);
			rs.close();
			ps.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		return result;
	}
	

	
}
	
	

