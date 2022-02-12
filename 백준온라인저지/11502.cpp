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

constexpr int sz = 1000;
vector<int> p; // 0-indexed base
int sieve[sz + 1];
void linear_sieve(int n = sz)
{
    for (int i = 2; i <= n; i++)
    {
        if (!sieve[i])
            p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n)
                break;
            sieve[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
}

void Sol()
{
    int x;
    cin >> x;
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < p.size(); j++)
            for (int k = 0; k < p.size(); k++)
            {
                if (p[i] + p[j] + p[k] == x)
                {
                    cout << p[i] << ' ' << p[j] << ' ' << p[k] << "\n";
                    return;
                }
            }
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    linear_sieve();
    while (t--)
    {
        Sol();
    }
}