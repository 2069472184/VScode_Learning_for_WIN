#include <iostream>
using namespace std;

const int N = 10010;

class Person
{
    private:  //��˽�еı�����ֻ�������е���
        int age, height;
        double money;
        string books[N];
    
    public:   //���õı����������ط�Ҳ���Ե���
        string name;
        
        void say ()  //���������а�������
        {
            cout << "I'm " << name << endl;
        }
        
        void set_age( int a )
        {
            age = a;
        }
        
        int get_age ()
        {
            return age;
        }
        
        void add_money ( double x )
        {
            money += x;
        }
} person_a, person_b, persons[100];

int main ()
{
    Person c;
    
    c.name = "yhq";
    //c.age = 18;  ���󣬲��ܷ���˽�б���
    c.set_age(18);
    c.add_money(100);
    
    c.say();
    cout << c.get_age() << endl;

    return 0;
}

