#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using pii = pair<int, int>;

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> LIS;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int t = v[i].second;
        if (LIS.empty() || LIS.back() < t)
            LIS.push_back(t);
        else
            *lower_bound(LIS.begin(), LIS.end(), t) = t;
    }
    cout << n - LIS.size() << "\n";
}