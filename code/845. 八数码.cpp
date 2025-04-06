// 2024.9.12
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 110;

int bfs(string s)
{
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(s);
    d[s] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    while (q.size())
    {
        string t = q.front();
        q.pop();
        int dst = d[t];

        if (t == end)
        {
            return dst;
        }
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        ffor(i, 0, 4)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t))
                {
                    d[t] = dst + 1;
                    q.push(t);
                }
                //向四个方向尝试，每次尝试后恢复原状态
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main()
{
    string s;
    ffor(i, 0, 9)
    {
        char c;
        cin >> c;
        s += c;
    }
    cout << bfs(s);
}