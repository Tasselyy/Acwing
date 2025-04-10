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
using namespace std;
typedef pair<int, int> PII;

const int N = 30;
int n, m;
int g[N][N], d[N][N], st[N];

char get_min()
{
    ffor(i, 0, n)
    {
        int flag = 1;
        if (!st[i])
        {
            ffor(j, 0, n)
            {
                if (!st[j] && d[j][i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                st[i] = 1;
                return (i + 'A');
            }
        }
    }
}

int check()
{
    ffor(i, 0, n)
    {
        if (d[i][i] == 1)
            return 2;
    }
    ffor(i, 0, n)
    {
        ffor(j, 0, i)
        {
            if (!d[i][j] && !d[j][i])
                return 0;
        }
    }
    return 1;
}

void floyd()
{
    memcpy(d, g, sizeof d);
    ffor(k, 0, n)
    {
        ffor(i, 0, n)
        {
            ffor(j, 0, n)
            {
                d[i][j] |= d[i][k] && d[k][j];
            }
        }
    }
}

int main()
{
    while (cin >> n >> m, n)
    {
        memset(g, 0, sizeof g);
        int type = 0, t;
        efor(i, 1, m)
        {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            if (!type)
            {
                g[a][b] = 1;
                floyd();
                type = check();
                if (type)
                    t = i;
            }
        }
        if (!type)
            puts("Sorted sequence cannot be determined.");
        else if (type == 2)
            printf("Inconsistency found after %d relations.\n", t);
        else
        {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for (int i = 0; i < n; i++)
                printf("%c", get_min());
            printf(".\n");
        }
    }
}