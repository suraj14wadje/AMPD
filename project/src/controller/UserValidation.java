package controller;

import Model.user_data;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class UserValidation extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String uname = request.getParameter("email");
        String temp = request.getParameter("current_email");
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        if(temp != null)
        {
            if(temp.equals(uname))
            {
                response.getWriter().println("true");
                return;
            }
        }

        boolean status = user_data.isEmailAvailable(uname);
        System.out.println(status);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        if(status)
        {

            response.getWriter().println("\"This Email Is Already Taken!\"");
        }
        else
            response.getWriter().println("true");


    }
}
