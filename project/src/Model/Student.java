package Model;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Calendar;
import java.util.Date;

import Model.connect;
import Model.user_data;

public class Student extends user_data {

	int rollno,cid,bid,year;
	String firstName;
	String lastName;
	public Student(String email, String password, String firstName, String lastName,int rollno) {
		super(email, password);
		this.firstName = firstName;
		this.lastName = lastName;
		Date today = new Date();
		Calendar cal = Calendar.getInstance();
		cal.setTime(today);
		
		this.year = cal.get(Calendar.YEAR);
		this.rollno = rollno;


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

	public static boolean rollNoAvailable(int rollno)
	{
		boolean result = false;
		connect connect = new connect();

		try {
			PreparedStatement statement = connect.conn.prepareStatement("select roll_no from student where roll_no = ? ;");
			ResultSet rs;
			statement.setInt(1,rollno);
			rs = statement.executeQuery();
			if(rs.next())
			{

				int temp = rs.getInt("roll_no");
				result = temp==rollno;

			}
			connect.close();

		} catch (SQLException e) {
		}

		return result;

	}
	public void setYear()
	{
		Date today = new Date();
		Calendar cal = Calendar.getInstance();
		cal.setTime(today);
		
		this.year = cal.get(Calendar.YEAR);
	}
		
	@Override
	public boolean createNew() {
		// TODO Auto-generated method stub
		
		boolean result = false;
		int count;
		connect connection = new connect();
		result = super.createNew();
		if(result)
		{
			try {
				PreparedStatement ps = connection.conn.prepareStatement("insert into Student(first_name,last_name,email,year,roll_no) values(?,?,?,?,?);");
				ps.setString(1,firstName);
				ps.setString(2,lastName);
				ps.setString(3,super.getEmail());
				ps.setInt(4,year);
				ps.setInt(5,rollno);
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

	public static String getFirstName(String email)
	{
		String result="";
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select first_name from student where email = ? ;");
			ps.setString(1,email);
			ResultSet rs = ps.executeQuery();
			result = rs.getString("first_name");
			connection.close();
		} catch (SQLException e) {

		}
		return result;
	}

	public static boolean authenticate(String email,String password) {
		connect connection = new connect();
		boolean ans = false;
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select email from Student where email = ?");
			ps.setString(1, email);
			ResultSet rs = ps.executeQuery();

			if (rs.next()) {

				ans= user_data.authenticate(email, password);
			}
			rs.close();
			ps.close();
			connection.close();


		} catch (Exception e) {
			System.out.println(e);
		}
		return ans;
	}
	
}

	
	
