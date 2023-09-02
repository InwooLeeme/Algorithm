#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

const int PRECISION = 0;

using matrix = vector<vector<int>>;

matrix I = {{1, 0}, {0, 1}};
matrix base = {{1, 1}, {1, 0}};
constexpr int MOD = 998244353;

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

void Main(){
    int n; cin >> n;
    auto ret =  _pow(base, n + 1);
    cout << ((ret[0][0] % MOD * ret[0][1] % MOD) % MOD) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}