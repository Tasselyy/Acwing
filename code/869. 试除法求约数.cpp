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

void get_divisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    for (auto t : res)
    {
        cout << t << " ";
    }
    cout << endl;
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        cin >> n;
        get_divisors(n);
    }
}