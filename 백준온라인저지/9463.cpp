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
    while (tc--)
    {
        FenwickTree<100001> FT;
        int check[100001] = {
            0,
        };
        int n, r = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            check[t] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            r += check[t] - 1 - FT.query(check[t]);
            FT.update(check[t], 1);
        }
        cout << r << "\n";
    }
}