#include<iostream>
using namespace std;
class time24;
class time12
{
  int hh, mm, ss;
  char array[2];
public:
    time12 ()
  {
    hh = 12;
    mm = 0;
    ss = 0;

  }
  void get ();
  friend void convert (time12 & x, time24 & y);
  void display ();
  friend void co (time12 & x, time24 & y);
};
inline void
time12::get ()
{
  cout << "\n Enter hours:";
  cin >> hh;
  cout << "\n Enter min:";
  cin >> mm;
  cout << "\n Enter seconds:";
  cin >> ss;
  cout << "\n Enter am/pm:";
  cin >> array;
  cout << endl;
}
inline void
time12::display ()
{

  cout << "\n  hours:" << hh << endl;
  cout << "\n  min:" << mm << endl;
  cout << "\n  seconds:" << ss << endl;

}

class time24
{
  int hh, mm, ss;

public:
    time24 ()
  {
    hh = 12;
    mm = 0;
    ss = 0;
  }
  void get ();
  void display ();
  friend void convert (time12 & x, time24 & y);
  friend void co (time12 & x, time24 & y);
};
inline void
time24::get ()
{
  cout << "\n Enter hours:";
  cin >> hh;
  cout << "\n Enter min:";
  cin >> mm;
  cout << "\n Enter seconds:";
  cin >> ss;
  cout << endl;
}
inline void
time24::display ()
{

  cout << "\n  hours:" << hh << endl;
  cout << "\n  min:" << mm << endl;
  cout << "\n  seconds:" << ss << endl;

}

void
co (time12 & x, time24 & y)
{
int h;
  if (strcmp (x.array, "pm"))
    {
      h = 12 + x.hh;
    }
  if (h != y.hh)
    {
      if (x.hh > y.hh)
	cout << "\n 12 hour time is greater..\n";
      else
	cout << "\n 24 hour time is greater..\n";
    }
  else if (x.mm != y.mm)
    {
      if (x.mm > y.mm)
	cout << "\n 12 hour time is greater..\n";
      else
	cout << "\n 24 hour time is greater..\n";
    }
  else if (x.ss != y.ss)
    {
      if (x.ss > y.ss)
	cout << "\n 12 hour time is greater..\n";
      else
	cout << "\n 24 hour time is greater..\n";
    }
  else
    cout << "\n Both are same...\n";
}

void
convert (time12 & x, time24 & y)
{
  cout << "\n Conversion of 12 hour format to 24 hour format..\n";
  int h;
  if (strcmp (x.array, "pm")==0)
    {
      h = x.hh+12;
    }
 else 
    h = x.hh;
  int m = x.mm;
  int s = x.ss;
  cout << "\n Hours:" << h << endl;
  cout << "\n Minutes:" << m << endl;
  cout << "\nSeconds:" << s << endl;

  cout << "\n Conversion of 24 hour format to 12 hour format..\n";
  int p, q, r, flag = 0;
  if (y.hh > 12)
    {
      p = y.hh - 12;
      flag = 1;
    }
  else
    p = y.hh;
  q = y.mm;
  r = y.ss;
  cout << "\n Hours:" << p << endl;
  cout << "\n Minutes:" << q << endl;
  cout << "\nSeconds:" << r << endl;
  if (flag == 1)
    cout << "pm";
  else
    cout << "am";

  cout << endl;
}



int
main ()
{
  system ("clear");
  time12 t;
  t.get ();
t.display();
  time24 p;
  p.get ();
p.display();
co(t,p);
  convert (t, p);
  return 0;
}
