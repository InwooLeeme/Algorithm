#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int, int>;

int CCW(const vector<pii> &v)
{
    return (v[1].first - v[0].first) * (v[2].second - v[0].second) - (v[2].first - v[0].first) * (v[1].second - v[0].second);
}

int32_t main()
{
    fastio;
    vector<pii> v(3);
    for (auto &[a, b] : v)
        cin >> a >> b;
    cout << (!CCW(v) ? "WHERE IS MY CHICKEN?" : "WINNER WINNER CHICKEN DINNER!") << "\n";
}