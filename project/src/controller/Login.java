package controller;

import Model.Student;
import Model.Teacher;

import javax.servlet.ServletException;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

public class Login extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String uname = request.getParameter("email");
        String pass = request.getParameter("pass");
        String userType = request.getParameter("user_type");
        PrintWriter out = response.getWriter();
        HttpSession session;
        boolean status = false;
        if(userType.equals("teacher"))
        {
            status = Teacher.authenticate(uname,pass);
        }
        else if(userType.equals("student"))
        {
            status = Student.authenticate(uname,pass);
        }


        if(status)
        {
           session=request.getSession();
            session.setAttribute("email",uname);
            session.setAttribute("role",userType);
        }
        else
        {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            String res = ("{\"status\" : true }");
            out.println(res);

        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
