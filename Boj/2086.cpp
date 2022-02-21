#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

const int MOD = 1e9;

matrix I = {{1, 0}, {0, 1}};
matrix base = {{1, 1}, {1, 0}};

matrix matrix_mul(matrix a, matrix b)
{
    return {
        {((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD) % MOD, ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD) % MOD},
        {((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[1][0]) % MOD) % MOD, ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD) % MOD}};
}

matrix _pow(matrix x, int n)
{
    matrix ret = I;
    while (n)
    {
        if (n & 1)
            ret = matrix_mul(ret, x);
        n /= 2;
        x = matrix_mul(x, x);
    }
    return ret;
}

int32_t main()
{
    fastio;
    int a, b;
    cin >> a >> b;
    cout << (_pow(base, b + 2)[0][1] % MOD - _pow(base, a - 1 + 2)[0][1] % MOD + MOD) % MOD << '\n';
}