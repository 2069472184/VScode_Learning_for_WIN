/* //https://www.acwing.com/problem/content/772/

//�������
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k, a, b;

int main ()
{
    getline(cin, k);
    cin >> a >> b;
    
    int La = a.size(), Lb = b.size(), Lk = k.size();
    
    for ( int i = 0; i + La <= Lk; i++ )
        if ( k.substr(i, La) == a && ( k[i-1] == ' ' || i == 0 ) && ( k[i+La] == ' ' || i+La == k.size() ) ) 
        {
            if ( i + La == k.size() )    //ע��substr()����Խ�磬���ں����ĵ�һ������������С���ַ�������
            {
                k = k.substr(0, i) + b;
                break;
            }
            else 
            {
                k = k.substr(0, i) + b + k.substr(i+La);
                i += La - 1;
            }
        }

    cout << k;
    
    return 0;
}

//���ַ���ת��Ϊ�ַ�����
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

string k, a, b;

int main ()
{
    getline(k);
    cin >> a >> b;

    stringstream ssin(k);
    string str;

    while ( ssin >> str )  //����ʼǣ�ÿ������һ�������ո���ַ���
    {
        if ( str == a ) cout << b << ' ';
        else cout << str << ' ';
    }

    return 0;
} */

//����string����
#include <iostream> 

using namespace std;

string s1, a, b;

int main()
{
    
    getline(cin, s1);
    cin >> a >> b;

    s1 = ' ' + s1 + ' ';    // �ѵ��ʺ����ǰ�󶼼��Ͽո� ���ڲ���
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';

    while(s1.find(a) != -1)  // һֱ���� �ҵ����滻
        s1.replace(s1.find(a), a.size(), b);

    s1.erase(s1.begin());    // s1.erase(0, 1);
    s1.erase(s1.end() - 1);  // �����˰Ѽӽ�ȥ����β�ո�ɾ��

    cout << s1;

    return 0;
}