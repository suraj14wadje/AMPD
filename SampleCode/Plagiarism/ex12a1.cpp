#include<iostream>
#include<math.h>
using namespace std;

class date1
{

  int dd, mm, yy;
public:

    date1 ()
  {
    dd = 0;
    mm = 0;
    yy = 0;
  }
  void binary (int a[], int n)
  {
    int i = 0, k;
    do
      {
	k = n % 2;
	a[i] = k;
	n = n / 2;
	i++;
      }
    while (n != 0);
  }

inline  date1 (int dd, int mm, int yy)
  {
    this->dd = dd;
    this->mm = mm;
    this->yy = yy;
  }
inline  void display ()
  {
    cout << "dd:mm:yy=" << dd << ":" << mm << ":" << yy;
  }
  int compress ()
  {
    int no = 0, arr[15];
    int i, j, k = yy;






    for (i = 9; i <= 15; i++)
      {
	arr[i] = k % 2;
	k = k / 2;

      }
    k = mm;



    i = 5;
    for (i = 5; i <= 8; i++)
      {
	arr[i] = k % 2;
	k = k / 2;

      }
    i = 0;
    for (i = 0; i <= 4; i++)
      {
	arr[i] = dd % 2;

	dd = dd / 2;

      }
    cout << "\n\n";
    for (int i = 15; i >= 0; i--)
      {
	cout << arr[i] << "\t";
      }
    cout << "\n";
    for (int i = 0; i <= 15; i++)
      {
       if(arr[i]==1)
	no = no + (int) (arr[i] * pow (2, i));
      }
    return no;
  }


inline int datediff (date1 d1)
  {
    if ((d1.mm == mm) && (d1.yy == yy) && (d1.dd == dd))
      return 0;
    int a1 = 0, a2 = 0;
    a1 = dd;
    a1 = a1 + (mm - 1) * 30;
    for (int i = 1; i < mm; i++)
      {
	if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10
	    || i == 12)
	  a1 = a1 + 1;
	else if (i == 2)
	  {
	    if (yy % 4 == 0)
	      a1 = a1 - 1;
	    else
	      a1 = a1 - 2;
	  }
      }
    a1 = a1 + yy / 4;
    a1 = a1 + 365 * (yy - 1);

    a2 = d1.dd;
    a2 = a2 + (d1.mm - 1) * 30;
    for (int i = 1; i < mm; i++)
      {
	if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10
	    || i == 12)
	  a2 = a2 + 1;
	else if (i == 2)
	  {
	    if (d1.yy % 4 == 0)
	      a1 = a1 - 1;
	    else
	      a2 = a2 - 2;
	  }
      }
    a2 = a2 + d1.yy / 4;
    a2 = a2 + 365 * (d1.yy - 1);
    return a1 - a2;
  }
};

int
main ()
{
  int dd, mm, yy, ans, d3, d4;
  cout << "\nEnter day (<=31),month (<=12) & year (enter 2 digit no.): " <<
    endl;
  cin >> dd >> mm >> yy;
  date1 d = date1 (dd, mm, yy);
  d.display ();
  d3 = d.compress ();
  cout << "\nCompressed date is :=" << d3 << " days" << "\n\n";

  cout << "\nEnter day (<=31),month (<=12) & year (enter 2 digit no.): " <<
    endl;
  cin >> dd >> mm >> yy;
  date1 d1 = date1 (dd, mm, yy);
  d1.display ();
  d4 = d1.compress ();
  cout << "\nCompressed date is :=" << d4 << " days" << "\n\n";
  ans = d.datediff (d1);
  if (ans < 0)
    ans = (ans * (-1));
  cout << "\n\n" << "Difference (in days) := " << ans << "  days" << "\n\n";
  return 0;

}
