<%@ page import="Model.Student" %>
<%@ page import="java.util.Vector" %>
<%@ page import="Model.Class_1" %><%--
  Created by IntelliJ IDEA.
  User: suraj
  Date: 1/2/2020
  Time: 5:46 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <%@ page contentType="text/html;charset=UTF-8" language="java" %>
    <html>
    <head>
        <title>Edit Your Profile</title>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">


        <link href="css/bootstrap.css" type="text/css" rel="stylesheet">
        <link href="font/css/all.css" type="text/css" rel ="stylesheet">

        <script src="js/lib/jquery-1.11.1.js"></script>
        <script src="font/js/all.js"></script>
        <script src="js/dist/jquery.validate.js"></script>
        <script src="js/dist/additional-methods.min.js"></script>
        <script src="js/lib/popper.min.js"></script>
        <script src="js/lib/bootstrap.js"></script>
    </head>
<body>
<%
    String fname="",email="";
    String lname="";
    int rollno=0;

    if(session!=null){
        email=(String)session.getAttribute("email");

        fname = Student.getFirstName(email);
        lname = Student.getLastName(email);
        rollno = Student.getRollNo(email);

    }

    if(request.getMethod().equals("POST"))
    {
        String new_email = request.getParameter("email");
        fname = request.getParameter("fname");
        lname = request.getParameter("lname");
        rollno = Integer.parseInt(request.getParameter("rollno"));
        int c_id = Integer.parseInt(request.getParameter("class"));
        int b_id = Integer.parseInt(request.getParameter("batch"));

        if(Student.update(email,new_email,fname,lname,rollno,c_id,b_id))
        {
            session.setAttribute("email",new_email);
            response.sendRedirect("StudentHome.jsp");
        }


    }

    Vector ClassNames = Class_1.getAllClassNames();

%>
<nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="StudentHome.jsp"><i class="fas fa-terminal"></i> Home</a>

    <div class="nav navbar-nav navbar-center">
    <span class="navbar-text">&#160; &#160; &#160;&#160; &#160;&#160;&#160; &#160;&#160; Welcome
        <% out.print(fname);%>
    </span>
    </div>

    <div class="nav navbar-nav navbar-right">

        <span class="navbar-text"> <a id="Logout" href="LogOut"><i class="fas fa-power-off"></i> Logout</a></span>
    </div>
</nav>
<br>

<div class="container">


    <div class="row justify-content-center h-100">

        <div class="col-6">
            <div class="card shadow p-3 mb-5 bg-white border-info rounded">
                <div class="card-header">
                    <h3 class="text-center"> <i class="fas fa-cog"></i>  Edit Your Profile </h3>
                </div>
                <div class="card-body">


                    <form id="update" class="" action="" method="POST">
                        <div class="form-group">
                            <input type="text" name="fname" class="form-control" placeholder="First Name" value="<%out.print(fname);%>">
                        </div>
                        <div class="form-group">
                            <input type="text"  name="lname" class="form-control" placeholder="Last Name" value="<%out.print(lname);%>">
                        </div>

                        <div class="form-group">
                            <input id = "rollno" type="number" value="<%out.print(rollno);%>" name="rollno" class="form-control" placeholder="Your Roll no">
                        </div>

                        <div class="form-group">
                            <input type="email" name="email" id="email" value="<%out.print(email);%>" class="form-control" placeholder="yourEmail@example.com" required>
                        </div>

                        <input hidden id="current_rollno" name="current_rollno" value="<%out.print(rollno);%>">
                        <input hidden id="current_email" name="current_email" value="<%out.print(email);%>">

                    <div class="form-group">

                        <label for="SelectClass">Select Your class</label>
                        <select id="SelectClass" name="class" class="custom-select" required>
                            <%
                                for(int i=0;i<ClassNames.size();i++)
                                {
                                    out.print(String.format("<option value=\"%s\">%s </option>",((Vector)ClassNames.get(i)).get(1).toString(),((Vector)ClassNames.get(i)).get(0)));
                                }
                            %>
                        </select>


                    </div>

                    <div class="form-group">
                        <label for="SelectBatch">Select Your Batch</label>
                        <select id="SelectBatch" name="batch" class="custom-select">
                            <script>
                                $("#SelectClass").change(function(e){

                                    $.ajax({
                                        url:"GetBatches?c_id="+$("#SelectClass").val(),

                                        success:function(data){
                                            $("#SelectBatch").html("");

                                            for(var i=0;i<data.length;i++){
                                                $("#SelectBatch").append("<option value='"+data[i]["id"]+"'>"+data[i]["name"]+"    </option>");
                                            }
                                        },
                                        error:function(err){
                                            $("#SelectBatch").html("");
                                            $("#SelectBatch").append("<option value=-1>"+"No Data Available"+"</option>");

                                        }
                                    });
                                });

                                $().ready(function() {
                                    // validate the comment form when it is submitted

                                    $.validator.setDefaults({
                                        errorClass: 'invalid-feedback',
                                        highlight: function (element) {
                                            $(element).removeClass('is-valid');
                                            $(element).addClass('is-invalid');
                                        },
                                        unhighlight: function (element) {
                                            $(element).removeClass('is-invalid');
                                            $(element).addClass('is-valid');
                                        }
                                    });

                                    $("#update").validate({
                                            rules: {

                                                lname: {
                                                    required: true,
                                                    maxlength: 30,
                                                    nowhitespace: true,
                                                    lettersonly: true
                                                },
                                                fname: {
                                                    required: true,
                                                    maxlength: 30,
                                                    nowhitespace: true,
                                                    lettersonly: true
                                                },
                                                rollno:{
                                                    required:true,
                                                    remote : {
                                                        url: "Rollno",
                                                        data: {current_rollno : $("#current_rollno").val()}
                                                    }
                                                },
                                                email: {
                                                    maxlength: 40,
                                                    email: true,
                                                    remote : {
                                                        url: "UserValidation",
                                                        data: {current_email : $("#current_email").val()}
                                                    }
                                                },
                                                class:
                                                    {
                                                        required: true,

                                                    },

                                                batch:
                                                    {
                                                        required: true,

                                                    }
                                            }
                                        })

                                })
                            </script>


                        </select>
                    </div>


                        <div class="form-group">
                            <input type="submit" class="btn btn-primary btn-md" value="Update Info">

                        </div>


                        <div class="alert" role="alert">

                        </div>
                    </form>





                </div>
            </div>

        </div>
    </div>
</div>
</body>
</html>
