// 2024.2.17
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <deque>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 510, M = 1;
char g[N][N];
int dst[N][N];
bool st[N][N];
int n, m;
// dx表示顶点坐标
int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
// ix表示每一步跨过的格子在g数组里的坐标
int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
// way代表跨过这个格子时可以走通的路径（不用翻转，边权为0）
char way[5] = {"\\/\\/"};

int bfs()
{
    memset(dst, 0x3f, sizeof dst);
    memset(st, false, sizeof st);
    deque<PII> q;
    q.push_front({0, 0});
    dst[0][0] = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop_front();
        if (t.first == n && t.second == m)
            return dst[n][m];
        if (st[t.first][t.second])
            continue;
        st[t.first][t.second] = true;
        ffor(i, 0, 4)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || x > n || y < 0 || y > m)
                continue;
            int gx = t.first + ix[i], gy = t.second + iy[i];
            int w = (g[gx][gy] != way[i]);
            int d = dst[t.first][t.second] + w;
            if (dst[x][y] >= d)
            {
                dst[x][y] = d;
                if (w)
                    q.push_back({x, y});
                else
                    q.push_front({x, y});
            }
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        ffor(i, 0, n)
        {
            cin >> g[i];
        }
        //每次移动，横纵坐标和只会：+2/+0，因此一定走不到横纵坐标和为奇数的点
        if (n + m & 1)
        {
            cout << "NO SOLUTION" << endl;
        }
        else
        {
            cout << bfs() << endl;
        }
    }
}