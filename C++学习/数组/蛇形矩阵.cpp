//https://www.acwing.com/problem/content/758/

//��������
/* #include <iostream>
#include <cstdio>

using namespace std;

const int N = 105;

int n, m, k[N][N];

int main ()
{
    cin >> n >> m;
    
    bool isprime = true;
    int num = 1, count = 0;
    while ( 1 )
    {
        for ( int j = num; j <= m-num+1; j++ ) 
        {
            k[num][j] = ++count;
            if ( count == n*m ) 
            {
                isprime = false;
                break;
            }
        }
        if ( !isprime ) break;
        for ( int j = num+1; j <= n-num+1; j++ ) 
        {
            k[j][m-num+1] = ++count;
            if ( count == n*m ) 
            {
                isprime = false;
                break;
            }
        }
        if ( !isprime ) break;
        for ( int j = m-num; j >= num; j-- ) 
        {
            k[n-num+1][j] = ++count;
            if ( count == n*m ) 
            {
                isprime = false;
                break;
            }
        }
        if ( !isprime ) break;
        for ( int j = n-num; j > num; j-- )
        {
            k[j][num] = ++count;
            if ( count == n*m ) 
            {
                isprime = false;
                break;
            }
        }
        if ( !isprime ) break;
        num++;
    }
    
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
            cout << k[i][j] << " ";
        puts( "" );
    }
    
    return 0;
} */

//ƫ����+������
#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int dx[] = { -1, 0 , 1, 0 }, dy[] = { 0, 1, 0, -1 }; //���������ĸ������ƫ����
int d = 1;  //d��ʾ����1���ң�2���£�3����0���ϣ���Ϊƫ�����±꣬����һһ��Ӧ
int j[105][105];

int main ()
{
    cin >> n >> m;

    int x = 1, y = 1;

    for ( int i = 1; i <= n * m; i++ )
    {
        j[x][y] = i;

        int a = x + dx[d], b = y + dy[d];  

        if ( a < 1 || a > n || b < 1 || b > m || j[a][b] )  //�ж��Ƿ�ײǽ
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }

        x = a, y = b;  //��������
    }

    for ( int i = 1; i <= n; i++ )
    {
        for ( int k = 1; k <= m; k++ ) 
            cout << j[i][k] << " ";
        puts( "" );
    }

    return 0;
}