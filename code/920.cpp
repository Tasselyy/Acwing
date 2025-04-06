// 2024.4.5
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <sstream>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define efor(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef pair<int, int> PII;

const int N = 250000;
int n, m;
int e[N], ne[N], w[N], h[N], idx;
int st[N], dst[N];

void add(int a, int b)
{
    e[idx] = b, w[idx] = 1, ne[idx] = h[a], h[a]=idx++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({1, 1});
    dst[1] = 1;
    while (heap.size())
    {
        auto [d, node] = heap.top();
        // cout<<d<<node;
        heap.pop();
        st[node] = 1;
        // cout<<h[node];
        for (int i = h[node]; i != -1; i = ne[i])
        {
            // cout<<111;
            int j = e[i];
            if (dst[j] > d + 1)
            {
                dst[j] = d + 1;
                cout<<dst[j];
                if (!st[j])
                    heap.push({dst[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    memset(dst, 0x3f, sizeof dst);
    cin >> m >> n;
    cin.ignore(); 
    while (m--)
    {
        string line;
        getline(cin, line);
        istringstream ss(line);
        vector<int> num;
        int x;
        while (ss >> x)
            num.push_back(x);
        for (int i = 0; i < num.size(); i++)
        {
            for (int j = i + 1; j < num.size(); j++)
            {
                add(num[i], num[j]);
            }
        }
    }
    dijkstra();
    if (dst[n] == INF)
        cout << "no";
    else
        cout << dst[n] - 1;
}