package Model;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Date;
import java.util.Vector;

public class program {
	int a_no;
	int t_id;
	String question;
	String expected_output;
	String last_date;
	String title;
	
	Date date_of_creation;
	
	public program()
	{
		date_of_creation = new Date(System.currentTimeMillis());
		
	}
	
	public program(int a_no, int t_id, String question, String expected_output,String last_date) {
		this.a_no = a_no;
		this.t_id = t_id;
		this.question = question;
		this.expected_output = expected_output;
		this.last_date = last_date;
		date_of_creation = new Date(System.currentTimeMillis());
	}

	public int getA_no() {
		return a_no;
	}

	public int getT_id() {
		return t_id;
	}

	public String getQuestion() {
		return question;
	}

	public String getExpected_output() {
		return expected_output;
	}

	public String getLast_date() {
		return last_date;
	}

	public Date getDate_of_creation() {
		return date_of_creation;
	}

	public void setA_no(int a_no) {
		this.a_no = a_no;
	}

	public void setT_id(int t_id) {
		this.t_id = t_id;
	}

	public void setQuestion(String question) {
		this.question = question;
	}

	public void setExpected_output(String expected_output) {
		this.expected_output = expected_output;
	}
	public void setLast_date(String date)
	{
		last_date = date;
	}

	public void setLast_date(int d,int m,int y) {
		last_date="";
		last_date+= y+"-"+d+"-"+m;
		
	}

	public void setTitle(String title)
	{
		this.title = title;
	}

	public static int getProgramCountFromA_no(int a_no)
	{
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select count(p_id) from program where a_no = ?;");
			ps.setInt(1,a_no);
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

	public void setDate_of_creation(Date date_of_creation) {
		this.date_of_creation = date_of_creation;
	}

	public boolean createNew()
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		

		try 
		{
			
			
			PreparedStatement ps = connection.conn.prepareStatement("insert into program(p_id,t_id,a_no,question,expected_output,last_date_of_submission,date_of_creation,title) values(default,?,?,?,?,?,?,?);");
			ps.setInt(2,a_no);
			ps.setInt(1,t_id);
			ps.setString(3,question);
			ps.setString(4,expected_output);
			ps.setDate(5,Date.valueOf(last_date));
			ps.setDate(6,date_of_creation);
			ps.setString(7,title);
			count = ps.executeUpdate();
			ps.close();
			connection.close();
			if(count == 1)
			{
				result = true;
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return result;
	}
	
	public boolean update()
	{
		boolean result = false;
		int count = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("update program set question = ?,expected_ouput=? ,last_date_of_submission=? where p_id = ?");
			ps.setString(1,question);
			ps.setString(2,expected_output);
			ps.setDate(3,Date.valueOf(last_date));
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


	public static String getQuestionFromP_id(int p_id)
	{
		String result="";
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("select question from program where p_id = ? ;");
			ps.setInt(1,p_id);
			ResultSet rs = ps.executeQuery();
			rs.next();
			result = rs.getString("question");
			connection.close();
		} catch (SQLException e) {
			connection.close();
		}
		return result;

	}

	public static String getTitleFromP_id(int p_id)
    {
        String result="";
        connect connection = new connect();
        try {
            PreparedStatement ps = connection.conn.prepareStatement("select title from program where p_id = ? ;");
            ps.setInt(1,p_id);
            ResultSet rs = ps.executeQuery();
            rs.next();
            result = rs.getString("title");
            connection.close();
        } catch (SQLException e) {
            connection.close();
        }
        return result;

    }

	public static Vector getProgramsFromA_no(int a_no)
	{
		Vector result = new Vector();

		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select p_id,title from program where a_no = ?");
			ps.setInt(1,a_no);
			ResultSet rs = ps.executeQuery();
			while (rs.next())
			{
				Vector temp = new Vector();
				temp.add(rs.getInt("p_id"));
				temp.add(rs.getString("title"));
				result.add(temp);
			}
			connect.close();

		}catch (Exception ex)
		{
			ex.printStackTrace();
		}

		return result;
	}
	
	public static boolean delete(int p_id)
	{
		int result = 0;
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("delete from program where p_id = ? ;");
			ps.setInt(1, p_id);
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
