// 2024.2.27
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

const int N = 25, M = 1;
int n, m, res;
char g[N][N];
bool st[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    res++;
    st[x][y] = true;
    ffor(i, 0, 4)
    {
        int a = dx[i] + x, b = dy[i] + y;
        if (a < 0 || a > n || b < 0 || b > m)
            continue;
        if (g[a][b] != '.' || st[a][b])
            continue;
        dfs(a, b);
    }
}

int main()
{
    while (cin >> m >> n, n)
    {
        int x, y;
        memset(st, false, sizeof st);
        res = 0;
        ffor(i, 0, n)
        {
            cin >> g[i];
        }
        ffor(i, 0, n)
        {
            ffor(j, 0, m)
            {
                if (g[i][j] == '@')
                {
                    x = i, y = j;
                }
            }
        }
        dfs(x, y);

        cout << res << endl;
    }
}