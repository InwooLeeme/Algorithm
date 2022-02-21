#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using pii = pair<int, int>;

template <size_t sz>
struct FenwickTree
{
    vector<int> tree;
    FenwickTree() : tree(sz + 1) {}
    void update(int i, int val)
    {
        for (; i <= sz; i += i & -i)
            tree[i] += val;
    }
    int query(int i)
    {
        int ret = 0;
        for (; i; i -= i & -i)
            ret += tree[i];
        return ret;
    }
};

int32_t main()
{
    fastio;
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        int n, m, k, r = 0;
        cin >> n >> m >> k;
        vector<pii> v(k);
        for (int i = 0; i < k; i++)
            cin >> v[i].first >> v[i].second;
        FenwickTree<1001> FT;
        sort(v.begin(), v.end());
        for (int i = k - 1; i >= 0; i--)
        {
            int t = v[i].second;
            r += FT.query(t - 1);
            FT.update(t, 1);
        }
        cout << "Test case " << i << ": " << r << "\n";
    }
}