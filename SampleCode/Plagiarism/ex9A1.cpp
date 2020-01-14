

using namespace std;

class Time
{
int ss,mm,hh;
public:
Time()
{ss=mm=hh=0;
}
void getTime();
void dispTime();
void add2Time(Time,Time);
void diff2Time(Time,Time);
};

void Time :: diff2Time(Time t1,Time t2)
{
if(t1.ss>t2.ss)
{ss=t1.ss-t2.ss;}
else
{ss=t2.ss-t1.ss;}

if(t1.mm>t2.mm)
{mm=t1.mm-t2.mm;}
else
{mm=t2.mm-t1.mm;}

if(t1.hh>t2.hh)
{hh=t1.hh-t2.hh;}
else
{hh=(t2.hh-t1.hh);}


}

void Time :: getTime()
{
cout<<[STRING_CONSTANT];
cin>>ss>>mm>>hh;
if(ss>59)
{ss=(ss-60);
mm++;
}
if(mm>59)
{mm=mm-60;
hh++;
}
if(hh>23)
{
hh=hh-24;
}

}
void Time :: dispTime()
{
cout<<[STRING_CONSTANT]<<hh;
}

void Time :: add2Time(Time t1,Time t2)
{
ss=t1.ss+t2.ss;
mm=t1.mm+t2.mm;
hh=t1.hh+t2.hh;

if(ss>59)
{ss=(ss-60);
mm++;
}
if(mm>59)
{mm=mm-60;
hh++;
}
if(hh>23)
{
hh=hh-24;
}

}

int main()
{
Time t1,t2,t3;
cout<<[STRING_CONSTANT];
t1.getTime();
t1.dispTime();
cout<<[STRING_CONSTANT];
t2.getTime();
t2.dispTime();

cout<<[STRING_CONSTANT];
t3.add2Time(t1,t2);
t3.dispTime();

cout<<[STRING_CONSTANT];
t3.diff2Time(t1,t2);
t3.dispTime();

}

