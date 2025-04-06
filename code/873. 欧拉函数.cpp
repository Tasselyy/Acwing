// 2024.10.2
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

// in note
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        int ans = a;

        for (int i = 2; i <= a / i; i++)
        {
            if (a % i == 0)
            {
                ans = ans / i * (i - 1);
                while (a % i == 0)
                {
                    a /= i;
                }
            }
        }
        if (a > 1)
        {
            ans = ans / a * (a - 1);
        }
        cout << ans << endl;
    }
}