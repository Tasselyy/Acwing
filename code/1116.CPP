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

const int N = 30, M = 1;

bool st[N][N];
int ans, n, m;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void dfs(int x, int y, int cnt)
{
    if (cnt == n * m)
    {
        ans++;
        return;
    }
    st[x][y] = true;
    ffor(i, 0, 8)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m)
            continue;
        if (st[a][b])
            continue;
        dfs(a, b, cnt + 1);
    }
    st[x][y] = false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        int x, y;
        cin >> n >> m >> x >> y;
        dfs(x, y, 1);
        cout << ans << endl;
    }
}