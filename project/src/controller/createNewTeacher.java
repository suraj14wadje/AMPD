package controller;

import Model.*;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class createNewTeacher
 */
public class createNewTeacher extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public createNewTeacher() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String uname = "suraj14wadje@gmail.com";
		boolean valid = false;
		if(uname.equals(request.getParameter("email")))
		{
			valid = true;
		}
		response.setContentType("application/json");
	    response.setCharacterEncoding("UTF-8");
	    response.getWriter().write("{\"valid\":" + valid + "}");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String fname = request.getParameter("fname");
		String lname = request.getParameter("lname");
		String email = request.getParameter("email");
		String pass = request.getParameter("pass");
		response.getWriter().append(fname+" "+ lname);
		new connect();
		Teacher t1 = new Teacher(email,pass,fname,lname);
		if(t1.createNew())
		{
			System.out.println("new account created");
		}
		else
		{
			System.out.println("there was some error!");
		}
	}
	
//	public static void main(String args[])
//	{
//		new connect();
//	}
}
