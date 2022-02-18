#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

using matrix = vector<vector<int>>;

matrix I = {{1, 0}, {0, 1}};
matrix base = {{1, 1}, {1, 0}};
constexpr int MOD = 1e9 + 7;

matrix operator*(const matrix &a, const matrix &b)
{
    int size = a.size();
    matrix ret(size, vector<int>(size));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

matrix _pow(matrix x, int n)
{
    matrix ret = I;
    while (n)
    {
        if (n & 1)
            ret = ret * x;
        n >>= 1;
        x = x * x;
    }
    return ret;
}

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    auto ret = _pow(base, n);
    cout << ((ret[0][0] % MOD * ret[0][1] % MOD) % MOD) << "\n";
}