// 2024.4.8
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

const int N = 1010, M = 30010;
int n, m, s;
int e[M], ne[M], h[N], w[M], idx;
int dst[N], st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dst, 0x3f, sizeof dst);
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(0);
    dst[0] = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > dst[t] + w[i])
            {
                dst[j] = dst[t] + w[i];
                if (!st[j])
                {
                    st[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    if (dst[s] == INF)
        return -1;
    else
        return dst[s];
}

int main()
{
    while (cin >> n >> m >> s)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        int t;
        cin >> t;
        while (t--)
        {
            int b;
            cin >> b;
            add(0, b, 0);
        }
        cout << spfa() << endl;
    }
}