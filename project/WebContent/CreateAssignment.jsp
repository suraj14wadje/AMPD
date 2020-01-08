<%@ page import="java.util.Vector" %>
<%@ page import="Model.Assignment" %>
<%@ page import="Model.Teacher" %>
<%@ page import="Model.Subject" %>
<%@ page import="Model.program" %>
<%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/1/2020
  Time: 12:53 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>View or Create Assignments</title>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="font/css/all.css" type="text/css" rel ="stylesheet">
    <script src="js/lib/jquery.js"></script>
    <script src="js/dist/jquery.validate.js"></script>
    <script src="js/lib/popper.min.js"></script>
    <script src="js/lib/bootstrap.js"></script>
    <script src="js/dist/jquery.validate.min.js"></script>
</head>
<body>
<%

    int sub_id =-1;
    String subject = request.getParameter("sub_id");
    if(subject!=null)
    {
        sub_id  = Integer.parseInt(subject);
        subject = Subject.getSubjectNameFromSubId(sub_id);
    }
    else {
        response.sendRedirect("TeacherHome.jsp");
    }

    if(request.getMethod().equals("POST"))
    {
        String Assignment_name = request.getParameter("Aname");

        Assignment A1 = new Assignment(Assignment_name,sub_id);
        A1.createNew();

    }



    String uname="",email="";

    if(session!=null) {
        email = (String) session.getAttribute("email");
        uname = Teacher.getFirstName(email);
    }
    Vector Assignments = Assignment.getAssNameAndNoFromSubId(sub_id);
%>

<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="TeacherHome.jsp"><i class="fas fa-terminal"></i> Home</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text">&#160; &#160; &#160;&#160; &#160;&#160;&#160; &#160;&#160; Welcome
        <% out.print(uname); %>
    </span>
    </div>

    <div class="nav navbar-nav navbar-right">
        <span class="navbar-text"> <a id="Logout" href="LogOut"><i class="fas fa-power-off"></i> Logout</a></span>
    </div>
</nav>
<br>
<div class="container h-100">


    <div class="row">

    <div class="col-lg-3 col-md-6 ">

        <div class="card shadow p-3 mb-5 bg-white border-success rounded">
            <div class="card-body">
                <h4 ><i class="fas fa-folder-plus"></i></h4>
                <h5 class="card-title text-center">Create New Assignment For</h5>
                <h6 class="card-subtitle mb-2 text-muted text-center"><% out.print(subject); %></h6>
    <p class="card-text">
                <form id="Assignment" method="post">
                <div class="form-group">
                    <label for="Name">Assignment Name </label>
                    <input type="text" class="form-control" name="Aname" id="Name" placeholder="Name Of Assignment">
                    <input type="integer" name="sub_id" hidden value="<% out.print(sub_id);%>">
                </div>
                <button type="submit" class="btn btn-outline-success">Create New</button>
                </form>
             
            </div>
        </div>
    </div>


        <%
            if(Assignments!=null) {
            	int count = 1;

                for (int i = 0; i < Assignments.size(); i++) {
                    int a_no = Integer.parseInt(((Vector)Assignments.get(i)).get(0)+"");
                    out.print("<div class=\"col-lg-3 col-md-6 my-auto\">\n" +
                            "\n" +
                            "        <div class=\"card shadow p-3 mb-5 bg-white border-primary rounded\">\n" +
                            "            <div class=\"card-body\">" +
                            "<h5 class=\"card-title text-center\">");

                    out.print(((Vector) (Assignments.get(i))).get(1));
                    out.print("</h5>");
                    String str = "Contains "+ program.getProgramCountFromA_no(a_no)+" Questions";
                    out.print("<h6 class=\"card-subtitle mb-2 text-info\">"+str+" </h6>");
                    out.print("<br>");

                    out.print("<div class=\"my-auto text-center text-muted\">");
                    String link = "CreateProgram.jsp?a_no="+a_no;
                    

                    out.print("<a class=\"btn btn-outline-primary\"href= \""+link+"\" >");
                    out.print("<i class=\"fas fa-plus\"></i>");
                    out.print("</a>");
                    out.print("</div>");


                    out.print("</div> </div> </div>");
                    count++;
                    
                    if(count >=4)
                    {
                    	out.print("</div>");
                    	out.print("<div class=\"row\">");
                    	count = 0;
                    }


                }
            }
        %>







    </div>


</div>


<script>
    $().ready(function() {

        $.validator.setDefaults({
            errorClass: 'invalid-feedback',
            highlight: function(element){
                $(element).removeClass('is-valid');
                $(element).addClass('is-invalid');
            },
            unhighlight: function(element){
                $(element).removeClass('is-invalid');
                $(element).addClass('is-valid');
            }
        })
        $("#Assignment").validate(
            {
                rules:{
                    Aname:{
                        required : true,
                        minlength : 5
                    }
                }
            }
    )
    });
</script>

</body>
</html>
