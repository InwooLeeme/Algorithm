#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

struct SegTree
{
    int tree[1 << 20];
    int sz = 1 << 19;
    void construct()
    {
        for (int i = sz - 1; i > 0; i--)
        {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    // 1 - indexed
    void update(int i, int val)
    {
        --i |= sz;
        tree[i] = val;
        while (i >>= 1)
        {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    // [l, r]
    int query(int l, int r)
    {
        --l |= sz, --r |= sz;
        int ret = 0;
        while (l <= r)
        {
            if (l & 1)
                ret += tree[l++];
            if (~r & 1)
                ret += tree[r--];
            l >>= 1, r >>= 1;
        }
        return ret;
    }
    int sol(int k)
    {
        int lo = 0, hi = 2000000;
        while (lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if (query(1, mid) < k)
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
} ST;

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            ST.update(i, b);
        }
        else
        {
            cin >> b;
            auto ans = ST.sol(b);
            cout << ans << "\n";
        }
    }
}