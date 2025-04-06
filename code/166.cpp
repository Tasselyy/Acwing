// 2024.2.28
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

const int N = 9, M = 1 << N;
// one[state]为该state中有几个1, map[state]把lowbit结果（二进制状态）转化为十进制
int map[M], ones[M];
int row[N], col[N], cell[3][3];
char str[100];

int lowbit(int x)
{
    return x & -x;
}
//得到可以填入数的二进制状态
int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

void init() //初始化所有位置都为1（可以填数的状态）
{
    for (int i = 0; i < N; i++)
        row[i] = col[i] = (1 << N) - 1;
    ffor(i, 0, 3)
    {
        ffor(j, 0, 3)
        {
            cell[i][j] = (1 << N) - 1;
        }
    }
}
// is_set用于恢复现场
void draw(int x, int y, int t, bool is_set)
{
    if (is_set)
        str[x * N + y] = t + '1';
    else
        str[x * N + y] = '.';

    //转化为二进制
    int v = 1 << t;
    if (!is_set)
        v = -v;
    //如果操作是set，state的该位置1->0，如果不是则 0->1，分别对应-v和+v
    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

bool dfs(int cnt)
{
    if (!cnt)
        return true;

    //剪枝：找到一个可填数最少的
    int minv = 10;
    int x, y;
    ffor(i, 0, N)
    {
        ffor(j, 0, N)
        {
            if (str[i * N + j] == '.')
            {
                int state = get(i, j);
                if (ones[state] < minv)
                {
                    x = i, y = j;
                    minv = ones[state];
                }
            }
        }
    }
    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(cnt - 1))
            return true;
        else
            draw(x, y, t, false);
    }
    return false;
}

int main()
{
    ffor(i, 0, N) map[1 << i] = i;
    ffor(i, 0, 1 << N)
    {
        ffor(j, 0, N)
        {
            ones[i] += i >> j & 1;
        }
    }

    while (cin >> str, str[0] != 'e')
    {
        init();
        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++, k++)
            {
                if (str[k] != '.')
                {
                    // t:0-8
                    int t = str[k] - '1';
                    //初始化填数
                    draw(i, j, t, true);
                }
                else
                    cnt++;
            }
        }
        dfs(cnt);
        cout << str << endl;
    }
}