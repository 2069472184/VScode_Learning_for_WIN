//https://www.acwing.com/problem/content/779/

#include <iostream>
#include <string>
using namespace std;

string a;
int num;

int main ()
{
    while ( cin >> a, a != "." )
        for ( int i = 1; i <= a.size(); i++ )
        {
            if ( a.size() % i ) continue;  //ֻ�����ܹ�ƽ�ֵ����
            
            num = a.size() / i;  //num��ʾ����

            string b = a.substr(0, i);  //b��ʾһС���ַ���

            for ( int j = 1; j < num; j++ ) b = b + a.substr(0, i); //���շ����ۼ�

            if ( b == a )  //����ж��Ƿ����
            {
                cout << num << endl;
                break;
            }
        }

    return 0;
}