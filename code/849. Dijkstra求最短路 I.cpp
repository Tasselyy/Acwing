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

int n, m, e[N], ne[N], w[N], idx, h[N], st[N], dst[N];

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
    ffor(i, 0, n)
    {
        //找到距离最近的点t
        int t = -1;
        efor(j, 1, n)
        {
            if (!st[j] && (t == -1 || dst[j] < dst[t]))
                t = j;
        }
        st[t] = 1;
        //遍历t的连接点
        for (int j = h[t]; j != -1; j = ne[j])
        {
            int k = e[j];
            dst[k] = min(dst[k], dst[t] + w[j]);
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