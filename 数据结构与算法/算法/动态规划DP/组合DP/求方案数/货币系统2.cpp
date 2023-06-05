//https://www.acwing.com/problem/content/534/

/*
本题有三个性质：对于极大无关组 K = (b1, b2, …, bn)
1. a1, a2, …, an 一定都可以被 (b1, b2, …, bn) 表示出来
2. 极大无关组中元素一定是从 a1, a2, …, an 中选择出来的
3. b1, b2, …, bn 一定不能相互表示出来 (线性无关)

对于第二点，采用反证法：
1.若 bi 不是从 a1, a2, …, an 中选择出来的，那么他一定可以被表示成 a1 * k1 + a2 * k2 + … + an * kn 
2.本题中所有元素和元素系数均为正数，故 bi 一定大于 a1, a2, …, an 
3.又因为性质1，所以 bi = f(b1, b2, …, bn)，从而 bi 与 b1, b2, …, bn 相关，bi 就可有可无了，说明此时并不是最优解
4.故命题矛盾，性质2成立
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, M = 25005;

int T, n, a[N];
int f[M];

int main ()
{
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        
        memset(f, 0, sizeof(f));
        f[0] = 1;
        
        /*
        下面就是运用完全背包来求解极大线性无关组：
        首先，一个数只可以被小于其本身的数表出。
        其次，本题中f数组元素值无意义时为0，有意义时非零，而当且仅当某个体积(也就是j)能被凑出时有意义
        也就是说，我们在做完全背包时，需要求出恰好能被前 i 个物品体积表示出的所有方案
        所以，我们可以先将待选的 a1, a2, …, an 从小到大排序，
        每遍历一个新的 a[i] 就先看看 f[a[i]] 是否有意义。
        (已经被前面的 a[1], a[2], …, a[i - 1] 线性组合表示，或者说，已经在之前的dp中被遍历过体积)
        如果 f[a[i]] 仍为 0，就说明在 a1, a2, …, an 中除了 ai 本身没有其他数能够表示 ai 了
        自然就说明 a[i] 属于极大线性无关组

        有点像线性筛。
        */
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!f[a[i]]) res++;
            for (int j = a[i]; j <= a[n]; j++)
                f[j] += f[j - a[i]];
        }
    
        cout << res << endl;
    }
    
    return 0;
}