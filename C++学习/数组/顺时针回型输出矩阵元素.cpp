#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[50][50];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};   //���������ĸ������ƫ����
int d = 1;   //d��ʾ����1���ң�2���£�3����0���ϣ���Ϊƫ�����±꣬����һһ��Ӧ

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> arr[i][j];

    bool st[50][50] = {false};  //�������飬��ֹ�ظ������ͬλ�õ�ֵ

    int x = 0, y = 0;   //��ʼ������  

    for (int i = 0; i < n * m; i ++ )
    {
        int a = x + dx[d], b = y + dy[d];
        
        if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
        {
            d = (d + 1) % 4;  //ת������
            a = x + dx[d], b = y + dy[d];
        }

        cout << arr[x][y] << ' ';

        st[x][y] = true;  //����ǰλ�ñ��Ϊ���ù���

        x = a, y = b;  //��������
    }

    cout << endl;

    return 0;
}