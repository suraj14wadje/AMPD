package Model;

import gst.GreedyStringTiling;
import gst.PlagResult;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class Submission {
	int roll_no;
	int p_id;
	String program;
	String processed;
	float plagiarism_score;
	int plag_source_roll_no;
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
		setProcessed(Plagiarism.clean(program));
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
		plagiarism_score= 0;
		plag_source_roll_no = -1;

		setSub_date();
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

	public static int getSubmissionId(int p_id,int roll_no)
	{

		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select sub_id from submission where roll_no = ? and p_id = ? ;");
			ps.setInt(1,roll_no);
			ps.setInt(2,p_id);
			ResultSet rs = ps.executeQuery();
			if(rs.next())
			{
				connect.close();
				return rs.getInt("sub_id");
			}
			else
			{
				connect.close();
				return -1;
			}
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}
		connect.close();
		return -1;
	}

	public static String getProgramFromSub_id(int sub_id)
	{
		String result ="";
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select program from submission where sub_id = ?");
			ps.setInt(1,sub_id);
			ResultSet rs = ps.executeQuery();
			if(rs.next())
			{
				result = rs.getString("program");
			}
			connect.close();

		}catch (Exception ex)
		{
			ex.printStackTrace();
			connect.close();
		}

		return result;
	}
	public boolean SubmitASubmission()
	{
		boolean result=false;
		int count = 0;
		this.processed = Plagiarism.clean(program);
		int sub_id = getSubmissionId(p_id,roll_no);
		System.out.println("sub Id : "+sub_id);
		connect connection = new connect();
		try {
			PreparedStatement ps;

			if(sub_id != -1)
			{
				ps = connection.conn.prepareStatement("update submission set sub_date= ?,program =?,processed_program=?,plagiarism_score=0,plagiarism_source=-1 where sub_id= ?;");
				ps.setDate(1,sub_date);
				ps.setString(2,program);
				ps.setString(3,processed);
				ps.setInt(4,sub_id);
			}
			else {
				ps = connection.conn.prepareStatement("insert into submission(sub_id,roll_no,p_id,sub_date,program,processed_program) values(default,?,?,?,?,?);");

				ps.setInt(1, roll_no);
				ps.setInt(2, p_id);
				ps.setDate(3, sub_date);
				ps.setString(4, program);
				ps.setString(5, processed);
			}
			count = ps.executeUpdate();
			if(count== 1)
			{
				result = true;
			}
			connection.close();
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}
		return result;

	}

	public boolean ProcessSubmission()
	{
		Vector result = getSubmissions();

		if(result == null)
			return true;
		float temp;
		for(int i = 0;i<result.size();i++)
		{
			String program2 = ((Vector)result.get(i)).get(1)+"";
			PlagResult plagResult=null;
			System.out.println("processing : "+((Vector)result.get(i)).get(0));
			System.out.print(processed);
			System.out.print(" : ");
			System.out.println(program2);
			if(processed.equals(program2))
			{
				plagiarism_score = 100;
				plag_source_roll_no = Integer.parseInt(((Vector)result.get(i)).get(0)+"");
				break;

			}
			else {
				plagResult = GreedyStringTiling.run(processed,program2 ,2,(float)0.80);
				temp = plagResult.similarity*100;
				if(temp > plagiarism_score)
				{
					plagiarism_score = temp;
					plag_source_roll_no = Integer.parseInt(((Vector)result.get(i)).get(0)+"");
				}
				if(plagResult.suspectedPlagiarism){
					break;
				}

			}

			System.out.println("Done");


		}
		return UpdatePlagiarism();
	}

	private boolean UpdatePlagiarism(){
		boolean result=false;
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("update submission set plagiarism_score=?,plagiarism_source=? where roll_no = ? and p_id = ?");
			ps.setFloat(1,plagiarism_score);
			ps.setInt(2,plag_source_roll_no);
			ps.setInt(3,roll_no);
			ps.setInt(4,p_id);
			int status = ps.executeUpdate();
			if(status==1)
			{
				result = true;
			}
			connect.close();
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}

		return result;
	}

	public static Vector getSubmissionDetails(int p_id)
	{
		Vector result = new Vector();
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select roll_no,sub_date,plagiarism_score from submission where p_id = ? ;");
			ps.setInt(1,p_id);

			ResultSet rs = ps.executeQuery();
			while (rs.next())
			{
				Vector temp = new Vector();
				temp.add(rs.getInt("roll_no")+"");
				String name = Student.getFullNameFromRollNo(rs.getInt("roll_no"));
				temp.add(name);
				temp.add(rs.getDate("sub_date")+"");
				temp.add(rs.getFloat("plagiarism_score"));
				result.add(temp);
			}

			connect.close();
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}

		return result;
	}

	public Vector getSubmissions()
	{
		Vector result = new Vector();
		connect connect = new connect();
		try {
			PreparedStatement ps = connect.conn.prepareStatement("select roll_no,processed_program from submission where p_id = ? and roll_no != ?");
			ps.setInt(1,p_id);
			ps.setInt(2,roll_no);
			ResultSet rs = ps.executeQuery();
			while (rs.next())
			{
				Vector temp = new Vector();
				temp.add(rs.getInt("roll_no"));
				temp.add(rs.getString("processed_program"));
				result.add(temp);
			}

			connect.close();
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}

		return result;
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
