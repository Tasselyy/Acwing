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

const int N = 20, M = 1;
long long w[N];
long long n, W, res = INF;
long long g[N];

void dfs(long long u, long long k)
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
        if (g[i] + w[u] <= W)
        {
            g[i] += w[u];
            dfs(u + 1, k);
            g[i] -= w[u];
        }
    }
    g[k] += w[u];
    dfs(u + 1, k + 1);
    g[k] = 0;
}

int main()
{
    cin >> n >> W;
    ffor(i, 0, n)
    {
        cin >> w[i];
    }
    sort(w, w + n, greater<int>());
    dfs(0, 0);
    cout << res;
}