// 2749번 : 피보나치 수 3

#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long
typedef vector<vector<ll>> matrix;
const long long mod = 1000000;

matrix operator*(const matrix &a, const matrix &b)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++)
    {
        for (ll j = 0; j < size; j++)
        {
            for (ll k = 0; k < size; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= mod;
        }
    }
    return res;
}

matrix power(matrix a, ll n)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++)
    { // 단위 행렬
        res[i][i] = 1;
    }
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

ll n;

int main()
{
    cin >> n;
    if (n <= 1)
    {
        printf("%lld\n", n);
        return 0;
    }
    matrix res = {{1, 1}, {1, 0}};
    matrix result = power(res, n);
    printf("%lld\n", result[0][1]);
    return 0;
}