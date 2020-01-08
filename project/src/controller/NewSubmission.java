package controller;

import Model.Student;
import Model.Submission;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class NewSubmission extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        HttpSession session = request.getSession(false);
        String email="";
        if(session!=null){

            email=(String)session.getAttribute("email");

            int rollno = Student.getRollNo(email);
            if(rollno==(Integer)session.getAttribute("roll_no"))
            {
                int p_id = Integer.parseInt(request.getParameter("p_id"));
                Submission s1 = new Submission();
                s1.setP_id(p_id);
                s1.setProgram(request.getParameter("answer"));
                s1.setRoll_no(rollno);
                System.out.println("about to submit");
                if(s1.SubmitASubmission())
                {
                    System.out.println("submitted succeffuly");
//                    response.getWriter().print("Submitted Successfully Now Processing");
                }

                if(s1.ProcessSubmission())
                {
                    System.out.println("Proccessed Successfully");
//                    response.getWriter().print("<br> Done Processing");
                }
                response.sendRedirect("SubmitProgram.jsp?p_id="+p_id);


            }



        }
        else {
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
