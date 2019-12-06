
<p align="center">
<h1> Assignment manager and Code Plagiarism Detection System </h1>
</p>

| Sr. no   |     Title      |  page no |
|:----------|:-------------:|:------:|
| 1 |  Introduction |  |
| 2 |    Existing System   |  |
| 3 | Drawbacks Of Existing System |   |
| 4 | Praposed system | |
| 5 | Scope Of Praposed System | |
| 6 | Technical Feasibility | |
| 7 | Operational Feasibility | |
| 8 | Economical Feasibility | |
| 9 | Use Case | |
| 10 | ER Diagram | |
### Introduction
 It is a sad reality of college, a lot of students copy other students submissions or fail to cite references and violate the honor code. The objective of this project is to detect such cases of plagiarism among students and build a system which will have an interface for teachers to create new assignments and view submitted assignments, and for students to submit assignments.

### Existing System:
    
<p>    In Existing system Teacher gives assignments to students manually i.e(Handwritten Handbook) these assignmets are then completed by the student.
most of these assignments are in the form of c++/java/c programming language.

after completing this assignmet and shows it to relative teacher from the machine that they are working. The teacher will evaluate the
assignments and gives the remark on some maintained paper.

 In this process, students were copying assignments of other students and get it checked by their respective teachers. And because of this student are out of knowledge. Practical knowledge is also important as of theoretical knowledge but because of this student habit of copying another student assignment, they are not aware of the actual practical knowledge



### Drawbacks Of Existing System:
*    Becomes Hard to Maintain paper records of students remarks.
*    It becomes nearly impossible for a teacher to recall other students code to check if the code is plagiarised.

### Proposed System

<p>In proposed system teacher will create new assignments each assignment belongs to some class(fy,sy,ty,msc-1,msc-2). these assignments will be visible on students homepage from there student can complete their assignments from local machine and once the assinment is done student can submit it.
when student clicks on submit button assignment is stored in database in the form of text this stored assignmet is now undergoes a plagiarism detection algorithm and assigns score for plagiarism. All the submission from students are visible to relative teachers.
this code is reviewed by teacher and remarks and marks are given.

### Scope of the proposed system:
*    A teacher can create new assignments, view submitted assignments, view plagiarised assignments, evaluate the
    submitted assignments.
   
*    A student can view available assignments, view remarks for evaluated assignments, view due assignments, Submit
     a particular assignment.
   
*    The system will
   
     * Store the Submitted assignment in the server.

     *    If the assignment is c/c++ source code it will scan other relative submitted assignments to detect plagiarism.

---

## Feasibility study:

###     Technical feasibility:

<p> Server will require any linux environment to run while client will have to have any web browser to use the system.

Minimum requirements for server are:
* 2 GB of ram
* Linux operating system
* PostGreSQL
* JAVA


### Operational feasibility:

<p> The System Is operationally feasible because it will be a GUI based system and will be simple and easy to use. In the existing system, all work is done manually which is a time-consuming and tedious job and also difficult to maintain paper records. Hence the proposed system provides a systematic method and improves the performance of the system in managing the submissions of student’s assignments.
 

    
###    Economic feasibility:
<p>        The tools that are being used in this project are open source hence there will be no economical cost to implement this system.



---


## Use Case Diagram

![Use Case](https://www.lucidchart.com/publicSegments/view/39ff1a53-79f1-4daa-9c54-19e739cb6500/image.jpeg)

## Use Case Scenario

* ### Usecase Description: 
    <p> This usecase describes the working of the system. It describes
    how the student logins and submits a assignment and how a teacher registers and reviews submitted Assignment </p>


* ### Actors:
    Teacher,Student,HOD,Database.
* ### Preconditions:
    student have registered

* ### Postconditions: 
    Updated all tables.

* ### Basic flow of system:
    <ol type="a">
    <li> teacher creates its account
    <li> HOD assigns Teacher their respective batches
    <li> Teacher will create assignments
    <li> Created Assignment will be visible to students
    <li> student completes its assignment and submits
    <li> submitted assignment will be visible to respective batch incharges
    <li>submitted assignment undergoes plagiarism detection algorithm
    <li> Teacher reviews assignment and gives remark
    </ol>

* ### Alternative Flow:
    If user enters wrong credentials there will be error




## ER Diagram

![ERD](https://www.lucidchart.com/publicSegments/view/e16be721-7d87-438e-bd5b-85ed0772e5cf/image.j00peg)


![ERD](https://www.lucidchart.com/publicSegments/view/10f34619-dcb6-44fc-a481-4fcbd625b9b2/image.jpeg)
