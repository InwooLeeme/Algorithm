// 10830번 : 행렬 제곱

#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long
typedef vector<vector<ll>> matrix;
const long long mod = 1000;

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

// 행렬 a를 n제곱
matrix power(matrix a, ll n)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++)
    {
        res[i][i] = 1; // 단위행렬
    }
    while (n > 0)
    {
        // n이 홀수이면
        if (n % 2 == 1)
        {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

void PrintMatrix(const matrix &a)
{
    ll size = a.size();
    for (ll i = 0; i < size; i++)
    {
        for (ll j = 0; j < size; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    fastio;
    ll a, b;
    cin >> a >> b;
    matrix input(a, vector<ll>(a));
    for (ll i = 0; i < a; i++)
    {
        for (ll j = 0; j < a; j++)
        {
            cin >> input[i][j];
        }
    }
    PrintMatrix(power(input, b));
    return 0;
}