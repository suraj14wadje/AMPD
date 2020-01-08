#include<iostream>
using namespace std;
class fra
{
	int n,d;
	int gcd(int x,int y)
	{
		if(y==0)
		return x;
		else
		return(x,gcd(y,x%y));
	}
	public:
	fra()
	{ n=0; d=1;}
	fra(int x,int y)
	{
		n=x/gcd(x,y);
		d=y/gcd(x,y);
	}

	void disp()
	{
		cout<<"\n"<<n<<"/"<<d;
	}
	void add(fra f1,fra f2)
	{
		if(f1.d==f2.d)
		{
			n=f1.n+f2.n;
			d=f1.d;
		}
		else
		{
			n=(f1.n*f2.d)+(f1.d*f2.n);
			d=f1.d*f2.d;
		}
	}
	 void sub(fra f1,fra f2)
          {
                if(f1.d==f2.d)
                {
                        n=f1.n-f2.n;
                        d=f1.d;
                }
                else
                {
                        n=(f1.n*f2.d)-(f1.d*f2.n);
                        d=f1.d*f2.d;
                }
        }


	void mul(fra f1,fra f2)
	{
		n=f1.n*f2.n;
		d=f1.d*f2.d;
	}
	void div(fra f1,fra f2)
	{
		n=f1.n*f2.d;
		d=f1.d*f2.n;
	}
};

int main()
{
	int n1,n2,d1,d2;
	cout<<"\nEnter Value of 1st  Numerator:";
	cin>>n1;
	cout<<"\nEnter Value of 1st Denominator:";
        cin>>d1;
	 cout<<"\nEnter Value of 2nd Numerator:";
        cin>>n2;
        cout<<"\nEnter Value of 2nd Denominator:";
        cin>>d2;
	fra f1(n1,d1),f2(n2,d2),f3;
	cout<<"\n f1=",f1.disp();
	cout<<"\n f2=",f2.disp();
	
        f3.add(f1,f2);
        cout<<"\n f1+f2=",f3.disp();

	f3.sub(f1,f2);
        cout<<"\n f1-f2=",f3.disp();
	 
        f3.mul(f1,f2);
        cout<<"\n f1*f2=",f3.disp();
	 
        f3.div(f1,f2);
        cout<<"\n f1/f2=",f3.disp();
}
