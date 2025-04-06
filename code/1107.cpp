// 2024.2.17
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

//字符串转为数组g方便处理
char g[2][4];
unordered_map<string, int> dst;
unordered_map<string, pair<char, string>> pre;
queue<string> q;

string get()
{
    string res;
    ffor(i, 0, 4)
    {
        res += g[0][i];
    }
    for (int i = 3; i >= 0; i--)
    {
        res += g[1][i];
    }
    return res;
}

void set(string st)
{
    ffor(i, 0, 4)
    {
        g[0][i] = st[i];
    }
    for (int i = 3, j = 4; i >= 0; i--, j++)
    {
        g[1][i] = st[j];
    }
}

string move0(string st)
{
    set(st);
    ffor(i, 0, 4)
    {
        swap(g[0][i], g[1][i]);
    }
    return get();
}
string move1(string st)
{
    set(st);
    char t[2] = {g[0][3], g[1][3]};
    for (int i = 2; i >= 0; i--)
    {
        swap(g[0][i], g[0][i + 1]);
        swap(g[1][i], g[1][i + 1]);
    }
    g[0][0] = t[0];
    g[1][0] = t[1];
    return get();
}
string move2(string st)
{
    set(st);
    swap(g[0][1], g[1][1]);
    swap(g[1][1], g[0][2]);
    swap(g[1][1], g[1][2]);
    return get();
}

void bfs(string start, string end)
{
    if (start == end)
        return;
    q.push(start);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        ffor(i, 0, 3)
        {
            string k = m[i];
            if (!dst.count(k))
            {
                dst[k] = dst[t] + 1;
                pre[k] = {char(i + 'A'), t};
                if (k == end)
                    return;
                q.push(k);
            }
        }
    }
}

int main()
{
    string start, end;
    ffor(i, 0, 8)
    {
        int x;
        cin >> x;
        start += char(i + '1');
        end += char(x + '0');
    }
    bfs(start, end);
    cout << dst[end] << endl;
    string res;
    while (end != start)
    {
        res += pre[end].first;
        end = pre[end].second;
    }
    reverse(res.begin(), res.end());
    if (res.size())
        cout << res;
}