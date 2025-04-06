// 2024.9.28
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;

void divide(int x)
{
    efor(i, 2, x / i)
    {
        if (x % i == 0)
        {
            cout << i << " ";
            int s = 0;
            while (x % i == 0)
            {
                x /= i;
                s++;
            }
            cout << s << endl;
        }
    }
    if (x > 1)
    {
        cout << x << " " << 1 << endl;
    }
    cout << endl;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        divide(x);
    }
}