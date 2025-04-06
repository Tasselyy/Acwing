// 2024.9.13
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 510;

//dst存储节点到生成树的距离，st存储是否在生成树内
int dst[N], g[N][N], st[N], n, m;

void prim()
{
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    int res = 0;
    ffor(i, 0, n)
    {
        int t = -1;
        efor(j, 1, n)
        {
            if (!st[j] && (t == -1 || dst[j] < dst[t]))
            {
                t = j;
            }
        }
        if (dst[t] == INF)
        {
            cout << "impossible";
            return;
        }
        st[t] = 1;
        res += dst[t];
        efor(j, 1, n)
        {
            if (dst[j] > g[t][j] && !st[j])
            {
                dst[j] = g[t][j];
            }
        }
    }
    cout << res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    prim();
}