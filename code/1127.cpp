// 2024.3.31
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

const int N = 1e5;
int n, m, p;
int e[N], ne[N], w[N], h[N], dst[N], cow[N], idx, ans[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijstra(int s)
{
    memset(dst, 0x3f, sizeof dst);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    dst[s] = 0;
    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int node = t.second, d = t.first;
        st[node] = true;
        for (int i = h[node]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > w[i] + d)
            {
                dst[j] = w[i] + d;
                if (!st[j])
                    heap.push({dst[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> p >> n >> m;
    while (p--)
    {
        int t;
        cin >> t;
        cow[t]++;
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    efor(i, 1, n)
    {
        dijstra(i);
        efor(j, 1, n)
        {
            if (cow[j] && dst[j] == INF)
            {
                ans[i] = -1;
                break;
            }
            ans[i] += cow[j] * dst[j];
        }
    }

    int res = INF;
    efor(i, 1, n)
    {
        if (ans[i] == -1)
            continue;
        res = min(ans[i], res);
    }
    cout << res;
}