package controller;

import Model.Teacher;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;


public class TeacherLogin extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String uname = request.getParameter("email");
        String pass = request.getParameter("pass");

        boolean status = Teacher.authenticate(uname,pass);

        if(status)
        {
            Cookie loginCookie = new Cookie("user",uname);
            //setting cookie to expiry in 3 hrs
            loginCookie.setMaxAge(60*60*3);
            response.addCookie(loginCookie);
        }
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();
        out.println("{ \"status\" : " + status + " }");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
