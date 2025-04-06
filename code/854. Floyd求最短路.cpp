// 2024.9.13
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 20010;

int d[N][N];
int n, m, k;

void floyd()
{
    efor(k, 1, n)
    {
        efor(i, 1, n)
        {
            efor(j, 1, n)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    efor(i, 1, n)
    {
        efor(j, 1, n)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << d[x][y] << endl;
    }
}