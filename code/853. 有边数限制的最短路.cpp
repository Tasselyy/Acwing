// 2024.9.13
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m, k;
int dst[N], backup[N];

// bf算法遍历所有边依次更新（松弛），因此不需要邻接表存图
struct Edge
{
    int a, b, w;
} edge[N];

bool bellman_ford()
{
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    ffor(i, 0, k)
    {
        //备份dst，防止a->b->c的情况下，更新bc边用到ab边更新后的数据
        memcpy(backup, dst, sizeof dst);
        ffor(j, 0, m)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dst[b] = min(dst[b], backup[a] + w);
        }
    }
    //走不到n的情况下，n也有可能被松弛导致dst[n]<0x3f3f3f3f
    //就比如1->2->3这条路径，如果1到2的距离是-2,2到3的距离是INF（说明2不能到3这个点）
    //，那么最终1到3的距离是INF-2，他不等于INF，但是1这个点到不了3这个点，
    //所以当d[1][3]=INF-2 时也要输出impossible
    if (dst[n] > 0x3f3f3f3f / 2)
        return false;
    else
        return true;
}

int main()
{
    cin >> n >> m >> k;
    ffor(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    if (!bellman_ford())
        cout << "impossible";
    else
        cout << dst[n];
}