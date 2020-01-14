<%@ page import="Model.Student" %>
<%@ page import="Model.Submission" %>
<%@ page import="Model.StringUtils" %>
<%@ page import="Model.Teacher" %><%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/14/2020
  Time: 9:59 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
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
    <link rel="stylesheet"
          href="//cdn.jsdelivr.net/gh/highlightjs/cdn-release@9.17.1/build/styles/github.min.css">
    <script src="//cdn.jsdelivr.net/gh/highlightjs/cdn-release@9.17.1/build/highlight.min.js"></script>

    <style>
        div.code {
            height: 70%;
            overflow: auto;

        }
        .rating {
            display: inline-block;
            position: relative;
            height: 30px;
            line-height: 30px;
            font-size: 30px;
        }

        .rating label {
            position: absolute;
            top: 0;
            left: 0;
            height: 100%;
            cursor: pointer;
        }

        .rating label:last-child {
            position: static;
        }

        .rating label:nth-child(1) {
            z-index: 5;
        }

        .rating label:nth-child(2) {
            z-index: 4;
        }

        .rating label:nth-child(3) {
            z-index: 3;
        }

        .rating label:nth-child(4) {
            z-index: 2;
        }

        .rating label:nth-child(5) {
            z-index: 1;
        }

        .rating label input {
            position: absolute;
            top: 0;
            left: 0;
            opacity: 0;
        }

        .rating label .icon {
            float: left;
            color: transparent;
        }

        .rating label:last-child .icon {
            color: #000;
        }

        .rating:not(:hover) label input:checked ~ .icon,
        .rating:hover label:hover input ~ .icon {
            color: rgba(240, 213, 0, 0.99);
        }

        .rating label input:focus:not(:checked) ~ .icon:last-child {
            color: #000;
            text-shadow: 0 0 5px rgb(217, 195, 0);
        }

    </style>
</head>

<body>
<%
    String uname="",email="";
    if(session!=null){

        email=(String)session.getAttribute("email");
        uname = Teacher.getFirstName(email);
    }
    String submission="" ;
    String fullName="";

    int sub_id=-1;
    try{
        sub_id = Integer.parseInt(request.getParameter("sub_id"));
    }catch (Exception ex)
    {
        ex.printStackTrace();
        response.sendRedirect("TeacherHome.jsp");
    }
    if(request.getMethod().equals("POST"))
    {
        try{
            String remark = request.getParameter("remark");
            int marks = Integer.parseInt(request.getParameter("stars"));
            if(Submission.updateRemark(marks,remark,sub_id))
            {
                response.sendRedirect("TeacherHome.jsp");
            }
        }catch (Exception ex){
            ex.printStackTrace();
        }

    }
    else
    {
        submission = Submission.getProgramFromSub_id(sub_id);
        fullName = Student.getFullNameFromRollNo(Submission.getRollNoFromSub_id(sub_id));
        submission = StringUtils.encodeHtml(submission);
        submission= submission.trim();


    }





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
<br>
<script>hljs.initHighlightingOnLoad();
</script>
<div class="container">

    <div class="text-center">
        <h4><%=fullName%></h4>
    </div>

    <div class="border border-dark rounded code">
   <pre><code><%out.print(submission);%></code></pre>
    </div>
    <br>

    <form id="submit" method="POST" action="">


        <div class="rating">
            <label>
                <input type="radio" name="stars" value="1">
                <span class="icon">★</span>
            </label>
            <label>
                <input type="radio" name="stars" value="2">
                <span class="icon">★</span>
                <span class="icon">★</span>
            </label>
            <label>
                <input type="radio" name="stars" value="3">
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
            </label>
            <label>
                <input type="radio" name="stars" value="4">
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
            </label>
            <label>
                <input type="radio" name="stars" value="5">
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
                <span class="icon">★</span>
            </label>
        </div>
        <br><br>
        <div class="form-group shadow-textarea">
            <label class="text-center" for="textArea"><h6>Write comment below</h6></label>
            <textarea class="form-control" name="remark" id="textArea" form="submit" rows="3"></textarea>
        </div>
        <input type="number" hidden name="sub_id" value="<%=sub_id%>">
        <div class="form-group">
        <input class="btn btn-primary btn-sm" type="submit" value="Submit">

        </div>
    </form>
<br><br><br>
</div>

</body>
</html>
