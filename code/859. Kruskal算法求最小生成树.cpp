// 2024.9.13
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m, ans, p[N], cnt;

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W)
    {
        return this->w < W.w;
    }
} edge[N * 2];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void kruskal()
{
    ffor(i, 0, m)
    {
        int pa = find(edge[i].a);
        int pb = find(edge[i].b);
        if (pa != pb)
        {
            ans += edge[i].w;
            p[pa] = pb;
            cnt++;
        }
    }
}

int main()
{
    cin >> n >> m;
    ffor(i, 0, n)
    {
        p[i] = i;
    }
    ffor(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    sort(edge, edge + m);
    kruskal();

    if (cnt < n - 1)
        cout << "impossible";
    else
        cout << ans;
}