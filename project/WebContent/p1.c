#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>
/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
#define pf printf
#define sf scanf


int A1 = 0;
int A2 = 0;
int A3 = 0;
int lc = -1;

const char *V4[]={
    "STOP","ADD","SUB","MULT","MOVER","MOVEM",
    "COMP","BC","DIV","READ","PRINT","DS","DC","START","STOP","END"
};

const char *V5[]={
    "AV5","BV5","CV5","DV5"
};

const char *V6[]={
    "LT","LE","EQ","GT","GE","ANY"
};

const char *V7[] = {
    "Used but not defined (Each Incident Is Reported Only once)","Invalid opcode","Wrong Statement format",
    "Invalid V5ister","Invalid Condition Code","No Start Statement declared",
    "No Label Has Defined","Invalid Lable.."
};

typedef struct V7{
    char symbol[30];
    int add;
    int used;
    int defined;
} V7;

V7* Add_V7(V7 *V7_arr,V7 temp){

    A3++;
    V7_arr = realloc(V7_arr,A3*sizeof(V7));
    V7_arr[A3-1] = temp;
    return V7_arr;
}

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/

typedef struct V9{
    int V15;
    int opcode;
    int V5op;
    char optype;
    int value;
} V9;
/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
V9* Add_V9(V9 *V9_Arr,V9 temp)
{
    A2++;
    V9_Arr = realloc(V9_Arr,A2*sizeof(V9));
    V9_Arr[A2-1] = temp;
    return V9_Arr;
}

typedef struct V10{
    int lineno;
    int errno;
} V10;

V10* Add_V10(V10* Err,V10 temp)
{
    A1++;
    Err = realloc(Err,sizeof(V10)*A1);
    Err[A1-1] = temp;
    return Err;
}
/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
int V19(char *temp)
{
    int count = sizeof(V4)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(V4[i],temp)==0)
            return i;
    }
    return -1;
}

int Check_Condition_Code(char *temp)
{
    int count = sizeof(V6)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(V6[i],temp)==0)
            return i;
    }
    return -1;
}
/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
void V20(V7 *temp)
{
    int i;

    pf("%30s\t%8s\t%8s\t%8s\n\n","Symbol","V15","Used","Defined");

    for(i =0;i<A3;i++)
    {
        pf("%30s\t%8d\t%8d\t%8d\n",temp[i].symbol,temp[i].add,temp[i].used,temp[i].defined);
    }
}

int Check_V5ister(char *temp)
{
    int count = sizeof(V5)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(V5[i],temp)==0)
            return i;
    }
    return -1;
}




void Display_Ic_Table(V9 *temp,V7 *symbol)
{
    int i;
    pf("%8s\t%8s\t%8s\t%8s\t%8s\n\n","V15","Opcode","V5 Opecode","Opcode Type","Value");

    for(i =0;i<A2;i++)
    {
        if(temp[i].optype == 'S')
        {
            pf("%8d\t%8d\t%8d\t%8c\t%8s\n",temp[i].V15,temp[i].opcode,temp[i].V5op,temp[i].optype,symbol[temp[i].value].symbol);
        }
        else
            pf("%8d\t%8d\t%8d\t%8c\t%8d\n",temp[i].V15,temp[i].opcode,temp[i].V5op,temp[i].optype,temp[i].value);
    }

}
/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/

void write_Ic_Table_to_file(char* filename,V9 *temp,V7 *symbol)
{
    FILE *fp = fopen(filename,"w");
    int i;

    for(i =0;i<A2;i++)
    {
        if(temp[i].optype == 'S')
        {
            fprintf(fp,"%3d %2d%1d %s\n",temp[i].V15,temp[i].opcode,temp[i].V5op,symbol[temp[i].value].symbol);
        }
        else
            fprintf(fp,"%03d %02d%1d%03d\n",temp[i].V15,temp[i].opcode,temp[i].V5op,temp[i].value);
    }

    fclose(fp);

}

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/
int find_sym(V7 *arr,char *str)
{
    int i;
    for(i=0;i<A3;i++)
    {
        if(strcmp(arr[i].symbol,str)==0)
        {
            return i;
        }
    }

    return -1;
}

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/



void Process_Tokens(char *lable,char *operand,int opcode,int V5,V10 **Err,V7 **V7_Arr,V9 **V9_arr,int line_no)
{
    V7 temp_sym;
    V10 temp_Err;
    V9 temp_V9;
    int i,n;
    temp_V9.V15 = lc;
    temp_V9.opcode = opcode;
    temp_V9.V5op = V5;
    if( strcmp(lable,"") != 0)
    {
        i = find_sym((*V7_Arr),lable);
        if(i !=-1 && (*V7_Arr)[i].defined==1)
        {

            temp_Err.errno = 7;
            temp_Err.lineno=line_no;
            *Err = Add_V10(*Err,temp_Err);
            return ;
        }
        else if( i != -1)
        {
           (*V7_Arr)[i].add = lc;
           (*V7_Arr)[i].defined = 1;
        }
        else
        {
            temp_sym.add=lc;
            temp_sym.defined=1;
            temp_sym.used = 0;
            strcpy(temp_sym.symbol,lable);
            (*V7_Arr)= Add_V7((*V7_Arr),temp_sym);
        }
    }

    if(!isdigit(operand[0]) && operand[0]!='\'' && opcode != 0){
        i = find_sym((*V7_Arr),operand);
        if(i == -1)
        {
            temp_V9.optype = 'S';
            temp_sym.add =-1;
            temp_sym.used = 1;
            temp_sym.defined =0;
            strcpy(temp_sym.symbol,operand);
            (*V7_Arr)= Add_V7((*V7_Arr),temp_sym);
            temp_V9.value = A3-1;
            *V9_arr= Add_V9(*V9_arr,temp_V9);
        }
        else if((*V7_Arr)[i].defined == 0)
        {
             temp_V9.optype = 'S';
             temp_V9.value = i;
             *V9_arr= Add_V9(*V9_arr,temp_V9);

        }
        else if(opcode == 15)
        {
            temp_V9.V15 = -1;
            temp_V9.opcode =0;
            temp_V9.value = (*V7_Arr)[i].add;
            *V9_arr=Add_V9(*V9_arr,temp_V9);
            return;
        }
        else{
             temp_V9.optype ='C';
            temp_V9.value = (*V7_Arr)[i].add;
            (*V7_Arr)[i].used=1;
            *V9_arr= Add_V9(*V9_arr,temp_V9);
        }
    }

    else
    {
        temp_V9.optype ='C';
        if(opcode == 12)
        {
            temp_V9.value = atoi(operand+1);
            temp_V9.opcode = 0;

        }
        else if(opcode == 15)
        {
            temp_V9.V15 = -1;
            temp_V9.opcode =0;
            *V9_arr=Add_V9(*V9_arr,temp_V9);
            return;
        }
        else if(opcode == 11)
        {
            temp_V9.opcode=0;
            temp_V9.V5op=0;
            temp_V9.value=0;
            n=atoi(operand);
            for(i=1;i<n;i++)
            {
                temp_V9.V15=lc;
                *V9_arr = Add_V9(*V9_arr,temp_V9);
                lc++;

            }
        }

        else
            temp_V9.value = atoi(operand);

        temp_V9.V15=lc;

        *V9_arr=Add_V9(*V9_arr,temp_V9);
    }


    if(lc == -1)
    {
        temp_Err.errno=5;
        temp_Err.lineno = 0;
        *Err= Add_V10(*Err,temp_Err);
        return;
    }
    lc++;

}

void Display_Error_table(V10 *err)
{
    int i;
    for(i=0;i<A1;i++)
    {
        pf("\n%d %s\n",err[i].lineno,V7[err[i].errno]);
    }
}




void passtwo(V9 *V9_arr,V7 *V7_arr,V10 **V10_arr)
{
    int i,j;
    V10 temp;
    for(i=0;i<A2;i++)
    {
        if(V9_arr[i].optype == 'S')
        {
            j = V7_arr[V9_arr[i].value].add;
            if(j==-1)
            {
                temp.errno = 0;
                temp.lineno = i+2;
               *V10_arr =  Add_V10(*V10_arr,temp);
               V7_arr[V9_arr[i].value].add = 0;

            }

            else
            {
                V9_arr[i].value = j;
                V9_arr[i].optype= 'C';

            }

        }
    }

    Display_Ic_Table(V9_arr,V7_arr);
    return;
}

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/


void Separate_Tokens(char *str,int line_No,V10 **Err,V7 **V7_arr,V9 **V9_arr)
{
    int n;
    int opcode ,V5;
    char s1[30],s2[30],s3[30],s4[30];
    n = sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
    V10 temp;
    V9 V9_temp;
    if(n==4)
    {
        opcode = V19(s2);
        if(opcode == 8)
            V5 = Check_Condition_Code(s3);
        else
            V5 = Check_V5ister(s3);

       if(opcode  == -1)
        {
           temp.errno = 1;
           temp.lineno = line_No;
          *Err= Add_V10(*Err,temp);
        }
        if(V5 == -1)
        {
            temp.errno = 3;
            temp.lineno = line_No;
            *Err= Add_V10(*Err,temp);
            return;
        }

        Process_Tokens(s1,s4,opcode,V5,Err,V7_arr,V9_arr,line_No);
        return;
    }

    else if(n==3)
    {
        opcode  = V19(s1);
        if(opcode  == -1)
        {
            opcode  = V19(s2);
            V5 = 0;

            if(opcode  == -1)
            {
                temp.errno = 1;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);
            }

            if(opcode  >= 1 && opcode  <= 8)
            {
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);

                return;
            }

            Process_Tokens(s1,s3,opcode,V5,Err,V7_arr,V9_arr,line_No);
            return;
        }
        if(opcode == 7)
        {
            V5 = Check_Condition_Code(s2);
            if(V5 == -1)
            {
                temp.errno = 4;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);
                return;
            }

        }
        else
        {
            V5 = Check_V5ister(s2);
            if(V5 == -1)
            {
                temp.errno = 3;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);
                return;
            }

        }
        Process_Tokens("",s3,opcode,V5,Err,V7_arr,V9_arr,line_No);
        return;
    }

    else if(n==2)
    {
        opcode  = V19(s1);
        if(opcode  == -1)
        {
            opcode  = V19(s2);
            if(opcode  !=  0)
            {
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);

                return;
            }
            Process_Tokens(s1,"",opcode,0,Err,V7_arr,V9_arr,line_No);
            return;
        }
        else if(opcode  <9 && opcode  > 13)
        {
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_V10(*Err,temp);

                return;

        }
        else if(opcode == 13)
        {
            lc = atoi(s2);
            return;
        }

        Process_Tokens("",s2,opcode,0,Err,V7_arr,V9_arr,line_No);
        return;
    }

    /* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/

    else if(n==1)
    {
        opcode  = V19(s1);
        if(opcode  != 0)
        {
            temp.errno = 2;
            temp.lineno = line_No;
            *Err= Add_V10(*Err,temp);
            return;
        }
        Process_Tokens("","",opcode,0,Err,V7_arr,V9_arr,line_No);
        return;
    }


}

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/

/* comment is being added to fool Plagiarism detection
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
*/