#include<iostream>

using namespace std;

class Fraction 
{
	int num,den;
	
	int gcd(int a,int b)
	{
		int min;
		min = a>b?b:a;
		if(min == 0)
			return 1;
		for(int i = min;i>0;i--)
			if(a%i== 0 && b%i== 0)
				return i;
	
	}
	
	
	public:
	
	Fraction(int a=0,int b=1)
	{
		int temp = gcd(a,b);
		if(temp != -1)
		{
			num = a/temp;
			den = b/temp;
		}
		
	}
	
	Fraction add(Fraction num1,Fraction num2)
	{
		int a,b;
		a= num1.num*num2.den + num2.num*num1.den;
		b = num1.den*num2.den;
		
		Fraction temp(a,b);
		return temp;
	}
	
	
	Fraction sub(Fraction num1,Fraction num2)
	{
		int a,b;
		a = num1.num*num2.den - num1.den*num2.num;
		b = num1.den*num2.den;
		
		Fraction temp(a,b);
		return temp;
	}
	
	Fraction mul(Fraction num1,Fraction num2)
	{
		int a,b;
		a = num1.num*num2.num;
		b = num1.den*num2.den;
		Fraction temp(a,b);
		return temp;
	}
	
	void print()
	{
		cout<<"  ";
		cout<<num<<endl;
		cout<<"------"<<endl;
		cout<<"  ";
		cout<<den<<endl;
	}
	
	
};


int main()
{
	int a,b;
	
	cout<<"Enter Numerator And Denominator For F1: ";
	cin>>a>>b;
	Fraction F1(a,b);
	F1.print();
	cout<<"Enter Numerator And Denominator For F2: ";
	cin>>a>>b;
	Fraction F2(a,b);
	F2.print();
	Fraction sum,substraction,Multiplication;
	
	sum = F1.add(F1,F2);
	cout<<"Sum Is ::  "<<endl;
	sum.print();
	cout<<endl;
	
	substraction = F2.sub(F1,F2);
	cout<<"Substraction Is ::  "<<endl;
	substraction.print();
	cout<<endl;
	
	Multiplication = F1.mul(F1,F2);
	cout<<"Multiplication Is ::"<<endl;
	Multiplication.print();
	cout<<endl;
	
	return 0;

}
	
	
	
	
		
		
		
	 
		
