<%@ page import="Model.Student" %>
<%@ page import="java.util.Vector" %>
<%@ page import="Model.Subject" %>
<%@ page import="Model.Assignment" %>
<%@ page import="Model.program" %>
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
</head>
<body>
<%
    String uname="",email="";
    if(session!=null){

        email=(String)session.getAttribute("email");
        uname = Student.getFirstName(email);



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

<div class="container h-75">
    <br>
    <div class="text-center"><h3>Choose Program</h3></div>
    <div class="row">

        <%
            int count1=0;
            Vector Programs=null;
            int a_no=-1;
            String ass_no = request.getParameter("a_no");
            if(ass_no!=null)
            {
                a_no  = Integer.parseInt(ass_no);
                ass_no = Assignment.getAssNameFromA_no(a_no);
                Programs = program.getProgramsFromA_no(a_no);
            }
            if(Programs!=null) {

                for (int i = 0; i < Programs.size(); i++) {
                    int p_id = Integer.parseInt(((Vector)Programs.get(i)).get(0)+"");
                    out.print("<div class=\"col-lg-3 col-md-6 ");
                    out.print("\">\n" +
                            "        <div class=\"card shadow p-3 mb-5 bg-white border-dark rounded\">\n" +
                            "            <div class=\"card-body\">" +
                            "<h5 class=\"card-title text-center\">");

                    out.print(((Vector) (Programs.get(i))).get(1));
                    out.print("</h5>");

                    out.print("<h6 class=\"card-subtitle mb-2 text-info\">"+" </h6>");
                    out.print("<br>");

                    out.print("<div class=\"my-auto text-center text-muted\">");
                    String link = "SubmitProgram.jsp?p_id="+p_id;


                    out.print("<a class=\"btn btn-outline-dark btn-lg\"href= \""+link+"\" >");
                    out.print("<i class=\"far fa-edit\"></i>");
                    out.print("</a>");
                    out.print("</div>");


                    out.print("</div> </div> </div>");
                    count1++;
                    if(count1 >=4)
                    {
                        out.print("</div>");
                        out.print("<div class=\"row\">");
                        count1 = 0;
                    }




                }
            }
        %>

    </div>

</div>




</body>
</html>
