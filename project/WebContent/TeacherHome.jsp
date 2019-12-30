<%@ page import="Model.Teacher" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Home Page</title>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Welcome To HomePage</title>
    <link href="css/bootstrap.css" type="text/css" rel="stylesheet">
    <link href="font/css/all.css" type="text/css" rel ="stylesheet">
    <script src="js/lib/jquery.js"></script>
    <script src="js/dist/jquery.validate.js"></script>
    <script src="js/lib/bootstrap.js"></script>
</head>
<body>
<%
String uname="",email="";

    if(session!=null){
        email=(String)session.getAttribute("email");
        uname = Teacher.getFirstName(email);

}

%>
<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="index.html"><i class="fas fa-terminal"></i> Code</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text"> <h5>Welcome
        <% out.print(uname); %>
    </h5></span>
    </div>

    <div class="nav navbar-nav navbar-right">
    <span class="navbar-text"> <a id="Logout" href="LogOut"><i class="fas fa-sign-out-alt">Logout</i></a></span>
    </div>
    <script>
        $('#Logout').click()
    </script>

</nav>


</body>
</html>
