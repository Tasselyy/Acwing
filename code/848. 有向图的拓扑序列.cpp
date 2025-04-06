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

// in: 入度
int n, m, e[N], ne[N], in[N], idx, h[N], ans[N], k;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    in[b]++;
}

bool bfs()
{
    queue<int> q;
    efor(i, 1, n)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int t = q.front();
        ans[++k] = t;
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            in[j]--;
            if (!in[j])
                q.push(j);
        }
    }
    return k == n;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    if (bfs())
    {
        efor(i, 1, k)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << -1;
}