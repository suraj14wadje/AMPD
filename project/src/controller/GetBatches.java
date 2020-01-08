package controller;

import Model.Batch;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Vector;

public class GetBatches extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String classId = request.getParameter("c_id");
        int c_id = -1;
        if(classId != null)
            c_id = Integer.parseInt(classId);
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        Vector result = Batch.getBatchNameFromC_id(c_id);
        String JsonString = "[";
        for(int i = 0;i<result.size();i++)
        {
            if(i!=0)
                JsonString+=",";
            JsonString+="{ \"id\" :";
            JsonString+=(((Vector)result.get(i)).get(1).toString()+",\"name\" : \"");
            JsonString+=((Vector)result.get(i)).get(0).toString()+"\"";





            JsonString+="}";

        }
        JsonString+="]";


        response.getWriter().write(JsonString);
    }
}
