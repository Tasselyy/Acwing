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

const int N = 110, M = 1;

char g[N][N];
bool st[N][N];
int xa, xb, ya, yb;
int n;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y)
{
    if (x == xb && y == yb)
        return true;
    st[x][y] = true;
    ffor(i, 0, 4)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= n)
            continue;
        if (st[a][b] || g[a][b] == '#')
            continue;
        if (dfs(a, b))
            return true;
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
        ffor(i, 0, n)
        {
            cin >> g[i];
        }
        memset(st, false, sizeof st);
        cin >> xa >> ya >> xb >> yb;
        if (g[xa][ya] == '#' || g[xb][yb] == '#')
            cout << "NO" << endl;
        else
        {
            if (dfs(xa, ya))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}