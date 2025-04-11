// 2024.4.10
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
int n, q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int flag = rand() % (r - l + 1) + l;
    int x = q[flag], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (q[i] < x);
        do
        {
            j--;
        } while (q[j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    int k;
    cin >> n >> k;
    ffor(i, 0, n) cin >> q[i];
    quick_sort(q, 0, n - 1);
    cout << q[k - 1];
}