// 2024.3.1
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

const int N = 70, M = 1;
int w[N]; //存木棍
int n;
bool st[N];
int len, sum; //当前枚举木棒长度，所有木棒总长

// u当前第几跟木棒，s当前的长度，start枚举木棍下标
bool dfs(int u, int s, int start)
{
    if (u * len == sum)
        return true;
    if (s == len)
        return dfs(u + 1, 0, 0);
    for (int i = start; i < n; i++)
    {
        if (st[i])
            continue;
        if (s + w[i] > len)
            continue;
        st[i] = true;
        if (dfs(u, s + w[i], i + 1))
        {
            return true;
        }
        //搜索失败，先还原现场
        st[i] = false;
        //再剪枝
        //如果第一根木棍就失败，一定找不到方案直接返回false
        if (!s)
            return false;
        //最后一根失败
        if (s + w[i] == len)
            return false;
        //后面相同长度的木棍都不用试了
        int j = i;
        while (j < n && w[j] == w[i])
            j++;
        i = j - 1;
    }
    return false;
}

int main()
{
    while (cin >> n, n)
    {
        memset(st, false, sizeof st);
        sum = 0, len = 0;
        ffor(i, 0, n)
        {
            cin >> w[i];
            sum += w[i];
            len = max(len, w[i]);
        }
        //从大到小排列，优化搜索顺序
        sort(w, w + n);
        reverse(w, w + n);

        while (true)
        {
            if (sum % len == 0 && dfs(0, 0, 0))
            {
                cout << len << endl;
                break;
            }
            len++;
        }
    }
}