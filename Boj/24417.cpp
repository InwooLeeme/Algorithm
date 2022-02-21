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

constexpr int MOD = 1e9 + 7;

using Matrix = array<array<int, 2>, 2>;

Matrix Mul(const Matrix &a, const Matrix &b)
{
    Matrix ret{};
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < a[0].size(); k++)
                ret[i][j] = (ret[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
        }
    return ret;
}

Matrix Pow(Matrix x, int n)
{
    Matrix ret{};
    ret[0][0] = ret[1][1] = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ret = Mul(ret, x);
        x = Mul(x, x);
    }
    return ret;
}

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    Matrix M = {1, 1, 1, 0};
    M = Pow(M, n);
    cout << M[1][0] << ' ' << n - 2 << "\n";
}