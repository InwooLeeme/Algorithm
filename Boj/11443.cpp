#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

const matrix I = {{1, 0}, {0, 1}};
const int MOD = 1e9 + 7;

struct Matrix
{
    matrix matrix_mul(matrix a, matrix b)
    {
        const int sz = a.size();
        matrix ret(sz, vector<ll>(sz, 0));
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    ret[i][j] += a[i][k] * b[k][j];
                }
                ret[i][j] %= MOD;
            }
        }
        return ret;
    }

    matrix matrix_pow(matrix x, int n)
    {
        matrix ret = I;
        for (; n; n >>= 1)
        {
            if (n & 1)
                ret = matrix_mul(ret, x);
            x = matrix_mul(x, x);
        }
        return ret;
    }
};

int32_t main()
{
    fastio;
    ll n;
    cin >> n;
    if (n % 2 == 0)
        n++;
    Matrix M;
    matrix base = {{1, 1}, {1, 0}};
    ll ans = M.matrix_pow(base, n)[0][1];
    ans = ((ans % MOD) - 1 + MOD) % MOD;
    cout << ans << "\n";
}