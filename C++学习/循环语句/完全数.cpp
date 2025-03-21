#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, x;

int main () 
{
    cin >> n;
    
    while ( n-- )
    {
        cin >> x;
        
        int sum = 0;
        
        for ( int i = 1; i*i <= x; i++ )
        {
            if ( x % i == 0 ) //Լ��������Ӧ
            {
                if ( i < x ) sum += i; //���е� i = 1 �����
                if ( i*i != x && x / i < x ) sum += x / i;
            }
        }
            
        if ( sum == x ) printf( "%d is perfect\n", x );
        else printf( "%d is not perfect\n", x );
    }
    
    return 0;
}