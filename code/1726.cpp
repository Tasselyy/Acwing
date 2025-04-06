#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <iomanip>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<double, int> PDI;

const int N = 2010, M = 2e5 + 10;
int n, m, start, ed;
int e[M], ne[M], h[N], idx;
int st[N];
double dst[N], w[M];

void add(int a, int b, double z)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = z, h[a] = idx++;
}

void dijkstra()
{
    priority_queue<PDI> heap; 
    heap.push({1.0, start});
    dst[start] = 1;

    while (!heap.empty())
    {
        auto [d, node] = heap.top();
        heap.pop();
        if (st[node]) continue;
        st[node] = 1;

        for (int i = h[node]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] < d * w[i])
            {
                dst[j] = d * w[i];
                if (!st[j]) heap.push({dst[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    memset(dst, 0, sizeof dst);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;  
        add(a, b, z);
        add(b, a, z);
    }
    cin >> start >> ed;
    dijkstra();

    cout << fixed << setprecision(8) << 100 / dst[ed] << endl;
}
