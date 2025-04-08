// 2024.4.7
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

const int N = 1e5 + 10, M = 2e6 + 10;
int n, m;
int h[N], rh[N], e[M], ne[M], w[N], idx;
int dmin[N], dmax[N], st[N];

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int start, int dst[], int type)
{
    memset(st, 0, sizeof st);
    if (type == 0)
        memset(dst, 0x3f, sizeof dmin);
    queue<int> q;
    q.push(start);
    dst[start] = w[start];

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i; i = ne[i])
        {

            int j = e[i];
            if (type == 0 && dst[j] > min(dst[t], w[j]) || type == 1 && dst[j] < max(dst[t], w[j]))
            {
                dst[j] = type ? max(dst[t], w[j]) : min(dst[t], w[j]);
                if (!st[j])
                {
                    st[j] = 1;
                    q.push(j);
                }
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    scanf("%d%d", &n, &m);
    efor(i, 1, n) cin >> w[i];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b), add(rh, b, a);
        if (c == 2)
            add(h, b, a), add(rh, a, b);
    }
    spfa(h, 1, dmin, 0);
    spfa(rh, n, dmax, 1);

    int res = 0;
    efor(i, 1, n) res = max(res, dmax[i] - dmin[i]);
    printf("%d\n", res);
}