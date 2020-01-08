package Model;
import java.security.*;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class user_data {
	private String email;
	private String password;
	private String salt;
	
	
	
	
	public user_data(String email,String password)
	{
		this.email = email;
		this.password = password;
		
	}

	public static boolean isEmailAvailable(String email)
	{
		boolean result=false;

		connect connection = new connect();
		try
		{
			PreparedStatement ps = connection.conn.prepareStatement("select email from user_data where email = ?;");
			ps.setString(1,email);

			ResultSet rs = ps.executeQuery();
			if(rs.next())
			{
				if(email.equals(rs.getString("email")))
				{
					return true;
				}
			}

		}catch(Exception ex)
		{
			System.out.println(ex);
			return false;
		}


		return  result;
	}
	
	public static boolean update(String oldEmail,String email,String password)
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update user_data set email = ?,passhash=? where email=?");
			password = user_data.generateHash(password);
			ps.setString(1,email);
			ps.setString(2,password);
			ps.setString(3,oldEmail);
			count = ps.executeUpdate();
			if(count == 1)
			{
				result = true;
			}
			ps.close();
			connection.conn.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return result;
		
	}

	public static boolean updateEmail(String oldEmail,String email)
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();

		try {
			PreparedStatement ps = connection.conn.prepareStatement("update user_data set email = ?where email=?");
			ps.setString(1,email);
			ps.setString(2,oldEmail);
			count = ps.executeUpdate();
			if(count == 1)
			{
				result = true;
			}
			ps.close();
			connection.conn.close();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


		return result;

	}
	
	public boolean createNew()
	{
		boolean ans=false;
		int result=0;
		connect connection = new connect();
		
		
		password = generateHash(password);
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("insert into user_data values(?,?,?);");
			ps.setString(1,email);
			ps.setString(2,salt);
			ps.setString(3,password);
			result = ps.executeUpdate();
			connection.conn.close();
			ps.close();
			if(result == 1)
			{
				ans = true;
			}
				
		}
		
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		
		
		
		return ans;
	}
	
	
	
	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public static boolean authenticate(String email,String password)
	{
		connect connection = new connect();
		boolean ans= false;
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select * from user_data where email = ?");
			ps.setString(1,email);
			ResultSet rs = ps.executeQuery();
			connection.conn.close();
			if(rs.next()==false)
			{
				return false;
			}
			String hash = rs.getString("passhash");
			rs.close();
			ps.close();
			password = generateHash(password);
			if(hash.equals(password))
			{
				ans = true;
			}
			
			
		
			
			
		}
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return ans;
		
	}
	
	
	
	

	private static String generateHash(String password)
	{
		StringBuilder sb = new StringBuilder();
		 try {
	            // Create MessageDigest instance for MD5
	            MessageDigest md = MessageDigest.getInstance("SHA-256");
	            //Get the hash's bytes 
	            byte[] bytes = md.digest(password.getBytes());
	            //This bytes[] has bytes in decimal format;
	            //Convert it to hexadecimal format
	            for(int i=0; i< bytes.length ;i++)
	            {
	                sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
	            }
	            //Get complete hashed password in hex format
	        } 
	        catch (NoSuchAlgorithmException e) 
	        {
	            e.printStackTrace();
	        }
		 return sb.toString();
	       // System.out.println(password);
	}
	
	
	public static boolean delete(String email)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from user_data where email = ? ;");
			ps.setString(1,email);
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
	
	
