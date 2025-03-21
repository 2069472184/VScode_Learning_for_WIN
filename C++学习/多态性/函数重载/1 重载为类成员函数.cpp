#include <iostream>

using namespace std;

class Clock
{
    public:	
	    Clock (int NewH = 0, int NewM = 0, int NewS = 0);
	    void ShowTime();
	    Clock operator++ ();  //ǰ�õ�Ŀ���������
	    Clock operator++ (int);  //���õ�Ŀ���������
    private:	
	    int Hour, Minute, Second;
};

Clock::Clock (int NewH, int NewM, int NewS)
{
    if (0 <= NewH && NewH < 24 && 0 <= NewM && NewM < 60 && 0 <= NewS && NewS < 60)
	{    
        Hour = NewH;
	    Minute = NewM;
	    Second = NewS;
	}
    else cout << "Time error!" << endl;
}

void Clock::ShowTime () 
{
	cout << Hour << ":" << Minute << ":" << Second << endl;
}

//ǰ�õ�Ŀ��������غ���
Clock Clock::operator++ ()
{	
    Second++;
	if (Second >= 60)
	{   
        Second = Second - 60;
	    Minute++;
	    if(Minute >= 60)
	    {
	        Minute = Minute-60;
	        Hour++;
	        Hour = Hour%24;
	    }
	}
    return *this;
}

// ���õ�Ŀ��������غ���
Clock Clock::operator++ (int)	
{  
    Clock old = *this;
    ++(*this);   //����ǰ��++��������غ���
    return old;
}

int main ()
{
	Clock myClock(23,59,59);
	cout << "First time output:";
	myClock.ShowTime();

    cout << "Show myClock++:";
    (myClock++).ShowTime();  //(myClock.operator++(0)).ShowTime()
    cout << "Show ++myClock:";
	(++myClock).ShowTime();  //(myClock.operator++()).ShowTime()

    return 0;
}