// 2024.9.13
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, m, e[N], ne[N], w[N], idx, h[N], dst[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// spfa对bf算法优化：采用bfs使得距离没有更新的点不用遍历
// spfa中st数组代表发生过更新的点
bool spfa()
{
    // memset 是按字节更改内存，memset(a, 0x3f, sizeof a): a 的每一个字节都是 0x3f,
    // int 取4个字节，所以是 0x3f3f3f3f，他的值是0x3f3f3f3f
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;

    queue<int> q;
    //所有点都入队，因为负环可能不如1连通
    efor(i, 1, n)
    {
        q.push(i);
        st[1] = true;
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        //更新一边完成后，重置st为false，等待下次更新
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dst[j] > dst[t] + w[i])
            {
                dst[j] = dst[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
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