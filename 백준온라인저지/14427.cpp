#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

template <typename T = int64_t, size_t sz = 17, typename F = plus<T>>
struct SegTree
{
    vector<T> tree;
    T t;
    F f{};
    SegTree(T t = T()) : tree(1 << sz + 1, t), t(t) {}
    explicit SegTree(T t, const F &f) : tree(1 << sz + 1, t), t(t), f(f) {}

    void Init()
    {
        for (int i = (1 << sz) - 1; i; i--)
        {
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void Update(int i, T val)
    {
        --i |= 1 << sz;
        tree[i] = val;
        while (i >>= 1)
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }
    T Query(int l, int r)
    {
        T L = t, R = t;
        --l |= 1 << sz, --r |= 1 << sz;
        while (l <= r)
        {
            if (l & 1)
                L = f(L, tree[l++]);
            if (~r & 1)
                R = f(tree[r--], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
};

struct F
{
    pii operator()(pii a, pii b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first ? a : b;
        }
        return a.second < b.second ? a : b;
    }
} f;

SegTree<pll, 20, F> ST({INF, INF}, f);

int main()
{
    fastio;
    int n, m;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        ST.Update(i, {i, t});
    }
    cin >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a;
        if (a & 1)
        {
            cin >> b >> c;
            ST.Update(b, {b, c});
        }
        else
            cout << ST.tree[1].first << "\n";
    }
    return 0;
}