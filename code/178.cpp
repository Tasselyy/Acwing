// 2024.3.4
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#define INF 0x3f3f3f3f;
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 2e4;
int n, m;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int S, T, K;
int dist[N], cnt[N];
bool st[N];

void add(int h[], int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;
    heap.push({0, T});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.y;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = rh[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int Astar()
{
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.y.y, d = t.y.x;
        cnt[ver]++;
        if (cnt[T] == K)
        {
            return d;
        }

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            //第K次访问该点对应的状态已经是到该点的第K短路，如果想得到到终点的第K短路，该点就已经不需要再被访问了（K+1次无意义），可以剪枝
            if (cnt[j] < K)
            {
                heap.push({w[i] + d + dist[j], {d + w[i], j}});
            }
        }
    }
    return -1;
}

int main()
{
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof h);

    cin >> n >> m;
    ffor(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin >> S >> T >> K;
    if (S == T)
        K++;

    dijkstra();
    cout << Astar();
}