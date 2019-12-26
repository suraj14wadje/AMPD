#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>

#define pf printf
#define sf scanf


int ErrTab_Count = 0;
int Ictab_Count = 0;
int Symtab_Count = 0;
int lc = -1;

const char *Mne[]={ 
    "STOP","ADD","SUB","MULT","MOVER","MOVEM",
    "COMP","BC","DIV","READ","PRINT","DS","DC","START","STOP","END"
};

const char *reg[]={
    "AREG","BREG","CREG","DREG"
};

const char *cc[]={
    "LT","LE","EQ","GT","GE","ANY"
};

const char *errmsg[] = {
    "Used but not defined (Each Incident Is Reported Only once)","Invalid opcode","Wrong Statement format",
    "Invalid Register","Invalid Condition Code","No Start Statement declared",
    "No Label Has Defined","Invalid Lable.."
};

typedef struct symtab{
    char symbol[30];
    int add;
    int used;
    int defined;
} symtab;

symtab* Add_symtab(symtab *symtab_arr,symtab temp){

    Symtab_Count++;
    symtab_arr = realloc(symtab_arr,Symtab_Count*sizeof(symtab));
    symtab_arr[Symtab_Count-1] = temp;
    return symtab_arr;
}

typedef struct ictab{
    int address;
    int opcode;
    int regop;
    char optype;
    int value;
} ictab;

ictab* Add_Ictab(ictab *Ictab_Arr,ictab temp)
{
    Ictab_Count++;
    Ictab_Arr = realloc(Ictab_Arr,Ictab_Count*sizeof(ictab));
    Ictab_Arr[Ictab_Count-1] = temp;
    return Ictab_Arr;
}

typedef struct errtab{
    int lineno;
    int errno;
} errtab;

errtab* Add_errtab(errtab* Err,errtab temp)
{
    ErrTab_Count++;
    Err = realloc(Err,sizeof(errtab)*ErrTab_Count);
    Err[ErrTab_Count-1] = temp;
    return Err; 
}

int Check_Mnemonics(char *temp)
{
    int count = sizeof(Mne)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(Mne[i],temp)==0)
            return i;
    }
    return -1;
}

int Check_Condition_Code(char *temp)
{
    int count = sizeof(cc)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(cc[i],temp)==0)
            return i;
    }
    return -1;
}

int Check_Register(char *temp)
{
    int count = sizeof(reg)/sizeof(char*);
    int i;
    for(i = 0;i<count;i++)
    {
        if(strcmp(reg[i],temp)==0)
            return i;
    }
    return -1;
}

void Display_Symbol_Table(symtab *temp)
{
    int i;

    pf("%30s\t%8s\t%8s\t%8s\n\n","Symbol","Address","Used","Defined");

    for(i =0;i<Symtab_Count;i++)
    {
        pf("%30s\t%8d\t%8d\t%8d\n",temp[i].symbol,temp[i].add,temp[i].used,temp[i].defined);
    }
}

void write_Ic_Table_to_file(char* filename,ictab *temp,symtab *symbol)
{
    FILE *fp = fopen(filename,"w");
    int i;

    for(i =0;i<Ictab_Count;i++)
    {
        if(temp[i].optype == 'S')
        {
            fprintf(fp,"%3d %2d%1d %s\n",temp[i].address,temp[i].opcode,temp[i].regop,symbol[temp[i].value].symbol);
        }
        else
            fprintf(fp,"%03d %02d%1d%03d\n",temp[i].address,temp[i].opcode,temp[i].regop,temp[i].value);
    }

    fclose(fp);

}


void Display_Ic_Table(ictab *temp,symtab *symbol)
{
    int i;
    pf("%8s\t%8s\t%8s\t%8s\t%8s\n\n","Address","Opcode","Reg Opecode","Opcode Type","Value");

    for(i =0;i<Ictab_Count;i++)
    {
        if(temp[i].optype == 'S')
        {
            pf("%8d\t%8d\t%8d\t%8c\t%8s\n",temp[i].address,temp[i].opcode,temp[i].regop,temp[i].optype,symbol[temp[i].value].symbol);
        }
        else
            pf("%8d\t%8d\t%8d\t%8c\t%8d\n",temp[i].address,temp[i].opcode,temp[i].regop,temp[i].optype,temp[i].value);
    }

}

int find_sym(symtab *arr,char *str)
{
    int i;
    for(i=0;i<Symtab_Count;i++)
    {
        if(strcmp(arr[i].symbol,str)==0)
        {
            return i;
        }
    }

    return -1;
}

void Display_Error_table(errtab *err)
{
    int i;
    for(i=0;i<ErrTab_Count;i++)
    {
        pf("\n%d %s\n",err[i].lineno,errmsg[err[i].errno]);
    }
}

void Process_Tokens(char *lable,char *operand,int opcode,int reg,errtab **Err,symtab **Symtab_Arr,ictab **Ictab_arr,int line_no)
{
    symtab temp_sym;
    errtab temp_Err;
    ictab temp_Ictab;
    int i,n;
    temp_Ictab.address = lc;
    temp_Ictab.opcode = opcode;
    temp_Ictab.regop = reg;
    if( strcmp(lable,"") != 0)
    {
        i = find_sym((*Symtab_Arr),lable);
        if(i !=-1 && (*Symtab_Arr)[i].defined==1)
        {
            
            temp_Err.errno = 7;
            temp_Err.lineno=line_no;
            *Err = Add_errtab(*Err,temp_Err);
            return ;
        }
        else if( i != -1)
        {
           (*Symtab_Arr)[i].add = lc;
           (*Symtab_Arr)[i].defined = 1;
        }
        else
        {
            temp_sym.add=lc;
            temp_sym.defined=1;
            temp_sym.used = 0;
            strcpy(temp_sym.symbol,lable);
            (*Symtab_Arr)= Add_symtab((*Symtab_Arr),temp_sym);
        }
    }

    if(!isdigit(operand[0]) && operand[0]!='\'' && opcode != 0){
        i = find_sym((*Symtab_Arr),operand);
        if(i == -1)
        {
            temp_Ictab.optype = 'S';
            temp_sym.add =-1;
            temp_sym.used = 1;
            temp_sym.defined =0;
            strcpy(temp_sym.symbol,operand);
            (*Symtab_Arr)= Add_symtab((*Symtab_Arr),temp_sym);
            temp_Ictab.value = Symtab_Count-1;
            *Ictab_arr= Add_Ictab(*Ictab_arr,temp_Ictab);
        }
        else if((*Symtab_Arr)[i].defined == 0)
        {
             temp_Ictab.optype = 'S';
             temp_Ictab.value = i;
             *Ictab_arr= Add_Ictab(*Ictab_arr,temp_Ictab);
           
        }
        else if(opcode == 15)
        {
            temp_Ictab.address = -1;
            temp_Ictab.opcode =0;
            temp_Ictab.value = (*Symtab_Arr)[i].add;
            *Ictab_arr=Add_Ictab(*Ictab_arr,temp_Ictab);
            return;
        }
        else{
             temp_Ictab.optype ='C';
            temp_Ictab.value = (*Symtab_Arr)[i].add;
            (*Symtab_Arr)[i].used=1;
            *Ictab_arr= Add_Ictab(*Ictab_arr,temp_Ictab);
        }
    }

    else
    {
        temp_Ictab.optype ='C';
        if(opcode == 12)
        {
            temp_Ictab.value = atoi(operand+1);
            temp_Ictab.opcode = 0;

        }
        else if(opcode == 15)
        {
            temp_Ictab.address = -1;
            temp_Ictab.opcode =0;
            *Ictab_arr=Add_Ictab(*Ictab_arr,temp_Ictab);
            return;
        }
        else if(opcode == 11)
        {
            temp_Ictab.opcode=0;
            temp_Ictab.regop=0;
            temp_Ictab.value=0;
            n=atoi(operand);
            for(i=1;i<n;i++)
            {
                temp_Ictab.address=lc;
                *Ictab_arr = Add_Ictab(*Ictab_arr,temp_Ictab);
                lc++;

            }
        }

        else
            temp_Ictab.value = atoi(operand);
        
        temp_Ictab.address=lc;

        *Ictab_arr=Add_Ictab(*Ictab_arr,temp_Ictab);
    }
   
    
    if(lc == -1)
    {
        temp_Err.errno=5;
        temp_Err.lineno = 0;
        *Err= Add_errtab(*Err,temp_Err);
        return;
    }
    lc++;

}


void Separate_Tokens(char *str,int line_No,errtab **Err,symtab **symtab_arr,ictab **ictab_arr)
{
    int n;
    int opcode ,reg;
    char s1[30],s2[30],s3[30],s4[30];
    n = sscanf(str,"%s%s%s%s",s1,s2,s3,s4);
    errtab temp;
    ictab ictab_temp;
    if(n==4)
    {
        opcode = Check_Mnemonics(s2);
        if(opcode == 8)
            reg = Check_Condition_Code(s3);
        else
            reg = Check_Register(s3);
        
       if(opcode  == -1)
        {
           temp.errno = 1;
           temp.lineno = line_No;
          *Err= Add_errtab(*Err,temp);
        }
        if(reg == -1)
        {
            temp.errno = 3;
            temp.lineno = line_No;
            *Err= Add_errtab(*Err,temp);
            return;
        }

        Process_Tokens(s1,s4,opcode,reg,Err,symtab_arr,ictab_arr,line_No);
        return;
    }

    else if(n==3)
    {
        opcode  = Check_Mnemonics(s1);
        if(opcode  == -1)
        {
            opcode  = Check_Mnemonics(s2);
            reg = 0;

            if(opcode  == -1)
            {
                temp.errno = 1;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);
            }

            if(opcode  >= 1 && opcode  <= 8)
            {
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);

                return;
            }

            Process_Tokens(s1,s3,opcode,reg,Err,symtab_arr,ictab_arr,line_No);
            return;
        }
        if(opcode == 7)
        {
            reg = Check_Condition_Code(s2);
            if(reg == -1)
            {
                temp.errno = 4;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);
                return;
            }

        }
        else
        {
            reg = Check_Register(s2);
            if(reg == -1)
            {
                temp.errno = 3;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);
                return;
            }

        }
        Process_Tokens("",s3,opcode,reg,Err,symtab_arr,ictab_arr,line_No);
        return;
}

    else if(n==2)
    {
        opcode  = Check_Mnemonics(s1);
        if(opcode  == -1)
        {
            opcode  = Check_Mnemonics(s2);
            if(opcode  !=  0)
            { 
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);

                return;
            }
            Process_Tokens(s1,"",opcode,0,Err,symtab_arr,ictab_arr,line_No);
            return;
        }
        else if(opcode  <9 && opcode  > 13)
        {
                temp.errno = 2;
                temp.lineno = line_No;
                *Err= Add_errtab(*Err,temp);

                return;

        }
        else if(opcode == 13)
        {
            lc = atoi(s2);
            return;
        }

        Process_Tokens("",s2,opcode,0,Err,symtab_arr,ictab_arr,line_No);
        return;
    }

    else if(n==1)
    {
        opcode  = Check_Mnemonics(s1);
        if(opcode  != 0)
        {
            temp.errno = 2;
            temp.lineno = line_No;
            *Err= Add_errtab(*Err,temp);
            return;
        }
        Process_Tokens("","",opcode,0,Err,symtab_arr,ictab_arr,line_No);
        return;
    }


}

void passtwo(ictab *ictab_arr,symtab *symtab_arr,errtab **errtab_arr)
{
    int i,j;
    errtab temp;
    for(i=0;i<Ictab_Count;i++)
    {
        if(ictab_arr[i].optype == 'S')
        {
            j = symtab_arr[ictab_arr[i].value].add;
            if(j==-1)
            {
                temp.errno = 0;
                temp.lineno = i+2;
               *errtab_arr =  Add_errtab(*errtab_arr,temp);
               symtab_arr[ictab_arr[i].value].add = 0;

            }

            else
            {
                ictab_arr[i].value = j;
                ictab_arr[i].optype= 'C';
                
            }
            
        }
    }

    Display_Ic_Table(ictab_arr,symtab_arr);
    return;
}