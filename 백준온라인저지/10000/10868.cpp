// 10868번 : 최솟값

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;
using tii = tuple<int, int, int>;

const int INF = 1e9 + 7;

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
    int operator()(int a, int b)
    {
        return (a < b ? a : b);
    }
} f;

SegTree<int, 17, F> ST(INF, f); // 최솟값을 저장하기 때문에 초기 생성시 INF로 초기화

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int64_t t;
        cin >> t;
        ST.Update(i, t);
    }
    for (int i = 0; i < m; i++)
    {
        int64_t b, c;
        cin >> b >> c;
        cout << ST.Query(b, c) << "\n";
    }
    return 0;
}