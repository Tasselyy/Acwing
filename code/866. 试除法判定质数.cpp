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

bool is_prime(int x)
{
    if (x < 2)
        return false;
    efor(i, 2, x / i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (is_prime(x))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
}