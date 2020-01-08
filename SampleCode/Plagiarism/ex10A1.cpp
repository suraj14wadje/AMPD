#include<iostream>


using namespace std;
class Fraction
{
  int num, denom;
  int gcd (int, int);
  void reduce ();

public:

  Fraction ():num (0), denom (1) {}
  Fraction (int n):num (n), denom (1) {}
  Fraction (int n, int d):num (n), denom (d){}

  void getFraction ();
  void dispFrac ();

  Fraction addFrac (Fraction f);
  Fraction subFrac (Fraction f);
  Fraction mulFrac (Fraction f);
  Fraction divFrac (Fraction f);
};

void Fraction::reduce ()
{
  int a, b, tmp, gcd;
  a = num;
  b = denom;
  
  if (a == 0)
  {
      num = 0;
      denom = 1;
      return;
  }
  if (a > b)
  {
     tmp = a;
     a = b;
     b = tmp;
  }
  for (int i = 1; i< b; ++i)
  {
     if (a % i == 0 && b % i == 0)
         gcd = i;
  }
  num = num / gcd;
  denom = denom / gcd;
}

void Fraction :: dispFrac ()
{
  reduce();
  cout << num << "/ " << denom;
}

void Fraction :: getFraction ()
{
  cout << "\n Enter numerator value:";
  cin >> num;
  do{
     cout << "\n Enter denominator value:";
     cin >> denom;
     if (denom == 0)
        cout << "\n Denominator cannot be 0 ! Reenter...";
  } while(denom ==0);
}
  

Fraction Fraction:: addFrac (Fraction f)
{
  Fraction result;
   result.num = (num * f.denom) + (denom * f.num);
   result.denom = (denom * f.denom);
   result.reduce();
   return result;
}

Fraction Fraction:: subFrac (Fraction f)
{
   Fraction result;
   result.num = ( num * f.denom ) - (denom * f.num);
   result.denom = (denom * f.denom);
   result.reduce();
   return result;
}

Fraction Fraction:: mulFrac (Fraction f)
{
   Fraction result;
   result.num = ( num * f.num );
   result.denom = (denom * f.denom);
   result.reduce();
   return result;
}


Fraction Fraction :: divFrac (Fraction f)
{
   Fraction result;
   result.num = ( num * f.denom);
   result.denom = (denom * f.num);
   result.reduce();
   return result;
}

int main()
{
  Fraction f1, f2, f3(0,1);
 
 // system("clear"); 
  cout << "\n Enter the First fraction : ";
  f1.getFraction();
  cout << "\n Enter the Second fraction : ";
  f2.getFraction();

  cout << "\n Reduced First Fraction is : ";  
  f1.dispFrac();
  cout << "\nReduced Second Fraction is : ";  
  f2.dispFrac();

  cout << "\n The addition of the two fractions is : ";
  f3 = f1.addFrac(f2);
  f3.dispFrac();
  cout << "\n The Subtraction of the two fractions is : ";
  f3 = f1.subFrac(f2);
  f3.dispFrac();
  cout << "\n The multiplication of the two fractions is : ";
  f3 = f1.mulFrac(f2);
  f3.dispFrac();
  cout << "\n The division of the two fractions is : ";
  f3 = f1.divFrac(f2);
  f3.dispFrac();
  return 1;
}

