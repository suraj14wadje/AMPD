#include<iostream>
#include<string>

#define SIZE 2

using namespace std;

class Time24;
class Time12
{
  int hh, mm, ss;
  char suf[SIZE];
public:
    Time12 ()
  {
    hh = mm = ss = 0;
    strcpy (suf, "am");
  }
  void set ();
  friend void compair (Time12, Time24);
  void display ()
  {
    cout << hh << ":" << mm << ":" << ss << "  " << suf;
  }
};

void
Time12::set ()
{
  cout << "Enter the time in formate(HH:MM:SS)";
  cin >> hh >> mm >> ss;
while((hh<1 ||hh>12) ||
      (mm<1 ||mm>59) ||
      (ss<1 ||ss>59))
   {
  cout<<"Enter valid time:"; 
  cin>>hh>>mm>>ss;
   } 
  cout << "Enter the meridan(am/pm):";
 cin >> suf;
}



class Time24
{
  int ss, mm, hh;
public:
    Time24 ()
  {
    ss = mm = hh = 0;
  }
  inline void getTime ();
  inline void dispTime ();

  friend void compair (Time12 t1, Time24 t2)
  {
    char a[] = "pm";
    if (strcmp (t1.suf, a) == 0)
	  {cout<<"\nthe conservation of time from 12 hr to 24:-  ";
	    cout << (t1.hh + 12) << ":" << t1.mm << ":" << t1.ss;
	  }
	else
	  {cout<<"\nthe conservation of time from 12 hr to 24:-  ";
	    cout << t1.hh << ":" << t1.mm << ":" << t1.ss;
	  }
      
    cout << "\n";
    if (t2.hh > 12)
      {cout<<"\nthe converted of time from 24 hr to 12:-   ";
	cout << (t2.hh - 12) << ":" << t2.mm << ":" << t2.ss << "  pm";
      }
    else
      {cout<<"\nthe converted time from 24 hr to 12:-   ";
	cout << t2.hh << ":" << t2.mm << ":" << t2.ss << "  am";
      }
  }
};

inline void
Time24::getTime ()
{
  cout << "\nEnter the hrs,min & secc\t";
  cin >> hh >> mm >> ss;
  if (ss > 59)
    {
      ss = (ss - 60);
      mm++;
    }
  if (mm > 59)
    {
      mm = mm - 60;
      hh++;
    }
  if (hh > 23)
    {
      hh = hh - 24;
    }

}

inline void
Time24::dispTime ()
{
  cout << "\nThe  Time is\t hrs:" << hh << "\tmin:" << mm << "\tsec:" << ss;
}

int
main ()
{
  Time12 t1;
  Time24 t2;
  t1.set ();
  t1.display ();
  cout<<"\n";
  Time12 t3 = t1;

  t2.getTime ();
  t2.dispTime ();
cout<<"\n";
  Time24 t4 = t2;

  compair (t3, t4);

}

