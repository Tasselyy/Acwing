// 2024.3.5
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#define INF 0x3f3f3f3f;
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 30, M = 1;
int n = 24;
int q[N];
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};

int path[100];

int f()
{
    int sum[4] = {};
    for (int i = 0; i < 8; i++)
        sum[q[center[i]]]++;
    int maxv = 0;
    for (int i = 1; i <= 3; i++)
    {
        maxv = max(sum[i], maxv);
    }
    return 8 - maxv;
}

void operate(int x)
{
    int t = q[op[x][0]];
    ffor(i, 0, 6) q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = t;
}

bool dfs(int depth, int max_depth, int last)
{
    if (depth + f() > max_depth)
        return false;
    if (!f())
        return true;
    ffor(i, 0, 8)
    {
        if (opposite[i] == last)
            continue;
        operate(i);
        path[depth] = i;
        if (dfs(depth + 1, max_depth, i))
            return true;
        operate(opposite[i]);
    }
    return false;
}

int main()
{
    while (cin >> q[0], q[0])
    {
        ffor(i, 1, n) cin >> q[i];
        int depth = 0;
        while (!dfs(0, depth, -1))
            depth++;
        if (!depth)
            cout << "No moves needed" << endl;
        else
        {
            for (int i = 0; i < depth; i++)
            {
                cout << char(path[i] + 'A');
            }
            cout << endl;
        }
        cout << q[6] << endl;
    }
}