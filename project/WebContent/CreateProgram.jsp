<%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/1/2020
  Time: 4:43 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="Model.Teacher" %>
<%@ page import="Model.Assignment" %>
<%@ page import="Model.program" %>
<html>
<head>
    <%@ page contentType="text/html;charset=UTF-8" language="java" %>
    <html>
    <head>
        <title>Create Program</title>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">


        <link href="css/bootstrap.css" type="text/css" rel="stylesheet">
        <link href="font/css/all.css" type="text/css" rel ="stylesheet">

        <script src="js/lib/jquery-1.11.1.js"></script>
        <script src="font/js/all.js"></script>
        <script src="js/dist/jquery.validate.js"></script>
        <script src="js/lib/popper.min.js"></script>
        <script src="js/lib/bootstrap.js"></script>

        <link href="css/editor.css" type="text/css" rel="stylesheet"/>
        <script src="js/editor.js"></script>
    </head>
<body>
<%
    String uname="",email="";
    int t_id = 0;
    if(session!=null) {
        email = (String) session.getAttribute("email");
        uname = Teacher.getFirstName(email);
        t_id = Teacher.getT_idfromEmail(email);
    }

    String Assingnment = request.getParameter("a_no");
    int a_no=-1;
    if(Assingnment!=null)
    {
        a_no = Integer.parseInt(Assingnment);
        Assingnment = Assignment.getAssNameFromA_no(a_no);
    }
    else {
        response.sendRedirect("CreateAssignment.jsp");
    }

    if(request.getMethod().equals("POST"))
    {
        String question = request.getParameter("question");
        String date = request.getParameter("date");
        String title = request.getParameter("title");

        program p1 = new program();
        p1.setA_no(a_no);
        p1.setT_id(t_id);
        p1.setLast_date(date);
        p1.setQuestion(question);
        p1.setTitle(title);
        p1.createNew();
        int sub_id = Assignment.getSubject_IdFroma_no(a_no);
        response.sendRedirect("CreateAssignment.jsp?sub_id="+sub_id);

    }




%>

<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="TeacherHome.jsp"><i class="fas fa-terminal"></i> Home</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text">&#160; &#160; &#160;&#160; &#160;&#160; Welcome
        <% out.print(uname); %>
    </span>
    </div>

    <div class="nav navbar-nav navbar-right">
        <span class="navbar-text"> <a id="Logout" href="LogOut"><i class="fas fa-power-off"></i> Logout</a></span>
    </div>
</nav>



<div class="container">
        <br>


        <div class="container text-center">
            <h1 class="display-7"><%out.print(Assingnment);%></h1>
            <p class="lead">Write Your Question here ! </p>
        </div>

    <form id="form" action="CreateProgram.jsp" method="post">

        <br>

   <div class="form-group input-group-lg">
        <input type="text" name="title" class="form-control" placeholder="Enter Your Question Title Here">
    </div>


    <div id="txtEditor">
    </div>
<br>


<br>



        <div class="row">
    <div class="form-group col-md-4">
        <label for="date">Last Submission Date :</label>

        <input type="date" id="date" name="date">
        <input type="text" id="question" name="question" hidden>
        <input type="number" name="a_no" hidden value="<%out.print(a_no+"");%>">

    </div>
    <div class="form-group col-md-5">

        <button id="button" class="btn btn-primary btn-lg">Create New Assignment</button>

    </div>
</div>
</form>



</div>



<script type="text/javascript">
    $(document).ready(function() {
        $("#txtEditor").Editor();
    });

    $("#button").click(function () {
        var text = $("#txtEditor").Editor("getText");

        $("#question").val(text);




    // $("#form").validate(
    //     {
    //         rules:{
    //             date:
    //         }
    //     }
    // )

    })
</script>



</body>
</html>
