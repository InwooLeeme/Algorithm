#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using pii = pair<int, int>;

vector<int> coord;
int arr[500001], idx[500001];

inline int getIdx(int val)
{
    return (lower_bound(coord.begin(), coord.end(), val) - coord.begin()) + 1;
}

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
    int n, r = 0;
    cin >> n;
    vector<pii> v;
    FenwickTree<500001> FT;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        coord.push_back(arr[i]);
    }
    // compress coordinate
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    for (int i = 1; i <= n; i++)
        idx[i] = getIdx(arr[i]);
    for (int i = n; i >= 1; i--)
    {
        int t = idx[i];
        r += FT.query(t - 1);
        FT.update(t, 1);
    }
    cout << r << "\n";
}