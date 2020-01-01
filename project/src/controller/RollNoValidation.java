package controller;

import Model.Student;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "RollNoValidation")
public class RollNoValidation extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        int rollno = Integer.parseInt(request.getParameter("rollno"));
        boolean result = Student.rollNoAvailable(rollno);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
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
