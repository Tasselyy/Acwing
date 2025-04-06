// 2024.9.12
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, m, e[N], ne[N], w[N], idx, h[N], dst[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra()
{
    // memset 是按字节更改内存，memset(a, 0x3f, sizeof a): a 的每一个字节都是 0x3f,
    // int 取4个字节，所以是 0x3f3f3f3f，他的值是0x3f3f3f3f
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    //利用pq对距离进行排序，所以需要PII
    //利用pq定义小根堆,PII first为距离，second为点数
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size())
    {
        PII k = heap.top();
        heap.pop();
        int d = k.first, t = k.second;
        if (st[t])
            continue;
        st[t] = true;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > d + w[i])
            {
                dst[j] = d + w[i];
                heap.push({dst[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();

    if (dst[n] != 0x3f3f3f3f)
        cout << dst[n];
    else
        cout << -1;
}