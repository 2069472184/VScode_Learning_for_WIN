//https://www.acwing.com/problem/content/83/

//�������ᱬlong long, ����Ҫ��ʱ�ж�return��

//���num��int�ͱ�����
//INT_MAX = 2147483647 , INT_MIN = -2147483648
//������������һ�����ۣ�������ټ��Ϸ��Żᵼ��
//ԭ��Ϊ������num��forѭ�����ۼӵ���2147483648��Խ��ת��Ϊ����

class Solution {
public:
    int strToInt(string str) {
        long long num = 0;
        
        int i = 0;
        while ( str[i] == ' ' ) i++;
        
        if ( str[i] == '-' )
            for ( int j = i + 1; str[j] <= '9' && str[j] >= '0' && j < str.size(); j++ )
            {
                num = num*10 - (str[j] - '0');
                if ( num < INT_MIN ) return INT_MIN;
            }

        if ( str[i] == '+' ) i++;

        for ( int j = i; str[j] <= '9' && str[j] >= '0' && j < str.size(); j++ )
        {
            num = num*10 + (str[j] - '0');
            if ( num > INT_MAX ) return INT_MAX;
        }
            
        return num;
    }
};

//����д��
class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k ++ ;
        long long res = 0;

        int minus = 1;
        if (k < str.size())
        {
            if (str[k] == '-') minus = -1, k ++ ;
            else if (str[k] == '+') k ++ ;
        }
        while (k < str.size() && str[k] >= '0' && str[k] <= '9')
        {
            res = res * 10 + str[k] - '0';
            if (res > 1e11) break;  //��ֹlong longԽ��
            k ++ ;
        }

        res *= minus;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};