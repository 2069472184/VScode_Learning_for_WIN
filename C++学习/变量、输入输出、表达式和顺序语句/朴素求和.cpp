//https://www.acwing.com/problem/content/80/

//Ҫ��1+2+3+����+n
#include <iostream>
using namespace std;

int n;

int getSum ( int num )
{
    int res = num;
    num > 0 && ( res += getSum(num-1) );  //���numΪ0��ֱ�ӷ���
    return res;
}

int main ()
{
    cin >> n;

    cout << getSum(n);

    return 0;
}