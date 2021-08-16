// 11444번 : 피보나치 수 6

#include <iostream>
#include <vector>
#define ll long long
#define matrix vector<vector<ll>>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const ll mod = 1e9 + 7;

ll n;

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
    {
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

int main()
{
    fastio;
    cin >> n;
    matrix fiboMatrix = {{1, 1}, {1, 0}};
    matrix res = power(fiboMatrix, n);
    printf("%lld\n", res[0][1]);
    return 0;
}
