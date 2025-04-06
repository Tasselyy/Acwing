// 2024.3.5
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

const int N = 20, M = 1;
int n;
int q[N], tmp[5][N];

int f()
{
    int tot = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        if (q[i + 1] != q[i] + 1)
        {
            tot++;
        }
    }
    return (tot + 2) / 3;
}

bool check()
{
    for (int i = 0; i + 1 < n; i++)
    {
        if (q[i + 1] != q[i] + 1)
        {
            return false;
        }
    }
    return true;
}

bool dfs(int depth, int max_depth)
{
    if (check())
        return true;
    if (depth + f() > max_depth)
        return false;
    for (int len = 1; len < n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            for (int k = r + 1; k < n; k++)
            {
                memcpy(tmp[depth], q, sizeof q);
                int x, y;
                for (x = r + 1, y = l; x <= k; x++, y++)
                    q[y] = tmp[depth][x];
                for (x = l; x <= r; x++, y++)
                    q[y] = tmp[depth][x];
                if (dfs(depth + 1, max_depth))
                    return true;
                memcpy(q, tmp[depth], sizeof tmp[depth]);
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        ffor(i, 0, n) cin >> q[i];
        int depth = 0;
        while (depth < 5)
        {
            if (dfs(0, depth))
                break;
            else
                depth++;
        }
        if (depth < 5)
            cout << depth << endl;
        else
            cout << "5 or more" << endl;
    }
}