// 2024.10.10
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int pre[N], bi[N], cnt;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int a, k, p;
        cin >> a >> k >> p;
        ll ans = 1;
        while (k)
        {
            if (k & 1)
            {
                ans = (ll)ans * a % p;
            }
            k >>= 1;
            a = (ll)a * a % p;
        }
        cout << ans << endl;
    }
}