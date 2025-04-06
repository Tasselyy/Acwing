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

char g[N][N];
int dst[N][N];
queue<PII> q;
int n, m;

void bfs()
{
    memset(dst, -1, sizeof dst);
    ffor(i, 0, n)
    {
        ffor(j, 0, m)
        {
            if (g[i][j] == '1')
            {
                dst[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        PII t = q.front();
        q.pop();
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        ffor(i, 0, 4)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (g[x][y] == '1')
                continue;
            if (dst[x][y] == -1)
            {
                dst[x][y] = dst[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    ffor(i, 0, n)
    {
        cin >> g[i];
    }
    bfs();
    ffor(i, 0, n)
    {
        ffor(j, 0, m)
        {
            cout << dst[i][j] << " ";
        }
        cout << endl;
    }
}