#include <iostream>
#include <string>
using namespace std;

struct Person
{
    int age;
    double money, height;
    string k;

    //��Ĺ��캯�����潨�����public��
    //ÿ�ֹ��캯������Ӧ��һ��������ṹ����������帳ֵ��ʱ����������Щ����е�����һ��
    Person () {}   //��Ҫ�������

    Person ( string _k ) : k(_k) {}  //ֻҪ����һ����������

    //���Ҫ�������в���
/*     Person ( int _age, int _height, double _money ) 
    {
        age = _age;
        height = _height;
        money = _money;
    }  */
    //��д�����Ч��
    Person ( int _age, double _height, double _money ) : age(_age), height(_height), money(_money) {}
};

int main ()
{
    Person p = { "dhduqof" };  //�˴����Ը�3��ֵ/1��ֵ/����ֵ��û����ֵ�Զ�Ϊ0

    cout << p.age << endl << p.height << endl << p.money << endl << p.k << endl;

    return 0;
}