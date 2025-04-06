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

const int N = 1e5, M = 1;
int n, m, start, ed;
int e[N], ne[N], w[N], h[N], dst[N], idx;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijstra()
{
    memset(dst, 0x3f, sizeof dst);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    dst[start] = 0;
    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int node = t.second, d = t.first;
        st[node] = true;
        for (int i = h[node]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > d + w[i])
            {
                dst[j] = d + w[i];
                if (!st[j])
                    heap.push({dst[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m >> start >> ed;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dijstra();
    cout << dst[ed];
}