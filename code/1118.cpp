// 2024.2.27
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 12, M = 1;
int n, q[N], res = INF;
//互质组
vector<int> g[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

// u：第几个数, k: 有几个组
void dfs(int u, int k)
{
    if (k >= res)
        return;
    if (u == n)
    {
        res = k;
        return;
    }
    ffor(i, 0, k)
    {
        int flag = 1;
        for (auto t : g[i])
        {
            if (gcd(q[u], t) != 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            g[i].push_back(q[u]);
            dfs(u + 1, k);
            g[i].pop_back();
        }
    }
    g[k].push_back(q[u]);
    dfs(u + 1, k + 1);
    g[k].pop_back();
}
int main()
{
    cin >> n;
    ffor(i, 0, n) cin >> q[i];
    dfs(0, 0);
    cout << res;
}