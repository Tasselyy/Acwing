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

const int N = 1e5 + 10;
int n, m;
int e[N], ne[N], w[N], h[N], idx;
int dst[N];
bool st[N];
int cnt[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    queue<int> q;
    efor(i, 1, n)
    {
        q.push(i);
        st[i] = true;
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > dst[t] + w[i])
            {
                dst[j] = dst[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n) return true;
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
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

    if (spfa())
        cout << "Yes";
    else
        cout << "No";
}