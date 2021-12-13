#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

int v[1001];

int32_t main()
{
    fastio;
    int n, k, cnt = 0;
    cin >> n >> k;
    for (int i = 2; i < 1001; i++)
        v[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (v[j] != 0)
            {
                cnt++;
                v[j] = 0;
            }
            if (cnt == k)
            {
                cout << j << "\n";
                break;
            }
        }
    }
}