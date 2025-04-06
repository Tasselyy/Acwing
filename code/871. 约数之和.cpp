// 2024.9.29
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

const int mod = 1e9 + 7;
// hashmap<质因子，指数>
unordered_map<int, int> primes;

//一个数的约数是由这个数的几个质因子相乘得到的
//如果 N=p1c1∗p2c2∗…∗pkck
//约数个数：(c1+1)∗(c2+1)∗…∗(ck+1)
//约数之和： (p10+p11+…+p1c1)∗…∗(pk0+pk1+…+pkck)
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n / i; i++)
        {
            while (n % i == 0)
            {
                primes[i]++;
                n /= i;
            }
        }
        if (n > 1)
            primes[n]++;
    }
    ll ans = 1;

    for (auto prime : primes)
    {
        ll p = prime.first, c = prime.second;
        //秦九韶算法 in note
        ll t = 1;
        while (c--)
        {
            t = (t * p + 1) % mod;
        }
        ans = ans * t % mod;
    }
    cout << ans;
}