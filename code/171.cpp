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
using namespace std;
typedef pair<int, int> PII;

const int N = 1 << 25;
int n, m, k;
int w[50];
int weight[N]; //存组合
int cnt, ans;

void dfs(int u, int sum)
{
    //遍历完所有数，存组合
    if (u == k)
    {
        weight[cnt++] = sum;
        return;
    }
    //不选u
    dfs(u + 1, sum);
    //选u
    if ((long long)sum + w[u] <= m)
    {
        dfs(u + 1, sum + w[u]);
    }
}

void dfs2(int u, int sum)
{
    //二分搜一个前半段最大的组合
    if (u == n)
    {
        int l = 0, r = cnt - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (weight[mid] <= m - sum)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans = max(ans, weight[l] + sum);
        return;
    }
    dfs2(u + 1, sum);
    if ((long long)w[u] + sum <= m)
    {
        dfs2(u + 1, sum + w[u]);
    }
}

int main()
{
    cin >> m >> n;
    ffor(i, 0, n)
    {
        cin >> w[i];
    }
    sort(w, w + n);
    reverse(w, w + n);
    k = n >> 1;
    dfs(0, 0);
    //去重
    sort(weight, weight + cnt);
    int t = 1;
    for (int i = 1; i < cnt; i++)
    {
        if (weight[i] != weight[i - 1])
        {
            weight[t++] = weight[i];
        }
    }
    cnt = t;
    dfs2(k, 0);
    cout << ans;
}