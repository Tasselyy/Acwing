// 2024.3.3
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

const int N = 110, M = 1;
int n;
int path[N];

bool dfs(int u, int depth)
{
    if (u == depth)
        return path[u - 1] == n;
    bool st[N] = {0};
    for (int i = u - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int s = path[i] + path[j];
            // s <= path[u-1] 保证path递增
            if (st[s] || s > n || s <= path[u - 1])
                continue;
            st[s] = true;
            path[u] = s;
            if (dfs(u + 1, depth))
                return true;
        }
    }
    return false;
}

int main()
{
    path[0] = 1;
    while (cin >> n, n)
    {
        int depth = 1;
        while (true)
        {
            if (dfs(1, depth))
            {
                break;
            }
            depth++;
        }
        ffor(i, 0, depth)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}