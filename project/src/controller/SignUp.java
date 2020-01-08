package controller;

import Model.Teacher;
import Model.Student;
import Model.user_data;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class SignUp extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String uname = request.getParameter("email");
        boolean temp= false;
        String message="";

        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        String fname = request.getParameter("fname");
        String lname = request.getParameter("lname");
        String email = request.getParameter("email");
        String pass = request.getParameter("pass");
        String user_type = request.getParameter("user_type");

        System.out.println(user_type);

        boolean valid = user_data.isEmailAvailable(uname);
        if(valid)
        {
            response.getWriter().println("{\"status\" : true, \"message\" : \"Email Already Exist ! \"}");
            return;

        }

            if(user_type.equals("teacher"))
            {
                Teacher t1 = new Teacher(email, pass, fname, lname);
                temp = t1.createNew();
                System.out.println("new Teacher created!");
            }
            else if(user_type.equals("student")){
                int rollno = Integer.parseInt(request.getParameter("rollno"));
                Student s1 = new Student(email,pass,fname,lname,rollno);
                temp = s1.createNew();

                System.out.println("new Student created!");

            }


        if(temp)
            response.getWriter().write("{\"status\" : false, \"message\" : \"\"}");
        else
            response.getWriter().println("{\"status\" : true, \"message\" : \"Some Internal Error Occured ! \"}");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
