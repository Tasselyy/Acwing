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

const int N = 5e4 + 10, M = 2e5 + 10;
int n, m;
int e[M], ne[M], w[M], h[N], idx;
int st[N], dst[6][N], source[6];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int dst[])
{
    memset(st, 0, sizeof st);
    //int size = 4
    memset(dst, 0x3f, 4 * N);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    dst[start] = 0;
    while (heap.size())
    {
        int ver = heap.top().second;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > dst[ver] + w[i])
            {
                dst[j] = dst[ver] + w[i];
                heap.push({dst[j], j});
            }
        }
    }
}

int dfs(int u, int start, int d)
{
    if (u > 5)
        return d;
    int res = INF;
    efor(i, 1, 5)
    {
        if (!st[i])
        {
            int next = source[i];
            st[i] = 1;
            res = min(res, dfs(u + 1, i, d + dst[start][next]));
            st[i] = 0;
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    source[0] = 1;
    efor(i, 1, 5) cin >> source[i];

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    efor(i, 0, 5)
    {
        dijkstra(source[i], dst[i]);
    }
    memset(st, 0, sizeof st);
    cout << dfs(1, 0, 0);
}