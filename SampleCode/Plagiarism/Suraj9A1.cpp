#include <iostream>


using namespace std;

class Time
{
	int hh,mm,ss;
	
	public:
	void settime(int,int,int);
	void showtime();
	Time add(Time);
	Time sub(Time);
	
};


void Time::settime(int a, int b,int c)
{
	hh=a;
	mm=b;
	ss=c;
}

void Time::showtime()
{
	cout<<hh<<"H "<<mm<<"M "<<ss<<"S "<<endl;
	
}


Time Time::add(Time t1)
{
	Time ans;
	int temp;
	ans.ss = ss+t1.ss;
	temp = ans.ss/60;
	ans.ss%=60;
	
	ans.mm = mm+(t1.mm+temp);
	temp = ans.mm/60;
	ans.mm%=60;
	
	ans.hh = hh+ (t1.hh+temp);
	ans.hh %=24;
	
	
	return ans;
	
	
}


Time Time::sub(Time t1)
{
	int borrow,temp;
	ss = ss-t1.ss;
	
	if(ss<0)
	{
		ss*=-1;
		ss = 60 - (ss%60);	
	}
	borrow =ss/60;
	ss = ss%60;
	
	mm = (mm-t1.mm-borrow);
	
	if(mm<0)
	{
		mm*=-1;
		mm = 60 - (mm%60);
	}
	
	borrow = mm/60;
	mm = mm%60;
	
	hh = hh-t1.hh-borrow;
	
	hh = hh<0? (hh*=-1):hh;
	hh%=24;
	
	
	return *this;
	
}
		
	
	
	
	
	
	
	
	
	
	



int main()

{
	int a,b,c;
	
	Time t1,t2,add,subt;
	
	cout<<"Enter First Time in HH MM SS Format: ";
	cin>>a>>b>>c;
	t1.settime(a,b,c);
	
	cout<<"Enter Second Time in HH MM SS Format: ";
	cin>>a>>b>>c;
	t2.settime(a,b,c);
	
	add = t1.add(t2);
	cout<<"After Adding Two Times : ";
	add.showtime();
	
	subt = t1.sub(t2);
	cout<<"After Subtracting : ";
	subt.showtime();
	
	return 0;
	
}
