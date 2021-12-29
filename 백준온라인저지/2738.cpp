#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

using matrix = vector<vector<int>>;

struct Matrix
{
    matrix plus(matrix &a, matrix &b)
    {
        const int n = a.size();
        const int m = a[0].size();
        matrix ret(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret[i][j] = a[i][j] + b[i][j];
            }
        }
        return ret;
    }
};

int32_t main()
{
    fastio;
    Matrix M;
    int n, m;
    cin >> n >> m;
    matrix a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    auto ret = M.plus(a, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ret[i][j] << ' ';
        }
        cout << "\n";
    }
}