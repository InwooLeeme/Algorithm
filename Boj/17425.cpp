#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define fastio cin.tie(0)->sync_with_stdio(0)
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vs = vector<string>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;
#define int int64_t

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

template <size_t sz = 1'000'000>
struct Math
{
    vector<int> p;      // primes
    int fpr[sz + 1];    // smallest prime divisor, IsPrime(p) ? 0 : fpr[p]
    int expo[sz + 1];   // exponent of smallest prime divisor
    int cnt_pr[sz + 1]; // number of distinct prime divisors
    int phi[sz + 1];    // euler phi function
    int mu[sz + 1];     // mobius function
    int tau[sz + 1];    // number of divisors
    int sig[sz + 1];    // sum of divisors

    Math() { linear_sieve(); }

    int _pow(int x, int n)
    {
        int ret = 1;
        while (n)
        {
            if (n & 1)
                ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }

    void linear_sieve(int n = sz)
    {
        phi[1] = mu[1] = tau[1] = sig[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!fpr[i])
            {
                p.push_back(i);
                expo[i] = 1;
                phi[i] = i - 1;
                mu[i] = -1;
                tau[i] = 2;
                sig[i] = i + 1;
            }
            for (const auto &j : p)
            {
                if (i * j > n)
                    break;
                fpr[i * j] = j;
                if (i % j == 0)
                {
                    expo[i * j] = expo[i] + 1;
                    phi[i * j] = phi[i] * j;
                    mu[i * j] = 0;
                    tau[i * j] = tau[i] / expo[i * j] * (expo[i * j] + 1);
                    sig[i * j] = sig[i] * (j - 1) / (_pow(j, expo[i * j]) - 1) * (_pow(j, expo[i * j] + 1) - 1) / (j - 1);
                    break;
                }
                expo[i * j] = 1;
                phi[i * j] = phi[i] * phi[j];
                mu[i * j] = mu[i] * mu[j];
                tau[i * j] = tau[i] * tau[j];
                sig[i * j] = sig[i] * sig[j];
            }
        }
    }

    bool IsPrime(int n)
    {
        if (n <= 1)
            return 0;
        return !fpr[n];
    }

    bool IsPrime_naive(int n)
    {
        if (n <= 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i)
                continue;
            return 0;
        }
        return 1;
    }

    int phi_naive(int n)
    {
        int ret = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i)
                continue;
            ret = ret / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
        if (n != 1)
            ret = ret / n * (n - 1);
        return ret;
    }

    int tau_naive(int n)
    {
        int ret = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i)
                continue;
            ret += i * i == n ? 1 : 2;
        }
        return ret;
    }

    int sig_naive(int n)
    {
        int ret = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i)
                continue;
            ret += i * i == n ? i : i + n / i;
        }
        return ret;
    }

    vector<pair<int, int>> Factorize_naive(int n)
    { // must be n > 1
        vector<pair<int, int>> ret;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i)
                continue;
            int t = 0;
            while (n % i == 0)
                t++, n /= i;
            ret.push_back({i, t});
        }
        if (n != 1)
            ret.push_back({n, 1});
        return ret;
    }
};

int pSum[1'000'001];
Math<> math;

int32_t main()
{
    fastio;
    int tc;
    cin >> tc;
    for (int i = 1; i < 1'000'001; i++)
        pSum[i] = math.sig[i] + pSum[i - 1];
    while (tc--)
    {
        int n;
        cin >> n;
        cout << pSum[n] << "\n";
    }
    return 0;
}