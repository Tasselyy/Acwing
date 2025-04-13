// 2025.4.10
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

const int N = 100010;
int n, q, k;
int a[N];

int main()
{
    cin >> n >> q;
    ffor(i, 0, n)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (a[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
}