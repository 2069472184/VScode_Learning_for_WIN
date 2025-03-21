//https://www.acwing.com/problem/content/773/

//����д��
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char k[205];
char ans;
int t;

int main ()
{
    cin >> t;
    
    while ( t-- )
    {
        cin >> k;
        
        int count = 1, Max = 0, i;
        
        for ( i  = 1; k[i] != '\0'; i++ ) 
        {
            if ( k[i] == k[i-1] ) 
            {
                count++;
                if ( k[i+1] == '\0' && count > Max )
                {
                    Max = count;  
                    ans = k[i-1];
                }
                else continue;
            }
            else if ( k[i] != k[i-1] ) 
            {
                if ( count > Max )
                {
                    Max = count;  
                    ans = k[i-1];
                }
                count = 1;
            }
        }
        
        cout << ans << " " << Max << endl;
    }
    
    return 0;
}

//����д��
/* #include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        int maxn = -1;//maxn��¼��󳤶�
        string str, maxs;//maxs��¼��󳤶�ʱ���ַ�
        cin >> str;
        for(int i = 0; i < str.size(); i ++)
        {
            int j = i;
            int cnt = 0;
            while(str[j] == str[i] && j < str.size())//��ָ��jû��Խ������ָ��i��������ͬʱ�ƶ�
                j ++, cnt ++;
            if(cnt > maxn)//�������ֵ
                maxn = cnt, maxs = str[i];
            i = j - 1;//�ƶ�ָ��i
        }
        cout << maxs << " " << maxn << endl;
    }
} */