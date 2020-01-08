<%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/5/2020
  Time: 8:29 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="Model.Student" %>
<%@ page import="Model.program" %>
<%@ page import="Model.Submission" %>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>View Programs</title>
    <link href="css/bootstrap.css" type="text/css" rel="stylesheet">
    <link href="font/css/all.css" type="text/css" rel ="stylesheet">
    <script src="js/lib/jquery.js"></script>
    <script src="js/dist/jquery.validate.js"></script>
    <script src="js/lib/bootstrap.js"></script>
    <link
            rel="stylesheet"
            href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.5.0/themes/prism.min.css"
    />
    <script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.5.0/prism.min.js"></script>
</head>
<body>
    <%
    String uname="",email="";
    if(session!=null){

        email=(String)session.getAttribute("email");
        uname = Student.getFirstName(email);



    }

    int p_id =-1;
    String temp = request.getParameter("p_id");
    if(temp!=null)
    {
        p_id= Integer.parseInt(temp);
    }

    int roll_no = (Integer)session.getAttribute("roll_no");
    int sub_id = Submission.getSubmissionId(p_id,roll_no);
    String Program = Submission.getProgramFromSub_id(sub_id);

%>
<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="StudentHome.jsp"><i class="fas fa-terminal"></i> Home</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text">&#160; &#160; &#160;&#160; &#160;&#160;&#160; &#160;&#160; Welcome
        <% out.print(uname); %>
    </span>
    </div>

    <div class="nav navbar-nav navbar-right">
        <span class="navbar-text"><a href="EditProfile.jsp"> <i class="fas fa-user-cog"></i> Edit Profile</a> &#160; &#160; &#160;&#160;&#160; <a id="Logout" href="LogOut"><i class="fas fa-power-off"></i> Logout</a></span>
    </div>



</nav>

<body>

<div class="container">
    <br>
    <h3 class="text-center"><%out.print(program.getTitleFromP_id(p_id));%></h3>
    <br>

    <div class="text-md-center"><%out.print(program.getQuestionFromP_id(p_id));%></div>

    <br><br>
    <div class="form-group shadow-textarea">
        <label class="text-center" for="textArea"><h6>Submit Your Solution Below</h6></label>
        <textarea class="form-control" name="answer" id="textArea" form="submit" rows="15"><%out.print(Program);%></textarea>
    </div>


    <form action="NewSubmission" id="submit" method="POST">

        <input type="number" name="p_id" hidden value="<%out.print(p_id);%>">
        <input type="submit" class="btn btn-primary btn-lg" value="Submit Assignment">
    </form>

</div>

</body>
</html>
