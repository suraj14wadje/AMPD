package controller;

import Model.Student;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class RollNoValidation extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        int rollno = Integer.parseInt(request.getParameter("rollno"));
        String temp = request.getParameter("current_rollno");
        System.out.println(temp+" roll no");
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        if(temp != null)
        {
            if(rollno==Integer.parseInt(temp))
            {
                response.getWriter().write("true");
                return;
            }


        }
        boolean result = Student.rollNoAvailable(rollno);

        if(result)
        {
            response.getWriter().write("\"This Roll Number Is already registered\"");
        }
        else
        {
            response.getWriter().write("true");
        }


    }
}
