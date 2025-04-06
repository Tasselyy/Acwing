// 2024.10.2
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
bool st[N];
ll ans, phi[N];
int primes[N], cnt;

void get_eulers(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            //质数和除了自己之外的所有数互质
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_eulers(n);
    phi[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans += phi[i];
    }
    cout << ans;
}