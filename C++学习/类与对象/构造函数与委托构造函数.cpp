#include <iostream>

using namespace std;

class Clock
{
    public:
        // ���ֹ��캯����������ί�и���һ�����캯��
        Clock(int initH, int initM, int initS): hour(initH), minute(initM), second(initS)
        {
            cout << "��������ɹ�" << endl;
        }
        Clock(): Clock(0, 0, 0)
        {
            cout << "����ί�й��캯��" << endl;
        }
        Clock(int initH): Clock(initH, 0, 0) 
        {
            cout << "����ί�й��캯��" << endl;
        }

        void showTime()
        {
            cout << hour << ':' << minute << ':' << second << endl;
        }
        void setTime(int newH, int newM, int newS);
    private:
        int hour, minute, second;
};

inline void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

// // ���캯������
// Clock::Clock(int initH, int initM, int initS): hour(initH), minute(initM), second(initS) 
// {
//     cout << "��������ɹ�" << endl;
// }

// // ί�й��캯������
// Clock::Clock(): Clock(0, 0, 0) 
// {
//     cout << "����ί�й��캯��" << endl;
// }

// Clock::Clock(int initH): Clock(initH, 0, 0) 
// {
//     cout << "����ί�й��캯��" << endl;
// }

int main ()
{
    Clock c(9);

    c.showTime();

    c.setTime(10, 20, 21);

    c.showTime();

    return 0;
}