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

int main()
{
    int n;
    int a, b;

    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        while (b)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        cout << a << endl;
    }
}