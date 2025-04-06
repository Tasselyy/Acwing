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

const int N = 1010, M = N * N;

int g[N][N];
PII pre[N][N];
PII q[M];
int n;

void bfs(int sx, int sy)
{
    int hh = 0, tt = 0;
    memset(pre, -1, sizeof pre);
    q[0] = {sx, sy};
    while (hh <= tt)
    {
        PII t = q[hh++];
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        ffor(i, 0, 4)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            if (g[x][y])
                continue;
            if (pre[x][y].first != -1)
                continue;
            q[++tt] = {x, y};
            pre[x][y] = t;
        }
    }
}

int main()
{
    cin >> n;
    ffor(i, 0, n)
    {
        ffor(j, 0, n)
        {
            cin >> g[i][j];
        }
    }

    bfs(n - 1, n - 1);

    PII end = {0, 0};
    while (true)
    {
        cout << end.first << " " << end.second << endl;
        if (end.first == n - 1 && end.second == n - 1)
            break;
        end = pre[end.first][end.second];
    }
}