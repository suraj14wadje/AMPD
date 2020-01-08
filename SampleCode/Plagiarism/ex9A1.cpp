#include<iostream>
using namespace std;
class time1
{
	int ss,mm,hh;
	public:
	time1()
	{
		ss=mm=hh=0;
	}
	void gettime();
	void disptime();
	void addtime(time1,time1 );
	void difftime(time1,time1 );
};

void time1::gettime()
{
	cout<<"\n Enter time:(hh/mm/ss)";
	cin>>hh>>mm>>ss;
	if(ss>59)
	{
		ss=(ss-60);
		mm++;
	}
	if(mm>59)
	{
		mm=(mm-60);
		hh++;
	}
	if(hh>23)
	{
		hh=(hh-24);
	}
}
void time1::disptime()
{
	cout<<"\n time list is \t hours:"<<hh<<"\t min:"<<mm<<"\t sec:"<<ss;
}

void time1::addtime(time1 t1,time1 t2)
{
	ss=t1.ss+t2.ss;
	mm=t1.mm=t2.mm;
	hh=t1.hh+t2.hh;

	if(ss>59)
	{
		ss=(ss-60);
                mm++;
        }
        if(mm>59)
        {
                mm=(mm-60);
                hh++;
        }
        if(hh>23)
        {
                hh=(hh-24);
        }
}

void time1::difftime(time1 t1,time1 t2)
{
	if(t1.ss>t2.ss)
	{
		ss=t1.ss-t2.ss;
	}
	else
	{
		ss=t2.ss-t1.ss;
	}
	if(t1.mm>t2.mm)
	{
		mm=t1.mm-t2.mm;
	}
	else
	{
		mm=t2.mm-t1.mm;
	}
	if(t1.hh>t2.hh)
	{
		hh=t1.hh-t2.hh;
	}
	else
	{
		hh=t2.hh-t1.hh;
	}
}

int  main()
{
	 time1 t1,t2,t3;
	cout<<"\n Enter time for t1:";
	t1.gettime();
	t1.disptime();
	cout<<"\n enter time for t2:";
	t2.gettime();
	t2.disptime();
	cout<<"\n addition of time is:";
	t3.addtime(t1,t2);
	t3.disptime();
	cout<<"\n Difference of time is:";
	t3.difftime(t1,t2);
	t3.disptime();
}
