<%@ page import="java.util.Vector" %>
<%@ page import="Model.*" %><%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/8/2020
  Time: 9:26 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Submissions</title>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="font/css/all.css" type="text/css" rel ="stylesheet">
    <script src="js/lib/jquery.js"></script>
    <script src="js/dist/jquery.validate.js"></script>
    <script src="js/lib/popper.min.js"></script>
    <script src="js/lib/bootstrap.js"></script>
    <link href="https://cdn.datatables.net/1.10.20/css/jquery.dataTables.min.css" type="text/css" rel="stylesheet">
    <script src="https://cdn.datatables.net/1.10.20/js/jquery.dataTables.min.js"></script>

</head>
<body>
<%
    String uname="",email="";

    if(session!=null){
        email=(String)session.getAttribute("email");
        uname = Teacher.getFirstName(email);

    }
    String batch_id = request.getParameter("b_id");
    String subject_id = request.getParameter("sub_id");
    String Ass_no = request.getParameter("a_no");
    String Program_id = request.getParameter("p_id");
    if(batch_id==null)
    {
        response.sendRedirect("TeacherHome.jsp");
    }
    int b_id = Integer.parseInt(batch_id);
    int sub_id=-1;
    int a_no=-1;
    int p_id = -1;
    if(subject_id!=null) {
        sub_id = Integer.parseInt(subject_id);
    }
    if(Ass_no!=null)
    {
        a_no = Integer.parseInt(Ass_no);
    }
    if(Program_id!=null)
    {
        p_id = Integer.parseInt(Program_id);
    }
    Vector SubjectNames = Subject.getSubjectNamesFromB_id(b_id);

%>
<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="TeacherHome.jsp"><i class="fas fa-terminal"></i> Home</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text">&#160; &#160; &#160;&#160; &#160;&#160;&#160; &#160;&#160; Welcome
        <% out.print(uname); %>
    </span>
    </div>

    <div class="nav navbar-nav navbar-right">
        <span class="navbar-text"><a href="#"> <i class="fas fa-user-cog"></i> Edit Profile</a> &#160; &#160; &#160;&#160;&#160; <a id="Logout" href="LogOut"><i class="fas fa-power-off"></i> Logout</a></span>
    </div>
</nav>
<br>
<br>

<script>
    $(document).ready( function () {
        $('#myTable').DataTable();
    } );
</script>
<div class="container">
    <div class="row">
    <%
        if(SubjectNames!=null)
        {
            for(int i = 0;i<SubjectNames.size();i++)
            {
                int temp = Integer.parseInt(((Vector)SubjectNames.get(i)).get(1)+"");
                String link = "Submissions.jsp?b_id="+b_id+"&sub_id="+((Vector)SubjectNames.get(i)).get(1)+"";
                out.print("<div class=\"col-md-3\">");
                if(sub_id == temp)
                {
                    out.print("<a href=\""+link+"\" class=\"btn btn-primary btn-block\">\n ");
                }
                else{
                    out.print("<a href=\""+link+"\" class=\"btn btn-outline-primary btn-block\">\n ");
                }

                        out.print(((Vector)SubjectNames.get(i)).get(0)+
                        "</a>");

                        out.print("</div>");

            }
            out.print("</div>");


            if(sub_id!=-1)
            {
                Vector Assignments = Assignment.getAssNameAndNoFromSubId(sub_id);
                if(Assignments!=null) {
                    out.print("<br><h4 class=\"\"> choose Assignment </h4><br>");
                    out.print("<div class=\"row\">");
                    int count = 0;
                    for (int i = 0; i < Assignments.size(); i++) {
                        int temp = Integer.parseInt(((Vector) Assignments.get(i)).get(0) + "");
                        String link = "Submissions.jsp?b_id=" + b_id + "&sub_id=" + sub_id + "&a_no="+temp ;
                        out.print("<div class=\"col-md-3\">");
                        if (a_no == temp) {
                            out.print("<a href=\"" + link + "\" class=\"btn btn-success btn-block\">\n ");
                        } else {
                            out.print("<a href=\"" + link + "\" class=\"btn btn-outline-success btn-block\">\n ");
                        }

                        out.print(((Vector) Assignments.get(i)).get(1) +
                                "</a>");

                        out.print("</div>");

                        count++;
                        if(count>=4)
                        {
                            out.print("</div>");
                            out.print("<br><div class=\"row\">");
                            count = 0;
                        }

                    }if(count != 4)
                        out.print("</div>");
                }

            }


            if(a_no!=-1)
            {
                Vector Questions = program.getProgramsFromA_no(a_no);
                if(Questions!=null) {
                    out.print("<br><h4 class=\"\"> choose Question </h4><br>");
                    out.print("<div class=\"row\">");
                    int count = 0;
                    for (int i = 0; i < Questions.size(); i++) {
                        int temp = Integer.parseInt(((Vector) Questions.get(i)).get(0) + "");
                        String link = "Submissions.jsp?b_id=" + b_id + "&sub_id=" + sub_id + "&a_no="+a_no+"&p_id="+temp;
                        out.print("<div class=\"col-md-3\">");
                        if (p_id == temp) {
                            out.print("<a href=\"" + link + "\" class=\"btn btn-dark btn-block\">\n ");
                        } else {
                            out.print("<a href=\"" + link + "\" class=\"btn btn-outline-dark btn-block\">\n ");
                        }

                        out.print(((Vector) Questions.get(i)).get(1) +
                                "</a>");

                        out.print("</div>");

                        count++;
                        if(count>=4)
                        {
                            out.print("</div>");
                            out.print("<br><div class=\"row\">");
                            count = 0;
                        }

                    }
                    if(count != 4)
                        out.print("</div>");
                }

            }

            if(p_id != -1)
            {
                out.print("<br>");
                out.print("<table id=\"myTable\" class=\"table display\">\n" +
                        "  <thead class=\"table-dark\">\n" +
                        "    <tr>\n" +
                        "      <th scope=\"col\">Roll No</th>\n" +
                        "      <th scope=\"col\">Name Of Student</th>\n" +
                        "      <th scope=\"col\">Plagiarism Score</th>\n" +
                        "      <th scope=\"col\">Date Of Submission</th>\n" +
                        "    </tr>\n" +
                        "  </thead>\n "+
                        "<tbody>\n");

                Vector submitted = Submission.getSubmissionDetails(p_id);

                if(submitted != null)
                {
                    for(int i=0;i<submitted.size();i++)
                    {
                        if(Float.parseFloat(((Vector)submitted.get(i)).get(3)+"")>90.0)
                        {
                            out.print("<tr class=\"table-danger\">\n");

                        }
                        else if(Float.parseFloat(((Vector)submitted.get(i)).get(3)+"")<50.0){
                            out.print("<tr class=\"table-success\">\n");
                        }
                        else{
                            out.print("<tr class=\"table-warning\">\n");
                        }
                                out.print(" <th scope=\"row\">"+((Vector)submitted.get(i)).get(0)+"</th>\n" +
                                "      <td>"+((Vector)submitted.get(i)).get(1)+"</td>\n" +
                                "      <td>"+((Vector)submitted.get(i)).get(3)+" % </td>\n" +
                                "      <td>"+((Vector)submitted.get(i)).get(2)+"</td>\n" +
                                "    </tr>\n");

                    }

                }
                out.print("  </tbody>\n" +
                        "</table>\n" +
                        "</p>");




            }

        }

    %>
    </div>

</div>
</body>
</html>
