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

const int N = 1e5 + 10;
int n, k;
int dst[N];
queue<int> q;

void bfs()
{
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int dt[3] = {-1, 1, t};
        ffor(i, 0, 3)
        {
            int y = t + dt[i];
            if (y < 0 || y > N)
                continue;
            if (!dst[y])
            {
                dst[y] = dst[t] + 1;
                if (y == k)
                {
                    cout << dst[y];
                    return;
                }
                q.push(y);
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    q.push(n);
    if (n == k)
    {
        cout << 0;
    }
    else
    {
        bfs();
    }
}