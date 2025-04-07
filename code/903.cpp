// 2024.4.6
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

const int N = 110, M = 1e4 + 10;
int n, m;
int e[M], ne[M], h[N], w[M], idx;
int st[N], dst[N];
int value[N], Rank[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dijstra(int l, int r)
{
    memset(dst, 0x3f, sizeof dst);
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dst[1] = 0;
    while ((heap.size()))
    {
        int ver = heap.top().second;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > dst[ver] + w[i] && Rank[j] >= l && Rank[j] <= r)
            {
                dst[j] = dst[ver] + w[i];
                heap.push({dst[j], j});
            }
        }
    }
    int res = INF;
    efor(i, 1, n)
    {
        res = min(res, dst[i] + value[i]);
    }
    return res;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> m >> n;
    efor(i, 1, n)
    {
        int x;
        cin >> value[i] >> Rank[i] >> x;
        efor(j, 1, x)
        {
            int b, c;
            cin >> b >> c;
            add(i, b, c);
        }
    }
    int res = INF;
    for (int i = Rank[1]; i <= Rank[1] + m; i++)
    {
        res = min(res, dijstra(i - m, i));
    }
    cout << res;
}