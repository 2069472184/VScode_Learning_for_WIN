//������˳ʱ����תk��---����ѭ���İ취
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[100], n, k;

int main ()
{
    cin >> n >> k;

    for ( int i = 0; i < n; i++ ) cin >> a[i];

    reverse( a, a+n ); 
    reverse( a, a+k ); 
    reverse( a+k, a+n ); 

    for ( int i = 0; i < n; i++ ) cout << a[i] << " ";

    return 0;
}