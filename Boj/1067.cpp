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

const double _PI = 3.14159265358979323846;
typedef complex<double> C;

inline C E(double x) { return C(cos(2 * _PI * x), -sin(2 * _PI * x)); }

void FFT(vector<C> &x, bool invert)
{
    int n = (int)x.size(), newN = 1;
    vector<int> scramble;
    while (newN < n)
        newN <<= 1;
    x.resize(newN);
    scramble.resize(newN);
    int d = 1;
    for (int bit = (newN >> 1); bit; bit >>= 1)
    {
        for (int i = 0; i < newN; i++)
            if ((i / d) & 1)
                scramble[i] |= bit;
        d <<= 1;
    }
    vector<C> v(n), w(n);
    for (int i = 0; i < n; i++)
        v[i] = x[scramble[i]];
    int inv = (invert ? -1 : 1);
    for (int lv = 2; lv <= n; lv <<= 1)
    {
        for (int i = 0; i < n; i += lv)
        {
            for (int k = 0; k < lv / 2; k++)
            {
                C ve = v[i + k];
                C vo = v[i + k + lv / 2] * E((double)k / lv * inv);
                w[i + k] = ve + vo;
                w[i + k + lv / 2] = ve - vo;
            }
        }
        for (int i = 0; i < n; i++)
            v[i] = w[i];
    }
    if (invert)
        for (int i = 0; i < n; i++)
            x[i] = v[i] / (double)n;
    else
        for (int i = 0; i < n; i++)
            x[i] = v[i];
}

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<C> A(a.begin(), a.end()), B(b.begin(), b.end());
    int n = (int)max(A.size(), B.size());
    int i = 0;
    while ((1 << i) < (n << 1))
        i++;
    n = (1 << i);
    A.resize(n);
    B.resize(n);
    FFT(A, 0);
    FFT(B, 0);
    for (int i = 0; i < n; i++)
        A[i] *= B[i];
    FFT(A, 1);
    vector<int> ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = round(A[i].real());
    return ret;
}

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a)
        cin >> c;
    for (auto &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    reverse(all(b));
    vector<int> ret = mul(a, b);
    cout << *max_element(all(ret)) << "\n";
}