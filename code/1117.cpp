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

const int N = 25, M = 1;
// g代表j单词接在i单词后面时重合的最短长度
int g[N][N];
int used[N];
string words[N];
int n;
int ans;

void dfs(string s, int last)
{
    ans = max(ans, (int)s.size());
    used[last]++;
    ffor(i, 0, n)
    {
        if (g[last][i] && used[i] < 2)
        {
            dfs(s + words[i].substr(g[last][i]), i);
        }
    }
    used[last]--;
}

int main()
{
    cin >> n;
    ffor(i, 0, n)
    {
        cin >> words[i];
    }
    char start;
    cin >> start;
    ffor(i, 0, n)
    {
        ffor(j, 0, n)
        {
            string a = words[i], b = words[j];
            for (int k = 1; k < min(a.size(), b.size()); k++)
            {
                if (a.substr(a.size() - k, k) == b.substr(0, k))
                {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    ffor(i, 0, n)
    {
        if (words[i][0] == start)
        {
            dfs(words[i], i);
        }
    }
    cout << ans;
}