//����<=10000
#include <iostream>
#include <cstdio>

using namespace std;

int a[10000] = {1}, size = 1, n;

int main ()
{
    cin >> n;

    while ( n-- )  //ȡn��^2 --> 1��n��2
    {
        int t = 0;

        for ( int i = 0; i < size; i++ )
        {
            t += a[i] * 2;   //t�ȴ洢ÿһλ����2��Ľ��
            a[i] = t % 10;   //a[i]�ϻ��Ǵ�ų���2�� <=9 �Ĳ���
            t /= 10;    //�õ�a[i]��Ԫ��ֵ����2�� >9 �Ĳ���
        }

        if (t) a[size++] = t;    //�������� >9������Ҫ��λ���ں���һλ�ϴ�Ž�λ��ֵ
    }

    for (int i = size - 1; i >= 0; i -- ) cout << a[i];
    puts( "" );

    return 0;
}