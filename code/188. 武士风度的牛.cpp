// 2024.2.17
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 160, M = N * N;

char g[N][N];
int n, m;
PII q[M];
int dst[N][N];

int bfs(int sx, int sy)
{
    memset(dst, -1, sizeof dst);
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    dst[sx][sy] = 0;
    while (hh <= tt)
    {
        PII t = q[hh++];
        int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (g[x][y] == '*')
                continue;
            else if (dst[x][y] == -1)
            {
                q[++tt] = {x, y};
                dst[x][y] = dst[t.first][t.second] + 1;
                if (g[x][y] == 'H')
                    return dst[x][y];
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    int sx, sy;
    ffor(i, 0, n)
    {
        ffor(j, 0, m)
        {
            cin >> g[i][j];
            if (g[i][j] == 'K')
            {
                sx = i;
                sy = j;
            }
        }
    }
    cout << bfs(sx, sy);
}