// 2024.4.9
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <cmath>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 155;
int n;
PDD q[N];
double d[N][N], maxd[N];
char g[N][N];

double get_d(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin >> n;
    ffor(i, 0, n) cin >> q[i].x >> q[i].y;
    ffor(i, 0, n) cin >> g[i];
    ffor(i, 0, n)
    {
        ffor(j, 0, n)
        {
            if (i == j)
                d[i][j] = 0;
            else if (g[i][j] == '1')
            {
                d[i][j] = get_d(q[i], q[j]);
            }
            else
                d[i][j] = INF;
        }
    }

    ffor(k, 0, n)
    {
        ffor(i, 0, n)
        {
            ffor(j, 0, n)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    // r1求没加边之前所有连通块内的最长直径
    double r1 = 0;
    ffor(i, 0, n)
    {
        ffor(j, 0, n)
        {
            // INF/2 避免double计算中精度损失
            if (d[i][j] < INF / 2)
            {
                // maxd 表示 i到能联通i的点的最长距离
                maxd[i] = max(maxd[i], d[i][j]);
            }
        }
        r1 = max(r1, maxd[i]);
    }
    // r2 求任意加边后，经过该边的最长直径的最小值
    double r2 = INF;
    ffor(i, 0, n)
    {
        ffor(j, 0, n)
        {
            if (d[i][j] > INF / 2)
                r2 = min(r2, maxd[i] + maxd[j] + get_d(q[i], q[j]));
        }
    }
    printf("%.6lf", max(r1, r2));
}