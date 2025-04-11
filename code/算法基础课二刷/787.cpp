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
int n, q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
    {
        tmp[k++] = q[i++];
    }
    while (j <= r)
    {
        tmp[k++] = q[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++)
    {
        q[i] = tmp[j];
    }
}

int main()
{
    cin >> n;
    ffor(i, 0, n) cin >> q[i];
    merge_sort(q, 0, n - 1);
    ffor(i, 0, n) cout << q[i] << " ";
}