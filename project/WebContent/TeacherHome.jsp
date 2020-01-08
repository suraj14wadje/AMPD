<%@ page import="Model.Teacher" %>
<%@ page import="java.util.Vector" %>
<%@ page import="Model.Class_1" %>
<%@ page import="java.util.Iterator" %>
<%@ page import="Model.Subject" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Home Page</title>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="css/bootstrap.min.css" type="text/css" rel="stylesheet">
    <link href="font/css/all.css" type="text/css" rel ="stylesheet">
    <script src="js/lib/jquery.js"></script>
    <script src="js/dist/jquery.validate.js"></script>
    <script src="js/lib/popper.min.js"></script>
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

<%
    int t_id = Teacher.getT_id(email);
    Vector Class_names = Class_1.getClassNamesFromT_id(t_id);
%>


<div class="container">


    <div class="row h-100">

        <div class="col-md-6 my-auto">
            <div class="card shadow p-3 mb-5 bg-white border-info rounded">
                <div class="card-header">
                    <h3 class="text-center"> <i class="fas fa-folder-plus"></i>  Create An Assignment </h3>
                </div>
                <div class="card-body">
                    <h5 class="card-title">Choose Class</h5>
                    <p class="card-text">

                        <%
                            String className;
                            int c_id;
                            for(int i =0;i<Class_names.size();i++)
                            {
                                className = ((Vector) Class_names.get(i)).get(0).toString();
                                c_id = (Integer.parseInt((((Vector) Class_names.get(i)).get(1)+"")));
                                Vector subject = Subject.getSubjectNamesFromC_id(c_id);
                                out.println(" <p> ");
                                out.println("<div class=\"btn-group dropright\">");
                                out.println("<button type=\"button\" class=\"btn btn-info dropdown-toggle\" data-toggle=\"dropdown\" aria-haspopup=\"true\" aria-expanded=\"false\">");
                                out.println(className);
                                out.println(" </button>");
                                out.println("<div class=\"dropdown-menu\">");


                                for(int j =0;j<subject.size();j++)
                                {
                                    String link = "CreateAssignment.jsp?sub_id="+((Vector)subject.get(j)).get(1).toString();
                                    out.println("<a class=\"dropdown-item\" href=\""+link+"\">");
                                    out.println(((Vector)subject.get(j)).get(0).toString());
                                    out.println("</a>");
                                }

                                out.println("</div></div> </p>");

                            }



                        %>
                    </p>



                </div>
            </div>

        </div>

        <div class="col-md-6 my-auto">

            <div class="card shadow p-3 mb-5 bg-white border-success rounded">
                <div class="card-header">
                    <h3 class="text-center"> <i class="fas fa-tasks"></i>  View Submitted Assignments </h3>
                </div>
                <div class="card-body">
                    <h5 class="card-title">Choose Your Batch</h5>
                    <p class="card-text">

                        <%

                            Vector BatchAndClassNames = Class_1.getClassAndBatchNamesFromT_id(t_id);

                            for(int i = 0;i<BatchAndClassNames.size();i++)
                            {
                                int b_id = Integer.parseInt(((Vector)BatchAndClassNames.get(i)).get(2)+"");
                                String link = "Submissions.jsp?b_id="+b_id;
                                out.print("<p class=\"row\">");

                                out.print("<a href=\""+link+"\" class=\"btn btn-success\">");

                                out.print(((Vector) BatchAndClassNames.get(i)).get(0).toString() + "  : "+((Vector) BatchAndClassNames.get(i)).get(1).toString());
                                out.print("</a>");

                                out.print("</p>");
                            }



                        %>
                    </p>



                </div>
            </div>

        </div>

    </div>









</div>

</body>
</html>
