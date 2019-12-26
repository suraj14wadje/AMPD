package Model;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Submission {
	int roll_no;
	int p_id;
	String program;
	String processed;
	float plagiarism_score;
	String comment;
	int marks;
	Date sub_date;
	
	public int getRoll_no() {
		return roll_no;
	}

	public int getP_id() {
		return p_id;
	}

	public String getProgram() {
		return program;
	}

	public String getProcessed() {
		return processed;
	}

	public float getPlagiarism_score() {
		return plagiarism_score;
	}

	public String getComment() {
		return comment;
	}

	public int getMarks() {
		return marks;
	}

	public Date getSub_date() {
		return sub_date;
	}

	public void setRoll_no(int roll_no) {
		this.roll_no = roll_no;
	}

	public void setP_id(int p_id) {
		this.p_id = p_id;
	}

	public void setProgram(String program) {
		this.program = program;
	}

	public void setProcessed(String processed) {
		this.processed = processed;
	}

	public void setPlagiarism_score(float plagiarism_score) {
		this.plagiarism_score = plagiarism_score;
	}

	public void setComment(String comment) {
		this.comment = comment;
	}

	public void setMarks(int marks) {
		this.marks = marks;
	}

	public void setSub_date() {
		this.sub_date =new Date(System.currentTimeMillis());
	}
	public Submission()
	{
		this.sub_date = new Date(System.currentTimeMillis());
	}

	public Submission(int roll_no, int p_id, String program, String processed, float plagiarism_score, String comment,
			int marks, String sub_date) {
		super();
		this.roll_no = roll_no;
		this.p_id = p_id;
		this.program = program;
		this.processed = processed;
		this.plagiarism_score = plagiarism_score;
		this.comment = comment;
		this.marks = marks;
		this.sub_date = new Date(System.currentTimeMillis());
	}
	
	
	public boolean createNew()
	{
		boolean result=false;
		int count = 0;
		
		connect connection = new connect();
		try {
			PreparedStatement ps = connection.conn.prepareStatement("insert into submission values(default,?,?,?,?,?,?,?,?);");
			ps.setInt(1,roll_no);
			ps.setInt(2,p_id);
			ps.setDate(3,sub_date);
			ps.setString(4,program);
			ps.setString(5,processed);
			ps.setFloat(6,plagiarism_score);
			ps.setString(7,comment);
			ps.setInt(8,marks);
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
	
//	public boolean update()
//	{
//		boolean result = false;
//		int count = 0;
//		connect connection = new connect();
//		try {
//			PreparedStatement ps = connection.conn.prepareStatement("update submission set sub_date=? ,program=?, processed_program=?, plagiarism_score=? where p_id = ?");
//			ps.setString(1,question);
//			ps.setString(2,expected_output);
//			ps.setDate(3,Date.valueOf(last_date));
//			count = ps.executeUpdate();
//			ps.close();
//			connection.close();
//			if(count == 1)
//			{
//				result = true;
//			}
//		} catch (SQLException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		return result;
//	}
//	
	

}
