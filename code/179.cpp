// 2024.2.23
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
typedef pair<int, string> PIS;

const int N = 10, M = 1;
char c;
string start;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char op[] = "urdl";

int f(string s)
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == 'x')
            continue;
        int t = s[i] - '1';
        ans += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
    }
    return ans;
}

string bfs()
{
    string end = "12345678x";
    unordered_map<string, int> dist;
    unordered_map<string, pair<char, string>> pre;
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;

    dist[start] = 0;
    heap.push({f(start), start});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        string state = t.second;
        if (state == end)
            break;
        int x, y;
        for (int i = 0; i < 9; i++)
        {
            if (state[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
        }
        string source = state;
        ffor(i, 0, 4)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > 2 || b < 0 || b > 2)
                continue;
            swap(state[a * 3 + b], state[x * 3 + y]);
            if (!dist.count(state) || dist[state] > dist[source] + 1)
            {
                dist[state] = dist[source] + 1;
                pre[state] = {op[i], source};
                heap.push({f(state) + dist[state], state});
            }
            state = source;
        }
    }
    string ans;
    while (end != start)
    {
        ans += pre[end].first;
        end = pre[end].second;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ffor(i, 0, 9)
    {
        cin >> c;
        start += c;
    }

    int t = 0;
    ffor(i, 0, 9)
    {
        for (int j = i; j < 9; j++)
        {
            if (start[i] == 'x' || start[j] == 'x')
                continue;
            if (start[j] > start[i])
            {
                t++;
            }
        }
    }
    if (t & 1)
        cout << "unsolvable" << endl;
    else
        cout << bfs() << endl;
}