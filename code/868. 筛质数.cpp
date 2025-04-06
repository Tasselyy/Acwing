// 2024.9.28
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int primes[N], cnt;
bool st[N];

//用最小质因子去筛合数
void get_prime(int x)
{
    efor(i, 2, x)
    {
        //和数已经被比他小的质数筛掉了
        if (!st[i])
            primes[cnt++] = i;
        //因为prime中素数是递增的，所以如果i%prime[j]!=0代表i的最小质因数还没有找到，即i的最小质因数大于prime[j]。也就是说prime[j]就是iprime[j]的最小质因数，于是iprime[j]被它的最小质因数筛掉了。
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = true;
            //找到最小质因子，结束循环
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    int x;
    cin >> x;
    get_prime(x);
    cout << cnt;
}