// 2024.2.17
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <cstring>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 10;
int n;
string a[N], b[N];

int trans(unordered_map<string, int> &da, unordered_map<string, int> &db, queue<string> &q, string a[], string b[])
{
    // trans()里只进行一层的扩展，通过检测da[q.front()]的值，来判断是否完成了这一层的遍历
    //（进行到下一层时，da[q.front()]会+1）
    int flag = da[q.front()];
    while (q.size() && flag == da[q.front()])
    {
        string t = q.front();
        q.pop();
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (t.substr(i, a[j].size()) == a[j])
                {
                    string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                    if (db.count(state))
                        return 1 + da[t] + db[state];
                    if (da.count(state))
                        continue;
                    q.push(state);
                    da[state] = 1 + da[t];
                }
            }
        }
    }

    return 11;
}

int bfs(string start, string end)
{
    if (start == end)
        return 0;
    unordered_map<string, int> da, db;
    queue<string> qa, qb;
    da[start] = 0;
    db[end] = 0;
    qa.push(start), qb.push(end);

    int step = 0;
    while (qa.size() && qb.size())
    {
        int res;
        //判断哪个队列里可以扩展的点少，先在点少的队列进行一轮扩展
        if (qa.size() < qb.size())
            res = trans(da, db, qa, a, b);
        else
            res = trans(db, da, qb, b, a);
        if (res <= 10)
            return res;
        //超过十步直接返回
        if (++step == 10)
            return 11;
    }
    return 11;
}

int main()
{
    string start, end;
    cin >> start >> end;
    while (cin >> a[n] >> b[n])
    {
        n++;
    }
    int ans = bfs(start, end);
    if (ans > 10)
    {
        cout << "NO ANSWER!";
    }
    else
        cout << ans;
}