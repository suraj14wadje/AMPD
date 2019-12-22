package Model;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.Year;

import Model.connect;
import Model.user_data;

public class Student extends user_data {

	int rollno,cid,bid,year;
	String firstName;
	String lastName;
	public Student(String email, String password, String firstName, String lastName) {
		super(email, password);
		this.firstName = firstName;
		this.lastName = lastName;
		this.year = Year.now().getValue();
	}
	public void setRollno(int rollno) {
		this.rollno = rollno;
	}
	public void setCid(int cid) {
		this.cid = cid;
	}
	public void setBid(int bid) {
		this.bid = bid;
	}
	public void setYear()
	{
		this.year = Year.now().getValue();
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
				PreparedStatement ps = connection.conn.prepareStatement("insert into Student values(default,?,?,?);");
				ps.setString(1,firstName);
				ps.setString(3,lastName);
				ps.setString(4,super.getEmail());
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
	
	public boolean update()
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update student set roll_no=?,c_id=?,b_id=?,first_name=?,last_name=?,year=? where email = ? ");
			ps.setInt(1,rollno);
			ps.setInt(2,cid);
			ps.setInt(3,bid);
			ps.setString(4,firstName);
			ps.setString(5,lastName);
			ps.setInt(6,year);
			ps.setString(7,super.getEmail());
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
	
	public static boolean delete(int roll_no)
	{
		boolean result=false;
		String email;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select email from student where roll_no = ? ;");
			ps.setInt(1, roll_no);
			ResultSet rs = ps.executeQuery();
			rs.next();
			email = rs.getString("email");
			result = user_data.delete(email);
			ps.close();
			rs.close();
			connection.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		return result;
	}
	
}

	
	
