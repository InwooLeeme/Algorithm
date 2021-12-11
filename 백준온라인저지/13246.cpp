#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;
const int MOD = 1000;

struct Matrix
{
    int sz;
    Matrix(int n)
    {
        sz = n;
    }
    matrix unitMatrix()
    {
        matrix I(sz, vector<ll>(sz));
        for (int i = 0; i < sz; i++)
            I[i][i] = 1;
        return I;
    }

    matrix matrix_mul(matrix a, matrix b)
    {
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

    matrix matrix_plus(matrix a, matrix b)
    {
        matrix ret(sz, vector<ll>(sz, 0));
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                ret[i][j] = a[i][j] + b[i][j];
                ret[i][j] %= MOD;
            }
        }
        return ret;
    }

    matrix matrix_pow(matrix x, int n)
    {
        matrix ret = unitMatrix();
        for (; n; n >>= 1)
        {
            if (n & 1)
                ret = matrix_mul(ret, x);
            x = matrix_mul(x, x);
        }
        return ret;
    }

    void printMatrix(const matrix x)
    {
        const int n = x.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << x[i][j] << ' ';
            }
            cout << "\n";
        }
    }
};

int32_t main()
{
    fastio;
    int n, b;
    cin >> n >> b;
    Matrix M(n);
    matrix base(n, vector<ll>(n));
    matrix ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> base[i][j];
    for (int i = 1; i <= b; i++)
    {
        auto ret = M.matrix_pow(base, i);
        ans = M.matrix_plus(ret, ans);
    }
    M.printMatrix(ans);
}